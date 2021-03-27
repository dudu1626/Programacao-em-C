/*
 ============================================================================
 Name        : pilha 01.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : pilha estática homogenea
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int numero [5], op, topo=0,i;
	
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
				if (topo==5) printf ("\nPilha cheia.\n");
				else {
					printf ("\n Digite o numero a ser inserido: ");
					scanf ("%d", &numero[topo]);
					topo++;
					printf("\n Numero inserido\n");
				}// fim else
			break;
					
			case 2:
				if (topo==0) printf ("\n Pilha vazia.\n");
				else{
					printf ("\n Topo: %d\n", numero[topo-1]);
				}//fim else
			break;
			
			case 3:
				if (topo==0) printf ("\n Pilha vazia.\n");
				else{
					printf ("\n Numeros empilhados\n");
					for (i=topo-1;i>=0;i--)
						printf ("%d\n", numero[i]);
				}//fim else
			break;
				
			case 4:
				if (topo==0) printf ("\n Pilha vazia.\n");
				else{
					topo--;
					printf("\n Numero desempilhado.\n");
				}// fim else
			break;
			
			case 5:
				if (topo==0) printf ("\n Pilha vazia.\n");
				else{
					topo=0;
					printf("\n Pilha esvaziada\n");
				}//fim else
		}//fim switch
		system ("PAUSE");
	} while (op!=6);

return 0;
}

