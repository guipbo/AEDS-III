/*--------------------------------------------------
 * Projeto: -
 * File: AVLTree
 * Author: ProfGuibpo
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
void rlRotation( Tree *tree );
void lrRotation( Tree *tree );
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
    int status = 0;
    int exit = 0;

    printStatement();
    while( exit != 1 ){
        if( isEmpty(&(tree))==1 ) tree=createTree();
        status = 0;
        switch( mainMenu() ){
            //Imprimir Pre-ordem
            case 1:{
                printf("\n********** 1- PRE-ORDEM");
                printf("\nÁrvore: (");
                printPreOrder(tree);
                printf("...)");
                break;
            }
            //Imprimir In-ordem
            case 2:{
                printf("\n********** 2- IN-ORDEM");
                printf("\nÁrvore: (");
                printInOrder(tree);
                printf("...)");
                break;
            }
            //Imprimir Pos-ordem
            case 3:{
                printf("\n********** 3- POS-ORDEM");
                printf("\nÁrvore: (");
                printPostOrder(tree);
                printf("...)");
                break;
            }
            //Inserir valor na árvore
            case 4:{
                printf("\n********** 4- INSERIR VALOR NA ÁRVORE");
                int newValue = 0;

                printf("\n\nDigite o valor a ser inserido na árvore: ");
                scanf("%d", &newValue);

                status = insertNode(tree, newValue);

                status==1 ? printf("Valor %d inserido com sucesso!", newValue) : printf("Valor %d não foi inserido!", newValue);

                break;
            }
            //Remover valor da árvore
            case 5:{
                printf("\n********** 5- REMOVER VALOR DA ÁRVORE");
                int removeValue = 0;

                printf("\n\nDigite o valor a ser removido da árvore: ");
                scanf("%d", &removeValue);


                break;
            }
            //Pesquisar valor
            case 6:{
                printf("\n********** 6- PESQUISAR VALOR");
                int search = 0;
                printf("\n\nDigite o valor que deseja pequisar: ");
                scanf("%d", &search);
                
                status = searchNode(tree, search);

                status == 1 ? printf("\n%d existe na árvore!", search) : printf("\n%d não existe na árvore!", search);

                break;
            }
            //Limpar árvore
            case 7:{
                printf("\n********** 7- LIMPAR ÁRVORE");

                break;
            }
            //Imprimir altura da árvore
            case 8:{
                printf("\n********** 8- IMPRIMIR ALTURA DA ÁRVORE");
                
                break;
            }
            //Imprimir se a árvore está completa
            case 9:{
                printf("\n********** 9- IMPRIMIR SE A ÁRVORE ESTÁ COMPLETA");
                status = isComplete(tree);
                printf("\nÁrvore: (");
                printPreOrder(tree);
                printf("...) ");
                status == 1 ? printf("está completa.") : printf("NÃO está completa.");
                break;
            }
            //Imprimir soma dos valores da árvore
            case 10:{
                printf("\n********** 10- IMPRIMIR SOMA DOS VALORES DA ÁRVORE");
                
                break;
            }
            //Imprimir valor mínimo
            case 11:{
                printf("\n********** 11- IMPRIMIR VALOR MÍNIMO");
                
                break;
            }
            //Imprimir valor máximo
            case 12:{
                printf("\n********** 12- IMPRIMIR VALOR MÁXIMO");
                
                break;
            }
            //Imprimir quantidade de registros
            case 13:{
                printf("\n********** 13- IMPRIMIR QUANTIDADE DE REGISTROS");
                
                break;
            }
            //Imprimir quantidade de não folhas
            case 14:{
                printf("\n********** 14- IMPRIMIR QUANTIDADE DE NÃO FOLHAS");
                
                break;
            }
            //Imprimir quantidade de folhas
            case 15:{
                printf("\n********** 15- IMPRIMIR QUANTIDADE DE FOLHAS");
                
                break;
            }
            //Inserir valores de teste
            case 16:{
                printf("\n********** 16- INSERIR VALORES DE TESTE");
                insertTestTree(tree);
                break;
            }
            //Inserir valores aleatórios
            case 17:{
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
    printf("\n");
}

int isEmpty( Tree *tree ){
    if(tree->root == NULL || tree == NULL)
        return 1;
    return 0;
}

int balanceFactor( Tree *tree ){

    int balance = 0;

    balance = height(&(tree->root->right)) - height(&(tree->root->left));

    if( balance >= -1 && balance <= 1)
        return 1;

    return 0;
}

Node *biggerLeft( Tree *tree ){

}

Node *smallerRight( Tree *tree ){

}

void leftRotation( Tree *tree ){

}

void rightRotation( Tree *tree ){

}

void rlRotation( Tree *tree ){

}

void lrRotation( Tree *tree ){

}

int balance( Tree *tree ){

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
}

int removeNode( Tree *tree, int value ){

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
        if( tree->root->right == NULL && tree->root->left != NULL )
            return 0;
        if( tree->root->right != NULL && tree->root->left == NULL )
            return 0;
        
        isComplete(&(tree->root->left));
        isComplete(&(tree->root->right));

        return 1;
    }
}

int sum( Tree *tree ){

}

int minValue( Tree *tree ){

}

int maxValue( Tree *tree ){

}

int countNodes( Tree *tree ){

}

int countNonLeaves( Tree* tree ){

}

int countLeaves( Tree* tree ){

}

int insertRandomTree(Tree *tree, int quant){
    int value = 0;

    for( int i=0; i<quant; i++ ){
        value = rand()%101;
        if(insertNode(tree, value) == 0)
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
