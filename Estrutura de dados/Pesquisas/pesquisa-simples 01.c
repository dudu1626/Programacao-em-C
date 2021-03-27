// algoritmo de pesquisa simples não ordenada

#include <stdio.h>
#include <stdlib.h>

int main (){

    int i, maior, menor;
    int vetor[] = {50, 80, 30, 10, 8, 79, 88, 7, 105, 2};
    maior =-1;
    menor =100000;


    for (i=0;i<10;i++){ // pq está fixo o vetor, poderia criar um contador

        if (vetor[i]<menor)
            menor = vetor[i];
        if (vetor[i]>maior)
            maior = vetor[i];

    }

    printf( " o maior valor eh igual a: %i\n", maior);
    printf( " o menor valor eh igual a: %i\n", menor);

return 0;
}
