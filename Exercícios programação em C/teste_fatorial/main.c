/*
 ============================================================================
 Name        : teste fatorial.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : teste
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resposta=1, fatorial;

    printf("digite um numero para o calculo:\n");

    scanf("%d",&fatorial);

    if ( fatorial !=0){
       for ( ;fatorial>0;--fatorial){
            resposta *= fatorial;
        }
    }

    printf("O fatorial e' igual a %d", resposta);

    return 0;
}
