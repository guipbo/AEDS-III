/*--------------------------------------------------
 * Universidade do Estado de Minas Gerais
 * Engenharia da Computação
 * Project: Lista01
 * File: Exercicio06
 * Author: Guilherme Patrick Braga de Oliveira - ProfGuibpo
--------------------------------------------------*/

//LIBRARYS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*--------------------------------------------------*/

//ABSTRACT DATA TYPES

typedef struct user {
    char name[200];
    int priority;
}User;

typedef struct priorityQueue{
    int quantity;
    User data[250];
}Queue;

/*--------------------------------------------------*/

//FUNCTIONS LIST

void delay( unsigned int mseconds );
int mainMenu();
Queue *createQueue();
void printStatement();

int insertQueue( Queue *queue );
int removeQueue( Queue *queue );
int first( Queue *queue );

/*--------------------------------------------------*/

//MAIN

void main (){
    setlocale(LC_ALL, "");

    Queue *queue = createQueue();
    int exit = 0;
    int repeatFunction = 1;
    int index = 0;
    int status = 0;

    printStatement();
    while( exit != 1 ){
        status = 0;
        repeatFunction = 1;
        switch( mainMenu() ){
            //Inserir item na fila
            case 1:{
                printf("\n--------------------------------------------------");
                printf("\n********** 1- INSERIR ITEM NA FILA");

                status = insertQueue( queue );

                status != 1 ? printf("\nErro ao inserir a pessoa.") : printf("\nPessoa inserida com sucesso.");
                break;
            }
            //Remover item da fila
            case 2:{
                printf("\n--------------------------------------------------");
                printf("\n********** 2- REMOVER ITEM DA FILA");

                status = removeQueue( queue );

                status != 1 ? printf("\nErro ao remover a pessoa.") : printf("\nPessoa removida com sucesso.");
                break;
            }
            //Perquisar item na fila
            case 3:{
                printf("\n--------------------------------------------------");
                printf("\n********** 3- PESQUISAR ITEM NA FILA");

                status = first( queue );

                if( status != 1 ) printf("\nFila vazia.");
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
    free(queue);
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
    printf("\n1- Inserir item na fila;");
    printf("\n2- Remover item da fila;");
    printf("\n3- Perquisar item na fila;");
    printf("\n99- Limpar tela;");
    printf("\n0- Sair.");
    printf("\n\n-----> ");
    scanf("\r%d", &option);

    return option;
}

Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if(queue != NULL) queue->quantity = 0;
    return queue;
}

void printStatement(){
    printf("\n********** EXERCÍCIO 07 **********");
    printf("\nEscreva um Algoritmo que utilize fila de prioridade que deve funcionar como fila de banco onde deve seguir o seguinte critério de prioridade.");
    printf("\na. Usuário preferencial Prioridade 1");
    printf("\nb. Usuário exclusivo do Banco Prioridade 2");
    printf("\nc. Usuário comum Prioridade 3");
    printf("\nd. O algoritmo deve inserir novos usuários (informando sua Prioridade) e retirar usuários de acordo com a prioridade.");
    printf("\n");
}

int insertQueue( Queue *queue ){
    if( queue == NULL || queue == 250 )
        return 0;
    
    char name[200];
    int priority;

    printf("Escreva o nome da pessoa: ");
    setbuf(stdin, NULL);
    gets(name);

    printf("\nDigite: ");
    printf("\n1- para Preferencial;");
    printf("\n2- para Exclusivo;");
    printf("\n3- para Comum;");
    printf("\n-----> ");
    scanf("%d", &priority);

    int i = queue->quantity-1;
	while(i >= 0 && queue->data[i].priority >= priority){
		queue->data[i+1] = queue->data[i];
		i--;
	}

    strcpy( queue->data[i+1].name, name);
    queue->data[i+1].priority = priority;
    queue->quantity++;
    return 1;
}

int removeQueue( Queue *queue ){
    if( queue == NULL || queue->quantity == 0 )
        return 0;
    queue->quantity--;
    return 1;
}

int first( Queue *queue ){
    if( queue == NULL || queue->quantity == 0 )
        return 0;
    printf("Próximo: %s\n", queue->data[queue->quantity-1].name);
    return 1;
}

/*--------------------------------------------------*/
