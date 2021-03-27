/*
 ============================================================================
 Name        : exercicio8.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float deposito,juros,montante,taxa;
		printf("\nInforme o valor do deposito!\n");
		scanf("%f",&deposito);
		printf("\nInforme o valor da taxa de juros!\n");
		scanf("%f",&taxa);
		juros=deposito*taxa/100;
		montante=deposito+juros;
		printf("\n o rendimento foi de %f e o montante final sera de %f\n",juros,montante);
		return(0);
}
