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
int array[100];
int test, o = 0;
void searchDepth( Graph* graph, int initial, int* visited, int counter );
void searchDepth_Graph( Graph* graph, int initial, int* visited );
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
                int source, destination;
                int visited[100];
                printf("\n----- Busca de Profundidade -----");
                printf("\nDIGITE");
                printf("\n");
                printf("\nOrigem: ");
                scanf("%d", &source);
                printf("\nDestino: ");
                scanf("%d", &destination);

                searchDepth_Graph( graph, 0, visited );

                test = 0;
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
    printf("\n\n4. Escreva o algoritmo implementando grafos em que o usuário poderá informar n vértices e suas arestas. Implemente a busca em profundidade para buscar a saída de um labirinto caso exista. Para realizar a busca o usuário irá passar o vértice inicial e qual é o vértice de saída do labirinto.");
    printf("\n\n************************************************\n\n");
}

int menu(){
    int option = 0;

    printf("\n ----- MENU -----"
            "\nDigite a opção desejada: "
            "\n1- Inserir no grafo;"
            "\n2- Remover no grafo;"
            "\n3- Buscar por profundidade;"
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

int removeEdge( Graph* graph ){
    if( graph == NULL )
        return 0;
    printf("\n----- REMOVER ARESTA -----");
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

    int i = 0;
    while( i < graph->degree[source] && graph->edges[source][i] != destination )
        i++;
    //Não encontrado
    if( i == graph->degree[source] )
        return 0;
    graph->degree[source]--;
    graph->edges[source][i] = graph->edges[source][graph->degree[source]];
   
    i = 0;
    while( i < graph->degree[destination] && graph->edges[destination][i] != source )
        i++;
    if( i == graph->degree[destination] )
        return 0;
    graph->degree[destination]--;
    graph->edges[destination][i] = graph->edges[destination][graph->degree[destination]];

    return 1;
}

void searchDepth( Graph* graph, int initial, int* visited, int counter ){
    visited[initial] = counter;
    for( int i = 0; i < graph->degree[initial]; i++ ){
        printf("Visitado: %d", graph->edges[initial][i]);
        if( !visited[graph->edges[initial][i]])
            searchDepth(graph, graph->edges[initial][i], visited, counter+1);
    }
}

void searchDepth_Graph( Graph* graph, int initial, int* visited ){
    for( int i = 0; i < graph->qntVertex; i++ )
        visited[i] = 0;
    searchDepth(graph, initial, visited, 1);
}
