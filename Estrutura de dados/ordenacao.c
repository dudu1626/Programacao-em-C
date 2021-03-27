/* Eduardo Ferreira RA: 5012699818
   Paulo Sérgio RA: 5012664285 */

#include <stdio.h>
#include <stdlib.h>

#define tam 5

int main (void){
	float v[tam], aux;
	int i, j;
	
	aux=0;
	
	for(i=0;i<tam;i++){
		printf ( "\nDigite um numero para a posicao %i\n", i);
		scanf ("%f", &v[i]);
	}
	
	printf ( "A sequencia ordenada e igua a:\n");
	
	for(i=0;i<tam-1;i++){
		for(j=i+1;j<tam;j++){
			if(v[i]>v[j]){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	
		for(i=0;i<tam;i++){
			printf ( "%.2f\n", v[i]);
		}
	
	return 0;
}
