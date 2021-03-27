// algoritmo de ordenação

#include <stdio.h>
#include <stdlib.h>

#define tamanho 10
int main (){

    int vetor[] = {50, 80, 2, 10, 8, 79, 88, 7, 88, 2};
    int aux, i, j;

    for( i=0; i<tamanho-1; i++ ){
            for( j=i+1; j<10; j++ ){
                if( vetor[i] > vetor[j] ){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
    }

    for (i=0;i<tamanho;i++){
        printf("%d, ",vetor[i]);
    }
    return 0;
}
