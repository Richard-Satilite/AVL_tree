#ifndef AVL_H
#define AVL_H

// --- Struct do tipo no --- //
typedef struct node{
	int val;
	struct node *left;
	struct node *right;
	int balanceFactor;
}node;


// --- Funcao para gerar um No --- //
// --- Recebe um numero inteiro --- //
node *genNode(int val);


// --- Funcao para obter a altura da arvore AVL --- //
// --- Recebe a raiz da arvore --- //
int height(node *root);


// --- Funcao para realizar uma busca em uma arvore ABB --- //
// --- recebe a raiz da arvore e o valor buscado --- //
node *searchNode(node *root, int val);


// --- Funcao para realizar a busca do pai de um no em um arvore ABB --- //
// --- recebe a raiz da arvore e o valor do no filho --- //
// --- Retorna NULL em caso de arvore vazia --- //
node *searchFather(node *root, int val);


// --- Funcao para inserir um no em uma arvore ABB --- //
// --- Recebe a raiz da arvore e o valor do no a ser inserido --- //
void insertAtBST(node *root, int val);


// --- Funcao que obtem o menor no a direita de um no pai --- //
// --- recebe o filho a direita do no pai --- //
node *searchMinRight(node *rightChild);


// --- Funcao que obtem o maior no a esquerda de um no pai --- //
// --- recebe o filho a esquerda do no pai --- //
node *searchMaxLeft(node *leftChild);


// --- Funcao para remover um no em uma arvore ABB --- //
// --- Recebe a raiz da arvore e o valor a ser removido --- //
node* removeAtBST(node *root, int val);


// --- Funcao que realiza a atualizacao dos fatores de balanceamento de cada no da arvore --- //
// --- Recebe a raiz da arvore --- //
void autoBalanceFactor(node *root)


// --- Funcao que busca um no que esta desbalanceado --- //
// --- Recebe a raiz da arvore --- //
// --- Retorna NULL caso todos os nos estiverem balanceados --- //
node *findUnbalance(node *root);


// --- Funcao que verifica se uma arvore esta desbalanceada e chama funcoes de rotacao em caso de desbalanceamento --- //
// --- Recebe a raiz da arvore --- //
void adjustTree(node *root);


// --- Funcao que realiza uma rotacao simples a direita --- //
// --- Recebe o pai do no que esta desbalanceado e o no que esta desbalanceado --- //
void simpleRightRotation(node *fatehr, node *unbalanced);


// --- Funcao que realiza uma rotacao simples a esquerda --- //
// --- Recebe o pai do no que esta desbalanceado e o no que esta desbalanceado --- //
void simpleLeftRotation(node *father, node *unbalanced);


// --- Funcao que realiza uma rotacao composta a direta --- //
// --- Recebe o pai do no que esta desbalanceado e o no que esta desbalanceado --- //
void doubleRightRotation(node *father, node *unbalanced);


// --- Funcao que realiza uma rotacao composta a esquerda --- //
// --- Recebe o pai do no que esta desbalanceado e o no que esta desbalanceado --- //
void doubleLeftRotation(node *father, node *unbalanced);


// --- Funcao que retorna a raiz de uma ABB dos itens [1,2,3,4,5,6,7] --- //
node *initialTree();


// --- Funcao para exibir a arvore em pre-ordem --- //
// --- Recebe a raiz da arvore --- //
void printPreOrder(node *root);


// --- Funcao para exibir a arvore em ordem --- //
// --- Recebe a raiz da arvore --- //
void printInOrder(node *root);


// --- Funcao para exibir a arvore em pos ordem --- //
// --- Recebe a raiz da arvore --- //
void printPosOrder(node *root);

#endif
