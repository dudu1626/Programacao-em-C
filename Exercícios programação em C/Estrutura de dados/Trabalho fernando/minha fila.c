#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 100


struct fila {
    int ini, fim;  
    float vet[N]; 
};
typedef struct fila Fila;

Fila* f;

Fila* cria (void);              
void insere (Fila* f, float v);  
float retira (Fila* f);             
int vazia (Fila* f);                
void libera (Fila* f);            

Fila* cria (void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));  
    f->ini = f->fim = 0;                                 
    return f;
}

void insere (Fila* f, float v) {
    if (incr(f->fim) == f->ini) {
        printf("A Fila está cheia. Nao e possivel inserir mais elementos.\n");
        exit(1);    
    }

    f->vet[f->fim] = v;          
    f->fim = incr(f->fim);       
}

float retira (Fila* f) {
    float v;
    if (vazia(f)) {
        printf("A Fila esta vazia.\n");
        exit(1);     
    }

    v = f->vet[f->ini];  
    f->ini = incr(f->ini); 
    return v;                  
}

int vazia (Fila* f) {
    return (f->ini == f->fim);  
}

void libera (Fila* f) {
    free(f);
}

int main (void){
	int opcao,i;
	float elemento, aux;
		
	f=cria();
	
	 do
    {
        system ("cls");
        
        printf("\n Programa CPF em fila \n");
		printf(" ============================ \n\n");
		printf(" ______________________________\n");
		printf("| Escolha uma opcao abaixo     |\n");
		printf("|------------------------------|\n");
		printf("| 1 - Inserir novo CPF         |\n");
		printf("| 2 - Remover CPF              |\n");
		printf("| 3 - Imprimir CPFs            |\n");
		printf("| 4 - SAIR                     |\n");
		printf("|______________________________|\n");
		
		printf("\n->");
	
        scanf("%d", &opcao);

        if(opcao ==1)
        {
            printf("\nDigite o CPF a ser inserido na Fila : ");
            scanf("%f", &elemento);
            insere (f,elemento);
        }

        if (opcao ==2)
        {
            aux=retira (f);
            printf("\nO CPF %d foi removido", aux);
        }
        
        if (opcao ==3)
        	for(i=0;i=N;i++)
        		printf ("CPF:%i",f->vet[i] );
    }
    while (opcao !=4);
    return 0;
}


