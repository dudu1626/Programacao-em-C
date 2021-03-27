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
#define TAM 100 
 
// Define a estrutura de dados Fila com 100 elementos do tipo char 
    struct fila 
    { 
        char itens[TAM]; 
        int inicio; 
        int fim; 
    }; 
 
// Funcao para inserir um novo elemento na fila 
void insere(struct fila *f, int el) { 
    if (f->fim == TAM -1) //fila cheia 
        exit(1); 
    else 
    { 
        f->fim = f->fim + 1; 
        f->itens[f->fim] = el; 
    } 
} 
 
// Funcao para verificar se a fila esta vazia. Retorna true caso a fila 
// esteja vazia e retorna false caso a fila possua pelo menos um elemento. 
int empty(struct fila *f) { 
    if (f->fim < f->inicio) 
        return true; 
    else return false; 
} 
 
// Funcao para remover um elemento da fila. O elemento do inicio da fila 
// sera removido. 
int remove(struct fila *f) 
{ 
    int aux; 
    if (empty(f) == true) 
        exit(1); 
    else 
    { 
        aux = f->itens[f->inicio]; 
        f->inicio = f->inicio + 1; 
        return aux; 
    } 
} 
 
int main() 
{ 
    int opcao, elemento; 
    struct fila f; 
    f.inicio = 0; 
    f.fim = -1; 
 
    do 
    { 
        printf("\n1-Inserir \n2-Remover \n3-Encerrar"); 
        scanf("%d", &opcao); 
 
        if(opcao ==1) 
        { 
            printf("\nDigite o Elemento a ser inserido na Fila : "); 
            scanf("%d", &elemento); 
            insere(&f, elemento); 
        } 
 
        if (opcao ==2) 
        { 
            int aux =remove(&f); 
            printf("\nO Elemento Removido foi: %d", aux); 
        } 
    } 
    while (opcao !=3); 
    return 0; 
} 
