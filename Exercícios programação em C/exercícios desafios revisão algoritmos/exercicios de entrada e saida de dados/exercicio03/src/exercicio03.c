/*
 ============================================================================
 Name        : exercicio03.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float nota1,nota2,nota3,peso1,peso2,peso3,media;
		printf("\ndigite a primeira nota!\n");
		scanf("%f",&nota1);
		printf("\ndigite o peso da primeira nota!\n");
		scanf("%f",&peso1);
		printf("\ndigite a segunda nota!\n");
		scanf("%f",&nota2);
		printf("\ndigite o peso da segunda nota!\n");
		scanf("%f",&peso2);
		printf("\ndigite a terceira nota!\n");
		scanf("%f",&nota3);
		printf("\ndigite o peso da terceira nota!\n");
		scanf("%f",&peso3);
		media=(nota1*peso1+nota2*peso2+nota3*peso3)/(peso1+peso2+peso3);
		printf("\n A media ponderada das notas e igual a %f\n",media);

		return(0);
}
