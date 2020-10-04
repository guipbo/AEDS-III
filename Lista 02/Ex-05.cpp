/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#define MAX 999999

/*--------------------------------------------------*/
//TAD
typedef struct graph Graph;
struct graph{
    int isWeighted;
    int noVertex;
    int maxDegree;
    int** edges;
    float** weight;
    int* degree;
};

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
void delay( unsigned int mseconds );
void printStatement();
int menu();

graph* createGraph(int noVertex, int maxDegree, int isWeighted);
void freeGraph(graph* _graph);
int insertEdge(graph* _graph, int start, int destination, int sDigraph, float weight);
void insert(int *vertex, int *edge, int n, float *weight);
int removeEdge(graph* gr, int orig, int destination, int sDigraph);

void printGraph(graph *_graph);
void widthSearch(graph *_graph, int start, int *visit);

/*--------------------------------------------------*/
//MAIN
int main(){
	int exit = 0;
    int opcao = 0, vertini=0, vertsai=0;
    float weight=0;
	int sDigraph = 1, n, vertex, edge;
	

	printf("Digite o total de vertices: ");
	scanf("%d",&n);
	
	Graph* _graph = NULL;
	
	int vis[100];
	int i, ant[100];
    float dist[100];
	
    while( exit != 1 ){
        printStatement();
        if( _graph == NULL )
            _graph = createGraph(n, n, 1);
        fflush(stdin);   
        switch( menu() ){
            //Inserir no grafo
            case 1: {
                insert(&vertex, &edge, n, &weight);
                insertEdge(_graph, vertex, edge, sDigraph, weight);
                break;
            }
            //Remover no grafo
            case 2: {
                printf("\nGrafo: \n");
                printGraph(_graph);
                printf("\n");
                system("PAUSE");
                break;
            }
            //Busca de largura
            case 3: {
                printf("\nLarguras: \n");
                ant[n];
                dist[n];
                widthSearch(_graph, i, ant);
                printf("\n");
                system("PAUSE");
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

    free( _graph );
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
        "\nDigite a opção desejada:"
        "\n1 - Inserir no grafo;"
        "\n2 - Imprimir o grafo;"
        "\n3 - Buscar por largura;"
        "\n0 - Sair.;"
        "\n\n-----> ");
    scanf("%d", &option);
    return option;
}

graph* createGraph(int noVertex, int maxDegree, int isWeighted){
    Graph *_graph;
    _graph = (graph*) malloc(sizeof(struct graph));
    if(_graph != NULL){
        int i;
        _graph->noVertex = noVertex;
        _graph->maxDegree = maxDegree;
        _graph->isWeighted = (isWeighted != 0)?1:0;
        _graph->degree = (int*) calloc(noVertex,sizeof(int));

        _graph->edges = (int**) malloc(noVertex * sizeof(int*));
        for(i=0; i<noVertex; i++)
            _graph->edges[i] = (int*) malloc(maxDegree * sizeof(int));

        if(_graph->isWeighted){
            _graph->weight = (float**) malloc(noVertex * sizeof(float*));
            for(i=0; i<noVertex; i++)
                _graph->weight[i] = (float*) malloc(maxDegree * sizeof(float));
        }

    }
    return _graph;
}

void freeGraph(graph* _graph){
    if(_graph != NULL){
        int i;
        for(i=0; i<_graph->noVertex; i++)
            free(_graph->edges[i]);
        free(_graph->edges);

        if(_graph->isWeighted){
            for(i=0; i<_graph->noVertex; i++)
                free(_graph->weight[i]);
            free(_graph->weight);
        }
        free(_graph->degree);
        free(_graph);
    }
}

int insertEdge(graph* _graph, int start, int destination, int sDigraph, float weight){
    if(_graph == NULL)
        return 0;
    if(start < 0 || start >= _graph->noVertex)
        return 0;
    if(destination < 0 || destination >= _graph->noVertex)
        return 0;

    _graph->edges[start][_graph->degree[start]] = destination;
    if(_graph->isWeighted)
        _graph->weight[start][_graph->degree[start]] = weight;
    _graph->degree[start]++;

    if(sDigraph == 0)
        insertEdge(_graph, destination, start, 1, weight);
    return 1;
}

void insert(int *vertex, int *edge, int n, float *weight){
		
		int vert=0,ares=0;
		float _weight=0;
		
		do{
			printf("\nVertice inicial: ");
    		scanf("%d",&vert);
		}while( vert<0 || vert>=n);
		
		*vertex = vert;
		do{
			printf("Vertice final: ");
    		scanf("%d",&ares);
		}while( ares<0 || ares>=n);
    	
    	*edge = ares;
    	do{
			printf("Peso: ");
    		scanf("%f",&weight);
		}while( weight<0);
    	
    	*weight= _weight;
}

int removeEdge(graph* _graph, int start, int destination, int sDigraph){
    if(_graph == NULL)
        return 0;
    if(start < 0 || start >= _graph->noVertex)
        return 0;
    if(destination < 0 || destination >= _graph->noVertex)
        return 0;

    int i = 0;
    while(i<_graph->degree[start] && _graph->edges[start][i] != destination)
        i++;
    if(i == _graph->degree[start])//elemento nao encontrado
        return 0;
    _graph->degree[start]--;
    _graph->edges[start][i] = _graph->edges[start][_graph->degree[start]];
    if(_graph->isWeighted)
        _graph->weight[start][i] = _graph->weight[start][_graph->degree[start]];
    if(sDigraph == 0)
        removeEdge(_graph, destination, start, 1);
    return 1;
}

void printGraph(graph *_graph){
    if(_graph == NULL)
        return;
    int i, j;
    for(i=0; i < _graph->noVertex; i++){
        printf("%d: ", i);
        for(j=0; j < _graph->degree[i]; j++){
            if(_graph->isWeighted)
                printf("%d, ", _graph->edges[i][j], _graph->weight[i][j]);
            else
                printf("%d, ", _graph->edges[i][j]);
        }
        printf("\n");
    }
}

void widthSearch(graph *_graph, int start, int *visit){
    int i, vert, noVertex, cont = 1;
    int *fila, IF = 0, FF = 0;
    for(i=0; i<_graph->noVertex; i++)
        visit[i] = 0;

    noVertex = _graph->noVertex;
    fila = (int*) malloc(noVertex * sizeof(int));
    FF++;
    fila[FF] = start;
    visit[start] = cont;
    while(IF != FF){
        IF = (IF + 1) % noVertex;
        vert = fila[IF];
        cont++;
        for(i=0; i<_graph->degree[vert]; i++){
            if(!visit[_graph->edges[vert][i]]){
                FF = (FF + 1) % noVertex;
                fila[FF] = _graph->edges[vert][i];
                visit[_graph->edges[vert][i]] = cont;
            }
        }
    }
    free(fila);
    for(i=0; i < _graph->noVertex; i++)
        printf("%d -> %d\n",i,visit[i]);
}
