/*
 ============================================================================
 Name        : Vari�vel local est�tica.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : a variaveis locais (estatica e automatica) em fun�oes
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    void teste (void); //declara��o local de fun��o

    teste();
    teste();
    teste();


    return 0;
}

void teste (void){

    int variavelLocalautomatica = 2;
    static int variavelLocalEstatica = 2; // vari�vel est�tica

    variavelLocalautomatica *= 2; //multiplica a vari�vel por 2

    variavelLocalEstatica *= 2; //multiplica a vari�vel por 2

    printf("Variavel automatica = %d\n",variavelLocalautomatica);

    printf("Variavel estatica = %d\n",variavelLocalEstatica);

}
