/*--------------------------------------------------
 * Projeto: Lista 01 AEDSIII
 * File: Exercício 02
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

void printPreOrder(Tree *tree);
void printInOrder(Tree *tree);
void printPostOrder(Tree *tree);
void printStatement();

int isEmpty( Tree *tree );
int insertNode( Tree *tree, int value );
int insertNodeMirror( Tree *mirrorTree, int value );
int mirror (Tree *tree, Tree *mirrorTree);
int searchNode( Tree *tree, int value );
void insertTestTree ( Tree *tree );
int insertRandomTree ( Tree *tree, int quant );

/*--------------------------------------------------*/

//MAIN

void main (){
    setlocale(LC_ALL, "");

    Tree *tree = createTree();
    Tree *mirrorTree = createTree();
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
            //Inserir valor
            case 4:{
                printf("\n********** 4- INSERIR VALOR");
                int newValue = 0;

                printf("\n\nDigite um valor a ser inserido na árvore: ");
                scanf("%d", &newValue);

                status = insertNode(tree, newValue);

                status==1 ? printf("Valor %d inserido com sucesso!", newValue) : printf("Valor %d não foi inserido!", newValue);

                break;
            }
            //Procurar valor
            case 5:{
                printf("\n********** 5- PROCURAR VALOR");
                int search = 0;
                printf("\n\nDigite o valor que deseja procurar: ");
                scanf("%d", &search);
                
                status = searchNode(tree, search);

                if(status != 1) printf("\n%d não encontrado!", search);

                break;
            }
            //Gerar árvore espelhada
            case 6:{
                printf("\n********** 6- GERAR ÁRVORE ESPELHADA");
                status = mirror(tree, mirrorTree);
                printf("\nÁrvore: (");
                printPreOrder(tree);
                printf("...)");
                printf("\nEspelho: (");
                printPreOrder(mirrorTree);
                printf("...)");
                break;
            }
            //Imprimir espelhada Pre-ordem
            case 7:{
                printf("\n********** 7- ESPELHADA PRE-ORDEM");
                printf("\nÁrvore: ");
                printPreOrder(tree);
                printf("...");
                break;
            }
            //Imprimir espelhada In-ordem
            case 8:{
                printf("\n********** 8- ESPELHADA IN-ORDEM");
                printf("\nÁrvore: ");
                printInOrder(mirrorTree);
                printf("...");
                break;
            }
            //Imprimir espelhada Pos-ordem
            case 9:{
                printf("\n********** 9- ESPELHADA POS-ORDEM");
                printf("\nÁrvore: ");
                printPostOrder(mirrorTree);
                printf("...");
                break;
            }
            //Inserir árvore de teste
            case 97:{
                printf("\n********** 97- INSERIR ÁRVORE DE TESTE");
                insertTestTree(tree);
                break;
            }
            //Inserir árvore aleatória
            case 98:{
                printf("\n********** 98- INSERIR ÁRVORE ALEATÓRIA");
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
                printf("\nTem certeza que deseja sair?\nDigite 1 para sim: ");
                scanf("\r%d", &exit);
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

void delay ( unsigned int mseconds ){
    clock_t goal = mseconds + clock();
    while(goal>clock());
}

int mainMenu(){
    int option=0;

    printf("\n--------------------------------------------------");
    printf("\n********** MAIN MENU");
    printf("\n1- Imprimir Pre ordem;");
    printf("\n2- Imprimir In ordem;");
    printf("\n3- Imprimir Pos ordem;");
    printf("\n4- Inserir valor;");
    printf("\n5- Procurar valor;");
    printf("\n6- Gerar árvore espelhada;");
    printf("\n7- Imprimir espelhada Pre ordem;");
    printf("\n8- Imprimir espelhada In ordem;");
    printf("\n9- Imprimir espelhada Pos ordem;");
    printf("\n97- Inserir árvore de teste;");
    printf("\n98- Inserir árvore aleatória;");
    printf("\n99- Limpar tela;");
    printf("\n0- Sair.");
    printf("\n\nSelecione: ");
    scanf("\r%d", &option);

    return option;
}

Tree *createTree(){
    Tree *tree = (Tree*)malloc(sizeof(Tree));

    if(tree != NULL) tree->root = NULL;

    return tree;
}

Node *newNode(int newData){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
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

void printStatement(){
    printf("\n********** EXERCÍCIO 02 **********");
    printf("\n\nEscreva um algoritmo que dado uma árvore binária busca informada, ele possa produzir uma arvore espelho.");
    printf("\n");
}

int isEmpty( Tree *tree ){
    if(tree->root == NULL || tree == NULL)
        return 1;
    return 0;
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

int insertNodeMirror( Tree *mirrorTree, int value ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if( newNode == NULL )
        return 0;
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if( mirrorTree->root == NULL ){
        mirrorTree->root = newNode;
        return 1;
    }

    if( newNode->data < mirrorTree->root->data )
        insertNodeMirror(&(mirrorTree->root->right), value);
    else if( newNode->data > mirrorTree->root->data)
        insertNodeMirror(&(mirrorTree->root->left), value);
}

int mirror (Tree *tree, Tree *mirrorTree){
    if( tree->root != NULL ){
        if(insertNodeMirror(mirrorTree, tree->root->data)==0)
            return 0;
        mirror(&(tree->root->left), mirrorTree);
        mirror(&(tree->root->right), mirrorTree);
    }
    return 1;
}

int searchNode( Tree *tree, int value ){
    if ( tree->root != NULL ){
        if(tree->root->data == value){
            printf("\n%d encontrado.", tree->root->data);
            return 1;
        }
        else if ( tree->root->data > value )
            searchNode(&(tree->root->left), value);
        else if ( tree->root->data < value )
            searchNode(&(tree->root->right), value);
    }
}

int insertRandomTree (Tree *tree, int quant){
    int value = 0;

    for( int i=0; i<quant; i++ ){
        value = rand()%101;
        if(insertNode(tree, value) == 0)
            return 0;
    }
    return 1;
}

void insertTestTree ( Tree *tree ){
    int value [18] = {15, 6, 12, 9, 14, 13, 25, 18, 20, 23, 5, 3, 38, 45, 50, 48, 46, 60};

    printf("\nÁrvore inserida: (");
    for( int i=0; i<18; i++ ){
        insertNode(tree, value[i]);
        printf("%d, ", value[i]);
    }
    printf("...)");
    
}

/*--------------------------------------------------*/
