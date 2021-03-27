/*
 ============================================================================
 Name        : lista duplamente encadeada.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
}Lista2;

// FUNÇÕES
Lista2* insere (Lista2* l, int v); /* inserção no início - Recebe como parametro a lista e o valor inteiro a ser inserido no início da lista */
Lista2* busca(Lista2* lista, int v); /* função busca: busca um elemento na lista */
Lista2* retira (Lista2* l, int v); /* função retira: retira elemento da lista */

int main(void) { // conferir a main que não tem no site do professor

int op, vremover, vbuscar; /* Variaveis para opcao do menu, para o elemento a ser excluido e para o elemento a ser localizado pela busca */

    struct Registro *Lista2; /* Variavel para apontar para o primeiro elemento da lista */

    Lista2 = cria(); /* Cria a lista inicialmente vazia */

    while(op != 5) { /* Enquanto o usuario nao escolher a opcao 5 para sair do programa, as opções escolhidas sao executadas */

        system("cls");

        printf("\nPrograma Para Manipulacao de Listas Ligadas"); /* Imprime o menu principal do programa */
        printf("\n1 - Inserir no Final da Lista");
        printf("\n2 - Visualizar Lista");
        printf("\n3 - Buscar Elemento na Lista");
        printf("\n4 - Excluir Elemento");
        printf("\n5 - Sair do Programa");

        printf("\nEntre com a Opcao Desejada: ");
        scanf("%i",&op); /* Le a opcao do usuario */

        switch(op) { /* Conforme a opção escolhida execuca a funcao solicitada que pode ser para inserir, listar, buscar ou remover um elemento da lista */

            case 1:
                Lista2 = insere_final();
                break;

            case 2: 
                visualiza_lista_final(lista);
                break;

            case 3:
                printf("Entre com o valor que se deseja buscar: ");
                scanf("%d",&vbuscar);
                busca(lista,vbuscar);
                break;

            case 4:
                printf("Entre com o valor que deseja remover: ");
                scanf("%i",&vremover);
                Lista2 = excluir(lista, vremover);
                break;

            case 5: 
                exit(1);
            } // fim switch
    } // fim while
} // fim main

Lista2* insere (Lista2* l, int v) {

    Lista2* novo = (Lista2*) malloc(sizeof(Lista2)); /* Cria um novo elemento na lista com */

	novo->info = v; /* Preenche o campo info do novo elemento criado com o valor inteiro */

	novo->prox = l; /* O novo elemento aponta para o inicio da lista. Lembre que a lista na 
	verdade é um ponteiro para o primeiro elemento, assim o novo elemento ao ser incluido no 
	inicio da lista deve apontar para o proximo que é o inicio da lista, ou seja, aquele que 
	era o primeiro elemento da lista anteriormente */
	
	novo->ant = NULL;  /* Como o novo elemento é inserido no inicio da lista, não há elemento
	anterior. Por isso, armazena a constante NULL no ponteiro que aponta para o elemento anterior*/

    if (l != NULL) /* verifica se lista não está vazia */
        l->ant = novo;

    return novo;
} // fim insere

Lista2* busca(Lista2* lista, int v) {
	Lista2 *aux;
	
	if(!lista_vazia(lista)) {
		aux = lista;
    	while(aux != ( Lista2 *) NULL) {
           if(aux->info == v) {  //  Se o campo valor do elemento for igual a busca entao  retorna o elemento
                   return aux;
            } // fim if
            
        aux = aux -> prox; /* Atualiza aux com o ponteiro para o proximo elemento da lista.  */
       } // fim while
    return NULL; /* Senao encontrou retorna nulo */
    } // fim if
	else {
    	printf("\n A lista esta Vazia");            // Se a lista nao exister preenchida exibe mensagem informando lista vazia
    	getch();
	}
 	return NULL;
} // fim busca

Lista2* retira (Lista2* l, int v) { 
   
    Lista2* p = busca(l,v); /* Busca o elemento a ser removido da lista */
   
    if (p == NULL) /* se não achou o elemento: retorna lista inalterada */
        return l;

    if (l == p) { /* se o elemento a ser retirado da lista for o primeiro elemento
	 da lista entao o primeiro elemento da lista sera o proximo elemento */
    	p->prox->ant = NULL;
    	l = p->prox;
	}
    else
    	p->ant->prox = p->prox; /* se o elemento a ser retirado da lista nao for
		o primeiro da lista entao o elemento anterior deve apontar para o elemento que esta sendo apontado pelo
		elemento a ser retirado */
    
    if (p->prox != NULL) /* Se o elemento a ser retirado nao for o ultimo, entao o proximo elemento deve apontar
	para o elemento anterior ao elemento a ser retirado */
        p->prox->ant = p->ant;

    free(p); /* Efetivamente remove o elemento da memoria. Note que o elemento já não faz mais parte da lista
	 pois nao e mais referenciado na lista */

    return l; /* Retorna a lista atualizada */
} // fim retira
