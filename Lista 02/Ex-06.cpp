/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX 100000

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
graph* createGraph( int noVertex, int maxDegree, int isWeighted );
void freeGraph( graph* _graph );
void printStatement();
int menu();
void delay( unsigned int mseconds );

int insertEdge( graph* _graph, int start, int destination, int isDigraph, float weight );
void insert( int *vertex, int *edge, int n, float *weight );
int removeEdge( graph* _graph, int orig, int destination, int isDigraph );
int searchBetterWay( float *dist, int *visited, int noVertex );
void betterWay( graph *_graph, int start, int *ant, float *dist );
void printfBetterWay( graph* _graph, int n );
void printGraph( graph *_graph );

/*--------------------------------------------------*/
//MAIN
int main(){
	int exit = 0;
    float weight=0;
	int isDigraph = 1, n, vertex, edge;
	

	printf("Digite o total de vertices: ");
	scanf("%d",&n);
	
	Graph* _graph = createGraph(n, n, 1);
	
	int vis[100];
	int i, ant[100];
    float dist[100];
	
    while( exit != 1 ){
        printStatement();
        fflush(stdin);   
    	switch(menu()){
    		case 1:{
    			insert(&vertex, &edge, n, &weight);
                insertEdge(_graph, vertex, edge, isDigraph, weight);
                break;
            }
            case 2:{
            	printf("\nGrafo: \n");
                printGraph(_graph);
                printf("\n");
                system("PAUSE");
                break;
            }
            case 3:{
            	printf("\nMenor caminho: \n");
            	ant[n];
    			dist[n];
                betterWay(_graph, 0, ant, dist);
                printf("\nTabela:\n\n");
                printf("Distancia: \n");
			    for(i=0; i<5; i++)
			       printf(" %d:   %d ->    %f\n",i,ant[i],dist[i]);
				
				printfBetterWay(_graph,n);
				printf("\n");
                system("PAUSE");
                break;
            }
            case 0:{
            	exit = true;
                break;
            }
            default :
                exit = false;
                break;
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
    printf("\n\n6. Escreva o algoritmo implementando grafos em que o usuário poderá informar n vértices e suas arestas. Implemente a busca de menor caminho para encontrar a menor distância entre dois vértices. Obs: o grafo deve trabalhar com Pesos positivos para as arestas.");
    printf("\n\n************************************************\n\n");
}

int menu(){
    int option = 0;

    printf("\n ----- MENU -----"
            "\nDigite a opção desejada: "
            "\n1 - Inserir no grafo"
            "\n2 - Imprimir o grafo"
            "\n3 - Buscar Menor Caminho"
            "\n0 - Sair."
            "\n\n-----> ");
    printf("\nOpcao: ");
    scanf("\r%d", &option);

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

int insertEdge(graph* _graph, int start, int destination, int isDigraph, float weight){
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

    if(isDigraph == 0)
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

int removeEdge(graph* _graph, int start, int destination, int isDigraph){
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
    if(isDigraph == 0)
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

int searchBetterWay(float *dist, int *visited, int noVertex){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < noVertex; i++){
        if(dist[i] >= 0 && visited[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void betterWay(graph *_graph, int start, int *ant, float *dist){
    int i, cont, noVertex, ind, *visited, vert;
    cont = noVertex = _graph->noVertex;
    visited = (int*) malloc(noVertex * sizeof(int));
    for(i=0; i < noVertex; i++){
        ant[i] = -1;
        dist[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;
    while(cont > 0){
        vert = searchBetterWay(dist, visited, noVertex);
        if(vert == -1)
            break;

        visited[vert] = 1;
        cont--;
        for(i=0; i<_graph->degree[vert]; i++){
            ind = _graph->edges[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + _graph->weight[vert][i];//weight da edge
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert]+1){
                   dist[ind] = dist[vert] + _graph->weight[vert][i];//weight da edge
                    ant[ind] = vert;
                }
            }
        }
    }
	 
    free(visited);
}

void printfBetterWay(graph* _graph,int n){
	int start, destination, pai;
	do{
		printf("\nInicio: ");
		scanf("%d", &start);
	}while(start<0 || start >=n);
	
	do{
		printf("Destino: ");
		scanf("%d", &destination);	
	}while(destination>=n || destination <0);
	

	int vetor1[_graph->noVertex];
	float vetor2[_graph->noVertex];
	betterWay(_graph, start, vetor1, vetor2);

	if(vetor2[destination]!= MAX){
		printf("\nDistacia com weight: %f\n", vetor2[destination]);
		pai = destination;
		printf("\nPercorrido: \n\n");
		while(pai != start){
			printf("<- %d ", pai);
			pai = vetor1[pai];
		}
		printf("<- %d ", start);
	}else{
		printf("Caminho Imposs�vel\n");
	}
	printf("\n------------------------------\n\n");

}
