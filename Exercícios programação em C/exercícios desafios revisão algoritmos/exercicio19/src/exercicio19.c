/*
 ============================================================================
 Name        : exercicio19.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float degrau, altura, qtd,total;
			printf("\n\t Escreva a altura a ser alcancada e a altura de cada degrau em metros!\n");
			scanf("%f",&altura);
			scanf("%f",&degrau);
			qtd=altura/degrau;
			printf("\n\t Voce devera subir %8.2f degraus",qtd);
			return(0);
}
