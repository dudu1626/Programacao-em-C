/*  Implementar um programa em linguagem C a intercalação de um arquivo de estoque com um arquivo de movimento
contendo as vendas e compras de produtos do estoque, gerando um novo arquivo de estoque a partir de um arquivo
 de movimento  de compra e venda de peças do estoque. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //acentuação
#include <string.h>

#define MAX 20

typedef struct Produto {
    int codigo;
    char descricao[30];
    int qtdEstq;
}produto;

struct Movimento {
    int codigo;
    int operacao; // 1 - Venda ou 2 - Compra
    int qtd;
};

FILE *arqEstoque, *arqMovimento, *arqNovoEstoque; // ponteiros para arquivo

// MAIN
int main() {
    setlocale (LC_ALL,"Portuguese"); // acentuação

    // abertura dos arquivos
    arqEstoque = fopen("ESTOQUE.txt", "r");
        if( arqEstoque == NULL ) {
            printf("\n Erro ao abrir o arquivo ESTOQUE");
            return(1);
        }

    arqMovimento = fopen("MOVIMENTO.txt", "r");
        if( arqMovimento == NULL ) {
            printf("\n Erro ao abrir o arquivo MOVIMENTO");
            return(1);
        }

    arqNovoEstoque = fopen("NOVOESTOQUE.txt", "w");
        if( arqNovoEstoque == NULL ) {
            printf("\n Erro ao abrir o arquivo NOVO ESTOQUE");
            return(1);
        }

    // variaveis
    produto estoque[MAX]; // vetor mestre e alteracoes
    struct Movimento movimento[10]; // vetor compras
    int opcao, i;

    for(i=0;i<MAX;i++){
        estoque[i] = fscanf(arqEstoque, "%d %s %d\n", &estoque->codigo, estoque->descricao, &estoque->qtdEstq);
    }

    do
    {
        system ("cls");

        printf("\n    Programa controle de papelaria \n");
		printf("    ===================================== \n\n");
		printf(" __________________________________________\n");
		printf("|          Escolha uma opcao abaixo        |\n");
		printf("|------------------------------------------|\n");
		printf("| 1 - Cadastrar Produto                    |\n");
		printf("| 2 - Cadastrar Movimentação (Compra/Venda)|\n");
		printf("| 3 - Atualizar Produtos (Intercalação)    |\n");
		printf("| 4 - Listar Produtos Atualizado           |\n");
		printf("| 5 - Sair                                 |\n");
		printf("|__________________________________________|\n");

		printf("\n->");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5: puts("Muito obrigado e volte sempre!!");
                    opcao = -1;
            break;
            default:puts("Opção digitada inválida");
            system("PAUSE");
        }
    } while (opcao !=-1);

    fclose(arqEstoque);
    fclose(arqMovimento);

    return 0;
}

