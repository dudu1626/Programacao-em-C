/*
 ============================================================================
 Name        : exercicio13.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float pes,pol,jar,mil;
	printf("\n\t Escreva uma medida em pes!");
	scanf("%f",&pes);
	pol=pes*12;
	jar=pes/3;
	mil=pes/(3*1750);
	printf("a medida e igual a %f polegadas",pol);
	printf("a medida e igual a %f jardas",jar);
	printf("a medida e igual a %f milhas",mil);

	return(0);

}
