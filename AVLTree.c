/*--------------------------------------------------
 * Universidade do Estado de Minas Gerais
 * Engenharia da Computação
 * Project: AVLTree
 * Author: Guilherme Patrick Braga de Oliveira - ProfGuibpo
 * Date: 06/09/2020
--------------------------------------------------*/

//LIBRARYS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>

/*--------------------------------------------------*/

//ABSTRACT DATA TYPES

typedef struct node {
    int data;
    struct node *left, *right;
}Node;

typedef struct tree{
    Node *root;
}Tree;

/*--------------------------------------------------*/

//FUNCTIONS LIST

void delay( unsigned int mseconds );
int mainMenu();
Tree *createTree();
Node *newNode(int newData);
void printStatement();
int isEmpty( Tree *tree );
int balanceFactor ( Tree *tree );
Node *biggerLeft( Tree *tree );
Node *smallerRight( Tree *tree );
void leftRotation( Tree *tree );
void rightRotation( Tree *tree );
void lrRotation( Tree *tree );
void rlRotation( Tree *tree );
int balance( Tree *tree );

void printPreOrder(Tree *tree);
void printInOrder(Tree *tree);
void printPostOrder(Tree *tree);
int insertNode( Tree *tree, int value );
int removeNode( Tree *tree, int value );
int searchNode( Tree *tree, int value );
int clearTree( Tree *tree );
int height( Tree *tree );
int isComplete( Tree *tree );
int totalSum = 0;
int sum( Tree *tree );
int minValue( Tree *tree );
int maxValue( Tree *tree );
int counterNodes = 0;
int countNodes( Tree *tree );
int countNonLeaves( Tree* tree );
int countLeaves( Tree* tree );
void insertTestTree( Tree *tree );
int insertRandomTree( Tree *tree, int quant );

/*--------------------------------------------------*/

//MAIN

void main (){
    setlocale(LC_ALL, "");

    Tree *tree = createTree();
    int exit = 0;
    int repeatFunction = 1;
    int index = 0;
    int status = 0;

    printStatement();
    while( exit != 1 ){
        if( isEmpty(&(tree))==1 ) tree=createTree();
        status = 0;
        repeatFunction = 1;
        switch( mainMenu() ){
            //Imprimir Pre-ordem
            case 1:{
                printf("\n--------------------------------------------------");
                printf("\n********** 1- PRE-ORDEM");
                printf("\nÁrvore: (");
                printPreOrder( tree );
                printf("...)");
                break;
            }
            //Imprimir In-ordem
            case 2:{
                printf("\n--------------------------------------------------");
                printf("\n********** 2- IN-ORDEM");
                printf("\nÁrvore: (");
                printInOrder( tree );
                printf("...)");
                break;
            }
            //Imprimir Pos-ordem
            case 3:{
                printf("\n--------------------------------------------------");
                printf("\n********** 3- POS-ORDEM");
                printf("\nÁrvore: (");
                printPostOrder( tree );
                printf("...)");
                break;
            }
            //Inserir valor na árvore
            case 4:{
                while( repeatFunction != 0 ){
                    printf("\n--------------------------------------------------");
                    printf("\n********** 4- INSERIR VALOR NA ÁRVORE");
                    printf("\n - Digite 0 (zero) para voltar ao menu principal.");

                    printf("\n\nDigite o valor a ser inserido na árvore: ");
                    scanf("%d", &index);
                    if( index != 0 ){
                        status = insertNode( tree, index );
                        status==1 ? printf("Valor %d inserido com sucesso!", index) : printf("Valor %d não foi inserido!", index);
                    }
                    repeatFunction = index;
                }
                break;
            }
            //Remover valor da árvore
            case 5:{
                while( repeatFunction != 0 ){
                    printf("\n--------------------------------------------------");
                    printf("\n********** 5- REMOVER VALOR DA ÁRVORE");
                    printf("\n - Digite 0 (zero) para voltar ao menu principal.");

                    printf("\n\nDigite o valor a ser removido da árvore: ");
                    scanf("%d", &index);

                    if( index != 0 ){
                        status = removeNode( tree, index );
                        status==1 ? printf("Valor %d removido com sucesso!", index) : printf("Valor %d não foi removido!", index);
                    }
                    repeatFunction = index;
                }
                break;
            }
            //Pesquisar valor
            case 6:{
                while( repeatFunction != 0 ){
                    printf("\n--------------------------------------------------");
                    printf("\n********** 6- PESQUISAR VALOR");
                    printf("\n - Digite 0 (zero) para voltar ao menu principal.");

                    printf("\n\nDigite o valor que deseja pequisar: ");
                    scanf("%d", &index);
                    
                    if( index != 0 ){
                        status = searchNode(tree, index);
                        status == 1 ? printf("\n%d existe na árvore!", index) : printf("\n%d não existe na árvore!", index);
                    }
                    repeatFunction = index;
                }

                break;
            }
            //Limpar árvore
            case 7:{
                printf("\n--------------------------------------------------");
                printf("\n********** 7- LIMPAR ÁRVORE");

                status = clearTree( tree );
                status == 1 ? printf("\nÁrvore limpa com sucesso.") : printf("\nÁrvore não foi limpa.");
                break;
            }
            //Imprimir altura da árvore
            case 8:{
                printf("\n--------------------------------------------------");
                printf("\n********** 8- IMPRIMIR ALTURA DA ÁRVORE");
                
                printf("\nAltura: %d", height( tree ));
                break;
            }
            //Imprimir se a árvore está completa 
            case 9:{
                printf("\n--------------------------------------------------");
                printf("\n********** 9- IMPRIMIR SE A ÁRVORE ESTÁ COMPLETA");
                status = isComplete( tree );
                printf("\nÁrvore: (");
                printPreOrder( tree );
                printf("...) ");
                status == 1 ? printf("está completa.") : printf("NÃO está completa.");
                break;
            }
            //Imprimir soma dos valores da árvore
            case 10:{
                printf("\n--------------------------------------------------");
                printf("\n********** 10- IMPRIMIR SOMA DOS VALORES DA ÁRVORE");
                
                printf("\nSoma: %d", sum( tree ));
                break;
            }
            //Imprimir valor mínimo
            case 11:{
                printf("\n--------------------------------------------------");
                printf("\n********** 11- IMPRIMIR VALOR MÍNIMO");

                printf("\nValor mínimo: %d", minValue( tree ));
                break;
            }
            //Imprimir valor máximo
            case 12:{
                printf("\n--------------------------------------------------");
                printf("\n********** 12- IMPRIMIR VALOR MÁXIMO");
                
                printf("\nValor máximo: %d", maxValue( tree ));
                break;
            }
            //Imprimir quantidade de registros
            case 13:{
                printf("\n--------------------------------------------------");
                printf("\n********** 13- IMPRIMIR QUANTIDADE DE REGISTROS");
                counterNodes = 0;

                printf("\nQuantidade de registros: %d", countNodes( tree ));
                break;
            }
            //Imprimir quantidade de não folhas
            case 14:{
                printf("\n--------------------------------------------------");
                printf("\n********** 14- IMPRIMIR QUANTIDADE DE NÃO FOLHAS");
                counterNodes = 0;
                
                printf("\nQuantidade de não folhas: %d", countNonLeaves( tree ));
                break;
            }
            //Imprimir quantidade de folhas
            case 15:{
                printf("\n--------------------------------------------------");
                printf("\n********** 15- IMPRIMIR QUANTIDADE DE FOLHAS");
                counterNodes = 0;
                
                printf("\nQuantidade de folhas: %d", countLeaves( tree ));
                break;
            }
            //Inserir valores de teste
            case 16:{
                printf("\n--------------------------------------------------");
                printf("\n********** 16- INSERIR VALORES DE TESTE");
                insertTestTree(tree);
                break;
            }
            //Inserir valores aleatórios
            case 17:{
                printf("\n--------------------------------------------------");
                printf("\n********** 17- INSERIR VALORES ALEATÓRIOS");
                int quant=0;
                printf("\nInsira a quantidade de valores aleatórios que serão inseridos na árvore: ");
                scanf("%d", &quant);

                status = insertRandomTree(tree, quant);


                if ( status==1 ){
                    printf("\nÁrvore: (");
                    printPreOrder(tree);
                    printf("...) inserida com sucesso.");
                }
                else
                    printf("\n\nFalha na inserção!");
                break;
            }
            //Limpar tela
            case 99: {
                system("@cls||clear");
                printStatement();
                break;
            }
            //Sair
            case 0: {
                exit = 1;
                break;
            }
            //Opção incorreta
            default: {
                printf("\nOpção incorreta.\nSelecione entre as opções disponíveis!");
                break;
            }
        }
    }
    free(tree);
    printf("\n--------------------\n");
    printf("Obrigado por utilizar o programa!");
    printf("\n--------------------\n");
    delay(3000);
}

/*--------------------------------------------------*/

//FUNCTIONS

void delay( unsigned int mseconds ){
    clock_t goal = mseconds + clock();
    while(goal>clock());
}

int mainMenu(){
    int option=0;

    printf("\n--------------------------------------------------");
    printf("\n\n********** MAIN MENU");
    printf("\n    Escolha uma das opções abaixo");
    printf("\n1- Imprimir Pre ordem;");
    printf("\n2- Imprimir In ordem;");
    printf("\n3- Imprimir Pos ordem;");
    printf("\n4- Inserir valor na árvore;");
    printf("\n5- Remover valor da árvore;");
    printf("\n6- Pesquisar valor;");
    printf("\n7- Limpar árvore;");
    printf("\n8- Imprimir altura da árvore;");
    printf("\n9- Imprimir se a árvore está completa;");
    printf("\n10- Imprimir soma dos valores da árvore;");
    printf("\n11- Imprimir valor mínimo;");
    printf("\n12- Imprimir valor máximo;");
    printf("\n13- Imprimir quantidade de registros;");
    printf("\n14- Imprimir quantidade de não folhas;");
    printf("\n15- Imprimir quantidade de folhas;");
    printf("\n16- Inserir valores de teste;");
    printf("\n17- Inserir valores aleatórios;");
    printf("\n99- Limpar tela;");
    printf("\n0- Sair.");
    printf("\n\n-----> ");
    scanf("\r%d", &option);

    return option;
}

Tree *createTree(){
    Tree *tree = (Tree*)malloc(sizeof(Tree));

    if(tree != NULL) tree->root = NULL;

    return tree;
}

Node *newNode( int newData ){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

void printStatement(){
    printf("\n********** Árvore AVL **********");
    printf("\n - Entre apenas com valores inteiros. \n - Zero não é uma entrada válida para a árvore.");
    printf("\n");
}

int isEmpty( Tree *tree ){
    if(tree->root == NULL || tree == NULL)
        return 1;
    return 0;
}

int balanceFactor( Tree *tree ){
    return height( &(tree->root->right) ) - height( &(tree->root->left) );
}
 
Node *biggerLeft( Tree *tree ){
    Node *aux;

    if( ( tree->root->right ) == NULL ){
        aux = tree->root;
        //Tendo ou não filho, vai setar NULL
        tree->root = tree->root->left;
        return aux;
    }
    biggerLeft( &(tree->root->right) );
}

Node *smallerRight( Tree *tree ){
    Node *aux;

    if( ( tree->root->left ) == NULL ){
        aux = tree->root;
        //Tendo ou não filho, vai setar NULL
        tree->root = tree->root->right;
        return aux;
    }
    smallerRight( &(tree->root->left) );
}

void leftRotation( Tree *tree ){
    Node *aux = tree->root;

    tree->root = aux->right;
    aux->right = tree->root->left;
    tree->root->left = aux;
}

void rightRotation( Tree *tree ){
    Node *aux = tree->root;

    tree->root = aux->left;
    aux->left = tree->root->right;
    tree->root->right = aux;
}

void lrRotation( Tree *tree ){
    leftRotation( &(tree->root->left) );
    rightRotation( tree );
}

void rlRotation( Tree *tree ){
    rightRotation( &(tree->root->right) );
    leftRotation( tree );
}

int balance( Tree *tree ){
    if( tree->root != NULL ){
        balance( &(tree->root->left) );
        balance( &(tree->root->right) );

        if( balanceFactor( tree ) < -1 ){
            balanceFactor( &(tree->root->left) ) == 1 ? lrRotation( tree ) : rightRotation( tree );
        }
        else if( balanceFactor(tree) > 1){
            balanceFactor( &(tree->root->right) ) == -1 ? rlRotation( tree ) : leftRotation( tree );
        }
        if( balanceFactor( tree ) == 1 || balanceFactor( tree ) == -1 )
            return 1;
    }
}

void printPreOrder(Tree *tree){
    if( tree->root != NULL ){
        printf("%d, ", tree->root->data);
        printPreOrder(&(tree->root->left));
        printPreOrder(&(tree->root->right));
    }
}

void printInOrder(Tree *tree){
    if( tree->root != NULL ){
        printInOrder(&(tree->root->left));
        printf("%d, ", tree->root->data);
        printInOrder(&(tree->root->right));
    }
}

void printPostOrder(Tree *tree){
    if( tree->root != NULL ){
        printPostOrder(&(tree->root->left));
        printPostOrder(&(tree->root->right));
        printf("%d, ", tree->root->data);
    }
}

int insertNode( Tree *tree, int value ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if( newNode == NULL )
        return 0;
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if( tree->root == NULL ){
        tree->root = newNode;
        return 1;
    }

    if( newNode->data < tree->root->data )
        insertNode(&(tree->root->left), value);
    else if( newNode->data > tree->root->data)
        insertNode(&(tree->root->right), value);

    return balance( tree );
}

int removeNode( Tree *tree, int value ){
    if( tree->root == NULL )
        return 1;
    
    if( searchNode( tree, value ) != 1 )
        return 0;

    if( value > tree->root->data )
        removeNode( &(tree->root->right), value );
    else if( value < tree->root->data )
        removeNode( &(tree->root->left), value );
    else{
        Node *aux = tree->root;

        if( tree->root->right == NULL && tree->root->left == NULL ){
            tree->root=NULL;
        }
        else if( tree->root->right != NULL && tree->root->left == NULL )
            tree->root = tree->root->right;
        else if( tree->root->right == NULL && tree->root->left != NULL )
            tree->root = tree->root->left;
        else{
            if( balanceFactor( tree ) > 0)
                aux = smallerRight( &(tree->root->right) );
            else
                aux = biggerLeft( &(tree->root->left) );

            aux->left = tree->root->left;
            aux->right = tree->root->right;

            tree->root = aux;

        }

        aux = NULL;
    }

    balance( tree );

    if( searchNode( tree, value ) != 1 )
        return 1;
    return 0;
}

int searchNode( Tree *tree, int value ){
    if ( tree->root != NULL ){
        if(tree->root->data == value)
            return 1;
        else if ( tree->root->data > value )
            searchNode(&(tree->root->left), value);
        else if ( tree->root->data < value )
            searchNode(&(tree->root->right), value);
    }
}

int clearTree( Tree *tree ){
    if(tree->root != NULL){
        clearTree( &(tree->root->left) );
        clearTree( &(tree->root->right) );
        tree->root = NULL;
        free(tree->root);
    }
    return 1;
}

int height( Tree *tree ){
    if(tree->root != NULL){
        int leftHeight = height(&(tree->root->left)) + 1;
        int rightHeight = height(&(tree->root->right)) + 1;

        if( leftHeight > rightHeight )
            return leftHeight;
        return rightHeight;
    }
}

int isComplete( Tree *tree ){
    if( tree->root != NULL ){
        if( isComplete( &(tree->root->left) ) == 0) return 0;
        if( isComplete( &(tree->root->right) ) == 0) return 0;
        if( ( tree->root->right == NULL && tree->root->left != NULL ) || ( tree->root->right != NULL && tree->root->left == NULL ))
            return 0;
    }
    return 1;
}

int sum( Tree *tree ){
    if( tree->root != NULL ){
        totalSum += tree->root->data;
        sum( &(tree->root->left) );
        sum( &(tree->root->right) );
    }
    return totalSum;
}

int minValue( Tree *tree ){
    if( tree->root->left == NULL )
        return tree->root->data;
    minValue( &(tree->root->left) );
}

int maxValue( Tree *tree ){
    if( tree->root->right == NULL)
        return tree->root->data;
    maxValue( &(tree->root->right) );
}

int countNodes( Tree *tree ){
    if( tree->root != NULL ){
        counterNodes += 1;
        countNodes( &(tree->root->left) );
        countNodes( &(tree->root->right) );
    }
    return counterNodes;
}

int countNonLeaves( Tree* tree ){
    if( tree->root != NULL ){
        if( tree->root->left != NULL || tree->root->right != NULL )
            counterNodes += 1;
        countNonLeaves( &(tree->root->left) );
        countNonLeaves( &(tree->root->right) );
    }
    return counterNodes;
}

int countLeaves( Tree* tree ){
    if( tree->root != NULL ){
        if( tree->root->left == NULL && tree->root->right == NULL )
            counterNodes += 1;
        countLeaves( &(tree->root->left) );
        countLeaves( &(tree->root->right) );
    }
    return counterNodes;
}

int insertRandomTree(Tree *tree, int quant){
    int value = 0;

    for( int i=0; i<quant; i++ ){
        value = rand()%101;
        if( value != 0 )
            if( insertNode(tree, value) == 0 )
                return 0;
    }
    return 1;
}

void insertTestTree( Tree *tree ){
    int value [18] = {15, 6, 12, 9, 14, 13, 25, 18, 20, 23, 5, 3, 38, 45, 50, 48, 46, 60};

    printf("\nÁrvore inserida: (");
    for( int i=0; i<18; i++ ){
        insertNode(tree, value[i]);
        printf("%d, ", value[i]);
    }
    printf("...)");
    
}

/*--------------------------------------------------*/
