/*
 ============================================================================
 Name        : exercicio11.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float num,raiz2,raiz3,quad,cubo;
	printf("\n\tEscreva um numero positivo e maior que zero!\n");
	scanf("%f",&num);
    quad=pow(num,2);
	cubo=pow(num,3);
	raiz2=sqrt(num);
	raiz3=cbrt(num);
	printf("\n\t informacoes do numero digitado:\n"
			"%f ao quadrado e igual a: %f\n"
			"%f ao cubo e igual a: %f\n"
			"a raiz quadrada de %f e %f\n"
			"a raiz cubica de %f e %f\n", num,quad,num,cubo,num,raiz2,num,raiz3);
	return(0);


}
