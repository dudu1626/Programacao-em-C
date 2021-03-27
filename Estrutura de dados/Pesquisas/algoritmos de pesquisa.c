// Pesquisa desordenada sem repetição ( Sequencial Simples )

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int totelem, pos, j, elemproc;
	int vet[5]= {8,9,7,5,2};
	
	totelem=pos=j=0;
		
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
		printf("O elemento esta na posicao ", pos);
	else
    	printf("O elemento nao foi encontrado");
   
	return 0;
}
