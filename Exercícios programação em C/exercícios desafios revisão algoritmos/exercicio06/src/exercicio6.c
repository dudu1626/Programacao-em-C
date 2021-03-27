/*
 ============================================================================
 Name        : exercicio6.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float Salbruto,Salliquido,gratif,imposto;
		printf("\nInforme o salario bruto do empregado!\n");
		scanf("%f",&Salbruto);
		gratif=Salbruto*5/100;
		imposto=Salbruto*7/100;
		Salliquido=Salbruto+gratif-imposto;
		printf("\n o salario liquido do empregado sera de %f\n",Salliquido);
		return(0);
}
