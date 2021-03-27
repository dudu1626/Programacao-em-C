#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Fun��o para c�lculo da m�dia */
/* Objetivo: Calcula a m�dia aritm�tica para um conjunto de notas */
/* Parametros: int n - Tamanho do vetor e float *v - Endereco do primeiro elemento do vetor de notas */
/* Valor de Retorno: float - Retorna a m�dia aritm�tica calculada */

float media(int n, float *v) {
    int i;
    float s = 0.0f;
    for(i=0; i<n; i++)
        s += v[i];
    return s/n;
}

/* fun��o para c�lculo da vari�ncia */
/* Objetivo: Calcula da Variancia para um conjunto de notas */
/* Parametros: int n - Tamanho do vetor e float *v - Endereco do primeiro elemento do vetor de notas */
/* Valor de Retorno: float - Retorna a variancia calculada */

float variancia(int n, float *v, float m) {
    int i;
    float s = 0.0f;
    for(i=0; i<n; i++)
        s += (v[i] - m) * (v[i] - m);
    return s/n;
}

int main() {

    int i, n;
    float *v;
    float med, var;

    printf("Quantas notas ser�o lidas?: ");
    scanf("%i",&n);

    /*aloca��o din�mica*/
    v = (float*) malloc (n*sizeof(float));

    /* tratamento de erro para aloca��o dinamica de memoria mal sucedida */
    if(v == NULL) {
        printf("Mem�ria Insuficiente");
        return 1;
    }

    /*leitura dos valores*/
    for(i=0; i<n; i++) {
        printf("Entre com a nota %i: ",i);
        scanf("%f", &v[i]);
    }

   /* Calculo da media e da variancia */
    med = media(n,v);
    var = variancia(n,v,med);

    /* Impressao do resultado */
    printf("Media: %.2f Variancia: %.2f \n", med, var);
    getche();

    /*libera mem�ria*/
    free(v);
    return 0;
}
