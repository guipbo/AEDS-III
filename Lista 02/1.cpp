#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INDICE 20

/*Escreva um algoritmo utilizando arvore b. Para a implementação da arvore b utilize a
ordem 20. A estrutura que será utilizada terá como chave o número de inscrição do
aluno, o conteúdo será o histórico (disciplinas, notas e faltas).
*/

//structs
typedef struct informacoes{
	int nota1;
	int nota2;
	int nota3;
	int numfaltas;
}info;
typedef struct pagina{;
	info *informa;
	int numinsc;
	int numirmaos;
	struct pagina *pai;
	struct pagina *prox;
	struct pagina *fil;
}pag;
typedef struct arvoreb{
	pag *alunos;
	int numele;
}arb;

//funcs
arb *criaarvore();
void insere(int va, arb *a);
pag *preenchimento();
void insereal(pag *at, pag *al, pag *in, arb *a);
void reorganiza(pag *at, arb *a);
void imprime(pag *n);
void preenche(pag *al);
void busca(pag *al, int va);

int main(){
	int insc, qqr;
	srand(time(NULL));
	arb *a = criaarvore();
	for(int x = 0; x < 100; ++x){
		insc = (rand() % 1000) + 1000;
		insere(insc, a);
	}
	printf("Alunos cadastrados: ");
	imprime(a->alunos);
	printf("\nDigite um numero de inscricao para encontrar: ");
	scanf("%d", &qqr);
	busca(a->alunos, qqr);
}

arb *criaarvore(){
	arb *a = (arb *) malloc(sizeof(arb));
	a->numele = 0;
	a->alunos = NULL;
}
void insere(int va, arb *a){
	pag *al = (pag *) malloc(sizeof(pag));
	al->prox = NULL;
	al->fil = NULL;
	al->pai = NULL;
	al->numirmaos = 0;
	al->numinsc = va;
	preenche(al);
	if(a->alunos == NULL){
		a->alunos = al;
	}else{
		pag *aux = a->alunos;
		insereal(aux, al, aux, a);
	}
}
void insereal(pag *at, pag *al, pag *in, arb *a){
	if(at != NULL){
		if(at->numinsc > al->numinsc){
			if(at->fil == NULL){
				al->pai = at;
				at->fil = al;
			}else{
				insereal(at->fil, al, at->fil, a);
			}
		}else{
			++at->numirmaos;
			al->numirmaos = at->numirmaos;
			if(at->prox == NULL){
				if(at->numirmaos == INDICE - 1){
					printf("Algo compilou errado por favor tentar novamente\n");
					reorganiza(in, a);
				}
				at->prox = al;
			}else{
				insereal(at->prox, al, in, a);
			}
		}
	}
}
void reorganiza(pag *at, arb *a){									//divide no meio e coloca o primeiro como o filho
	pag *inicial = at, *aux = at;
	while(aux->prox->prox != NULL){
		aux = aux->prox; 
	}
	inicial->pai->fil = aux->prox;
	aux->prox->fil = inicial;
	inicial->pai = aux->prox;
	aux->prox = NULL;
}
void imprime(pag *n){
	printf("[%d]  ", n->numinsc, n->informa->nota1, n->informa->nota2, n->informa->nota3, n->informa->numfaltas);
	if(n->fil != NULL){
		imprime(n->fil);
	}
	if(n->prox != NULL){
		imprime(n->prox);
	}
}
void preenche(pag *al){
	info *i = (info *) malloc(sizeof(info));
	i->nota1 = rand() % 10 + 1;
	i->nota2 = rand() % 10 + 1;
	i->nota3 = rand() % 10 + 1;
	i->numfaltas = rand() % 30;
	al->informa = i;
}
void busca(pag *al, int va){
	if(al->numinsc == va){
		printf("O aluno de numero de inscricao [%d] tem nota %d em matematica, %d em portugues e %d em ciencias\nNumero de faltas: %d\n\n", al->numinsc, al->informa->nota1, al->informa->nota2, al->informa->nota3, al->informa->numfaltas);
		return;
	}else if(va < al->numinsc && al->fil != NULL){
		busca(al->fil, va);
	}else if(va > al->numinsc && al->prox != NULL){
		busca(al->prox, va);
	}
}
