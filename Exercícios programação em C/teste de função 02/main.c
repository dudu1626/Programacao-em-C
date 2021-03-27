#include <stdio.h>
#include <stdlib.h>

void troca (int *px, int *py); // troca dos valores nos endereços

int main()
{
    int x = 10, y = 20;
    printf("Antes da troca x=%d e y=%d\n", x, y);
    troca(&x, &y);
    printf("Depois da troca x=%d e y=%d", x, y);
    return 0;
}

void troca(int *px, int *py){

    int temp;
    temp=*px;
    *px=*py;
    *py=temp;

}
