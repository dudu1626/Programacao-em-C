// Pesquisa desordenada com repetição ( Sequencial Simples )

#include <stdio.h>
#include <stdlib.h>
#define totelem 5

int main(void){
	
	int i, j, elemproc,c, vet[totelem];
	int vet_ocorrencia[totelem] = {8,6,7,6,4};
	
	for (c = 0; c<totelem; c++){
		vet[totelem]=0;
	}
	
	i=j=0;
	
	printf(" Digite um numero para ser procurado!\n");
	
	scanf("%d", &elemproc);
	
	while(j <= totelem){
        
		if (vet[j] == elemproc){
              
			  vet_ocorrencia[i] = vet[j];
               
			   i++;
        }
        j++;
	}
	
	for(c = 0; c<totelem; c++){
		printf("Elemento encontrado %d \n", vet_ocorrencia[c]);
    }
   	
return 0;	
}
