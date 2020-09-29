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

typedef struct city {
    char name[50];
    int percentage;
    int free;
}City;

typedef struct priorityQueue{
    int quantity;
    City data[250];
}Queue;

/*--------------------------------------------------*/

//FUNCTIONS LIST

void delay( unsigned int mseconds );
int mainMenu();
Queue *createQueue();
void printStatement();

int insertQueue( Queue *queue );
int removeQueue( Queue *queue );
int search( Queue *queue );
int changeCity( Queue *queue );

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

                status != 1 ? printf("\nErro ao inserir item.") : printf("\nItem inserido com sucesso.");
                break;
            }
            //Remover item da fila
            case 2:{
                printf("\n--------------------------------------------------");
                printf("\n********** 2- REMOVER ITEM DA FILA");

                status = removeQueue( queue );

                status != 1 ? printf("\nErro ao remover item.") : printf("\nItem removido com sucesso.");
                break;
            }
            //Perquisar item na fila
            case 3:{
                printf("\n--------------------------------------------------");
                printf("\n********** 3- PESQUISAR ITEM NA FILA");

                status = search( queue );

                if( status != 1 ) printf("\nItem não encontrado.");
                break;
            }
            //Alterar porcentagem do item na fila
            case 4:{
                printf("\n--------------------------------------------------");
                printf("\n********** 4- ALTERAR PORCENTAGEM DO ITEM");

                status = changeCity( queue );

                status != 1 ? printf("\nErro ao alterar item.") : printf("\nItem alterado com sucesso.");
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
    printf("\n4- Alterar porcentagem do item na fila;");
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
    printf("\n********** EXERCÍCIO 06 **********");
    printf("\nEscreva um Algoritmo que utilize fila de prioridade, este algoritmo deve trabalhar as ondas tratadas pelo nosso estado para o covid19 (Vermelha, amarela, verde) onde cada item da fila será uma cidade, e a Fila ajudara nosso governo a prestar assistências as cidades de acordo com a necessidade. Vamos utiliza para fins pedagógicos um único indicador “Taxa de Ocupação de leitos UTI ”. Se a cidade tem 70% dos leitos livres está na onda verde, de 70% a 30% esta na onda amarela e se esta com menos de 30% está na onda vermelha.");
    printf("\na. Cada item da fila pode ter sua taxa de ocupação alterada e consequentemente ter sua ordem na fila modificada.");
    printf("\nb. Cada nodo da fila deve ter as seguintes informações nome da cidade, quantidade de leitos e quantidade leitos livres.");
    printf("\n");
}

int insertQueue( Queue *queue ){
    if( queue == NULL || queue == 250 )
        return 0;
    
    char name[30];
    int percentage;

    printf("Escreva o nome da cidade: ");
    setbuf(stdin, NULL);
    gets(name);

    printf("\nQual a porcentagem de leitos ocupados? ");
    scanf("%d", &percentage);

    int i = queue->quantity-1;
    while( i >= 0 && (queue->data[i].free >= 100 - percentage) ){
        queue->data[i+1] = queue->data[i];
        i--;
    }
    
    if( percentage > 70 )
        percentage = 3;
    else if( percentage <= 70 && percentage > 30 )
        percentage = 2;
    else if( percentage <= 30 )
        percentage = 1;

    i = queue->quantity-1;
    while( i >= 0 && (queue->data[i].percentage >= percentage) ){
        queue->data[i+ 1] = queue->data[i];
        i--;
    }

    strcpy( queue->data[i+1].name, name);
    queue->data[i+1].percentage = percentage;
    queue->quantity++;
    return 1;
}

int removeQueue( Queue *queue ){
    if( queue == NULL || queue->quantity == 0 )
        return 0;
    queue->quantity--;
    return 1;
}

int search( Queue *queue ){
    if( queue == NULL || queue->quantity == 0 )
        return 0;

    for( int i=0; i < 250; i++ ){
        if(queue->data[i-1].name == NULL)
            return 0;
        printf("%s encontrado!\n", queue->data[i-1].name);
    }
    return 1;
}

int changeCity( Queue *queue ){
    char city[50];

    printf("Escreva o nome da cidade: ");
    setbuf( stdin, NULL );
    gets( city );

    for( int i=0; i<250; i++){
        if( strcmp(city, queue->data[i-1].name)==0 ){
            int value;
            printf("Digite a porcentagem atual dos leitos ocupados: ");
            scanf("%d", &value);

            int i = queue->quantity-1;
            while( i >= 0 && (queue->data[i].free >= 100 - value) ){
                queue->data[i+1] = queue->data[i];
                i--;
            }

            if( value > 70 )
                value = 3;
            else if( value <= 70 && value > 30 )
                value = 2;
            else if( value <= 30 )
                value = 1;

            i = queue->quantity-1;
            while( i >= 0 && (queue->data[i].percentage >= value) ){
                queue->data[i+1] = queue->data[i];
                i--;
            }

            strcpy(queue->data[i+1].name, city);
            queue->data[i+1].percentage = value;
            queue->quantity++;
            return 1;
        }
    }
    return 0;
}

/*--------------------------------------------------*/
