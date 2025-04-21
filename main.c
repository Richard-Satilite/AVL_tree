#include <stdio.h>
#include "avl.h"

int main(){

	int n, value;
	node *root = initialTree();

	printf("\nInitial Tree\n\n");
	printInOrder(root);

	do{
		printf("\n\nChoose one of the options\n[1] - View the Tree\n[2] - Add value in the Tree\n[3] - Remove a value in the Tree\n[4] - Exit program\n");

		scanf("%d", &n);	

		switch(n){
			case 1:
				printf("\n\nPre-order view:\n");
				printPreOrder(root);

				printf("\n\nIn-order view:\n");
				printInOrder(root);

				printf("\n\nPos-order view:\n");
				printPosOrder(root);
			break;
			case 2:
				printf("\n\nType the value that you want to add: ");
				scanf("%d", &value);
				insertAtBST(root, value);
			break;
			case 3:
				printf("\n\nType the value that you want to remove: ");
				scanf("%d", &value);
				removerAtBST(root, value);
			break;
			case 4:
				printf("\nSee you later!\n");
			break;
			default:
				printf("\nInvalid Option!\n");
			break;
		}

	}while(n != 4);

	return 0;
}
