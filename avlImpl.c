#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

node *genNode(int val){

	node *n = (node *) malloc(sizeof(node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	n->balanceFactor = 0;

	return n;
}

int height(node *root){

	if(root == NULL)
		return 0;
	int lH = height(root->left);
	int rH = height(root->right);
	return lH > rH ? 1 + lH : 1 + rH;

}

node *searchNode(node *root, int val){
	
	if(root == NULL)
		return NULL;
	else if(root->val == val)
		return root;
	else if(val < root->val)
		return searchNode(root->left, val);
	else
		return searchNode(root->right, val);
}

node *searchFather(node *root, int val){
	if(root == NULL || root->val == val){
		return NULL;
	}
	
	if(val < root->val){
		if(root->left == NULL || root->left->val == val)
			return root;
		return searchFather(root->left, val);
	} else if(val > root->val){
		if(root->right == NULL || root->right->val == val)
			return root;
		return searchFather(root->right, val);
	}
}

node* insertAtBST(node *root, int val){
	if(searchNode(root, val) == NULL){

		node *father = searchFather(root, val);
		node *child = genNode(val);

		if(val < father->val)
			father->left = child;
		else
			father->right = child;
		
		autoBalanceFactor(root);
		return adjustTree(root);
	} else{
		printf("\nThe value is already in the Tree!\n");
	}

	return root;
}

node *searchMinRight(node *rightChild){
	if(rightChild != NULL){
		node *temp = rightChild;

		while(temp->left != NULL){
			if(temp->left->left != NULL)
				temp = temp->left;
			else
				break;
		}

		return temp;
	}

	return NULL;
}

node *searchMaxLeft(node *leftChild){
	if(leftChild != NULL){
		node *temp = leftChild;

		while(temp->right != NULL){
			if(temp->right->right != NULL)
				temp = temp->right;
			else
				break;
		}		

		return temp;
	}

	return NULL;
}

node* removeAtBST(node *root, int val){
	
	node *nodeToBeRemoved = searchNode(root, val);
	node *father = NULL;
	
	if(root->val != val)
		father = searchFather(root, val);

	if(nodeToBeRemoved == NULL)
		return root;

	if(nodeToBeRemoved->left == NULL && nodeToBeRemoved->right == NULL){
		if(father != NULL){
			if(nodeToBeRemoved->val < father->val)
				father->left = NULL;
			else
				father->right = NULL;
		}

	} else if(nodeToBeRemoved->left != NULL && nodeToBeRemoved->right == NULL){
		
		node *maxFatherLeft = searchMaxLeft(nodeToBeRemoved->left);
		node *max;

		if(maxFatherLeft->right != NULL){
			max = maxFatherLeft->right;
			maxFatherLeft->right = max->left;
		}else
			max = maxFatherLeft;

		if(father != NULL){
			if(nodeToBeRemoved->val < father->val)
				father->left = max;
			else
				father->right = max;
		}

		if(max != maxFatherLeft)
			max->left = nodeToBeRemoved->left;

	} else{
		
		node *minFatherRight = searchMinRight(nodeToBeRemoved->right);
		node *min;

		if(minFatherRight->left != NULL){
			min = minFatherRight->left;
			minFatherRight->left = min->right;
		}else
			min = minFatherRight;

		if(father != NULL){
			if(nodeToBeRemoved->val < father->val)
				father->left = min;
			else
				father->right = min;
		}

		if(min != minFatherRight)
			min->right = nodeToBeRemoved->right;

		if(nodeToBeRemoved->left != NULL)
			min->left = nodeToBeRemoved->left;
	}

	nodeToBeRemoved->left = NULL;
	nodeToBeRemoved->right = NULL;
	free(nodeToBeRemoved);
	autoBalanceFactor(root);

	return adjustTree(root);
}

void autoBalanceFactor(node *root){
	if(root != NULL){
		int currDiff = height(root->right) - height(root->left);
		if(currDiff != root->balanceFactor)
			root->balanceFactor = currDiff;
		autoBalanceFactor(root->left);
		autoBalanceFactor(root->right);
	}
}

node *findUnbalance(node *root){

	if(root == NULL)
		return NULL;

	if(root->balanceFactor < -1 || root->balanceFactor > 1)
		return root;

	node *leftSearch = findUnbalance(root->left);

	if(leftSearch != NULL)
		return leftSearch;

	return findUnbalance(root->right);
}

node *adjustTree(node *root){

	node *unbalancedNode;

	do{
		unbalancedNode = findUnbalance(root);
		node *father = NULL;

		if(unbalancedNode != NULL){
			father = searchFather(root, unbalancedNode->val);

			if(unbalancedNode->balanceFactor > 1){
	
				if(father == NULL)
					root = unbalancedNode->right;

				if(unbalancedNode->right->balanceFactor < 0)
					doubleLeftRotation(father, unbalancedNode);
				else
					simpleLeftRotation(father, unbalancedNode);
			} else{
				if(father == NULL)
					root = unbalancedNode->left;

				if(unbalancedNode->left->balanceFactor > 0)
					doubleRightRotation(father, unbalancedNode);
				else
					simpleRightRotation(father, unbalancedNode);
			}
			
			autoBalanceFactor(root);
		}
	}while(unbalancedNode != NULL);

	return root;
}

node* simpleRightRotation(node *father, node *unbalanced){
	node *newFather = unbalanced->left;
	unbalanced->left = newFather->right;
	newFather->right = unbalanced;

	if(father != NULL)
		father->left = newFather;
	
	return newFather;
}

node* simpleLeftRotation(node *father, node *unbalanced){
	node *newFather = unbalanced->right;
	unbalanced->right = newFather->left;
	newFather->left = unbalanced;

	if(father != NULL)
		father->right = newFather;

	return newFather;
}

void doubleRightRotation(node *father, node* unbalanced){
	unbalanced->left = simpleLeftRotation(NULL, unbalanced->left);
	simpleRightRotation(father, unbalanced);
}

void doubleLeftRotation(node *father, node *unbalanced){
	unbalanced->right = simpleRightRotation(NULL, unbalanced->right);
	simpleLeftRotation(father, unbalanced);
}

node *initialTree(){
	node *root = genNode(4);
	root->left = genNode(2);
	root->left->left = genNode(1);
	root->left->right = genNode(3);
	root->right = genNode(6);
	root->right->left = genNode(5);
	root->right->right = genNode(7);

	return root;
}

void printPreOrder(node *root){
	if(root != NULL){
		printf("%d -> ", root->val);
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printInOrder(node *root){
	if(root != NULL){
		printInOrder(root->left);
		printf("%d -> ", root->val);
		printInOrder(root->right);
	}
}

void printPosOrder(node *root){
	if(root != NULL){
		printPosOrder(root->left);
		printPosOrder(root->right);
		printf("%d -> ", root->val);
	}
}
