#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>
#define MAX 100000


/*-----------------------------------------Structs-----------------------------------------*/
typedef struct graph Grafo;
struct graph{
    int ehponderado;
    int numVert;
    int maxGrau;
    int** arestas;
    float** pesos;
    int* grau;
};


/*-----------------------------------------Funcoes-----------------------------------------*/
graph* criaGrafo(int numVert, int maxGrau, int ponderado);
void liberaGrafo(graph* grafo);
int insereAresta(graph* grafo, int ini, int dest, int ehdigrafo, float peso);
void insere(int *vertice, int *aresta, int n, float *peso);
int removeAresta(graph* gr, int orig, int dest, int ehdigrafo);
int procuraMenorDist(float *dist, int *visit, int numVert);
void menorCaminhoGrafo(graph *grafo, int ini, int *ant, float *dist);
void mostraMenorCaminho(graph* grafo,int n);
void imprimeGrafo(graph *grafo);


/*-----------------------------------------Main-----------------------------------------*/
int main(){
	bool sair = false;
    int opcao = 0, vertini=0, vertsai=0;
    float peso=0;
	int ehdigrafo = 1, n, vertice, aresta;
	

	printf("Digite o total de vertices: ");
	scanf("%d",&n);
	
	Grafo* grafo = criaGrafo(n, n, 1);
	
	int vis[vertsai];
	int i, ant[n];
    float dist[n];
	
	//Menu
	do{
    	system("cls");
        printf("1 - Inserir no grafo\n"
        "2 - Imprimir o grafo\n"
        "3 - Buscar Menor Caminho\n"
        "4 - sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        fflush(stdin);   
    	
    	switch(opcao){
    		
    		case 1:
    			insere(&vertice, &aresta, n, &peso);
                insereAresta(grafo, vertice, aresta, ehdigrafo, peso);
                break;
                
                
            case 2:
            	printf("\nGrafo: \n");
                imprimeGrafo(grafo);
                printf("\n");
                system("PAUSE");
                break;
                
                
            case 3:
            	printf("\nMenor caminho: \n");
            	ant[n];
    			dist[n];
                menorCaminhoGrafo(grafo, 0, ant, dist);
                printf("\nTabela:\n\n");
                printf("Distancia: \n");
			    for(i=0; i<5; i++)
			       printf(" %d:   %d ->    %f\n",i,ant[i],dist[i]);
				
				mostraMenorCaminho(grafo,n);
				printf("\n");
                system("PAUSE");
                break;
                
                
            case 4:
            	sair = true;
                break;
            default :
                sair = false;
                break;
		}
    	
	}while(sair == false);
	 liberaGrafo(grafo);
	
	return 0;
}


/*-----------------------------------------Funcoes-----------------------------------------*/
graph* criaGrafo(int numVert, int maxGrau, int ponderado){
    Grafo *grafo;
    grafo = (graph*) malloc(sizeof(struct graph));
    if(grafo != NULL){
        int i;
        grafo->numVert = numVert;
        grafo->maxGrau = maxGrau;
        grafo->ehponderado = (ponderado != 0)?1:0;
        grafo->grau = (int*) calloc(numVert,sizeof(int));

        grafo->arestas = (int**) malloc(numVert * sizeof(int*));
        for(i=0; i<numVert; i++)
            grafo->arestas[i] = (int*) malloc(maxGrau * sizeof(int));

        if(grafo->ehponderado){
            grafo->pesos = (float**) malloc(numVert * sizeof(float*));
            for(i=0; i<numVert; i++)
                grafo->pesos[i] = (float*) malloc(maxGrau * sizeof(float));
        }

    }
    return grafo;
}

void liberaGrafo(graph* grafo){
    if(grafo != NULL){
        int i;
        for(i=0; i<grafo->numVert; i++)
            free(grafo->arestas[i]);
        free(grafo->arestas);

        if(grafo->ehponderado){
            for(i=0; i<grafo->numVert; i++)
                free(grafo->pesos[i]);
            free(grafo->pesos);
        }
        free(grafo->grau);
        free(grafo);
    }
}

int insereAresta(graph* grafo, int ini, int dest, int ehdigrafo, float peso){
    if(grafo == NULL)
        return 0;
    if(ini < 0 || ini >= grafo->numVert)
        return 0;
    if(dest < 0 || dest >= grafo->numVert)
        return 0;

    grafo->arestas[ini][grafo->grau[ini]] = dest;
    if(grafo->ehponderado)
        grafo->pesos[ini][grafo->grau[ini]] = peso;
    grafo->grau[ini]++;

    if(ehdigrafo == 0)
        insereAresta(grafo, dest, ini, 1, peso);
    return 1;
}

void insere(int *vertice, int *aresta, int n, float *peso){
		
		int vert=0,ares=0;
		float pesos=0;
		
		do{
			printf("\nVertice inicial: ");
    		scanf("%d",&vert);
		}while( vert<0 || vert>=n);
		
		*vertice = vert;
		do{
			printf("Vertice final: ");
    		scanf("%d",&ares);
		}while( ares<0 || ares>=n);
    	
    	*aresta = ares;
    	do{
			printf("Peso: ");
    		scanf("%f",&pesos);
		}while( pesos<0);
    	
    	*peso= pesos;
}

int removeAresta(graph* grafo, int ini, int dest, int ehdigrafo){
    if(grafo == NULL)
        return 0;
    if(ini < 0 || ini >= grafo->numVert)
        return 0;
    if(dest < 0 || dest >= grafo->numVert)
        return 0;

    int i = 0;
    while(i<grafo->grau[ini] && grafo->arestas[ini][i] != dest)
        i++;
    if(i == grafo->grau[ini])//elemento nao encontrado
        return 0;
    grafo->grau[ini]--;
    grafo->arestas[ini][i] = grafo->arestas[ini][grafo->grau[ini]];
    if(grafo->ehponderado)
        grafo->pesos[ini][i] = grafo->pesos[ini][grafo->grau[ini]];
    if(ehdigrafo == 0)
        removeAresta(grafo, dest, ini, 1);
    return 1;
}

void imprimeGrafo(graph *grafo){
    if(grafo == NULL)
        return;
    int i, j;
    for(i=0; i < grafo->numVert; i++){
        printf("%d: ", i);
        for(j=0; j < grafo->grau[i]; j++){
            if(grafo->ehponderado)
                printf("%d, ", grafo->arestas[i][j], grafo->pesos[i][j]);
            else
                printf("%d, ", grafo->arestas[i][j]);
        }
        printf("\n");
    }
}

int procuraMenorDist(float *dist, int *visit, int numVert){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < numVert; i++){
        if(dist[i] >= 0 && visit[i] == 0){
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

void menorCaminhoGrafo(graph *grafo, int ini, int *ant, float *dist){
    int i, cont, numVert, ind, *visit, vert;
    cont = numVert = grafo->numVert;
    visit = (int*) malloc(numVert * sizeof(int));
    for(i=0; i < numVert; i++){
        ant[i] = -1;
        dist[i] = -1;
        visit[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0){
        vert = procuraMenorDist(dist, visit, numVert);
        if(vert == -1)
            break;

        visit[vert] = 1;
        cont--;
        for(i=0; i<grafo->grau[vert]; i++){
            ind = grafo->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + grafo->pesos[vert][i];//peso da aresta
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert]+1){
                   dist[ind] = dist[vert] + grafo->pesos[vert][i];//peso da aresta
                    ant[ind] = vert;
                }
            }
        }
    }
	 
    free(visit);
}

void mostraMenorCaminho(graph* grafo,int n){
	int ini, dest, pai;
	do{
		printf("\nInicio: ");
		scanf("%d", &ini);
	}while(ini<0 || ini >=n);
	
	do{
		printf("Destino: ");
		scanf("%d", &dest);	
	}while(dest>=n || dest <0);
	

	int vetor1[grafo->numVert];
	float vetor2[grafo->numVert];
	menorCaminhoGrafo(grafo, ini, vetor1, vetor2);

	if(vetor2[dest]!= MAX){
		printf("\nDistacia com peso: %f\n", vetor2[dest]);
		pai = dest;
		printf("\nPercorrido: \n\n");
		while(pai != ini){
			printf("<- %d ", pai);
			pai = vetor1[pai];
		}
		printf("<- %d ", ini);
	}else{
		printf("Caminho Impossível\n");
	}
	printf("\n------------------------------\n\n");

}
