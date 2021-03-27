// Pesquisa ordenada sem repetição

#include <stdio.h>
#include <stdlib.h>
#define totelem 5

int main(void){
	
	int i, j, elemproc,c, pos, vet_pesq[totelem];
	int vet[totelem] = {20,20,55,55,150};

    pos = j = i = 0;
    
    for (c = 0; c<totelem; c++){
		vet_pesq[c]=0;
	}
    
    printf(" Digite um numero para ser procurado!\n");
	
	scanf("%d", &elemproc);
    
	while((j<=totelem) && (pos == 0)){
		
		if(vet[j] <= elemproc){
			
			if(vet[j] == elemproc){
				i++;
				vet_pesq[i] = vet[j];
			}
			else
				j++;
		}
		else{
			printf(" O elemento não está na lista\n");
        	break;		
		}
	}
    
    for(c = 0; c<i-1; c++){
		printf("Elemento encontrado \n", vet_pesq[c]);
    }
	
	return 0;
}
