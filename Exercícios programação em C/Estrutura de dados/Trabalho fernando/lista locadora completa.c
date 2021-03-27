#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct carro{
	int ano;
	char modelo[30];
	char cor[30];
	char placa[10];
};

struct no{
	int chave;
	struct carro car;
	struct no *prox;
};

typedef struct no lista;

lista *inicio=NULL, *final=NULL, *aux, *l;

lista* cria(void);
int listaVazia (lista*l);
lista* cadastro();
lista* remover(lista*l, int chave);
lista* imprimeLista (lista* l);
lista* consulta (lista*l, int chave);

int main(void) {

	int opcao, chave;
	l = cria();

	do {
		system("cls");
		printf("\n\t Locadora UNICAR \n");
		printf(" ============================ \n\n");
		printf(" ______________________________\n");
		printf("| Escolha uma opcao abaixo     |\n");
		printf("|------------------------------|\n");
		printf("| 1 - Cadastrar novo Veiculo   |\n");
		printf("| 2 - Consultar Veiculos       |\n");
		printf("| 3 - Remover Veiculo          |\n");
		printf("| 4 - Imprimir toda a lista de |\n"
		       "|     Veiculos                 |\n");
		printf("| 0 - Sair                     |\n");
		printf("|______________________________|\n");
		
		printf("\n->");
		scanf("%i", &opcao);
	
		switch (opcao){
			case 1:
				l=cadastro();
			break;
			
			case 2:
				printf("\nDigite a chave que deseja consultar:");
				scanf("%d",&chave);
				consulta (l,chave);
				
			break;
			
			case 3:
				printf("\nDigite a chave que deseja Remover:");
				scanf("%d",&chave);
				l=remover(l,chave);
			break;
			
			case 4:
				imprimeLista (l);
			break;
			
			case 0:
				opcao=-1;
			break;
			
			default:
				printf("\n\nOpcao nao encontrada.\nTente Novamente\n\n");
				system("pause");
				system("cls");
			break;
		} // fim switch
	
	}while (opcao!=-1);

system ("PAUSE");
return 0;
}


//funções: 

lista* cria(void){
	return NULL;
}
int listaVazia (lista*l){
	if(l==NULL)
		return 1;
	else
		return 0;
}
lista* cadastro(){
	int x;
	
	printf("Digite o numero da chave:\n");
	scanf("%i",&x);
	
	aux = (lista*) malloc (sizeof(lista));
	aux->chave = x;
	aux->prox = NULL;
	
	printf("digite o ano:");
	scanf("%d", &aux->car.ano);
	printf("digite o modelo:");
	scanf("%s", aux->car.modelo);
	printf("digite a cor:");
	scanf("%s", aux->car.cor);
	printf("digite o placa:");
	scanf("%s", aux->car.placa);
	
	if (inicio == NULL)
		inicio = final = aux;
	else{
		final->prox = aux;
		final = aux;
	}
	return inicio;
}

lista* remover(lista*l, int chave){
	lista* ant = NULL;
	aux = l;
	if (!listaVazia(l)){
		while(aux!=NULL && aux->chave!=chave){
			ant=aux;
			aux=aux->prox;
		}
		if (aux == NULL)
			return l;
		
		if(ant == NULL)
			l = aux->prox;
		else
			ant->prox=aux->prox;
		
		free(aux);
		printf("veiculo removido\n");
		system("PAUSE");
		return l;
		
	}else printf("veiculo não foi removido\n");
	system ("PAUSE");

}

lista* consulta (lista*l, int chave){

	if(!listaVazia(l)){
		for(aux=l;aux!=NULL;aux=aux->prox){
			if(aux->chave==chave){
				printf("Veiculo procurado encontrado\n");
				printf("Ano %d\n"
				   "Modelo %s\n"
				   "Cor %s\n"
				   "Placa %s",aux->car.ano,aux->car.modelo, aux->car.cor, aux->car.placa);
				system("PAUSE");
				return aux;
			}
		}
		return NULL;
	}
	else {
		printf("\n Nao ha veiculos cadastrados\n");
		system ("PAUSE");
		return NULL;
	}
	
	
}

lista* imprimeLista (lista* l){
	if (!listaVazia(l)){
		lista* aux;
		for (aux=l;aux!=NULL;aux=aux->prox)
			printf("Veículo procurado:\n"
				   "Ano %d\n"
				   "Modelo %s\n"
				   "Cor %s\n"
				   "Placa %s",aux->car.ano,aux->car.modelo, aux->car.cor, aux->car.placa);
	}else
		printf(" Nao ha veiculos cadastrados\n");
		system("PAUSE");
	
}
