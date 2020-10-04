/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*--------------------------------------------------*/
//TAD
typedef struct Graph {
    int qntVertex;
    int maxDegree;
    int **edges;
    int *degree;
}Graph;

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
void delay( unsigned int mseconds );
void printStatement();
int menu();
Graph *createGraph();

int insertEdge( Graph* graph );
int removeEdge( Graph* graph );
/*--------------------------------------------------*/
//MAIN

int main(){

    int exit = 0;
    Graph *graph = createGraph();
    int status;

    while( exit != 1 ){
        printStatement();
        status = 0;
        switch( menu() ){
            //Inserir no grafo
            case 1: {
                status = insertEdge( graph );
                printf("Status: %d", status);
                status != 1 
                ? printf("\nErro ao inserir!")
                : printf("\nSucesso na inserção");
                break;
            }
            //Remover no grafo
            case 2: {
                status = removeEdge( graph );
                printf("Status: %d", status);
                status != 1 
                ? printf("\nErro ao remover!")
                : printf("\nSucesso na remoção");
                break;
            }
            //Busca de profundidade
            case 3: {
                
                break;
            }
            //Sair
            case 0: {
                exit = 1;
                break;
            }
            //Opção inválida
            default:{
                printf("\nOpção inválida! Tente novamente.");
                break;
            }
        }
    }

    free( graph );
    printf("\n--------------------\n");
    printf("Obrigado por utilizar o programa!");
    printf("\n--------------------\n");
    delay(3000);
    return 0;
}
/*--------------------------------------------------*/
//FUNÇÕES

void delay( unsigned int mseconds ){
    clock_t goal = mseconds + clock();
    while(goal>clock());
}

void printStatement(){
    printf("\n************************************************");
    printf("\n\n5. Escreva o algoritmo implementando grafos em que o usuário poderá informar n vértices e suas arestas. Implemente a busca por largura para encontrar a menor distância entre dois vértices. Obs: o grafo não deve trabalhar com Pesos.");
    printf("\n\n************************************************\n\n");
}

int menu(){
    int option = 0;

    printf("\n ----- MENU -----"
            "\nDigite a opção desejada: "
            "\n1- Inserir no grafo;"
            "\n2- Remover no grafo;"
            "\n3- Buscar por largura;"
            "\n0- Sair"
            "\n\n-----> ");
    scanf("\r%d", &option);
    

    return option;
}

Graph *createGraph(){
    
    Graph *graph = ( Graph* )malloc( sizeof( Graph ) );

    if( graph != NULL ){
        printf("\n----- CRIAR GRAFO -----");
        printf("\nDIGITE");
        printf("\n");

        printf("\nQuantidade de vértices: ");
        scanf("\r%d", &graph->qntVertex);
        printf("Grau máximo: ");
        scanf("\r%d", &graph->maxDegree);

        graph->degree = ( int* )calloc( graph->qntVertex, sizeof( int ) );
        graph->edges = ( int** )malloc( graph->qntVertex*sizeof( int ) );

        for ( int i = 0; i < graph->qntVertex; i++ )
            graph->edges[i] = ( int* )malloc( graph->maxDegree*sizeof( int ) );

        printf("\n");
    }
    return graph;
}

int insertEdge( Graph* graph ){
    if( graph == NULL )
        return 0;
    printf("\n----- INSERIR ARESTA -----");
    printf("\nDIGITE");
    printf("\n");

    int source;
    int destination;
    printf("\nOrigem: ");
    scanf("%d", &source);
    printf("Destino: ");
    scanf("%d", &destination);

    if( source < 0 || source >= graph->maxDegree )
        return 0;
    if( destination < 0 || destination >= graph->maxDegree )
        return 0;

    //Liga origem ao destino
    graph->edges[source][graph->degree[source]] = destination;
    graph->degree[source]+=1;
    //Liga destino à origem
    graph->edges[destination][graph->degree[destination]] = source;
    graph->degree[destination]+=1;

    return 1;
}
