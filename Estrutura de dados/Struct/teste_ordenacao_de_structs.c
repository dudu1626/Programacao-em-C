#include <stdio.h>
#include <stdlib.h>


struct aluno{
        int mat;
        char nome[30];
        float n1,n2;
};

void ordenacao_por_insercao_structs(struct aluno *v, int n){
    int i, j;
    struct aluno aux;

    for(i=0; i<n; i++){
        aux=v[i];
        for(j=i; (j>0) && (aux.mat<v[j-1].mat); j--)
            v[j]=v[j-1];
        v[j]=aux;
    }

}

int main (){

    int i;
    struct aluno v[3] = {{2, "andre", 9.5, 7.8},
                         {3, "carlos", 8.7, 9.1},
                         {1, "ze", 7.5,7.5}
                         }; // vetor com 3 alunos;;

    ordenacao_por_insercao_structs(v, 3);

    for(i=0; i<3;i++){
        printf("%d %s\n", v[i].mat, v[i].nome);
    }

return 0;
}
