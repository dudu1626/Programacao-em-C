/* programa_pilha_02.c */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 100

/* Estrutura que ir? conter a pilha de informa??es com o topo e o vetor de itens da pilha. */
struct pilha {
    int topo;
    int itens[TAMANHO_PILHA];
};

int empty(struct pilha *p) {
    if( p->topo == -1 ) {
        return 1;
    }
        return 0;
}


/* Retorna um elemento do topo da pilha e atualiza o topo da pilha */
int pop(struct pilha *p) {
    if( empty(p) ) {
        printf("\nPilha vazia");
        exit(1);
    }
    /* retorna o item do topo da pilha atual e diminui a posi??o da pilha */
    return (p->itens[p->topo--]);
}

/* Inclui um elemento no topo da pilha */
void push(struct pilha *p, int e) {
    if( p->topo == (TAMANHO_PILHA - 1)) {
        printf("\nEstouro da pilha");
        exit(1);
    }
    /* ap?s veriicar se n?o haveria estouro na capacidade da pilha,
    ? criada uma nova posi??o na pilha e o elemento ? armazenado */
    p->itens[++(p->topo)] = e;
    return;
}

/* Retorna o tamanho da pilha */
int size(struct pilha *p) {
    /* sempre lembrando que na linguagem C o ?ndice de um vetor come?a na posi??o 0 */
    return p->topo+1;
}

/* Retorna o elemento do topo da pilha*/
int stackpop(struct pilha *p) {
    return p->itens[p->topo];
}

/* Programa principal */
int main(void) {
    struct pilha x;
    x.topo = -1;
    push(&x,1);
    push(&x, 2);
    push(&x, 3);
    printf("\nTamanho da pilha %d", size(&x));
    printf("\n Elemento do topo da pilha %d", stackpop(&x));
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    printf("\n%d", pop(&x));
    return 0;
}

