/*
 * Projeto ArvoreAVL
 * File:   ArvoreAVL.c
 * Author: ProfGuiBraga
 * 
 */

/*--------------------------------------------------*/

//BIBLIOTECAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//FIM DO BLOCO BIBLIOTECAS

/*--------------------------------------------------*/

//TAD'S

//Tipo que define cada elemento da Arvore
typedef struct elemento {
    
    int valor;
    struct elemento *esq, *dir;
    
}Elemento;

//Tipo que define a Arvore como um todo
typedef struct arvore {
    
    Elemento *raiz;
    
}Arvore;

//FIM DO BLOCO TAD'S

/*--------------------------------------------------*/

//PREVIA DE FUNCOES

//ESTRUTURAIS
//Delay
void delay (unsigned int mseconds);
//Menu
int menu ();
//Cria a Arvore
Arvore *criarArvore();
//Auxiliares de remocao
Elemento *maiorEsquerda (Arvore *arv);
Elemento *menorDireita (Arvore *arv);
//Calcular Fator de Balanceamento
int fatorBalanceamento (Arvore *arv);
//Inicializa um novo Elemento
Elemento *novoElemento (int novoValor);
//Rotacao a  esquerda
void rotacaoEsquerda (Arvore *arv);
//Rotacao a  direita
void rotacaoDireita (Arvore *arv);
//Rotacao dupla a  direita
void rotacaoDuplaDireita (Arvore *arv);
//Rotacao dupla a  esquerda
void rotacaoDuplaEsquerda (Arvore *arv);
//Verifica se existe necessidade e balanceia
int balanceia (Arvore *arv);

//EXECUCOES
//Opcao 1: Imprime Pre-Ordem
void imprimePreOrdem (Arvore *arv);
//Opcao 2: Imprime In-Ordem
void imprimeInOrdem (Arvore *arv);
//Opcao 3: Imprime Pos-Ordem
void imprimePosOrdem (Arvore *arv);
//Opcao 4: Pesquisa por elemento
int pesquisaElemento (Arvore *arv, int valor);
//Opcao 5: Verifica a altura da Arvore
int altura (Arvore *arv);
//Opcao 6: Insere elemento na Arvore
int insereArvore (Arvore *arv, int valor);
//Opcao 7: Remove elemento da Arvore
int removeElemento (Arvore *arv, int valor);
//Opcao 8 : Insere uma quantidade especifica de elementos na Arvore
int insereAleatorios (Arvore *arv, int quantidade);
//Opcao 9: Insere uma Arvore em especifico
int insereArvoreEspecifica (Arvore *arv);
//Opcao 10: Remove elementos especificos da Arvore criada na Opcao 9
void removerEspecificos(Arvore *arv);
//Opcao 11: Calcular a soma de todas as chaves da Arvore
int somaTotal = 0;
int somaChaves (Arvore *arv);
//Opcao 12: Encontra o valor minimo da arvore
int minimoArvore (Arvore *arv);
//Opcao 13: Encontra o valor maximo da arvore
int maximoArvore (Arvore *arv);
//Opcao 14: Contar numero de nao folhas
int contagemNaoFolha = 0;
int contaNaoFolha (Arvore *arv);

//FIM DO BLOCO PREVIA DE FUNCOES

/*--------------------------------------------------*/

//MAIN

int main() {
    
    //Teclas de controle estrutural
    char finalExecucao;
    char loop = 's';
    int saida_final = 0;
    
    //Criacao da Arvore
    Arvore* arv = criarArvore();
    
    while (loop == 's' || loop == 'S'){
        
        //Execucao
        switch (menu()){
            
            //Opcao 1: Imprime Pre-Ordem
            case 1: {system("cls");
                
                printf("\nImprimir Arvore Pre-ordem"
                    "\n--------------------\n");
            
                //Saida
                printf("\nArvore: ");
                imprimePreOrdem(arv);
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 2: Imprime In-Ordem
            case 2: {system("cls");
                
                printf("\nImprimir Arvore In-ordem"
                    "\n--------------------\n");
            
                //Saida
                printf("\nArvore: ");
                imprimeInOrdem(arv);
                
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 3: Imprime Pos-Ordem
            case 3: {system("cls");
                
                printf("\nImprimir Arvore Pos-ordem"
                    "\n--------------------\n");
            
                //Saida
                printf("\nArvore: ");
                imprimePosOrdem(arv);
                
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 4: Pesquisa por elemento
            case 4: {system("cls");
                
                printf("\nPesquisar por elemento: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessarios
                int valorPesquisa;

                //Entrada
                printf("\nInsira o elemento que deseja pesquisar: ");
                scanf("%d", &valorPesquisa);

                //Execucao da funcao
                int resultado = pesquisaElemento(arv, valorPesquisa);

                //Saida
                if(resultado == 1){
                    printf("\nO elemento %d existe na Ã?rvore.", valorPesquisa);
                }
                    
                else{
                    printf("\nO elemento %d nÃ£o existe na Ã?rvore.", valorPesquisa);
                }
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 5: Verifica a altura da Arvore
            case 5: {system("cls");
                
                printf("\nVerificar altura da Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessarios
                int h;

                //Execucao da funcao
                h = altura(arv);

                //Saida
                if (h>=0){
                    printf("\nAltura da Arvore: %d", h);
                }
                else{
                    printf("\nA Arvore nao possui elementos.");                    
                }
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 6: Insere elemento na Arvore
            case 6: {system("cls");
                
                printf("\nInserir elemento na Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessarios
                int valorInserir;

                //Entrada
                printf("\nDigite o valor que deseja inserir na Arvore: ");
                scanf("%d", &valorInserir);

                //Execucao da funcao
                int resultado = insereArvore(arv, valorInserir);
                
                //Saida
                if (resultado == 1){
                    printf("\nElemento %d inserido com sucesso!", valorInserir);
                    
                }
                else{
                    printf("\nElemento %d nao foi inserido!", valorInserir);
                }


                printf("\n--------------------\n");
            break;}
            
            //Opcao 7: Remove elemento da Arvore
            case 7: {system("cls");
                
            printf("\nInserir valores aleatorios: "
                    "\n--------------------\n");
            
                //Inicializacao de parametros necessarios
                int quantAleatorios;
            
                printf("\nInserir valores aleatorios: \n"
                       "--------------------\n");

                printf("\nDigite a quantidade de valores " 
                        "\naleatorios deseja inserir (Maximo 100): "
                        );
                scanf("%d", &quantAleatorios); 
               
                //Execucao da funcao
                inserirAleatorios(arv, quantAleatorios);

                printf("\n--------------------\n");
            break;}
            
            //Opcao 8 : Insere uma quantidade especifica de elementos na Arvore
            case 8: {system("cls");
                
                printf("\nInserir Arvore especifica: \n"
                       "--------------------\n");
                
                printf("\nValores em ordem de insercao:\n"
                       "-----\n"
                       "-> 15;\n"
                       "-> 6;\n"
                       "-> 12;\n"
                       "-> 9;\n"
                       "-> 14;\n"
                       "-> 13;\n"
                       "-> 25;\n"
                       "-> 18;\n"
                       "-> 20;\n"
                       "-> 23;\n"
                       "-> 5;\n"
                       "-> 3;\n"
                       "-> 38;\n"
                       "-> 45;\n"
                       "-> 50;\n"
                       "-> 48;\n"
                       "-> 46;\n"
                       "-> 60.\n"
                       "-----\n"
                      );

                //Execucao da funcao
                inserirArvoreEspecifica(arv);
                
                printf("\n\nValores em Pre-ordem:\n");
                imprimePreOrdem(arv);

                printf("\n--------------------\n");
            break;}
            
            //Opcao 9: Insere uma Arvore em especifico
            case 9: {system("cls");
                
                printf("\nRemover elemento da Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessarios
                int valorRemover, execucao;

                //Entrada
                printf("\nDigite o valor que deseja remover na Arvore: ");
                scanf("%d", &valorRemover);

                //Execucao da funcao
                execucao = removerElemento(arv, valorRemover);

                //Saida
                if(execucao == 1){
                    printf("\nO valor %d foi removido com sucesso!", valorRemover);
                }
                else{
                    printf("\nValor nao foi removido!");
                }

                printf("\n--------------------\n");
            break;}
            
            //Opcao 10: Remove elementos especificos da Arvore criada na Opcao 9
            case 10: {system("cls");
                
                printf("\nRemover elementos especificos da Arvore especifica: \n"
                       "--------------------\n");

                printf("\nValores que serao removidos:\n"
                       "-----\n"
                       "-> 23;\n"
                       "-> 3;\n"
                       "-> 48;\n"
                       "-> 15;\n"
                       "-> 13.\n"
                       "-----\n"
                      );

                //Execucao da funcao
                removerEspecificos(arv);

                printf("\n--------------------\n");
            break;}
            
            //Opcao 11: Calcular a soma de todas as chaves da Arvore
            case 10:{system("cls");

                printf("\nCalcular a soma de todas as chaves da Arvore: \n"
                       "--------------------\n");
                
                int somaTotal2 = 0;
                
                //Execucao da funcao
                somaTotal2 = somaChaves(arv);

                //Saida
                printf("\nA soma totaliza: %d", somaTotal2);
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 12: Encontra o valor minimo da arvore
            case 11:{system("cls");

                printf("\nEncontra o valor minimo da arvore: \n"
                       "--------------------\n");
                
                int minimo = 0;
                
                //Execucao da funcao
                minimo = minimoArvore (arv);

                //Saida
                printf("\nMinimo da Arvore: %d", minimo);
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 13: Encontra o valor maximo da arvore
            case 12:{system("cls");

                printf("\nEncontra o valor maximo da arvore: \n"
                       "--------------------\n");
                
                int maximo = 0;
                
                //Execucao da funcao
                maximo = maximoArvore (arv);

                //Saida
                printf("\nMaximo da Arvore: %d", maximo);
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 14: Contar numero de nao folhas
            case 13:{system("cls");

                printf("\nContar numero de nao folhas: \n"
                       "--------------------\n");
                
                int contagem = 0;
                
                //Execucao da funcao
                contagem = contaNaoFolha (arv);

                //Saida
                printf("\nContagem de nao folha: %d", contagem);
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao 0: Sair 
            case 0: {system("cls");
                
                printf("\nSair"
                        "\n--------------------\n");

                //Inicializacao de parametros necessarios
                char sair;

                printf("Tem certeza que deseja sair?"
                        "\nDigite:"
                        "\n'S' para confirmar;"
                        "\nQualquer outra tecla para cancelar."
                        "\n-----> ");
                scanf("%s", &sair);
                
                if(sair == 's' || sair == 'S'){
                    loop = 'n';
                    saida_final = 1;
                }
                
                printf("\n--------------------\n");
            break;}
            
            //Opcao Inexistente 
            default: {system("cls");
                
                printf("\nOpcao Inexistente: "
                    "\n--------------------\n");
            
                printf("Opcao invalida!"
                        "Tente novamente.");
                
                printf("\n--------------------\n");
            break;}
    
        }
        
        //Finalizacao do loop
        if(saida_final == 0){
            printf("\nDigite uma tecla e enter para continuar: ");
            scanf("%s", &finalExecucao);                
        }
        //Saida
        else{
            printf("\n--------------------\n");
            printf("Obrigado por utilizar o programa!");
            printf("\n--------------------\n");
            delay(3000);
        }             
    }

    return 0;
}

//FIM DO BLOCO MAIN

/*--------------------------------------------------*/

//FUNCOES ESTRUTURAIS

//Cria Arvore
Arvore *criarArvore(){
    Arvore *arv;
    arv = (Arvore*)malloc(sizeof(Arvore));
    //Teste se o espaco foi alocado
    if(arv==NULL){
        return;
    }

    //Inicializa nulo
    arv->raiz = NULL;
    return arv;

}

//Delay
void delay (unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while(goal>clock());
}

//Menu
int menu (){
    
    int opcao = 0;
    
    system ("cls");
    printf("----------BEM VINDO----------\n"
            "Por gentileza, escolha uma opcao:\n"
            "1 - Imprimir Arvore Pre-ordem;\n"
            "2 - Imprimir Arvore In-ordem;\n"
            "3 - Imprimir Arvore Pos-ordem;\n"
            "4 - Pesquisar por elemento;\n"
            "5 - Verificar altura da Arvore;\n"
            "6 - Inserir elemento na Arvore;\n"
            "7 - Inserir valores aleatorios;\n"
            "8 - Inserir Arvore especifica;\n"
            "9 - Remover elemento da Arvore;\n"
            "10 - Remover elementos especificos da Arvore especifica;\n"
            "11 - Calcular a soma de todas as chaves da Arvore;\n"
            "12 - Encontra o valor minimo da arvore;\n"
            "13 - Encontra o valor maximo da arvore;\n"
            "14 - Contar numero de nao folhas;\n"
            "0 - Sair.\n"
            "-----> ");
    scanf("%d", &opcao);
    printf("\n--------------------\n");
    
    return opcao;
}

//Calculo de Fator de Balanceamento
int fatorBalanceamento (Arvore *arv){
    
    int FB = 0;
    
    //Arvore nao existe
    if (arv == NULL){
        return 0;
    }
    //Arvore vazia
    else if (arv->raiz == NULL){
        return -3;
    }
    //Arvore existe e nao esta vazia
    else {
        FB = altura(&(arv->raiz->dir)) - altura(&(arv->raiz->esq));
    }
    
    return FB;
}

//Alocacao de um novo elemento para insercao
Elemento *novoElemento (int novoValor){
    
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    
    novo->valor = novoValor;
    novo->dir = NULL;
    novo->esq = NULL;
    
    return novo;
}

//AUXILIARES DE REMOCAO
//Encontra o maior elemento na sub-Arvore da esquerda
Elemento* maiorEsquerda (Arvore* arv){
    Elemento* aux;
    
    //Enquanto nao for a folha mais baixa a  direita
    if ((arv->raiz->dir) != NULL){
        maiorEsquerda(&(arv->raiz->dir));
    }
    
    //Chegamos na folha mais baixa da direita
    else{
        aux = arv->raiz;
        //Se o auxiliar tiver filho
        if (arv->raiz->esq != NULL){
            arv->raiz = arv->raiz->esq;
        }
        //Se o auxiliar nao tiver filho
        else{
            arv->raiz = NULL;
        }
        
        return aux;  
    }
}
//Encontra o menor elemento na sub-Arvore da direita
Elemento* menorDireita (Arvore* arv){
    Elemento* aux;
    
    //Enquanto nao for a folha mais baixa a  direita
    if ((arv->raiz->esq) != NULL){
        menorDireita(&(arv->raiz->esq));
    }
    
    //Chegamos na folha mais baixa da direita
    else{
        aux = arv->raiz;
        //Se o auxiliar tiver filho
        if (arv->raiz->dir != NULL){
            arv->raiz = arv->raiz->dir;
        }
        //Se o auxiliar nao tiver filho
        else{
            arv->raiz = NULL;
        }
        
        return aux;  
    }
}

//ROTACOES
//Rotacao a esquerda
void rotacaoEsquerda (Arvore *arv){
    
    //arv->raiz desbalanceado
    Elemento *aux = arv->raiz;
    
    //Raiz se torna o filho a esquerda
    arv->raiz = aux->dir; 
    //A direita do desbalanceado se torna a esquerda da nova raiz
    aux->dir = arv->raiz->esq; 
    //Desbalanceado se torna a esquerda da nova raiz
    arv->raiz->esq = aux;
    
}
//Rotacao a direita
void rotacaoDireita (Arvore *arv){

    //arv->raiz desbalanceado
    Elemento *aux = arv->raiz;

    //Raiz se torna o filho a esquerda
    arv->raiz = aux->esq; 
    //A esquerda do desbalanceado se torna a direita da nova raiz
    aux->esq = arv->raiz->dir; 
    //Desbalanceado se torna a direita da nova raiz
    arv->raiz->dir = aux;

}
//Rotacao dupla a direita
void rotacaoDuplaDireita (Arvore *arv){
    
    //Primeira rotacao (a esquerda)
    rotacaoEsquerda(&(arv->raiz->esq));
    //Segunda rotacao (a direita)
    rotacaoDireita(arv);

}
//Rotacao dupla a esquerda
void rotacaoDuplaEsquerda (Arvore *arv){
    
    //Primeira rotacao (a direita)
    rotacaoDireita(&(arv->raiz->dir));
    //Segunda rotacao (a esquerda)
    rotacaoEsquerda(arv);

}
//Verifica se existe necessidade e balanceia
int balanceia (Arvore *arv){
    //Verifica se a Arvore existe
    if (arv == NULL){
        return;
    }

    else if (arv->raiz != NULL){
        
        balanceia(&(arv->raiz->esq));
        balanceia(&(arv->raiz->dir));
        
        //Verifica qual dos lados o balanceamento deve ser feito
        if (fatorBalanceamento(arv) <= -2 ){
            //Verifica se o balanceamento e simples ou duplo
            if(fatorBalanceamento(&(arv->raiz->esq)) == 1 ){
                rotacaoDuplaDireita(arv);             
            }
            else{
                rotacaoDireita(arv);   
            }
        }
        //Verifica qual dos lados o balanceamento deve ser feito
        else if (fatorBalanceamento(arv) >= 2 ){
            //Verifica se o balanceamento e simples ou duplo
            if(fatorBalanceamento(&(arv->raiz->dir)) == -1 ){
                rotacaoDuplaEsquerda(arv);                
            }
            else{
                rotacaoEsquerda(arv);
            }
                
        }
        if (fatorBalanceamento(arv) == 1 || fatorBalanceamento(arv) == -1){
            return 1;
        }
    }    
}

//FIM DO BLOCO FUNCOES ESTRUTURAIS

/*--------------------------------------------------*/

//FUNCOES

//Opcao 1: Imprime Pre-Ordem
void imprimePreOrdem (Arvore *arv){
    //Verifica se a Arvore existe
    if (arv == NULL){
        return;
    }

    else if (arv->raiz != NULL){
        printf("\nValor: %d", arv->raiz->valor);
        imprimePreOrdem(&(arv->raiz->esq));
        imprimePreOrdem(&(arv->raiz->dir));

    }

}

//Opcao 2: Imprime In-Ordem
void imprimeInOrdem (Arvore *arv){
    //Verifica se a Arvore existe
    if (arv == NULL){
        return;
    }

    else if (arv->raiz != NULL){
        //Anda pela Arvore ate achar o NULL mais a esquerda.
        //Quando encontra comeca a imprimir e andar:
        //Esquerda, raiz, direita
        imprimeInOrdem(&(arv->raiz->esq));
        printf("\nValor: %d", arv->raiz->valor);
        imprimeInOrdem(&(arv->raiz->dir));

    }

}

//Opcao 3: Imprime Pos-Ordem
void imprimePosOrdem (Arvore *arv){
    //Verifica se a Arvore existe
    if (arv == NULL){
        return;
    }

    else if (arv->raiz != NULL){
        imprimePosOrdem(&(arv->raiz->esq));
        imprimePosOrdem(&(arv->raiz->dir));
        printf("\nValor: %d", arv->raiz->valor);

    }

}

//Opcao 4: Pesquisa por elemento
int pesquisaElemento(Arvore *arv, int v){

    //Verifica se a Arvore existe
    if (arv == NULL){
        return -1;
    }
    
    else if (arv->raiz == NULL){
        return 0;
    }

    else{

        if (arv->raiz->valor > v){
            pesquisaElemento(&(arv->raiz->esq), v);
        }
        else if (arv->raiz->valor < v){
            pesquisaElemento(&(arv->raiz->dir), v);
        }
        else if(arv->raiz->valor == v){
            return 1;
        }
    }
}

//Opcao 5: Verifica a altura da Arvore
int altura (Arvore *arv){
    //Arvore nao existe
    if (arv == NULL){
        return -1;

    }
    //Arvore vazia
    else if(arv->raiz == NULL){
        return -1;

    }
    else{
        int h_esq = altura(&(arv->raiz->esq))+1;
        int h_dir = altura(&(arv->raiz->dir))+1;

        if(h_esq > h_dir){
            return (h_esq);
        }
        else{
            return (h_dir);
        }
    }
}

//Opcao 6: Insere elemento na Arvore
int insereArvore (Arvore *arv, int v){
    //Verifica se a Arvore nao existe
    if (arv == NULL){
        return -1;
    }

    //Caso a Arvore exista

    //Alocacao para o novo elemento
    Elemento *novo;
    novo = (Elemento*)malloc(sizeof(Elemento));

    //Verificar se consegui alocar memoria
    if(novo==NULL){
        return -2; //Para tratar erros posso retornar outro valor, tipo -2
    }

    //Verifica se nao existe nenhum elemento na Arvore
    else if (arv->raiz == NULL){
        //O elemento adicionado sempre serao folha, assim posso atribuir nos
        //ponteiros da esq e dir o valor NULL
        novo->valor = v;
        novo->esq = NULL;
        novo->dir = NULL;

        arv->raiz = novo;
        return 1;
    }

    //Caso ja existam elementos na Arvore
    else{
        //O elemento adicionado sempre serao folha, assim posso atribuir nos
        //ponteiros da esq e dir o valor NULL
        novo->valor = v;
        novo->esq = NULL;
        novo->dir = NULL;

        //Verifica se o valor e menor que a raiz
        if(novo->valor < arv->raiz->valor){
            //& E necessario para passar o endereco do meu ponteiro
            insereArvore(&(arv->raiz->esq), v);

        }
        //Verifica se o valor e maior que a raiz
        else if (novo->valor > arv->raiz->valor){
            //& E necessario para passar o endereco do meu ponteiro
            insereArvore(&(arv->raiz->dir), v);

        }
    }
    
    //Balanceia Arvore
    balanceia (arv);
    
    //Buscar na Arvore
    if (pesquisaElemento(arv, v) == 1){
        return 1;
    }
    
}

//Opcao 7: Remove elemento da Arvore
void inserirAleatorios(Arvore *arv, int quant){

    int v = 0;

    for (int i=1; i<=quant; i++){
        v = rand() % 101;
        insereArvore(arv, v);        
    }
}

//Opcao 8 : Insere uma quantidade especifica de elementos na Arvore
void inserirArvoreEspecifica(Arvore *arv){

    int v = 15;
    insereArvore(arv, v);
    v = 6;
    insereArvore(arv, v);
    v = 12;
    insereArvore(arv, v);
    v = 9;
    insereArvore(arv, v);
    v = 14;
    insereArvore(arv, v);
    v = 13;
    insereArvore(arv, v);
    v = 25;
    insereArvore(arv, v);
    v = 18;
    insereArvore(arv, v);
    v = 20;
    insereArvore(arv, v);
    v = 23;
    insereArvore(arv, v);
    v = 5;
    insereArvore(arv, v);
    v = 3;
    insereArvore(arv, v);
    v = 38;
    insereArvore(arv, v);
    v = 45;
    insereArvore(arv, v);
    v = 50;
    insereArvore(arv, v);
    v = 48;
    insereArvore(arv, v);
    v = 46;
    insereArvore(arv, v);
    v = 60;
    insereArvore(arv, v);

}

//Opcao 9: Insere uma Arvore em especifico
int removerElemento (Arvore *arv, int v){

    //Arvore nao existe
    if (arv == NULL){
        return -1;
    }
    
    //Arvore existe, porem esta vazia
    else if(arv->raiz == NULL){
        return 0;        
    }
    
    //Funcao em si
    else{

        //Se o elemento existir na Arvore
        if (pesquisaElemento(arv, v) == 1){
        
            //Se o elemento for maior que a raiz
            if (arv->raiz->valor < v){
                removerElemento(&(arv->raiz->dir), v);
            }
            //Se o elemento for menor que a raiz
            else if (arv->raiz->valor > v){
                removerElemento(&(arv->raiz->esq), v);
            }
            //Se o elemento for igual Ã  raiz
            else if (arv->raiz->valor == v){
                Elemento* aux = arv->raiz;

                //No folha
                if((arv->raiz->dir)==NULL && (arv->raiz->esq)==NULL){
                    free(arv->raiz);
                    arv->raiz = NULL;
                    
                    return 1;                    
                }
                //Filho a direita
                else if((arv->raiz->dir)!=NULL && (arv->raiz->esq)==NULL){
                    arv->raiz = arv->raiz->dir;
                    aux->dir = NULL;
                    
                    return 1;                    
                }
                //Filho a esquerda
                else if((arv->raiz->dir)==NULL && (arv->raiz->esq)!=NULL){
                    arv->raiz = arv->raiz->esq;
                    aux->esq = NULL;
                    
                    return 1;                    
                }
                //Dois filhos
                else{
                    
                    int lado = fatorBalanceamento(arv);
                    
                    //Usando o menor da sub-Arvore da direita
                    if (lado > 0){
                        aux = menorDireita(&(arv->raiz->dir));
                    }
                    //Usando o maior da sub-Arvore da esquerda
                    else if (lado <= 0){
                        aux = maiorEsquerda(&(arv->raiz->esq));
                    }

                    //Ponteiros da raiz sao ligados aos do auxiliar
                    aux->esq = arv->raiz->esq;
                    aux->dir = arv->raiz->dir;
                    
                    //Recarregando valores na arvore
                    arv->raiz = aux;
                    
                    return 1;
                }
                free(aux);
                aux=NULL;
            }
        }
        //Elemento nao existe na Arvore
        else{
            return 0;
        }
    }
    
    //Balanceia Arvore
    balanceia (arv); 
}

//Opcao 10: Remove elementos especificos da Arvore criada na Opcao 9
void removerEspecificos(Arvore *arv){
    
    int v = 23;
    removerElemento(arv, v);
    v = 3;
    removerElemento(arv, v);
    v = 48;
    removerElemento(arv, v);
    v = 15;
    removerElemento(arv, v);
    v = 13;
    removerElemento(arv, v);
}

//Opcao 11: Calcular a soma de todas as chaves da Arvore
int somaChaves (Arvore *arv){
    
    if(arv->raiz->esq != NULL){
        somaChaves(&(arv->raiz->esq));
    }
    if(arv->raiz->dir != NULL){
        somaChaves(&(arv->raiz->dir));
    }
    
    somaTotal += arv->raiz->valor;
    
    return somaTotal;
}

//Opcao 12: Encontra o valor minimo da arvore
int minimoArvore (Arvore *arv){
    
    //Se a arvore estiver vazia
    if (arv->raiz == NULL){
        return 0;
    }
    if(arv->raiz->esq != NULL){
        minimoArvore(&(arv->raiz->esq));
    }
    else{
        return arv->raiz->valor;
    }
}

//Opcao 13: Encontra o valor maximo da arvore
int maximoArvore (Arvore *arv){
    
    //Se a arvore estiver vazia
    if (arv->raiz == NULL){
        return 0;
    }
    if(arv->raiz->dir != NULL){
        maximoArvore(&(arv->raiz->dir));
    }
    else{
        return arv->raiz->valor;
    }
}

//Opcao 14: Contar numero de nao folhas
int contaNaoFolha (Arvore *arv){
    
    //Se a arvore estiver vazia
    if (arv->raiz == NULL){
        return 0;
    }
    contaNaoFolha(&(arv->raiz->esq));
    contaNaoFolha(&(arv->raiz->dir));
    if(arv->raiz->dir == NULL && arv->raiz->esq == NULL){}
    else{
        contagemNaoFolha += 1;
    }
    
}

//FIM DO BLOCO FUNCOES

/*--------------------------------------------------*/