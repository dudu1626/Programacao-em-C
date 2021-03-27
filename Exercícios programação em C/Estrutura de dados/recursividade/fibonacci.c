/*
 ============================================================================
 Name        : recursividade 01.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : fibonacci (mostrar o valor na posição)
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n);

int main(void) {

int n;

printf ("escreva a posicao desejada na sequencia de Fibonacci\n");

scanf("%i",&n);

printf ("O valor na sequencia na posicao %i eh %i\n",n,fibonacci(n));

system ("PAUSE");
return 0;
}

int fibonacci (int n){
	
	if(n==1) return 0;
	
	if(n==2) return 1;
	
	if(n>2) return (fibonacci(n-1) + fibonacci(n-2));
	
	}
