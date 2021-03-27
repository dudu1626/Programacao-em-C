// Pesquisa ordenada sem repetição

#include <stdio.h>
#include <stdlib.h>
#define totelem 5

int main(void){
	
	int pos, j, elemproc,c;
	int vet[totelem] = {15,35,67,89,150};
	
	pos=j=0;
	
	printf(" Digite um numero para ser procurado!\n");
	
	scanf("%d", &elemproc);
		
	    while((j<=totelem) && (pos == 0)){

        	if(vet[j] <= elemproc){

                    if(vet[j] == elemproc)
						pos=j;

                    else       
						j++;

           	}else{
                printf(" O elemento não está na lista\n");
                break;   
			}
	}
	
		
return 0;	
}
