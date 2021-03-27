/*
 ============================================================================
 Name        : Lista, ponteiros e alocação dinâmica.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : exercício ponteiros e alocação dinâmica
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct { 
	int chave;
	char marca [20];
	char modelo [20];
	int ano;
	char placa[10];
	char cor[20];	
}CARRO;

typedef struct registro{
	CARRO car;
	struct NO* prox;
}NO;

typedef struct NO lista;

// funções:
lista* criaLista(void);
lista* insereNovo(lista* l, int chave);
int listaVazia(lista* l); // ver

pont consultar (LISTA* l, int ch);
int remover(LISTA* l, int ch);

int main(void) {

int op=0;

while (op!5){

	system("cls");
	printf("\n\tPrograma Locadora de veículos Anhanguera");
	printf("\n1 - Cadastrar novo Veículo");
	printf("\n2 - Visualizar Lista");
	printf("\n3 - Buscar Elemento na Lista");
	printf("\n4 - Excluir Elemento");
	printf("\n5 - Sair do Programa\n");
	
	printf("\nEntre com a Opcao Desejada: ");
	scanf("%i",&op);
	switch(op) {
		case 1: cadastrar(LISTA* l, registro reg);
		break;
		case 2: consultar (LISTA* l, int ch);
		break;
		case 3: 
			printf("Entre com o valor que se deseja buscar: ");
			scanf("%d",&vbuscar);
			busca(lista,vbuscar);
		break;
		case 4:
			printf("Entre com o valor que deseja remover: ");
			scanf("%i",&vremover);
			lista = remover(LISTA* l, int ch);
		break;
		case 5: exit(1);
	}
system ("PAUSE");
return 0;
}

lista* criaLista(void) {
    return NULL;
}

lista* insereNovo(lista* l, int chave)
{
    lista* novo = (lista*) malloc(sizeof(lista));
    novo->car.chave = chave;
    // colocar os outros atributos do cadastro do carro
    novo->prox = l;
    return novo;
}

int listaVazia(lista* l) {
   if(l == NULL)
      return 1; 
    else
      return 0;
}
