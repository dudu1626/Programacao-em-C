#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct voo {
	int numvoo;
	int datavoo;
	int horario;
	char saida[40];
	char chegada[40];
	char rota[60];
	int passabordo;
};

void menu();
void consultar();
void cadastro();
void selecao();
void remover();

struct voo *inf;

int main(void) {
	menu();
	system("pause"); //isso aq nao pode ficar depois do return pq o return e finalizado
	return 0;
}

void menu() {

printf("\n Empresa VOEBEM \n");
printf(" ============================ \n\n");
printf(" ____________________________\n");
printf("| Escolha uma opcao abaixo |\n");
printf("|--------------------------|\n");
printf("| 1 - Cadastrar Passagem   |\n");
printf("| 2 - Consultar Passagem   |\n");
printf("| 3 - Remover              |\n");
printf("| 0 - Sair                 |\n");
printf("|__________________________|\n... ");

selecao();

} //fim menu

void selecao(){
	int opcao;

	printf("\nDigite uma das opcoes: ");
	scanf("%i", &opcao);

	switch (opcao){
		case 1:
			cadastro();
			menu();
		break;
		
		case 2:
			consultar();
			menu();
		break;
		
		case 3:
			remover();
			menu();
		break;
		
		case 0:
			system("pause");
			exit(0);
		break;
		
		default:
		printf("\n\nOpcao nao encontrada.\nTente Novamente\n\n");
		system("pause");
		system("cls");
		menu();
		break;
	} // fim switch
} // fim função

//FUNÇÃO CADASTRAR

void cadastro(){
	int num;
	do{
		inf = (struct voo *) malloc(sizeof(struct voo));
		printf("\n\n*****CADASTRO DE VOO*****\n");
		printf("\nNumero do voo: ");
		scanf("%d", &inf->numvoo);
		fflush(stdin);
		printf("\nData do voo: ");
		scanf("%d", &inf->datavoo);
		printf("\nHorario do voo: ");
		scanf("%d", &inf->horario);
		printf("\nAeroporto de saida: ");
		fflush(stdin);
		gets(inf->saida);
		printf("\nAeroporto de chegada: ");
		fflush(stdin);
		gets(inf->chegada);
		printf("\nRota do voo: ");
		fflush(stdin);
		gets(inf->rota);
		printf("\nPassageiros a bordo: ");
		fflush(stdin);
		scanf("%d", &inf->passabordo);
		
		printf(" ______________________________\n");
		printf("| Escolha uma opcao abaixo     |\n");
		printf("|------------------------------|\n");
		printf("| 1 - Cadastrar outra Passagem |\n");
		printf("| 0 - Voltar ao menu           |\n");
		printf("|______________________________|\n");
		
		printf("Opcao: ");
		scanf("%d",&num);

	}
	while(num!=0);
system("cls");
}

void remover(){

free(inf); //aq nao deve colocar * do ponteiro

menu();

}

//FUNÇÃO CONSULTAR

void consultar(){

	system("cls");
	int consult;
	printf("Digite o numero do voo: ");
	scanf("%d", &consult);
	
	if(inf->numvoo!=consult){
		printf("Numero nao encontrado\n");
		printf("Tente Novamente");
		getch();
		system("cls");
		consultar();
	}else{
	
	printf("\n-----------------------------\n");
	printf("\nNumero do voo encontrado");
	printf("\nNumero do Voo: %d ", inf->numvoo);
	printf("\n\nData do voo: %d ", inf->datavoo);
	printf("\nHorario do voo: %d", inf->horario);
	printf("\nAeroporto de saida: %s ", &inf->saida);
	printf("\nAeroporto de chegada: %s", &inf->chegada);
	printf("\nRota: %s", &inf->rota);
	printf("\nPassageiros a bordo: %d", inf->passabordo);
	getch();
	system("cls");
	menu();
	}
} //faltaram umas chaves

