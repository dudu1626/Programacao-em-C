/*
Exercício 7 - Lista duplamente encadeada
1 ) Criar um programa para manter uma lista de temas para os trabalhos de uma faculdade. 
Cada  tema deve ter as seguintes informações:

nome - char[80]
descricao - char[400]

Criar uma estrutura tema para representar um tema de trabalho com os campos acima.

Criar um ponteiro para estrutura tema para representar uma lista

O programa deve exibir ao usuário um menu com as opções para:

Incluir um Tema
Remover um Tema
Navegar pelos Temas com opção para ver o próximo tema e o tema anterior.
Pesquisar um Tema pelo nome
Sair do Programa

Crie o programa com base no exemplo que foi apresentado em aula e no exercício sobre Lista encadeada simples.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
   char nome[30];
    int codigo; 
};
typedef struct pessoa pessoa;

pessoa temp;

struct lista { 
       struct pessoa func;
       struct lista *ant;
       struct lista *prox; 
};
typedef struct lista lista;

int empty (lista *l);
void inserirInicio(lista **i, lista **f, struct pessoa p);
void inserirFim(lista **i, lista **f, struct pessoa p);
void inserirOrdem(lista **i,lista **f, struct pessoa p);
void listar(lista *i);
void listarInvertida(lista *f);


int main() {
    
    lista *i=NULL, *f=NULL;
    struct pessoa temp;
    
    printf("\nInserir 1:\n");
    temp.codigo = 10;
    strcpy(temp.nome, "Ana");
    inserirOrdem(&i, &f, temp);
    listar(i);

    printf("\nInserir 2:\n");
    temp.codigo = 2;
    strcpy(temp.nome, "Zelia");
    inserirOrdem(&i, &f,temp);
    listar(i);

    printf("\nInserir 3:\n");
    temp.codigo = 50;
    strcpy(temp.nome, "Lucia");
    inserirOrdem(&i, &f,temp);
    listar(i);
    listarInvertida(f);
    system("pause");

    return 0;
    
}


int empty (lista *l) {
   if (l==NULL) 
       return 1;
   else 
       return 0;
}

void inserirInicio(lista **i, lista **f, struct pessoa p){
   lista *novo;
   
   novo = (lista*) malloc(sizeof(lista*));
   novo->func = p;
   novo->prox = *i;
   novo->ant=NULL;
   
   *i = novo;
   if (*f== NULL)
      *f = novo;
}

void inserirFim(lista **i, lista **f, struct pessoa p){
    lista *novo;
    
    novo = (lista*) malloc(sizeof(lista*));
    novo->func = p;
    novo->prox = NULL;
    novo->ant = *f;
    
    if (*f == NULL)
       *i = novo;
    else
       (*f)->prox = novo;
       
    *f = novo;
}

void inserirOrdem(lista **i,lista **f, struct pessoa p){
    lista *aux, *ant;
    aux = *i;
    while (aux != NULL && strcmp(aux->func.nome, p.nome) < 0) {
        ant = aux;
        aux = aux->prox;
    }

     if (aux == *i) 
        inserirInicio(i, f, p);
      else 
         if (aux == NULL) 
             inserirFim(i, f, p);
          else { 
             lista *novo;
             novo = (lista*) malloc(sizeof(lista*));
             novo->func = p;
             novo->prox = aux;
             novo->ant = ant;
             ant->prox = novo;
             aux->ant = novo;
          }
}

void listar(lista *i) {
    lista *aux;
    
    if (i==NULL) 
        printf("\nLista vazia!!!");
    else { 
         aux = i;
         while (aux!=NULL) {
            printf("Codigo: %d Nome:%s\n",aux->func.codigo, aux->func.nome);
            aux = aux->prox;
         }
    }
}

void listarInvertida(lista *f) {
    if (f==NULL) 
        printf("\nLista vazia!!!");
    else { 
        lista *aux = f;
        while (aux != NULL) {
            printf("Codigo: %d", aux->func.codigo);
            printf("Nome: %s\n", aux->func.nome);
            aux = aux->ant;
         }
    }
}

