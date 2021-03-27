// algoritmo de pesquisa simples  ordenada

#include <stdio.h>
#include <stdlib.h>

int main (){

    int vetor[] = {2,7,5,15,24,35,68,79,88,90};
    int i=0, pos=0, aux;

    printf("\n digite um numero para buscar: ");
    scanf( "%d", &aux);

    do {

        if(vetor[i]<=aux){
            if (vetor[i]==aux){
                pos=i;
                printf( "\n numero encontrado na posicao %i", pos);
                }
                else i++;
            }
            else {
                printf( "\n numero nao encontrado");
                pos=-1;
                }
    } while ((i<10)&&(pos==0)); // 10 é o total de elementos no vetor

return 0;
}
