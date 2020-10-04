/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#define INDEX 5

/*--------------------------------------------------*/
//TAD
typedef struct page{;
	int numInsc;
	int numBrothers;
	struct page *next;
	struct page *fil;
}page;

typedef struct bTree{
	page *students;
	int numele;
}bTree;

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
void printStatement();
bTree *createTree();
void insert(int va, bTree *a);
void insertSt(page *at, page *st, page *in, bTree *a);
void reorder(page *at, bTree *a);

/*--------------------------------------------------*/
//MAIN
int main(){
	int exit = 0;
	bTree *a = createTree();
	printStatement();

	insert(1, a);
	insert(2, a);
	insert(3, a);
	insert(4, a);
	insert(5, a);
	insert(6, a);
	insert(7, a);
	insert(8, a);
	insert(9, a);
	insert(10, a);
	printf("Número de irmãos de %d = %d", a->students->numInsc, a->students->numBrothers);

	printf("\n\n");
	scanf("%d", &exit);
}

/*--------------------------------------------------*/
//FUNÇÕES
void printStatement(){
    printf("\n************************************************");
    printf("\n\n1. Escreva um algoritmo utilizando arvore b. Para a implementação da arvore b utilize a ordem 20. A estrutura que será utilizada terá como chave o número de inscrição do aluno, o conteúdo será o histórico (disciplinas, notas e faltas).");
    printf("\n\n************************************************\n\n");
}

bTree *createTree(){
	bTree *a = (bTree *) malloc(sizeof(bTree));
	a->numele = 0;
	a->students = NULL;

	return a;
}

void insert(int va, bTree *a){
	page *st = (page *) malloc(sizeof(page));
	st->next = NULL;
	st->fil = NULL;
	st->numBrothers = 0;
	st->numInsc = va;
	if(a->students == NULL){
		a->students = st;
	}else{
		page *aux = a->students;
		insertSt(aux, st, aux, a);
	}
}

void insertSt(page *at, page *st, page *in, bTree *a){
	if(at != NULL){
		if(at->numInsc > st->numInsc){
			if(at->fil == NULL){
				at->fil = st;
			}else{
				insertSt(at->fil, st, at->fil, a);
			}
		}else{
			++at->numBrothers;
			st->numBrothers = at->numBrothers;
			if(at->next == NULL){
				at->next = st;
				if(at->numBrothers == INDEX - 1){
					reorder(in, a);
				}
			}else{
				insertSt(at->next, st, in, a);
			}
		}
	}
}

void reorder(page *at, bTree *a){
	page *aux = at, *auxin = at, *aux2, *auxreset = at;
	while(auxreset->next != NULL){
		auxreset->numBrothers = (INDEX / 2);
		auxreset = auxreset->next;
	}
	auxreset->numBrothers = (INDEX / 2);
	if(at->fil == NULL){	
		for(int x = 0; x < (INDEX / 2) - 1; ++x){
			aux = aux->next;
		}
		aux2 = aux->next;
		aux->next = NULL;
		aux2->fil = aux;
		at = aux2;
		at->fil = auxin;
		if(a->students->numInsc == at->fil->numInsc){
			a->students = at;
		}
	}
}
