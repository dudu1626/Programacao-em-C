/*
 ============================================================================
 Name        : exercicio17.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float salario,saldo,cheque1,cheque2,cpmf1,cpmf2;
	printf("\n\t Escreva o valor do salario!\n");
	scanf("%f",&salario);
	printf("\n\t Escreva o valor dos cheques!\n");
	scanf("%f",&cheque1);
	scanf("%f",&cheque2);
	cpmf1=cheque1*0.38/100;
	cpmf2=cheque2*0.38/100;
	saldo=salario-cheque1-cheque2-cpmf1-cpmf2;

	printf("O saldo final e de %8.2f \n",saldo);

	return(0);


}
