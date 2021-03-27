// Pesquisa desordenada sem repetição ( Sequencial Simples )

#include <stdio.h>
#include <stdlib.h>
#define totelem 5

int main(void){
	
	int pos, j, elemproc;
	int vet[totelem]= {8,9,7,5,2};
	
	pos=j=0;
		
	printf(" Digite um numero para ser procurado!\n");
	
	scanf("%d", &elemproc);
	
	while((pos==0) && (j<=totelem)){
		if( vet[j]==elemproc){
			pos = j;
			j = totelem + 1;
		}
    	else{
    		j++;
		}
				
	}
	
	if (pos != 0)
		printf("O elemento esta na posicao %d \n", pos);
	else
    	printf("O elemento nao foi encontrado\n");
   
	return 0;
}
