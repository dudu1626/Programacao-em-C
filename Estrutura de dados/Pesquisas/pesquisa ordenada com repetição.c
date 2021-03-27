// algoritmo do professor

#include <stdio.h>
#include <stdlib.h>

#define TOTELEM 10
int main (){

    int I=0, J =0, POS=0, VET_PESQ[TOTELEM],K,ELEMPROC;
    int VET[TOTELEM]={2,7,7,15,24,35,35,79,88,90};

    puts("Digite o numero procurado:");
    scanf("%d", &ELEMPROC);

    /*Executa a Pesquisa da primeira ocorrência de ELEMPROC em VET e retorna em POS
    o índice onde foi encontrada ou 0 se não existe. VET tem de estar ordenado pelo campo chave*/

    while((J<TOTELEM) && (POS==0)){
        if (VET[J] <= ELEMPROC) {
            if (VET[J] = ELEMPROC) {
                I++;
                VET_PESQ[I] = VET[J];
            }else{
            J++;
            }
        }else{
            puts(" O elemento não está na lista");
            break;
        }
    }

    for(K=1; K<I; K++){
        printf("%d",VET_PESQ[K]);
    }

    return 0;
}
