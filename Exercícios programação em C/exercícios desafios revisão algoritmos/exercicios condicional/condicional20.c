/*
 ============================================================================
 Name        : exercício_condicional04.c
 Author      : Eduardo Ferreira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int idade;

	printf ("Digite a idade do nadador\n");
	scanf ("%i",&idade);
	if ((idade>=5)&&(idade<=7)){ printf ("infantil\n");}
		if((idade>=8)&&(idade<=10)){ printf ("juvenil\n");}
			if((idade>=11)&&(idade<=15)){ printf ("adolescente\n");}
				if((idade>=16)&&(idade<=30)){ printf ("adulto\n");}
					if(idade>30){ printf ("senior\n");}

	return EXIT_SUCCESS;
}
