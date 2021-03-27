/*
 ============================================================================
 Name        : malloc vs calloc.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : diferen�a entre malloc e calloc
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int i;
	int *p, *p1;
	
	p = (int *) malloc(5*sizeof(int)); // aloca espa�o de mem�ria 5x tamanho de inteiros
	if ( p==NULL)
		printf("ERRO! - Memoria insuficiente na aloca��o malloc.\n");
	
	p1 = (int*) calloc (5,sizeof(int)); // aloca espa�o de 5 inteiros de tamanho e completa com zero
	if ( p1==NULL)
		printf("ERRO! - Memoria insuficiente na aloca��o calloc.\n");
	
	
	printf("calloc \t\t malloc\n");
	for (i=0;i<5;i++)
		printf("p1[%d]=%d \t p[%d]=%d\n",i,p1[i],i,p[i]);


system ("PAUSE");
return 0;
}

