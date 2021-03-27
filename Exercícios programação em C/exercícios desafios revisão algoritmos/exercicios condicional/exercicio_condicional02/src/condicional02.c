/*
 ============================================================================
 Name        : teste02.c
 Author      : Eduardo Ferreira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float numero1,numero2,numero3,extra;
		printf("\t\n digite sua nota do trabalho de laboratorio!\n");
		scanf("%f",&notat);

		if ((10>=media)&&(media>=8))
		{
			printf("\t\n Seu conceito e A!\n");
		}
		if ((8>media)&&(media>=7))
		{
			printf("\t\n Seu conceito e B!\n");
		}
		if ((7>media)&&(media>=6))
		{
			printf("\t\n Seu conceito e C!\n");
		}
		if ((6>media)&&(media>=5))
		{
			printf("\t\n Seu conceito e D!\n");
		}
		if ((5>media)&&(media>=0))
		{
			printf("\t\n Seu conceito e E!\n");
		}

		printf ("\n\t sua media e %8.2f", media);

		return 0;
}
