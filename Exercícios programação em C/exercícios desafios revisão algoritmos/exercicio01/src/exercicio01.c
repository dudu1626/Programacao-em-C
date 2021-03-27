/*
 ============================================================================
 Name        : exercicio01.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n1,n2,n3,n4,soma;
	printf("digite 4 numeros!\n");
	scanf("%i",&n1);
	scanf("%i",&n2);
	scanf("%i",&n3);
	scanf("%i",&n4);
	soma=n1+n2+n3+n4;
	printf("\n A soma dos numeros e igual a %i\n",soma);

	return(0);
}
