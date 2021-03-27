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

typedef struct lista {
    int info;
    struct lista *ant;
    struct lista *prox;
}Lista;

Lista *insere (Lista *l, int v);
Lista *busca (Lista * l, int v);
Lista* retira (Lista* l, int v);

int main(void) {
//de outro código, tem que adaptar
	int op, vremover, vbuscar;

/* Variavel para apontar para o primeiro elemento da lista */
	struct lista *lista;

/* Cria a lista inicialmente vazia */
	lista = cria();

/* Enquanto o usuario nao escolher a opcao 5 para sair do programa, as opções escolhidas sao executadas */
while(op != 5) {

/* Imprime o menu principal do programa */
system("cls");
printf("\nPrograma Para Manipulacao de Listas Ligadas");
printf("\n1 - Inserir no Final da Lista");
printf("\n2 - Visualizar Lista");
printf("\n3 - Buscar Elemento na Lista");
printf("\n4 - Excluir Elemento");
printf("\n5 - Sair do Programa");

/* Le a opcao do usuario */
printf("\nEntre com a Opcao Desejada: ");
scanf("%i",&op);

/* Conforme a opção escolhida execuca a funcao solicitada que pode ser para inserir, listar, buscar ou remover um elemento da lista */
switch(op) {
case 1:
lista = insere_final();
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
lista = excluir(lista, vremover);
break;
case 5: 
exit(1);
}
}


system ("PAUSE");
return 0;
}


Lista *insere (Lista *l, int v) {

Lista *novo = (Lista *) malloc(sizeof(Lista));

novo->info = v;

novo->prox = l;

novo->ant = NULL;   

if (l != NULL)
	l->ant = novo;

return novo;
}

Lista * busca (Lista * l, int v) {
    Lista* p;
    for (p=l; p!=NULL; p=p->prox)
        if (p->info == v)
            return p;
   
   return NULL;
}

// alternativa para busca:
/*
Lista2* busca(Lista2* lista, int v) { 
     Lista2 *aux;
     if(!lista_vazia(lista)) { 
        aux = lista; 
       while(aux != ( Lista2 *) NULL) { 
           if(aux->info == v) {  //  Se o campo valor do elemento for igual a busca entao  retorna o elemento
                   return aux;} */
         /* Atualiza aux com o ponteiro para o proximo elemento da lista.  */
        //   aux = aux -> prox; } 
     /* Senao encontrou retorna nulo */
   /*   return NULL;} } 
else { printf("\n A lista esta Vazia");   // Se a lista nao exister preenchida exibe mensagem informando lista vazia 
    getch(); } 
 return NULL; } */
 
 Lista* retira (Lista* l, int v) {
   
    Lista* p = busca(l,v);
   
    if (p == NULL)
        return l;

    if (l == p) {
	
        p->prox->ant = NULL;
        l = p->prox;
	}
	else
        p->ant->prox = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;

    free(p);

    return l;
}
