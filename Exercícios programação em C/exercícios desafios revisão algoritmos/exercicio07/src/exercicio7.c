/*
 ============================================================================
 Name        : exercicio7.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float Salbruto,Salliquido,imposto;
			printf("\nInforme o salario bruto do empregado!\n");
			scanf("%f",&Salbruto);
			imposto=Salbruto*0.1;
			Salliquido=Salbruto+50-imposto;
			printf("\n o salario liquido do empregado sera de %f\n",Salliquido);
			return(0);
}
