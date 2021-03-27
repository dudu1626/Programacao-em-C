/*
 ============================================================================
 Name        : exercicio12.c
 Author      : Eduardo Ferreira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float num1, num2,pot;
		printf("\n\tEscreva dois numeros maiores que zero!\n");
		scanf("%f",&num1);
		scanf("%f",&num2);
		pot=pow(num1,num2);
		pot=num1^num2;
		printf("\n\t O numero %f elevado a %f é %f\n", num1,num2,pot);
		return(0);

}
