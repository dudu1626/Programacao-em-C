#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct contatos{
    int telefone;
	char nome[80];
    char email[80];
    struct contatos *prox;
};

typedef struct contatos agenda;    

agenda *inicio=NULL, *final=NULL, *aux, *A;

agenda* cria(void);
int listaVazia (agenda*A);
agenda* cadastro();
agenda* remover(agenda*A, int tel);
agenda* imprimeLista (agenda*A);
agenda* consulta (agenda*A, int tel);

int main(void) {
	int opcao;
	unsigned int tel;

	A = cria();

	do {
		system("cls");
		printf(" ****************************** \n");
		printf("\n\t Agenda Eletronica \n");
		printf(" ****************************** \n\n");
		printf(" ______________________________\n");
		printf("| Escolha uma opcao abaixo     |\n");
		printf("|------------------------------|\n");
		printf("| 1 - Cadastrar novo contato   |\n");
		printf("| 2 - Consultar contato        |\n");
		printf("| 3 - Remover contato          |\n");
		printf("| 4 - Listar contatos          |\n");
		printf("| 0 - Sair                     |\n");
		printf("|______________________________|\n");
		
		printf("\n->");
		scanf("%i", &opcao);
	
		switch (opcao){
			case 1:
				A=cadastro();
			break;
			
			case 2:
				printf("\nDigite o telefone que deseja consultar (sem traco):");
				scanf("%i",&tel);
				consulta (A,tel);
				
			break;
			
			case 3:
				printf("\nDigite o contato que deseja remover");
				printf("\nDigite o telefone:");
				scanf("%i",&tel);
				A=remover(A,tel);
			break;
			
			case 4:
				imprimeLista (A);
			break;
			
			case 0:
				opcao=-1;
			break;
			
			default:
				printf("\n\nOpcao nao encontrada.\nTente Novamente\n\n");
				system("pause");
				system("cls");
			break;
		}
	
	}while (opcao!=-1);

system ("PAUSE");
return 0;
}

agenda* cria(void){
	return NULL;
}
int listaVazia (agenda*A){
	if(A==NULL)
		return 1;
	else
		return 0;
}
agenda* cadastro(){
	unsigned int x;
	
	printf("Digite o numero do telefone:\n");
	scanf("%i",&x);
	
	aux = (agenda*)malloc(sizeof(agenda));
	aux->telefone = x;
	aux->prox = NULL;
	
	printf("digite o nome:");
	scanf("%s", aux->nome);
	printf("digite o email:");
	scanf("%s", aux->email);
	
	if (inicio == NULL)
		inicio = final = aux;
	else{
		final->prox = aux;
		final = aux;
	}
	return inicio;
}

agenda* remover(agenda*A, int tel){
	agenda* ant = NULL;
	aux = A;
	if (!listaVazia(A)){
		while(aux!=NULL && aux->telefone!=tel){
			ant=aux;
			aux=aux->prox;
		}
		if (aux == NULL)
			return A;
		
		if(ant == NULL)
			A = aux->prox;
		else
			ant->prox=aux->prox;
		
		free(aux);
		printf("Contato removido\n");
		system("PAUSE");
		return A;
		
	}else printf("Contato não foi removido, lista vazia\n");
	system ("PAUSE");
	
}

agenda* consulta (agenda*A, int tel){

	if(!listaVazia(A)){
		for(aux=A; aux!=NULL; aux=aux->telefone){
			if(aux->telefone==tel){
				printf("Contato procurado encontrado!\n");
				printf("Nome %s\n"
				       "Telefone %i\n"
				       "email %s\n",aux->nome,aux->telefone, aux->email);
				system("PAUSE");
				return aux;
			}
		}
		return NULL;
	}
	else {
		printf("\n Nao ha contatos cadastrados\n");
		system ("PAUSE");
		return NULL;
	}
	
	
}

agenda* imprimeLista (agenda* A){
	if (!listaVazia(A)){
		agenda* aux;
		for (aux=A;aux!=NULL;aux=aux->prox)
			printf("Contato procurado:\n");
			printf("Nome %s\n"
				    "Telefone %i\n"
				    "email %s\n",aux->nome,aux->telefone, aux->email);
	}else
		printf(" Nao ha contatos cadastrados\n");
		system("PAUSE");
	
}
