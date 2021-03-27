/*
 ============================================================================
 Name        : exercicio15.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float prefab,lucrop,lucro,impostop,imposto, custofinal;
		printf("\n\t Escreva o preco de fabrica do carro!\n");
		scanf("%f",&prefab);
		printf("\n\t Escreva o percentual de lucro do distribuidor!\n");
		scanf("%f",&lucrop);
		printf("\n\t Escreva o percentual de imposto!\n");
		scanf("%f",&impostop);
		lucro=lucrop*prefab/100;
		imposto=impostop*prefab/100;
		custofinal=lucro+imposto+prefab;
		printf("O lucro do distribuidor e %8.2f \n",lucro);
		printf("O valor de imposto e %8.2f \n",imposto);
		printf("o valor final do veiculo e %8.2f \n",custofinal);

		return(0);
}
