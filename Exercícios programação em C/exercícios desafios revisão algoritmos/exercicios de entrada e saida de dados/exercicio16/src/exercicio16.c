/*
 ============================================================================
 Name        : exercicio16.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float salariom,horas,vhoras,bruto,imposto,liquido;
	printf("\n\t Escreva o valor do salario minimo!\n");
	scanf("%f",&salariom);
	printf("\n\t Escreva o numero de horas trabalhadas!\n");
	scanf("%f",&horas);
	vhoras=salariom/2;
	bruto=vhoras*horas;
	imposto=bruto*3/100;
	liquido=bruto-imposto;
	printf("O salario a receber e igual a %8.2f \n",liquido);

	return(0);
}
