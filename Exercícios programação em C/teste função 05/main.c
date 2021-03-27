/* lenda do xadrez, o inventor pediu 1 grao de trigo para a primeira casa, 2 para a segunda, 4 para a terceira
e assim por diante, sempre dobrando o valor do anterior até a ultima casa */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Lenda do Inventor do Xadrez");

    long double i, soma=1;

    for(i=0;i<65;i++)
        soma = 2*soma+soma;

    printf("%lf", soma);

    return 0;
}
