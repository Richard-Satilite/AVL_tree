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

	if(!root)
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

void insertAtBST(node *root, node *leaf){
	if(leaf->val < root->val){
		if(!root->left)
			root->left = leaf;
		else
			insertAtBST(root->left, leaf);
	}
	else if(leaf->val > root->val){
		if(!root->right)
			root->right = leaf;
		else
			insertAtBST(root->right, leaf);
	}
}
