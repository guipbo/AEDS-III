/*--------------------------------------------------*/
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INDICE 20

/*--------------------------------------------------*/
//TAD
typedef struct info{
	int grade1;
	int grade2;
	int grade3;
	int miss;
};

typedef struct page{;
	info *information;
	int noRegistration;
	int noBrothers;
	struct page *father;
	struct page *next;
	struct page *son;
};

typedef struct bTree{
	page *student;
	int numele;
};

/*--------------------------------------------------*/
//INICIALIZAÇÃO FUNÇÕES
bTree *createTree();
void insert( int va, bTree *tree );
void insertStudent( page *at, page *student, page *in, bTree *tree );
void reorder( page *at, bTree *tree );
void print( page *n );
void fill( page *student );
int search( page *student, int va );

/*--------------------------------------------------*/
//MAIN
int main(){

	int status = 0;
	int exit = 0;
	int registration, qqr;
	srand(time(NULL));
	bTree *tree = createTree();

	for(int x = 0; x < 100; ++x){
		registration = (rand() % 1000) + 1000;
		insert(registration, tree);
	}

	printf("Alunos cadastrados: ");
	print(tree->student);
	printf("\nDigite um número de inscrição para encontrar: ");
	scanf("%d", &qqr);
	status = search(tree->student, qqr);

	status != 1 
		? printf("\nInscrição não encontrada!")
		: printf("\nInscrição encontrada");

	printf("\n");
	scanf("%d", &exit);
}
/*--------------------------------------------------*/
//FUNÇÕES
bTree *createTree(){
	bTree *tree = (bTree *) malloc(sizeof(bTree));
	tree->numele = 0;
	tree->student = NULL;
}

void insert(int va, bTree *tree){
	page *student = (page *) malloc(sizeof(page));
	student->next = NULL;
	student->son = NULL;
	student->father = NULL;
	student->noBrothers = 0;
	student->noRegistration = va;
	fill(student);
	if(tree->student == NULL){
		tree->student = student;
	}else{
		page *aux = tree->student;
		insertStudent(aux, student, aux, tree);
	}
}

void insertStudent(page *at, page *student, page *in, bTree *tree){
	if(at != NULL){
		if(at->noRegistration > student->noRegistration){
			if(at->son == NULL){
				student->father = at;
				at->son = student;
			}else{
				insertStudent(at->son, student, at->son, tree);
			}
		}else{
			++at->noBrothers;
			student->noBrothers = at->noBrothers;
			if(at->next == NULL){
				if(at->noBrothers == INDICE - 1){
					printf("Algo compilou errado por favor tentar novamente\n");
					reorder(in, tree);
				}
				at->next = student;
			}else{
				insertStudent(at->next, student, in, tree);
			}
		}
	}
}

void reorder(page *at, bTree *tree){
	page *inicial = at, *aux = at;
	while(aux->next->next != NULL){
		aux = aux->next; 
	}
	inicial->father->son = aux->next;
	aux->next->son = inicial;
	inicial->father = aux->next;
	aux->next = NULL;
}

void print(page *n){
	printf("[%d]  ", n->noRegistration, n->information->grade1, n->information->grade2, n->information->grade3, n->information->miss);
	if(n->son != NULL){
		print(n->son);
	}
	if(n->next != NULL){
		print(n->next);
	}
}

void fill(page *student){
	info *i = (info *) malloc(sizeof(info));
	i->grade1 = rand() % 10 + 1;
	i->grade2 = rand() % 10 + 1;
	i->grade3 = rand() % 10 + 1;
	i->miss = rand() % 30;
	student->information = i;
}

int search(page *student, int va){
	if(student->noRegistration == va){
		printf("O aluno de numero de inscricao [%d] tem nota %d em matematica, %d em portugues e %d em ciencias\nNumero de faltas: %d\n\n", student->noRegistration, student->information->grade1, student->information->grade2, student->information->grade3, student->information->miss);
		return 1;
	}else if(va < student->noRegistration && student->son != NULL){
		search(student->son, va);
	}else if(va > student->noRegistration && student->next != NULL){
		search(student->next, va);
	}
}
