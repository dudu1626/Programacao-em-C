/*
 ============================================================================
 Name        : teste alocação dinamica.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct voo {
	char numero_voo[10];
 	int dia_voo;
	char mes_voo[10];
 	int hora_voo;
 	char aeroporto_saida[30], aeroporto_chegada[30];
 	char rota[30];
 	int tempo_voo, passageiros;
}voo;

	int i;
	
void cadastrarVoo(voo *pVoo);


int main(void) {

	struct voo *pVoo;
	int n;
	
	puts("\tVOEBEM Aero Linhas S/A");
	
	puts("Digite o numero de Voos para cadastrar");
	scanf("%i",&n);
	
	pVoo = (struct voo *) calloc (n,sizeof(struct voo));
	if (pVoo==NULL){
		puts("\nErro de alocacao de memoria voo");
        exit(1);
    }
     	
	for (i=0;i<n;i++){
	cadastrarVoo(&pVoo[i]);
 	}

	free(pVoo);

	system ("PAUSE");
	return 0;
}


void cadastrarVoo(voo *pVoo){
	
	puts(" Escreva o numero do voo");
	scanf("%s",pVoo[i].numero_voo);
		
	puts ("Escreva a data do Voo");
	printf("Dia:");
	scanf("%d",&pVoo[i].dia_voo);
	printf("\nMes (mmm):");
	scanf("%d",&pVoo[i].mes_voo);
		
	puts("\nEscreva o horario do voo:");
	printf("Horas");
	scanf("%i",&pVoo[i].hora_voo);
 		
 	puts("\nEscreva o aeroporto de saida:");
 	scanf("%s",pVoo[i].aeroporto_saida);
 	
 	puts("Escreva o aeroporto de chegada:");
 	scanf("%s",pVoo[i].aeroporto_chegada);
 	
 	puts("Escreva a rota:");
 	scanf("%s",pVoo[i].rota);
 	
	puts("Escreva o tempo do voo:");
 	scanf("%i",&pVoo[i].tempo_voo);
 		
 	puts("Escreva o numero de passageiros a bordo:");
 	scanf("%i",&pVoo[i].passageiros);
		
}

