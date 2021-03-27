// algoritmo de pesquisa simples não ordenada com mais de um valor

#include <stdio.h>
#include <stdlib.h>

int main (){

    int i,j=0, k=0, auxmaior, auxmenor;
    int vetor[] = {50, 80, 2, 10, 8, 79, 88, 7, 88, 2};

    auxmaior = -1;
    auxmenor = 1000000;


    for (i=0;i<10;i++){ // pq está fixo o vetor, poderia criar um contador

        if (vetor[i]<auxmenor){
            auxmenor = vetor[i];
        }
        if (vetor[i]>auxmaior){
            auxmaior = vetor[i];
        }
    }

    for (i=0;i<10;i++){

        if (auxmenor == vetor[i])
            j++;
        if (auxmaior == vetor[i])
            k++;

    }

    printf( " o menor valor eh igual a: %i e aparece %i vezes\n", auxmenor,j);

    printf( " o maior valor eh igual a: %i e aparece %i vezes\n", auxmaior,k);


return 0;
}
