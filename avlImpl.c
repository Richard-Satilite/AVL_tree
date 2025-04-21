#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

typedef struct node{

	int val;
	struct node *left;
	struct node *right;
	int balanceFactor;

}node;


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
	if(root == NULL){
		printf("\nEmpty tree!\n");
		return NULL;
	}
	
	if(val < root->val){
		if(root->left->val == val || root->left == NULL)
			return root;
		return searchFather(root->left, val);
	} else if(val > root->val){
		if(root->right->val == val || root->right == NULL)
			return root;
		return searchFather(root->right, val);
	}
}

void insertAtBST(node *root, int val){
	if(searchNode(root, val) == NULL){

		node *father = searchFather(root, val);
		node *child = genNode(val);

		if(val < father->val)
			father->left = child;
		else
			father->right = child;
		
		autoBalanceFactor(root);
	} else{
		printf("\nThe value is already in the Tree!\n");
	}
}

node *searchMinRight(node *rightChild){
	if(rightChild != NULL){
		node *temp = rightChild;

		while(temp->left != NULL)
			temp = temp->left;
		
		return temp;
	}

	return NULL;
}

node *searchMaxLeft(node *leftChild){
	if(leftChild != NULL){
		node *temp = leftChild;

		while(temp->right != NULL)
			temp = temp->right;
		
		return temp;
	}

	return NULL
}

void removeAtBST(node *root, int val){
	
	node *nodeToBeRemoved = searchNode(root, val);
	node *father = NULL;
	
	if(root->val != val)
		father = searchFather(root, val);

	if(nodeToBeRemoved == NULL)
		return;

	if(nodeToBeRemoved->left == NULL && nodeToBeRemoved->right == NULL){
		if(father != NULL){
			if(nodeToBeRemoved-> val < father->val)
				father->left = NULL;
			else
				father->right = NULL
		}

	} else if(nodeToBeRemoved->left != NULL && nodeToBeRemoved->right == NULL){
		
		node *maxLeft = searchMaxLeft(nodeToBeRemoved->left);

		if(father != NULL){
			if(nodeToBeRemoved->val < father->val)
				father->left = maxLeft;
			else
				father->right = maxLeft;
		}

	} else{
		
		node *minRight = searchMinRight(nodeToBeRemoved->right);

		if(father != NULL){
			if(nodeToBeRemoved->val < father->val)
				father->left = minRight;
			else
				father->right = minRight;
		}

	}

	free(nodeToBeRemoved);
	autoBalanceFactor(root);
}

void autoBalanceFactor(node *root){
	if(root != NULL){
		int currDiff = height(root->right) - height(root->left);
		if(currDiff != root->balanceFactor)
			root->balanceFactor = currDif;
		autoBalanceFactor(root->left);
		autoBalanceFactor(root->right);
	}
}


void adjustBalance(node *root){
	if(root == NULL)
		return;

	if(root->balanceFactor > -2 && root->balanceFactor < 2){
		adjustBalance(root->left);
		adjustBalance(root->right);
	} else{

		if(root->balanceFactor > 1){
			if(root->right->balanceFactor < 0)
				//Rotacao dupla a esquerda
			else	
				//Rotacao simples a esquerda
		} else{
			if(root->left->balanceFactor > 0)
				//Rotacao dupla a direita
			else
				//Rotcao simples a direita
		}
	}
}

void simpleRightRotation(node *root){
	
}

