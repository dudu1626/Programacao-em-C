/*
 ============================================================================
 Name        : exercicio18.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float racao, gato1,gato2,total;
		printf("\n\t Escreva o peso do saco de racao, em quilos!\n");
		scanf("%f",&racao);
		printf("\n\t Escreva o quanto de racao e dado a cada gato ,em gramas!\n");
		scanf("%f",&gato1);
		scanf("%f",&gato2);
		gato1=gato1/1000;
		gato2=gato2/1000;
		total=racao-5*(gato1+gato2);
		printf("no final de 5 dias restara %8.2f quilos de racao\n",total);

		return(0);

}
