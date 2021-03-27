/*
 ============================================================================
 Name        : XXXX.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


int main(void) {
setlocale (LC_ALL,"Portuguese"); // necessário para usar acentuação

 int a=0;
    printf("IMPRIMINDO TABELA ASCII\n");
    
	for(a=0;a<=255;a++)
    printf("Decimal: %i   Octal: %o   Hexadecimal: %x   Caractere: %c \n",a,a,a,a);
    //Obs: %i imprime iteiro, %o imprime octal, %x imprime Hexadecimal, %c imprime caractere char
    
	printf("\n\t\tFIM\n\n");


system ("PAUSE");
return 0;
}

