#include <stdio.h>
#include <stdlib.h>

void loop_count( int *i ); // função incremento

int main(){

    int i = 2;
    loop_count( &i );
    printf( "\nEm main, i = %d.\n", i );

    return 0;
}

void loop_count(int *i){
    printf(" Em loop_count, i = ");
    while (*i<10)
        printf( "%d.", (*i)++);

}
