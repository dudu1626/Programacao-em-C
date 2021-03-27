/*
 ============================================================================
 Name        : projeto_cinema.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : projeto_cinema in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define linha  10 //fixar número de linhas para a matriz
#define coluna 20 //fixar número de colunas para a matriz


// matrizes como variáveis globais
int sala11[linha][coluna], sala12[linha][coluna],sala21[linha][coluna],sala22[linha][coluna];
int sala31[linha][coluna],sala32[linha][coluna];
FILE *arquivo;

// FUNÇOES:
void leitura_matriz (); // denominaçao de funçao, a estrutura está no final da main
void cabecalho ();
void gravacao_matriz();
void faturamento(float num);


int main(void) {
	setlocale (LC_ALL,"Portuguese"); // necessário para usar acentuação

	int op,lin,col,i,j,qtd,filme,opf,pagar, meia, inteira, trava;
	float soma;
	qtd=0;

	leitura_matriz(); // funçao para ler as salas de cinema (matrizes)

	do {
		inicio: // marcação para usar goto

		cabecalho();

		printf("Digite o número correspondente ao filme desejado \n\n"
				"\t| FILMES EM CARTAZ |\n\n\n"
				"\t| 1 - Mulher Maravilha  |\n"
				"\t| 2 - Piratas do Caribe |\n"
				"\t| 3 - Rei Arthur        |\n"
				"\t| Digite qualquer outra tecla para finalizar a compra e sair!|\n");

		scanf("%i",&filme);
		getchar();

		system ("cls");

		switch(filme)
		{
			case 1:

				cabecalho();

				printf("\t--------------------------------------\n"
						"\t Cine 1: Mulher Maravilha\n"
						"\t Sessão: 1 - 13:30 \n"
						"\t Sessão: 2 - 15:30 \n"
						"\t pressione 0 - para voltar ao início\n\n\n"
						"\tComprar bilhete para qual sessão ? \n\n"
						"\t--------------------------------------\n");

				scanf("%i",&op);
				getchar();

				system ("cls");

				if(op==1)
				{
					do{
						cabecalho();
						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();

						system ("cls");


						switch(opf){
						case 1:
							cabecalho();

							printf ("Legenda:\n"
									"|Ö| - Poltronas disponíveis\n"
									"|X| - Poltronas ocupadas\n\n\n");
							for(i=0;i<linha;i++)
							{
								for(j=0;j<coluna;j++)
								{
									if (sala11[i][j]==0)
										printf ("|Ö|");
									if (sala11[i][j]==1 )
										printf ("|X|");
								}
								printf ("\n");
								}
								printf ("\n\n");
							break;
							case 2:
								do{
									cabecalho();

									printf("digite a linha desejada:");
									scanf("%d",&lin);

									printf("digite a poltrona desejada:");
									scanf("%d",&col);

									if (sala11[lin-1][col-1]==1)
										printf("Poltrona já está ocupada, escolha outra!\n");
									else
										{sala11[lin-1][col-1]=1;


										printf("Você deseja comprar mais?\n"
											"digite: 1 - SIM"
											"        2 - NÃO\n");
										scanf("%d",&pagar);
										getchar();

										system ("cls");


										}

								}while(pagar!=2);

								break;
							case 3:
								cabecalho();

								printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
								scanf("%d",&lin);
								getchar();

								scanf("%d",&col);
								getchar();

								system("cls");

								if(sala11[lin-1][col-1]==1)
										sala11[lin-1][col-1]=0;
								else
										printf ("A poltrona não está disponível para o cancelamento!");
							break;
							case 4:
								goto final;
								system("cls");

							break;
							default:
								op=0;

						}}
						while(op!=0);

				}// fim opção sala 1 filme 1
				if(op==2)
				{
					do{
						cabecalho();

						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();
						system ("cls");

						switch(opf){
						case 1:
							cabecalho();

							printf ("Legenda:\n"
									"|Ö| - Poltronas disponíveis\n"
									"|X| - Poltronas ocupadas\n\n\n");
							for(i=0;i<linha;i++)
							{
								for(j=0;j<coluna;j++)
								{
									if (sala12[i][j]==0)
									printf ("|Ö|");
									if (sala12[i][j]==1 )
									printf ("|X|");
								}
								printf ("\n");
							}
							printf ("\n\n");
						break;
						case 2:

							do{
								printf("digite a linha desejada:");
								scanf("%d",&lin);

								printf("digite a poltrona desejada:");
								scanf("%d",&col);

								if (sala12[lin-1][col-1]==1)
									printf("Poltrona já está ocupada, escolha outra!\n");
								else
								{sala12[lin-1][col-1]=1;

								printf("Você deseja comprar mais?\n"
										"digite: 1 - SIM"
										"        2 - NÃO\n");
								scanf("%d",&pagar);
								getchar();

								system ("cls");

								}
							}while(pagar!=2);

//							printf ("O valor total a pagar é R$ %.2f",comprar (qtd));
						break;
						case 3:
							cabecalho();

							printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
							scanf("%d",&lin);
							getchar();

							scanf("%d",&col);
							getchar();

							system("cls");

							if(sala12[lin-1][col-1]==1)
								sala12[lin-1][col-1]=0;
							else
								printf ("A poltrona não está disponível para o cancelamento!");
						break;
						case 4:
							system("cls");
							goto final;

						break;
						default:
							op=0;

						}
					}
				while(op!=0);
				}// fim opção sala 1 filme 2
				if((op!=1)||(op!=2))
				{
					system("cls");
					goto inicio; //joga para o início
				}

			break;
			case 2:
				cabecalho();

				printf("\t--------------------------------------\n"
										"\t Cine 2: Piratas do Caribe\n"
										"\t Sessão: 1 - 12:30 \n"
										"\t Sessão: 2 - 17:30 \n"
										"\t pressione qualquer tecla para voltar ao início\n\n\n"
										"\tComprar bilhete para qual sessão ? \n\n"
										"\t--------------------------------------\n");

				scanf("%i",&op);
				getchar();

				system ("cls");

				if(op==1)
				{
					do{
						cabecalho();

						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();

						system ("cls");

						switch(opf){
							case 1:
								cabecalho();

								printf ("Legenda:\n"
										"|Ö| - Poltronas disponíveis\n"
										"|X| - Poltronas ocupadas\n\n\n");
								for(i=0;i<linha;i++)
								{
									for(j=0;j<coluna;j++)
									{
										if (sala21[i][j]==0)
										printf ("|Ö|");
										if (sala21[i][j]==1 )
										printf ("|X|");
									}
									printf ("\n");
								}
								printf ("\n\n");
						break;
							case 2:
								do{
									printf("digite a linha desejada:");
									scanf("%d",&lin);
									getchar();

									printf("digite a poltrona desejada:");
									scanf("%d",&col);
									getchar();

									if (sala21[lin-1][col-1]==1)
										printf("Poltrona já está ocupada, escolha outra!\n");
									else
									{sala21[lin-1][col-1]=1;

									printf("Você deseja comprar mais?\n"
											"digite: 1 - SIM"
											"        2 - NÃO\n");
									scanf("%d",&pagar);
									getchar();

									system("cls");
									}
								}while(pagar!=2);

								break;
								case 3:
									cabecalho();

									printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
									scanf("%d",&lin);
									getchar();

									scanf("%d",&col);
									getchar();

									system("cls");

									if(sala21[lin-1][col-1]==1)
										sala21[lin-1][col-1]=0;
									else
										printf ("A poltrona não está disponível para o cancelamento!");
							break;
							case 4:
								system("cls");
								goto final;
							break;
								default:
									op=0;

						}
					}
					while(op!=0);

				}// fim opção filme 1 sala 2
				if(op==2)
				{
					do{
						cabecalho();

						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();

						system("cls");

						switch(opf){
							case 1:
								cabecalho();

								printf ("Legenda:\n"
										"|Ö| - Poltronas disponíveis\n"
										"|X| - Poltronas ocupadas\n\n\n");
								for(i=0;i<linha;i++)
								{
									for(j=0;j<coluna;j++)
									{
										if (sala22[i][j]==0)
											printf ("|Ö|");
										if (sala22[i][j]==1 )
											printf ("|X|");
									}
									printf ("\n");
								}
								printf ("\n\n");
								break;
							case 2:
								do{
									printf("digite a linha desejada:");
									scanf("%d",&lin);
									getchar();

									printf("digite a poltrona desejada:");
									scanf("%d",&col);
									getchar();

									system("cls");

									if (sala22[lin-1][col-1]==1)
										printf("Poltrona já está ocupada, escolha outra!\n");
									else
									{sala22[lin-1][col-1]=1;

									printf("Você deseja comprar mais?\n"
											"digite: 1 - SIM"
											"        2 - NÃO\n");
									scanf("%d",&pagar);
									getchar();

									system("cls");
									}
								}while(pagar!=2);

								break;
							case 3:
								cabecalho();

								printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
								scanf("%d",&lin);
								getchar();

								scanf("%d",&col);
								getchar();

								system("cls");

								if(sala22[lin-1][col-1]==1)
									sala22[lin-1][col-1]=0;
								else
									printf ("A poltrona não está disponível para o cancelamento!");
								break;

							case 4:
								system("cls");
								goto final;

							break;

							default:
								op=0;

						}
					}
					while(op!=0);
				}// fim opção  filme 2 sala 2
				if((op!=1)||(op!=2))
				{
					system ("cls");
					goto inicio; //joga para o início
				}

			break;
			case 3:
				cabecalho();

				printf("\t--------------------------------------\n"
						"\t Cine 3: Rei Arthur\n"
						"\t Sessão: 1 - 14:30 \n"
						"\t Sessão: 2 - 18:30 \n"
						"\t pressione qualquer tecla para voltar ao início\n\n\n"
						"\tComprar bilhete para qual sessão ? \n\n"
						"\t--------------------------------------\n");

				scanf("%i",&op);
				getchar();

				system("cls");

				if(op==1)
				{
					do{
						cabecalho();

						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();

						system("cls");

						switch(opf){
						case 1:
							cabecalho();

							printf ("Legenda:\n"
									"|Ö| - Poltronas disponíveis\n"
									"|X| - Poltronas ocupadas\n\n\n");
							for(i=0;i<linha;i++)
							{
								for(j=0;j<coluna;j++)
								{
									if (sala31[i][j]==0)
										printf ("|Ö|");
									if (sala31[i][j]==1 )
										printf ("|X|");
								}
								printf ("\n");
							}
							printf ("\n\n");
							break;
						case 2:
							do{

								printf("digite a linha desejada:");
								scanf("%d",&lin);

								printf("digite a poltrona desejada:");
								scanf("%d",&col);
								getchar();

								system("cls");

								if (sala31[lin-1][col-1]==1)
									printf("Poltrona já está ocupada, escolha outra!\n");
								else
								{sala31[lin-1][col-1]=1;

								printf("Você deseja comprar mais?\n"
										"digite: 1 - SIM"
										"        2 - NÃO\n");
								scanf("%d",&pagar);
								getchar();

								system("cls");
								}
							}while(pagar!=2);

							break;
						case 3:
							cabecalho();

							printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
							scanf("%d",&lin);
							getchar();

							scanf("%d",&col);
							getchar();

							system("cls");

							if(sala31[lin-1][col-1]==1)
								sala31[lin-1][col-1]=0;
							else
								printf ("A poltrona não está disponível para o cancelamento!");
							break;
						case 4:
							system("cls");
							goto final;
						break;
						default:
							op=0;

						}
					}
					while(op!=0);

				}// fim opção filme 3 sala 1
				if(op==2)
				{
					do{
						cabecalho();

						printf("\n\nDigite:         1 - Ver poltronas disponíveis\n"
								"		2 - Comprar ingresso\n"
								"		3 - Cancelar compra de ingressos\n"
								"		4 - Finalizar a compra\n"
								"		Qualquer outro número para voltar e continuar comprando\n");

						scanf("%d",&opf);
						getchar();

						system("cls");

						switch(opf){
						case 1:
							cabecalho();

							printf ("Legenda:\n"
									"|Ö| - Poltronas disponíveis\n"
									"|X| - Poltronas ocupadas\n\n\n");
							for(i=0;i<linha;i++)
							{
								for(j=0;j<coluna;j++)
								{
									if (sala32[i][j]==0)
										printf ("|Ö|");
									if (sala32[i][j]==1 )
										printf ("|X|");
								}
								printf ("\n");
							}
							printf ("\n\n");
							break;
						case 2:
							do{
								printf("digite a linha desejada:");
								scanf("%d",&lin);
								getchar();

								printf("digite a poltrona desejada:");
								scanf("%d",&col);
								getchar();

								system("cls");

								if (sala32[lin-1][col-1]==1)
									printf("Poltrona já está ocupada, escolha outra!\n");
								else
								{sala32[lin-1][col-1]=1;

								printf("Você deseja comprar mais?\n"
										"digite: 1 - SIM"
										"        2 - NÃO\n");
								scanf("%d",&pagar);
								getchar();

								system("cls");

								}
							}while(pagar!=2);

							break;
						case 3:
							cabecalho();

							printf("Digite a linha e poltrona que deseja cancelar a compra:\n");
							scanf("%d",&lin);
							getchar();

							scanf("%d",&col);
							getchar();

							system("cls");

							if(sala32[lin-1][col-1]==1)
								sala32[lin-1][col-1]=0;
							else
								printf ("A poltrona não está disponível para o cancelamento!");
							break;
						case 4:
							system("cls");
							goto final;
						break;
						default:
							op=0;

						}
					}
					while(op!=0);
				}// fim opção  filme 3 sala 2
				if((op!=1)||(op!=2))
				{
					system ("cls");
					goto inicio; //joga para o início
				}
			break;
			default:
				filme=0;

		}//final switch de filme
	}while (filme!=0);

final: // finalizar a compra

	for(i=0;i<linha;i++) // calcular o total de ingressos
	{
		for(j=0;j<coluna;j++)
		{
			if(sala11[i][j]==1)
				qtd=qtd+1;
			if(sala12[i][j]==1)
				qtd=qtd+1;
			if(sala21[i][j]==1)
				qtd=qtd+1;
			if(sala22[i][j]==1)
				qtd=qtd+1;
			if(sala31[i][j]==1)
				qtd=qtd+1;
			if(sala32[i][j]==1)
				qtd=qtd+1;
		}// fim for 2

	}//fim for 1


	do{
		cabecalho();

		printf("\t---------------------------------------\n"
				   "\t Escolha da forma de pagamento : : : \n\n"
				   "\t Inteira: R$ 20,00  \n"
					"\t Meia: R$ 10,00  \n\n");

			printf("Você comprou %d ingressos\n", qtd);

			printf("Digite a quantidade de ingressos do tipo -> INTEIRA ");
			scanf("%d",&inteira);
			getchar();


			printf("\nDigite a quantidade de ingressos do tipo -> MEIA ");
			scanf("%d",&meia);
			getchar();

			soma=(meia*10)+(inteira*20);

			if ((inteira+meia)!=qtd)
			printf ("A soma da quantidade de ingressos está errada!");

			else
			{printf ("\n\n\tO valor total a pagar é R$ %.2f\n",soma);
			trava=0;}

	}while(trava!=0);

	printf ("\n\tMuito obrigado pela preferência!\n\n"
				"\t\t Volte Sempre!!\n\n");


	gravacao_matriz();

	faturamento(soma);

	return EXIT_SUCCESS;
}

void leitura_matriz () // funçao para a leitura das salas de cinema no inicio do programa
{
	int i,j;

	arquivo=fopen("sala11.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala11[i][j]);
		}
	}

	fclose (arquivo);

	arquivo=fopen("sala12.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala12[i][j]);
		}
	}

	fclose (arquivo);

	arquivo=fopen("sala21.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala21[i][j]);
		}
	}

	fclose (arquivo);

	arquivo=fopen("sala22.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala22[i][j]);
		}
	}

	fclose (arquivo);

	arquivo=fopen("sala31.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala31[i][j]);
		}
	}

	fclose (arquivo);

	arquivo=fopen("sala32.txt","r");

	for(i=0;i<linha;i++)  // ler a matriz
	{
		for(j=0;j<coluna;j++)
		{
			fscanf(arquivo,"%d", &sala32[i][j]);
		}
	}

	fclose (arquivo);
} // fim funçao de leitura dos arquivos


void gravacao_matriz(){
	int i,j;

		arquivo=fopen("sala11.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala11[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);

		arquivo=fopen("sala12.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala12[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);

		arquivo=fopen("sala21.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala21[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);

		arquivo=fopen("sala22.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala22[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);

		arquivo=fopen("sala31.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala31[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);

		arquivo=fopen("sala32.txt","w");

		for(i=0;i<linha;i++)
		{
			for(j=0;j<coluna;j++)
			{
				fprintf(arquivo,"%d", sala32[i][j]);
			}
			fprintf(arquivo,"\n");
		}

		fclose (arquivo);


} // fim funcao gravacao

void faturamento(float num)
{
	arquivo=fopen("faturamento.txt","a");

	fprintf (arquivo,"R$ %.2f \n", num);

	fclose (arquivo);
} // fim funcao faturamento

void cabecalho(){

printf("\t************************************************************\n"
		"\t************************************************************\n"
		"\t------------------------CINEMA C----------------------------\n"
		"\t************************************************************\n"
		"\t************************************************************\n\n\n");

} // fim funcao para imprimir o cabecalho nas telas
