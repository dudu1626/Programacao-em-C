/*
 ============================================================================
 Name        : exercicio5.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float salariom,salarioM,percentual;
				printf("\nInforme o salario do empregado!\n");
				scanf("%f",&salariom);
				printf("\nInforme o percentual do aumento!\n");
				scanf("%f",&percentual);
				salarioM=salariom+(salariom*percentual/100);
				printf("\n o salario com aumento sera de %f\n",salarioM);

				return(0);
}
