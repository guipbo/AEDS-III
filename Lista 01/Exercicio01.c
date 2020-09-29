/*--------------------------------------------------
 * Projeto: Lista 01 AEDSIII
 * File: Exercício 01
 * Author: ProfGuibpo
--------------------------------------------------*/

//LIBRARYS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

/*--------------------------------------------------*/

//ABSTRACT DATA TYPES

typedef struct node {
    char data;
    int quant;
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
Node *newNode(char newData);

void printPreOrder(Tree *tree);
void printInOrder(Tree *tree);
void printPostOrder(Tree *tree);
void printStatement();

int isEmpty( Tree *tree );
int searchNode( Tree *tree, char value );
int insertNode( Tree *tree, char value );
int insertTree( Tree *tree, char value[250] );

/*--------------------------------------------------*/

//MAIN

void main (){
    setlocale(LC_ALL, "");

    Tree *tree = createTree();
    int status = 0;
    int exit = 0;
    
    char sentence[250]="";

    printStatement();
    while( exit != 1 ){
        if( isEmpty(&(tree))==1 ) tree=createTree();
        status = 0;
        switch( mainMenu() ){
            //Imprimir Pre-ordem
            case 1:{
                printf("\n********** 1- PRE-ORDEM");
                printf("\n********** ÁRVORE\n");
                printPreOrder(tree);
                break;
            }
            //Imprimir In-ordem
            case 2:{
                printf("\n********** 2- IN-ORDEM");
                printf("\n********** ÁRVORE\n");
                printInOrder(tree);
                break;
            }
            //Imprimir Pos-ordem
            case 3:{
                printf("\n********** 3- POS-ORDEM");
                printf("\n********** ÁRVORE\n");
                printPostOrder(tree);
                break;
            }
            //Inserir sentença
            case 4:{
                printf("\n********** 4- INSERIR SENTENÇA");
                printf("\n\nDigite a sentença que deseja inserir na árvore: ");
                fgets(sentence, 250, stdin);

                printf("Sentença: %s", sentence);

                status = insertTree(tree, sentence);

                status == 1 ? printf("\n\nSentença inserida com sucesso!") : printf("\n\nFalha na inserção!");

                break;
            }
            //Procurar caractere
            case 5:{
                printf("\n********** 5- PROCURAR CARACTERE");
                char search = "";
                printf("\n\nDigite o caractere que deseja procurar: ");
                scanf("%c", &search);
                search = getchar();
                
                status = searchNode(tree, search);

                if(status != 1) printf("\n%c não encontrado!", search);

                break;
            }
            //Inserir sentença de teste
            case 98:{
                printf("\n********** 98- INSERIR SENTENÇA DE TESTE NA ÁRVORE");

                status = insertTestSentence(tree);

                printf("\n********** ÁRVORE GERADA\n");
                printPreOrder(tree);

                status == 1 ? printf("\n\nSentença inserida com sucesso!") : printf("\n\nFalha na inserção!");
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
    printf("\n4- Inserir sentença;");
    printf("\n5- Procurar caractere;");
    printf("\n98- Inserir sentença de teste;");
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

Node *newNode(char newData){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

void printPreOrder(Tree *tree){
    if( tree->root != NULL ){
        printf("\nNó: %c - Quantidade: %d", tree->root->data, tree->root->quant);
        printPreOrder(&(tree->root->left));
        printPreOrder(&(tree->root->right));
    }
}

void printInOrder(Tree *tree){
    if( tree->root != NULL ){
        printInOrder(&(tree->root->left));
        printf("\nNó: %c - Quantidade: %d", tree->root->data, tree->root->quant);
        printInOrder(&(tree->root->right));
    }
}

void printPostOrder(Tree *tree){
    if( tree->root != NULL ){
        printPostOrder(&(tree->root->left));
        printPostOrder(&(tree->root->right));
        printf("\nNó: %c - Quantidade: %d", tree->root->data, tree->root->quant);
    }
}

void printStatement(){
    printf("\n********** EXERCÍCIO 01 **********");
    printf("\n\nEscreva um algoritmo em que o usuário irá informar uma frase, logo em seguida algoritmo irá usar a arvore binaria simples para montar a arvore, cada nodo será representado por uma letra e deverá conter a quantidade de vezes que apareceu na frase informada pelo usuário. O algoritmo deverá permitir o usuário consultar se uma letra está contida na frase informada e quantas vezes é apareceu.");
    printf("\n");
}

int isEmpty( Tree *tree ){
    if(tree->root == NULL || tree == NULL)
        return 1;
    return 0;
}

int insertNode( Tree *tree, char value ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if( newNode == NULL )
        return 0;
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if( tree->root == NULL ){
        newNode->quant = 1;
        tree->root = newNode;
        return 1;
    }

    if( newNode->data < tree->root->data )
        insertNode(&(tree->root->left), value);
    else if( newNode->data > tree->root->data)
        insertNode(&(tree->root->right), value);
    else if( newNode->data == tree->root->data ){
        tree->root->quant += 1;
        return 1;
    }
}

int insertTree( Tree *tree, char value[250] ){
    for( int i=0; i < strlen(value); i++ ){
        if( value[i] != NULL ){
            int status = insertNode( tree, value[i] );
            if(status == 0)
                return 0;
        }
    }
    return 1;
}

int insertTestSentence (Tree *tree){
    char testSentence[250] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    printf("\nSentença inserida: '%s'", &testSentence);
    return insertTree(tree, testSentence);
}

int searchNode( Tree *tree, char value ){
    if ( tree->root != NULL ){
        if(tree->root->data == value){
            printf("\n%c encontrado %d vezes.", tree->root->data, tree->root->quant);
            return 1;
        }
        else if ( tree->root->data > value )
            searchNode(&(tree->root->left), value);
        else if ( tree->root->data < value )
            searchNode(&(tree->root->right), value);
    }
}

/*--------------------------------------------------*/
