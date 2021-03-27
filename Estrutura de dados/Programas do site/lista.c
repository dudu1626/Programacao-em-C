/*
 ============================================================================
 Name        : Lista.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : site do professor
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int bool; // renomeia bool como inteiro - eu fiz para funcionar o programa do professor

struct Registro {
    int valor;
    struct Registro *prox;
};

struct Registro *aux, *inicio = NULL, *final = NULL; // criação dos ponteiros

struct Registro* cria(void); /*função responsável por criar a lista*/
struct Registro* insere_final(); /* função com tipo de retorno ponteiro para estrutura, realizando inserção pelo final*/
int lista_vazia(struct Registro *lista); /* função que verifica o estado da lista: retorno 1 se vazia ou 0 se não vazia*/
void visualiza_lista_final(struct Registro *lista); /* função responsável por imprimir o conteúdo da lista */
struct Registro* busca(struct Registro* lista, int busca); /* função que busca um elemento na lista*/
struct Registro* excluir(struct Registro *lista, int valor); /* função para excluir registros da lista*/

int main(void) {

    int op, vremover, vbuscar; /* Variaveis para opcao do menu, para o elemento a ser excluido e para o elemento a ser localizado pela busca */

    struct Registro *lista; /* Variavel para apontar para o primeiro elemento da lista */

    lista = cria(); /* Cria a lista inicialmente vazia */

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
            } // fim switch
    } // fim while
} // fim main

// FUNÇÕES

struct Registro* cria(void) { 
  return NULL;
} // fim cria

struct Registro* insere_final() {
   int x;

   printf("Entre com um numero inteiro: ");
   scanf("%i",&x);

   aux = (struct Registro*) malloc (sizeof(struct Registro));
   aux->valor = x;
   aux -> prox = (struct Registro *) NULL;

   if(inicio == NULL)
      inicio = final = aux; // Não existe elemento anterior e portanto há apenas um elemento na lista. Assim inicio e final são o mesmo elemento da lista.
   else  {
           final -> prox = aux;  // O elemento incluido se torna o ultimo elemento da lista. Assim o prox aponta para o elemento incluido.
           final = aux;
    }
    return inicio;
} // fim insere final

int lista_vazia(struct Registro *lista) {
   if(lista == NULL)
       return 1;
   else
       return 0;
} // fim lista vazia

void visualiza_lista_final(struct Registro *lista) {
    
    if(!lista_vazia(lista))  { /* verifica se a lista está vazia*/
       aux = lista;
       while(aux != (struct Registro *) NULL) { // Enquando o aux for diferente de NULL. Note que aux é atualizado com o ponteiro para o proximo elemento.
           printf("Valor da Lista: %i\n", aux->valor);
           aux = aux -> prox;                             // Atualiza aux com o ponteiro para o proximo elemento.
       }
   }
   
   else /* indica que a lista está vazia*/
         printf("\nTentou imprimir uma lista vazia!");
	getch();
} // fim visualizar lista

struct Registro* busca(struct Registro* lista, int busca) {
   bool achou = 0;                               // Assume que o elemento nao existe na lista, inicializando o flag com 0
   if(!lista_vazia(lista)) {                     // Se a lista nao estiver vazia inicia a busca
        for(aux=lista;aux!=NULL;aux=aux->prox) { // Percorre a lista a partir do primeiro elemento ate que o proximo elemento seja NULL
               if(aux->valor == busca) {         //  Se o campo valor do elemento for igual a busca entao  atualiza o flag para 1
                   achou = 1;
               }
        }
		if(!achou)                                 // Ao final da busca, verifica se achou e caso tenha encontrado imprime mensagem
			printf("Valor nao encontrado.\n");
	}
	else {
    	printf("\nTentou buscar de uma lista vazia");  // Se a lista nao exister preenchida exibe mensagem informando lista vazia
	}
 	getch();
 return NULL;
} // busca lista

struct Registro* excluir(struct Registro *lista, int valor) {

struct Registro *ant = NULL; /* ponteiro para elemento anterior */
aux = lista; /* ponteiro para percorrer a lista */

if(!lista_vazia(lista)) { 
       
	while(aux!= NULL && aux->valor != valor) { /* procura elemento na lista, guardando anterior */
          ant = aux;
          aux = aux->prox;
    } // fim while
       
	if(aux == NULL) { /* verifica se achou o elemento */
		printf("\nNao foi possivel a exclusao. Elemento nao encontrado!");
		getche();
        return lista;
    } // fim if
    
    if(ant == NULL) 				/* retira elemento */
         lista = aux->prox;         // Se o elemento excluido for o primeiro elemento da lista entao o inicio da lista aponta para o elemento seguinte
    else
         ant->prox = aux->prox;    // Se o elemento excluido nao for o primeiro, faz o elemento anterior apontar para o proximo elemento da lista

    free(aux); /* Libera a memoria alocada para o elemento excluido. Neste momento o elemento não faz mais parte da lista e pode ser exlcuido.  */

    printf("Elemento removido com sucesso!\n");
    getche();

    return lista;  /* Retorna a lista atualizada, sem o elemento que foi excluido */
} // fim if 
else  {
    printf("\nTentou remover de uma lista vazia");
    getche();
    return lista;
  } // fim else
} // fim excluir
