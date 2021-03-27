/*
 ============================================================================
 Name        : exercicio_condicional03.c
 Author      : Eduardo Ferreira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	float salario, aumento;
	printf("Digite o salário do empregado\n" );
	scanf("%f",&salario);

	if (salario<=300)
		{aumento = salario * 1.5;}
			if ((salario>300)&&(salario<=500))
				{aumento = salario * 1.4;}
					if ((salario>500)&&(salario<=700))
						{aumento = salario * 1.3;}
							if ((salario>700)&&(salario<=800))
								{aumento = salario * 1.2;}
									if ((salario>800)&&(salario<=1000))
										{aumento = salario * 1.1;}
											if (salario>1000)
												{aumento = salario * 1.05;}

	printf ("o salario com aumento sera de %f", aumento);

// não estava dando certo sem as chaves depois do if
// não foi usado switch porque só aceita inteiros como parâmetro
	return EXIT_SUCCESS;
}
