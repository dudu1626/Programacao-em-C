/*
 ============================================================================
 Name        : pilha 03.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : pilha dinâmica homogenea
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	struct pilha{
		int num;
		pilha *prox;
	};
	
	pilha *topo, *aux;
	int op;
	topo = NULL; //acho que tem que por isso e no *prox também
	
	do {
		system ("CLS");
		
		printf ("\n\tMenu:\n");
		printf ("1. Inserir numero (empilhar)\n"
				"2. Consultar topo\n"
				"3. Consultar toda a pilha\n"
				"4. Excluir (desempilhar)\n"
				"5. Esvaziar a pilha\n"
				"6. Sair\n");
		printf (" Digite sua opcao: ");
		scanf ("%d", &op);
		
		if (op<1 || op>6) printf ("\n Opcao invalida!\n");
		
		switch (op){
			case 1: 
				aux = malloc(sizeof(pilha));
				printf("\n Digite o numero:");
				scanf("%d",&aux->num);
				aux->prox=topo;
				topo=aux;
				printf("\n numero inserido");
			break;
		
			case 2:
				if (topo==NULL) printf("\n Pilha vazia.\n");
				else{
					printf("\n Numero do topo: %d", topo->num);
				}//fim else
			break;
			
			case 3:
				if (topo==NULL) printf("\n Pilha vazia.\n");
				else{
					aux=topo;
					printf("\n Toda a pilha:");
					while(aux!=NULL){
						printf("%d",aux->num);
						aux=aux->prox;
					}
				}// fim else
			break;
			
			case 4:
				if (topo==NULL) printf("\n Pilha vazia.\n");
				else{
					aux=topo;
					topo=topo->prox;
					free(aux);
					printf ("\n Numero do topo excluido.\n");
				} // fim else
				
			case 5:
				if (topo==NULL) printf("\n Pilha vazia.\n");
				else{
					while (topo=NULL){
						aux=topo;
						topo=topo->prox;
						free(aux);
					}//fim while
					printf("\n Piha esvaziada. \n");
				}// fim else
			}// fim switch
			system ("PAUSE");
		} while (op!=6);

return 0;
}

