/*
 ============================================================================
 Name        : batalha campal.c
 Author      : 
 Version     : 0.2
 Description : 
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // para acentuação 
#include <conio.h> // mudar coloração da tela (ainda tem que ver como)
#include <ctype.h> // ver se vai precisar
#include <string.h> // ver se vai precisar
#include <windows.h> // ver se vai precisar


#define dim 6 // tamanho do campo de batalha

//funções
int resetCampo ();
void telaInicial ();
int mostrarCampo ();
void instrucoes ();

//variaveis globais
int i, j, campo[dim][dim];

int main(void) {
	
	int op;
	
	setlocale (LC_ALL,"Portuguese"); // necessário para usar acentuação
	
   	do {
		telaInicial();
		scanf ("%d", &op);
   		switch (op){
   			case 1:
   				resetCampo();
				mostrarCampo();
   			//fazer outra função para o jogo
			break;
			case 2:
				instrucoes(); // escrever as instruções na função
			break;
			case 3:
			break;	
		 	default:
				op=4; 
		}
	}
	while (op!=4);
	
	system ("PAUSE");
	return 0;
} // fm main


void telaInicial (){
	
  puts("      ____________________________________________________________________      ");
  puts("     |  ****************************************************************  |     ");
  puts("     |  ************************ BATALHA CAMPAL ************************  |     ");
  puts("     |  ****************************************************************  |     ");
  puts("     |                          [1] Iniciar                               |     ");
  puts("     |                          [2] Instruções                            |     ");
  puts("     |                          [3] Recordes                              |     ");
  puts("     |                          [4] Sair                                  |     ");
  puts("     |____________________________________________________________________|     ");
	
		
} // fim tela inicial

int resetCampo(){
	
	 for (i=0;i<dim;i++){
		for (j=0;j<dim;j++){ // carregar o campo
			campo[i][j]=0;
		}// fim for j
	}// fim for i
	
	campo[0][0] = 7;
	campo[0][1] = 2;
	campo[0][2] = 3;
	campo[0][3] = 4;
	campo[0][4] = 5;
	campo[0][5] = 6;
	campo[1][0] = 8;
	campo[2][0] = 9;
	campo[3][0] = 10;
	campo[4][0] = 11;
	campo[5][0] = 12;
	
} // fim zerar campo

int mostrarCampo(){
	
  
  puts("       ****************************************************************       ");
  puts("       ************************ BATALHA CAMPAL ************************       ");
  puts("       ****************************************************************       ");
  
	for (i=0;i<dim;i++){
			for (j=0;j<dim;j++){
			
				if (campo[i][j]==7)
					printf ("\t   ");
				if (campo[i][j]==2)
					printf ("\t A ");
				if (campo[i][j]==3)
					printf ("\t B ");
				if (campo[i][j]==4)
					printf ("\t C ");
				if (campo[i][j]==5)
					printf ("\t D ");
				if (campo[i][j]==6)
					printf ("\t E \n");
				if (campo[i][j]==8)
					printf ("\t 1 ");
				if (campo[i][j]==9)
					printf ("\t 2 ");
				if (campo[i][j]==10)
					printf ("\t 3 ");
				if (campo[i][j]==11)
					printf ("\t 4 ");	
				if (campo[i][j]==12)
					printf ("\t 5 ");	
					
				if (campo[i][j]==0)
					printf ("\t%c%c%c",47, 94,92);  // mostrar o campo
				if (campo[i][j]==1 )
					printf ("\t%c%c%c",124, 95, 124);
												
			}// fim for j
			printf ("\n");
		}//fim for i
	
}// fim mostrar campo

void instrucoes(){
	
	
	
	
}
