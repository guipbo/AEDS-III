/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------*/
//TAD
typedef struct Graph{
    int qntVertex;
    int maxDegree;
    int **edges;
    int *degree;
    float** weight;
};

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
int mainMenu();
Graph *createGraph();

int insert( Graph* graph );
int remove( Graph* graph );
int searchDistance( float *dist, int *visit, int numVert );
void betterWay( Graph *graph, int ini, int *ant, float *dist );

/*--------------------------------------------------*/
//MAIN
int main(){

    int exit = 0;
    Graph *graph = createGraph();
    int status;

    while(exit != 1){
        status = 0;
        switch(mainMenu()){
            //Inserir no grafo
            case 1: {
                status = insert(graph);
                printf("Status: %d", status);
                status != 1 
                ? printf("\nErro ao inserir!")
                : printf("\nSucesso na insercao");
                break;
            }
            //Remover no grafo
            case 2: {
                status = remove(graph);
                printf("Status: %d", status);
                status != 1 
                ? printf("\nErro ao remover!")
                : printf("\nSucesso na remocao");
                break;
            }
            //busca
            case 3: {
            	int ant[100];
            	float dist[100];
            	betterWay(graph, 0, ant, dist);
				break;
			}            	
            //Sair
            case 0: {
                exit = 1;
                break;
            }
            //Opção inválida
            default:{
                printf("\nOpçãoo inválida! Tente novamente.");
                break;
            }
        }
    }

    free(graph);
    return 0;
}

/*--------------------------------------------------*/
//FUNÇÕES
int mainMenu(){
    int option = 0;
    printf("----- MENU -----\n"
        "DIGITE:\n"
        "1- Inserir no Graph;\n"
        "2- Remover no Graph;\n"
        "3- Verificar menor caminho\n"
        "0- Sair\n"
        "\n-----> ");
    scanf("\r%d", &option);
    return option;
}

Graph *createGraph(){
    
    Graph *graph = (Graph*)malloc(sizeof(Graph));

    if(graph != NULL){
        printf("----- CRIAR GRAFO -----");
        printf("\nDIGITE");
        printf("\n");

        printf("\nQuantidade de vertices: ");
        scanf("\r%d", &graph->qntVertex);
        printf("Grau maximo: ");
        scanf("\r%d", &graph->maxDegree);

        graph->degree = (int*)calloc(graph->qntVertex, sizeof(int));
        graph->edges = (int**)malloc(graph->qntVertex*sizeof(int));
        graph->weight = (float**)malloc(graph->qntVertex*sizeof(float*));
        for(int i=0; i < graph->qntVertex; i++)
                graph->weight[i] = (float*) malloc(graph->maxDegree*sizeof(float));

        for (int i = 0; i < graph->qntVertex; i++)
            graph->edges[i] = (int*)malloc(graph->maxDegree*sizeof(int));

        printf("\n");
    }
    return graph;
}

int insert(Graph* graph){
    if(graph == NULL)
        return 0;
    printf("----- INSERIR ARESTA -----");
    printf("\nDIGITE");
    printf("\n");

    int source;
    int destination;
    printf("\nOrigem: ");
    scanf("%d", &source);
    printf("Destino: ");
    scanf("%d", &destination);

    if(source < 0 || source >= graph->maxDegree)
        return 0;
    if(destination < 0 || destination >= graph->maxDegree)
        return 0;

    //Liga origem ao destino
    graph->edges[source][graph->degree[source]] = destination;
    graph->degree[source]++;
    //Liga destino � origem
    graph->edges[destination][graph->degree[destination]] = source;
    graph->degree[destination]++;

    return 1;
}

int remove(Graph* graph){
    if(graph == NULL)
        return 0;
    printf("----- REMOVER ARESTA -----");
    printf("\nDIGITE");
    printf("\n");

    int source;
    int destination;
    printf("\nOrigem: ");
    scanf("%d", &source);
    printf("Destino: ");
    scanf("%d", &destination);

    if(source < 0 || source >= graph->maxDegree)
        return 0;
    if(destination < 0 || destination >= graph->maxDegree)
        return 0;

    int i = 0;
    while(i < graph->degree[source] && graph->edges[source][i] != destination)
        i++;
    //N�o encontrado
    if(i == graph->degree[source])
        return 0;
    graph->degree[source]--;
    graph->edges[source][i] = graph->edges[source][graph->degree[source]];
   
    i = 0;
    while(i < graph->degree[destination] && graph->edges[destination][i] != source)
        i++;
    if(i == graph->degree[destination])
        return 0;
    graph->degree[destination]--;
    graph->edges[destination][i] = graph->edges[destination][graph->degree[destination]];

    return 1;
}

int searchDistance(float *dist, int *visit, int numVert){
	int i, menor = -1, prim = 1;
	
	for(i = 0; i < numVert; i++){
		if(dist[i] >= 0 && visit[i] == 0){
			if(prim){
				menor = i;
				prim = 0;
			}else{
				if(dist[menor] > dist[i])
					menor = i;
			}
		}
	}
	return menor;
}

void betterWay(Graph *graph, int ini, int *ant, float *dist){
	int i, cont, numVert, ind, *visit, x;
	cont = numVert = graph->qntVertex;
	visit = (int*) malloc(numVert*sizeof(int));
	for(i=0; i < numVert; i++){
		ant[i] = -1;
		dist[i] = -1;
		visit[i] = 0;
	}
	dist[ini] = 0;
	while(cont > 0){
		x = searchDistance(dist, visit, numVert);
		if(x == -1)
			break;
		visit[x] = 1;
		cont--;
		
		for(i=0; i < graph->degree[x]; i++){
			ind = graph->edges[x][i];
			if(dist[ind] < 0){
				dist[ind] = dist[x] + 1;
				ant[ind] = x;
			}else{
				if(dist[ind] > dist[x] + 1){
					dist[ind] = dist[x] +1;
					ant[ind] = x;
				}
			}
		}
	}
	free(visit);
}
