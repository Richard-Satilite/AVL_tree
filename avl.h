// --- Struct do tipo no --- //
typedef struct node node;


// --- Funcao para gerar um No --- //
// --- Recebe um numero inteiro --- //
node *genNode(int val);


// --- Funcao para obter a altura da arvore AVL --- //
// --- Recebe a raiz da arvore --- //
int height(node *root);


// --- Funcao para realizar uma busca em uma arvore ABB -- //
// --- recebe a raiz da arvore e o valor buscado --- //
node *searchNode(node *root, int val);


// --- Funcao para inserir um no em uma arvore ABB --- //
// --- Recebe o no a ser inserido e a raiz da arvore
void insertAtBST(node *root, node *leaf);


// --- Funcao para remover um no em uma arvore ABB --- //
// --- Recebe a raiz da arvore e o valor a ser removido --- //
node* removeAtBST(node *root, int val);


// --- Funcao que realiza a atualizacao dos fatores de balanceamento de cada no da arvore --- //
// --- Recebe a raiz da arvore --- //
void autoBalanceFactor(node *root)


// --- Funcao que realiza uma rotacao simples a direita --- //
// --- Recebe a raiz da sub arvore desbalanceada --- //
void simpleRightRotation(node *root);


// --- Funcao que realiza uma rotacao simples a esquerda --- //
// --- Recebe a raiz da sub arvore desbalanceada --- //
void simpleRightRotation(node *root);


// --- Funcao que realiza uma rotacao composta a direta --- //
// --- Recebe a raiz da sub arvore desbalanceada --- //
void doubleRightRotation(node *root);


// --- Funcao que realiza uma rotacao composta a esquerda --- //
// --- Recebe a raiz da sub arvore desbalanceada --- //
void doubleLeftRotation(node *root);
