/*
 ============================================================================
 Name        : exercicio02.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float nota1,nota2,nota3,soma,media;
		printf("\t\n digite suas 3 notas!\n");
		scanf("%f",&nota1);
		scanf("%f",&nota2);
		scanf("%f",&nota3);
		soma=nota1+nota2+nota3;
		media=soma/3;
		printf("\n A media das notas e igual a %f\n",media);

		return(0);
}
