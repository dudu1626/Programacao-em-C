/*
 ============================================================================
 Name        : exercicio9.c
 Author      : Eduardo Ferreira
 RA          :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float base,altura,area;
			printf("\nInforme a base e altura do triangulo!\n");
			scanf("%f",&base);
			scanf("%f",&altura);
			area=base*altura/2;
			printf("\n A area do triangulo informado e de %f\n",area);
			return(0);
}
