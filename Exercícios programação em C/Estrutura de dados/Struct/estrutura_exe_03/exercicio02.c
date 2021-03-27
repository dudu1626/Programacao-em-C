/* Exercicio 2 - Ponteiros e Alocação Dinâmica de Memória
	1. Fazer um programa em Linguagem C que criem uma estrutura de dados voo(struct voo) para a empresa VOEBEM,
	 que servirá para implementar funções para controle da lista dos voos. 
	 A estrutura voo deve ser implementada de forma dinâmica e deve conter os seguintes dados:
 	
	número do voo;
 	data do voo;
 	horário do voo;
 	aeroporto de Saída;
 	aeroporto de Chegada;
 	rota;
 	tempo estimado de voo;
 	passageiros a bordo;

	2. Implementar a função cadastrarVoo() que deve permitir o cadastro de um novo voo;
	
	3. Implementar a função consultaVoo() que deve permitir obter as informações do voo com base na digitação
	 do número do voo;
	
	4. Implementar a função removeVoo() que permita a exclusão de um determinado voo.


	5. Fazer um programa em Linguagem C que implemente a estrutura passagem (struct passagem) para a empresa VOEBEM 
	que servirá para implementar funções para controle
	da lista de passagens aéreas vendidas. A estrutura passagem deve ser implementada de forma dinâmica e deve conter
	 os seguintes dados:
 	
	 número da Passagem;
 	número do Voo;
 	data Embarque;
 	horário de Embarque;
 	portão de Embarque.

	6. Implementar a função cadastrarPassagem() que deve permitir o cadastro de uma nova passagem;
	
	7. Implementar a função consultaPassagem() que deve permitir obter informações sobre a passagem com base na digitação
	 do número da passagem. */
	 
/*
 ============================================================================
 Name        : Estrutura de Dados.c
 Grupo       : Eduardo Ferreira,
 Description : Exercicio 02
 ============================================================================ */
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variáveis globais
int i,n;

// estruturas obrigatórias voo (construção interna minha)
// elas terão que ser implementadas dinamicamente
typedef struct voo {
char numero_voo[10];
 	int dia_voo, hora_voo;
	char mes_voo[10];
 	char aeroporto_saida[30], aeroporto_chegada[30], rota[30];
 	int tempo_voo, passageiros;
}voo;

/*struct passagem { 
	int numero_Passagem;
 	char numero_Voo[10];
 	struct data_Embarque{
 		int dia, mes, ano;
	 };
 	struct horario_Embarque{
 		int horas, minutos;
	 };
 	char portao_Embarque[10];
}; */


// funções obrigatórias :
//consultaVoo(numero_voo); achar o cadastro com o numero do voo
//removeVoo(numero_voo); remover um voo 
//cadastrarPassagem();
//consultaPassagem(numero_passagem);

void cadastrarVoo(voo *pVoo);
void consultaVoo(voo *pVoo);

int main() {

	struct voo *pVoo;
	int op;
	
	puts("\tVOEBEM Aero Linhas S/A");
	
	puts("Digite um número para a opcao desejada!");
	puts("\t 1. Cadastrar novos Voos");
	puts("\t 2. Consultar Voos");
	puts("\t 3. Remover Voos");
	
	scanf("%d", &op);
	
	switch(op){
	case 1: 
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
	break;
	case 2:
		consultaVoo(&pVoo);
	break;
	case 3: //removeVoo(numero_voo);
	break;
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

void consultaVoo(voo *pVoo){
	
	char busca[10];
	
	scanf("%s", &busca);
	
    for (i=0; i<n; i++)
        if (strcmp(busca,pVoo[i].numero_voo)==0){
		    printf("%s",pVoo[i].numero_voo);
			printf("%d",pVoo[i].dia_voo);
			printf("%d",pVoo[i].mes_voo);
			printf("%i",pVoo[i].hora_voo);
 			printf("%s",pVoo[i].aeroporto_saida);
 			printf("%s",pVoo[i].aeroporto_chegada);
 			printf("%s",pVoo[i].rota);
 			printf("%i",pVoo[i].tempo_voo);
 			printf("%i",pVoo[i].passageiros);
		}
		printf("Voo nao encontrado!");
   
}
