/*
 ============================================================================
 Name        : Variável local estática.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : a variaveis locais (estatica e automatica) em funçoes
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    void teste (void); //declaração local de função

    teste();
    teste();
    teste();


    return 0;
}

void teste (void){

    int variavelLocalautomatica = 2;
    static int variavelLocalEstatica = 2; // variável estática

    variavelLocalautomatica *= 2; //multiplica a variável por 2

    variavelLocalEstatica *= 2; //multiplica a variável por 2

    printf("Variavel automatica = %d\n",variavelLocalautomatica);

    printf("Variavel estatica = %d\n",variavelLocalEstatica);

}
