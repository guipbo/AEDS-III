
/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*--------------------------------------------------*/
//TAD
typedef struct caractere{
	char caracter[MAX];
	struct caractere *ant;
	struct caractere *prox;
}car;
typedef struct lista{
	car *raiz;
	int numele;
}li;

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
li *crialista();
void inserec(li *l, char *va, int tam);
void check(char va, car *l);

/*--------------------------------------------------*/
//MAIN
int main(){
	char cara, *nome;
	nome = (char *) malloc(sizeof(char) * strlen("divinopolis"));
	li *l = (li *) malloc(sizeof(li));
	nome = "divinopolis";
	inserec(l, nome , strlen("divinopolis"));
	nome = "igreja";
	inserec(l, nome , strlen("igreja"));
	nome = "parque";
	inserec(l, nome , strlen("parque"));
	nome = "circo";
	inserec(l, nome , strlen("circo"));
	nome = "praca";
	inserec(l, nome , strlen("praca"));
	nome = "show";
	inserec(l, nome , strlen("show"));
	nome = "shopping";
	inserec(l, nome , strlen("shopping"));
	nome = "rua famosa";
	inserec(l, nome , strlen("rua famosa"));
	
	printf("Digite um caractere para encontrar em %s buscar: ", l->raiz->caracter);
	scanf("%c", &cara);
	check(cara, l->raiz);

	int exit = 0;
	scanf("%d", &exit);
}

/*--------------------------------------------------*/
//FUNÇÕES
li *crialista(){
	li *l = (li *) malloc(sizeof(li));
	l->numele = 0;
	return l;
}

void inserec(li *l, char *va, int tam){
	car *c = (car *) malloc(sizeof(car));
	c->ant = NULL;
	c->prox = NULL;
	strcpy(c->caracter, va);
	if(l->raiz == NULL){
		l->raiz = c;
	}else{
		car *aux = l->raiz;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = c;
		c->ant = aux;
	}
}

void check(char va, car *l){
	int x = 0;
	car *aux = l;
	while(aux->caracter[x] != '\0'){
		if(aux->caracter[x] == va){
			printf("%s encontrado\n", aux->caracter);
			break;
		}else{
			++x;
		}
	}
	if(aux->prox != NULL){
		check(va, l->prox);
	}
}
