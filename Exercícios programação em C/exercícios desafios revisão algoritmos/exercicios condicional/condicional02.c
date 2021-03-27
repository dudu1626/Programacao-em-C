/*
 ============================================================================
 Name        : exercicio02.c
 Author      : Eduardo Ferreira
 Ra          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float nota1,nota2,nota3,media,exame;
	printf("\t\n digite suas 3 notas\n");
	scanf("%f %f %f",&nota1, &nota2, &nota3);
	
	media=(nota1+nota2+nota3)/3;
	
	if ((10>=media)&&(media>=7))
	{
		printf("\t\n Aprovado!\n");
	}
	if ((7>media)&&(media>=3))
	{
		printf("\t\n Exame!\n");
		exame=12-media;
		printf ("A nota para o exame deverá ser maior que %.2f para ser aprovado", exame);
	}
	if ((3>media)&&(media>=0))
	{
		printf("\t\n Reprovado\n");
	}
	
	return 0;


}
