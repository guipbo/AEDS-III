/*
 * Projeto ArvoreBinaria
 * File:   ArvoreBinaria.c
 * Author: ProfGuiBraga
 * 
 */

/*--------------------------------------------------*/

//BIBLIOTECAS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//FIM DAS BIBLIOTECAS

/*-------------------------------------------------*/

//TAD's

//Tipo que define cada elemento da Arvore
typedef struct elemento{
    struct elemento *esq, *dir;
    int valor;

}Elemento;

//Tipo que define a Arvore como um todo
typedef struct arvore{
    Elemento *raiz;

}Arvore;

//FIM DAS TAD's

/*--------------------------------------------------*/

//PREVIAS DE FUNCOES

//FUNCOES ESTRUTURAIS
//Delay
void delay ();
//Menu
int menu ();
//Cria a Arvore
Arvore *criarArvore();
//Retorna o maior No da sub-Arvore da esquerda
Elemento* maiorEsquerda (Arvore* atual);
//Retorna o menor No da sub-Arvore da direita
Elemento* menorDireita (Arvore* atual);

//FUNCOES DE EXECUCAO
//Opcao 1: Imprime a Arvore em Pre-Ordem
void imprimePreOrdem (Arvore *arv);
//Opcao 2: Imprime a Arvore em In-Ordem
void imprimeInOrdem (Arvore *arv);
//Opcao 3: Imprime a Arvore em Pos-Ordem
void imprimePosOrdem (Arvore *arv);
//Opcao 4: Pesquisa por elemento na Arvore
int pesquisaElemento(Arvore *arv, int v);
//Opcao 5: Calcula a altura da Arvore
int altura (Arvore *arv);
//Opcao 6: Inserir elemento na Arvore
int insereArvore (Arvore *arv, int v);
//Opcao 7: Inserir elementos aleatorios na Arvore
void inserirAleatorios(Arvore *arv, int quant);
//Opcao 8: Inserir elementos especificos na Arvore
void inserirArvoreEspecifica(Arvore *arv);
//Opcao 9: Remove elemento da Arvore
int removerElemento (Arvore *arv, int v);
//Opcao 10: Calcular a soma de todas as chaves da Arvore
int somaTotal = 0;
int somaChaves (Arvore *arv);
//Opcao 11: Encontra o valor minimo da arvore
int minimoArvore (Arvore *arv);
//Opcao 12: Encontra o valor maximo da arvore
int maximoArvore (Arvore *arv);
//Opcao 13: Contar numero de nao folhas
int contagemNaoFolha = 0;
int contaNaoFolha (Arvore *arv);

//FIM DO BLOCO DE PREVIAS DE FUNCOES

/*-------------------------------------------------*/

//MAIN
int main()
{setlocale(LC_ALL, "");

    //Teclas de controle estrutural
    char finalExecucao;
    char loop = 's';
    int saida_final = 0;

    //Criacao da Arvore
    Arvore* arv = criarArvore();

    while (loop == 's' || loop == 'S'){

	//EXECUCAO
        switch(menu()){

            //Opcao 1: Imprime a Arvore em Pre-Ordem
            case 1:{system("cls");

                printf("\nImprimir Arvore Pre-Ordem: \n"
                       "--------------------\n");

                //Saida
                printf("\nArvore: ");
                imprimePreOrdem(arv);


                printf("\n--------------------\n");
            break;}

            //Opcao 2: Imprime a Arvore em In-Ordem
            case 2:{system("cls");

                printf("\nImprimir Arvore In-Ordem: \n"
                       "--------------------\n");

                //Saida
                printf("\nArvore: ");
                imprimeInOrdem(arv);


                printf("\n--------------------\n");
            break;}

            //Opcao 3: Imprime a Arvore em Pos-Ordem
            case 3:{system("cls");

                printf("\nImprimir Arvore Pos-Ordem: \n"
                       "--------------------\n");

                //Saida
                printf("\nArvore: ");
                imprimePosOrdem(arv);


                printf("\n--------------------\n");
            break;}

            //Opcao 4: Pesquisa por elemento na Arvore
            case 4:{system("cls");

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
                    printf("\nO elemento %d existe na Arvore.", valorPesquisa);
                }
                    
                else{
                    printf("\nO elemento %d nao existe na Arvore.", valorPesquisa);
                }
                
                printf("\n--------------------\n");
            break;}

            //Opcao 5: Calcula a altura da Arvore
            case 5:{system("cls");

                printf("\nVerificar altura da Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessArios
                int h;

                //Execucao da funcao
                h = altura(arv);

                //Saida
                if (h>=0){
                    printf("\nA altura da Arvore e: %d", h);
                }
                else{
                    printf("\nA Arvore nao possui elementos.");                    
                }
                
                printf("\n--------------------\n");
            break;}

            //Opcao 6: Inserir elemento na Arvore
            case 6:{system("cls");

                printf("\nInserir elemento na Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessArios
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

            //Opcao 7: Inserir elementos aleatorios na Arvore
            case 7:{system("cls");

                //Inicializacao de parametros necessArios
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
            
            //Opcao 8: Inserir elementos especificos na Arvore
            case 8:{system("cls");

                printf("\nInserir Arvore especifica: \n"
                       "--------------------\n");
                
                printf("\nValores que serao inseridos:\n"
                       "-----\n"
                       "-> 20;\n"
                       "-> 10;\n"
                       "-> 50;\n"
                       "-> 7;\n"
                       "-> 17;\n"
                       "-> 47;\n"
                       "-> 60;\n"
                       "-> 2;\n"
                       "-> 9;\n"
                       "-> 11;\n"
                       "-> 18;\n"
                       "-> 32;\n"
                       "-> 55;\n"
                       "-> 61;\n"
                       "-> 1;\n"
                       "-> 19.\n"
                       "-----\n"
                      );

                //Execucao da funcao
                inserirArvoreEspecifica(arv);

                printf("\n--------------------\n");
            break;}
            
            //Opcao 9: Remove elemento da Arvore
            case 9:{system("cls");

                printf("\nRemover elemento da Arvore: \n"
                       "--------------------\n");

                //Inicializacao de parametros necessArios
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
            
            //Opcao 10: Calcular a soma de todas as chaves da Arvore
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
            
            //Opcao 11: Encontra o valor minimo da arvore
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
            
            //Opcao 12: Encontra o valor maximo da arvore
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
            
            //Opcao 13: Contar numero de nao folhas
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
            case 0:{system("cls");

                printf("\nSaida\n"
                       "--------------------\n");
                
                //Inicializacao de parametros necessArios
                char certeza = 's';
                
                
                printf("\nTem certeza que deseja sair?"
                        "\nDigite 's' para confirmar;"
                        "\nQualquer outra tecla para cancelar: ");
                scanf("%s", &certeza);
                
                if(certeza == 's' || certeza == 'S'){
                    loop = 'n';
                    saida_final = 1;
                }

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
            printf("Escreva uma tecla e enter pra continuar: \n");  
            scanf("%s", &finalExecucao);
        }
        else{
            //Saida
            printf("\n--------------------\n");  
            printf("\nObrigado por utilizar o programa!");
            printf("\n--------------------\n");  
            delay(3000);
        }
        
    }

return 0;
}

//FIM DO BLOCO MAIN

/*--------------------------------------------------*/

//FUNCOES ESTRUTURAIS

//Delay
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//Menu
int menu (){

    int valor = 0;

    system("cls");
    printf("Escolha uma opcao: \n"
           "1 - Imprimir Arvore Pre-Ordem;\n"
           "2 - Imprimir Arvore In-Ordem;\n"
           "3 - Imprimir Arvore Pos-Ordem;\n"
           "4 - Pesquisar por elemento;\n"
           "5 - Verificar altura da Arvore;\n"
           "6 - Inserir elemento na Arvore;\n"
           "7 - Inserir elementos aleatorios;\n"
           "8 - Inserir Arvore especifica;\n"
           "9 - Remover elemento da Arvore;\n"
           "10 - Calcular a soma de chaves;\n"
           "11 - Encontra o valor minimo da arvore;\n"
           "12 - Encontra o valor maxima da arvore;\n"
           "13 - Contar numero de nao folhas;\n"
           "0 - Sair.\n"
           "-----> "
           );
    scanf("%d", &valor);
    printf("\n--------------------\n");

return valor;
}

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

//AUXILIARES DE REMOCAO
//Encontra o maior elemento na sub-Arvore da esquerda
Elemento* maiorEsquerda (Arvore* arv){
    Elemento* aux;
    
    //Enquanto nao for a folha mais b-Aixa a direita
    if ((arv->raiz->dir) != NULL){
        maiorEsquerda(&(arv->raiz->dir));
    }
    
    //Chegamos na folha mais b-Aixa da direita
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
    
    //Enquanto nao for a folha mais b-Aixa a direita
    if ((arv->raiz->esq) != NULL){
        maiorEsquerda(&(arv->raiz->esq));
    }
    
    //Chegamos na folha mais b-Aixa da direita
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

//FIM DO BLOCO FUNCOES ESTRUTURAIS

/*--------------------------------------------------*/

//FUNCOES DE EXECUCAO

//Opcao 1: Imprime a Arvore em Pre-Ordem
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

//Opcao 2: Imprime a Arvore em In-Ordem
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

//Opcao 3: Imprime a Arvore em Pos-Ordem
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

//Opcao 4: Pesquisa por elemento na Arvore
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

//Opcao 5: Calcula a altura da Arvore
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

//Opcao 6: Inserir elemento na Arvore
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
        //O elemento adicionado sempre sera folha, assim posso atribuir nos
        //ponteiros da esq e dir o valor NULL
        novo->valor = v;
        novo->esq = NULL;
        novo->dir = NULL;

        arv->raiz = novo;
        return 1;
    }

    //Caso ja existam elementos na Arvore
    else{
        //O elemento adicionado sempre sera folha, assim posso atribuir nos
        //ponteiros da esq e dir o valor NULL
        novo->valor = v;
        novo->esq = NULL;
        novo->dir = NULL;

        //Verifica se o valor e menor que a raiz
        if(novo->valor < arv->raiz->valor){
            //& e necessario para passar o endereco do meu ponteiro
            insereArvore(&(arv->raiz->esq), v);

        }
        //Verifica se o valor e maior que a raiz
        else if (novo->valor > arv->raiz->valor){
            //& e necessario para passar o endereco do meu ponteiro
            insereArvore(&(arv->raiz->dir), v);

        }
    }
    
}

//Opcao 7: Inserir elementos aleatorios na Arvore
void inserirAleatorios(Arvore *arv, int quant){

    int v = 0;

    for (int i=1; i<=quant; i++){
        v = rand() % 101;
        insereArvore(arv, v);        
    }
}

//Opcao 8: Inserir elementos especificos na Arvore
void inserirArvoreEspecifica(Arvore *arv){

    int v = 20;
    insereArvore(arv, v);
    v = 10;
    insereArvore(arv, v);
    v = 50;
    insereArvore(arv, v);
    v = 7;
    insereArvore(arv, v);
    v = 17;
    insereArvore(arv, v);
    v = 47;
    insereArvore(arv, v);
    v = 60;
    insereArvore(arv, v);
    v = 2;
    insereArvore(arv, v);
    v = 9;
    insereArvore(arv, v);
    v = 11;
    insereArvore(arv, v);
    v = 18;
    insereArvore(arv, v);
    v = 55;
    insereArvore(arv, v);
    v = 61;
    insereArvore(arv, v);
    v = 1;
    insereArvore(arv, v);
    v = 19;
    insereArvore(arv, v);
    v = 32;
    insereArvore(arv, v);

}

//Opcao 9: Remove elemento da Arvore
int removerElemento (Arvore *arv, int v){

    //Arvore nao existe
    if (arv == NULL){
        return -1;
    }
    
    //Arvore existe, porem estA vazia
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
            //Se o elemento for igual a raiz
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

                    int lado = 0;
                    
                    printf("\nDeseja usar o maior a direita ou o menor a esquerda? " 
                            "\n1 - Menor a direita;"
                            "\n2 - Maior a esquerda: "
                            );
                    scanf("%d", &lado);
                    
                    //Usando o menor da sub-Arvore da direita
                    if (lado == 1 && (arv->raiz->dir) != NULL){
                        aux = menorDireita(arv->raiz->dir);
                    }
                    //Usando o maior da sub-Arvore da esquerda
                    else if (lado == 2 && (arv->raiz->esq) != NULL){
                        aux = maiorEsquerda(arv->raiz);
                    }
                    //Opcao invalida
                    else{
                        printf("\nOpcao invalida!");
                    }

                    //Ponteiros da raiz sao ligados a do auxiliar
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
    
    /*
    
    FUNCIONAMENTO DA REMOCAO 
    
    Sao três casos para a remocao de nos,
    -> O no e uma folha (nao possue filhos);
    -> O no possue um filho;
    -> O no possue dois filhos.
    1- Verificar se a Arvore e nula (retornar erro de Arvore inexistente)
    2- Verificar se a Arvore estA vazia (arv->raiz == NULL)
    3- Verificar se o elemento e menor que a raiz (vai esquerda)
    4- Verificar se o elemento e menor que a raiz (vai direita)
    5- Else para elemento igual ao que estou procurando (encontramos o elemento)
    6- Criar auxiliar para nao perder minha referência
    7- Verificar casos: no folha, no de um filho, no de dois filhos
    8- Para verificar no folha, olhamos se os ponteiros esq e dir sao nulos
    8- Para no folha apenas o removemos
    9- Para apenas um filho
    10- Verificamos se esq ou dir sao nulos
    11- Utilizando o aux passamos o ponteiro para o filho e removemos o pai ()
    12- .arv->raiz = arv->raiz->esq ou arv->raiz = arv->raiz->dir;
        .aux->esq = NULL;
        .free aux;
    13- Para dois filhos
    14- Pegamos o mais a esquerda da sub-Arvore da direita ou o mais a direita da sub-Arvore da esquerda
    15- Para isso criamos e chamamos uma funcao auxiliar de remocao que tem como objetivo pegar o valor
        mais a esquerda da sub-Arvore da direita ou mais a direita da sub-Arvore da esquerda. Funcao vai retornar o elemento.
    16- aux->esq = arv->raiz->esq;
        aux->dir = arv->raiz->dir;
        arv->raiz->esq = NULL;
        arv->raiz->dir = NULL;
        free(arv->raiz);
        arv->raiz = aux;
        free(aux);
        aux=NULL;
    */    
}

//Opcao 10: Calcular a soma de todas as chaves da Arvore
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

//Opcao 11: Encontra o valor minimo da arvore
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

//Opcao 12: Encontra o valor maximo da arvore
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

//Opcao 13: Contar numero de nao folhas
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

//FIM DO BLOCO FUNCOES DE EXECUCAO

/*--------------------------------------------------*/