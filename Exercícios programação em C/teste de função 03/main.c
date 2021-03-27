#include <stdio.h>
#include <stdlib.h>

int power (int base, int n); // função potenciação

int main()
{
    int base, n;

    puts("Programa para potenciacao de um numero");

    printf("Digite a base do numero\n");
    scanf("%d", &base);

    printf("Digite o expoente do numero\n");
    scanf("%d", &n);

    printf("O resultado de %d elevado a %d eh igual a : %d", base,n,power (base, n));

    return 0;
}

int power (int base, int n){
    int i,p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p *= base;
    return p;
}
