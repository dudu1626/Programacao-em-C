#include <stdio.h>
#include <stdlib.h>

char *concatena( char cabeca[], char cauda[] );

int main()
{
    char nome[80] = "Santos";
    char sobrenome[] = " Dumont";
    printf( "O nome é %s.\n",concatena( nome, sobrenome ) );
    return 0;
}

char *concatena( char cabeca[], char cauda[] ){

    int i, j;

    for (i = 0; cabeca[i] != '\0'; i++);
        for (j = 0;(cabeca[i] = cauda[j]) != '\0';i++, j++);
            cabeca[i] = '\0';

    return cabeca;
}
