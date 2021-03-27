/*
 ============================================================================
 Name        : estrutura_exe_02.c
 Grupo       : Eduardo Ferreira, Caroline e Edvar
 Description : exercício 02
 ============================================================================

 Agora faça os exercícios abaixo onde cada programa deve executar os seguintes passos:

1 - Declarar o tipo abstrato de dados;
2 - Criar uma variável do tipo abstrato de dados;
3 - Ler os dados do teclado e preencher os campos da variável;
4 - Exibir na tela os campos preenchidos da variável do tipo abstrato de dados.

 Construir um programa em Linguagem C que implemente uma estrutura pedido( struct pedido ), permitindo o cadastro e exibição
  com os seguintes campos:

Pedido
        nome-cliente
 telefone
 endereco       ( deve ser declarado um tipo abstrato para endereco )
     logradouro
     numero
     bairro
     complemento
itens[10] ( Item deve ser declarado um tipo abstrato para item contendo os campos sabor,
tamanho e quantidade )
     sabor
     tamanho
     quantidade
pagamento ( deve ser declarado um tipo abstrato para pagamento contendo os campos forma
de pagamento e valor do pedido )
     forma de pagamento
    valor-pedido

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i, qtd;

	struct pedido {
		char nome[50];
		unsigned long int telefone;
		struct endereco {
			char logradouro[80], bairro[20], complemento[20];
			unsigned int numero;
		}add;
		struct itens {
			char sabor[50];
			unsigned int tamanho, quantidade;
		}its[10];

		struct pagamento {
			char formapgto[50];
			unsigned int valor;
		}pgto;

	}P;

	puts ("Cadastro de Pedidos");

	puts ("Escreva seu nome ____________:");
	gets(P.nome);
	//getchar();

	puts ("Escreva seu endereco:");
	puts ("Rua _________________________:");
	scanf("%s",P.add.logradouro);
	getchar();

	puts ("Numero ______________________:");
	scanf("%d", &P.add.numero);
	getchar();

	puts ("complemento _________________:");
//	scanf("%s",P.add.complemento);
//	getchar();
	gets (P.add.complemento);

	puts ("bairro ______________________:");
	scanf("%s",P.add.bairro);
	getchar();

	puts ("Escolha quantos itens _______:");
	scanf("%d", &qtd);


 	for(i=0;i<qtd;i++){
	 	puts ("Escreva o sabor desejado_____:");
		scanf("%s", P.its[i].sabor);
		puts ("Escreva o comprimento desejado___:");
		scanf("%d",&P.its[i].tamanho);
		puts ("Escreva a quantidade desejada:");
		scanf("%d", &P.its[i].quantidade);
	}


	puts ("Escreva a forma de pagamento_:");
	scanf("%s", P.pgto.formapgto);
	getchar();

	puts ("Escreva o valor total________:");
	scanf("%d", &P.pgto.valor);
	getchar();

	puts ("\n\nCadastro Realizado com sucesso!\n");
	printf ("Nome: %s\n",P.nome);
	printf ("Rua: %s\n",P.add.logradouro);
	printf ("Complemento: %s\n", P.add.complemento);
	printf ("Numero %d\n", P.add.numero);
	printf ("Bairro: %s\n",P.add.bairro);
	
	for(i=0;i<qtd;i++){
		printf("Sabor: %s\n", P.its[i].sabor);
		printf("Tamanho: %d\n", P.its[i].tamanho);
		printf("Quantidade: %d\n", P.its[i].quantidade);
	}

	printf("Forma de pagamento : %s", P.pgto.formapgto);
	printf("Valor total: %d\n", P.pgto.valor);


	puts("Muito Obrigado!");

	return 0;
	}
