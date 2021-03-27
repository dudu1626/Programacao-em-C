/*
 ============================================================================
 Name        : XXXX.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100 // tamanho da fila

struct fila {
    int ini, fim;  // inicio e fim da fila
    float vet[N]; // vetor com os elementos da fila
};

/*struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

struct fila {
    No* ini;
    No* fim;
}; // estou na dúvida sobre isso */

typedef struct fila Fila;   // Estrutura para a fila
Fila* cria (void);              // Ponteiro para a fila
void insere (Fila* f, float v);  // Funcao para incluir um elemento no final da fila
float retira (Fila* f);             // Funcao para remover um elemento do inicio da fila
int vazia (Fila* f);                // Funcao para verificar se a fila esta vazia
void libera (Fila* f);            // Funcao para liberar a fila da memoria
int incr (int i);

int main(void) {


system ("PAUSE");
return 0;
}

int incr (int i) { // incremento do indice
    if (i == N-1)
        return 0;
    else
        return i+1;
}

Fila* cria (void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));  // Cria ponteiro para a fila
    f->ini = f->fim = 0;                                 // inicializa fila vazia 
    return f;
}

void insere (Fila* f, float v) {
    if (incr(f->fim) == f->ini) {
        /* fila cheia: capacidade esgotada  */
        printf("A Fila está cheia. Nao e possivel inserir mais elementos.\n");
        exit(1);    /* finaliza funcao retornando 1 */
    }

    /* insere elemento na próxima posição livre */
    f->vet[f->fim] = v;           // Insere o elemento no fim da fila usando o vetor vet indexado por f->fim
    f->fim = incr(f->fim);       // Incrementa a posicao do fim da fila em 1
}

float retira (Fila* f) {
    float v;
    if (vazia(f)) {
        printf("A Fila esta vazia.\n");
        exit(1);     // finaliza funcao retornando 1
    }

    /* retira elemento do início */
    v = f->vet[f->ini];  // Obtem o elemento do inicio da fila
    f->ini = incr(f->ini); // Incrementa o indice para o inicio da fila
    return v;                  // retorna o valor do elemento que estava no inicio da fila
}

int vazia (Fila* f) {
    return (f->ini == f->fim);  // Retorna 1 se inicio da fila for igual ao fim
}

void libera (Fila* f) {
    free(f);
}


