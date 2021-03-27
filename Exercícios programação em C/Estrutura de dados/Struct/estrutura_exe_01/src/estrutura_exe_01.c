/*
 ============================================================================
 Name        : Estrutura de Dados.c
 Grupo       : Eduardo Ferreira, Caroline e Edvar
 Description : exerc�cio 01
 ============================================================================

Agora fa�a os exerc�cios abaixo onde cada programa deve executar os seguintes passos:

1 - Declarar o tipo abstrato de dados;
2 - Criar uma vari�vel do tipo abstrato de dados;
3 - Ler os dados do teclado e preencher os campos da vari�vel;
4 - Exibir na tela os campos preenchidos da vari�vel do tipo abstrato de dados.

1 ) Construir um programa em Linguagem C que implemente uma estrutura avi�o(structaviao),
 permitindo o cadastro e a exibi��o, com os seguintes campos:

     modelo;
     fabricante;
     passageiros;
     comprimento;
     altura;
     velocidade;
     altitude;
     motor. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    struct aviao {
        char modelo[10], fabricante[20], motor[20];
        int passageiros;
        float comprimento, altura, velocidade, altitude;
    } aerolinhas;

    printf("Cadastro de aeronaves AeroLinhas!\n\n\n");

 	printf("Digite o modelo do aviao:");
    scanf("%s", aerolinhas.modelo);
    getchar();

	printf("\nDigite o fabricante do aviao:");
    scanf("%s", aerolinhas.fabricante);
    getchar();

    printf("\nDigite o tipo do motor:");
    scanf("%s", aerolinhas.motor);
    getchar();

    printf("\nDigite o numero de passageiros do aviao:");
    scanf("%d", &aerolinhas.passageiros);
    getchar();

    printf("\nDigite o comprimento do aviao em metros:");
    scanf("%f", &aerolinhas.comprimento);
    getchar();

    printf("\nDigite a altura do aviao em metros:");
    scanf("%f", &aerolinhas.altura);
    getchar();

    printf("\nDigite a velocidade do aviao em Km/h:");
    scanf("%f", &aerolinhas.velocidade);
    getchar();

    printf("\nDigite a altitude do aviao em metros:");
    scanf("%f", &aerolinhas.altitude);
    getchar();

    printf("\nO aviao cadastrado tem as seguintes caracteristicas: \n");
    printf("modelo: %s\n", aerolinhas.modelo);
    printf("fabricante: %s\n", aerolinhas.fabricante);
    printf("motor: %s\n", aerolinhas.motor);
    printf("passageiros: %d\n", aerolinhas.passageiros);
    printf("comprimento: %f m\n", aerolinhas.comprimento);
    printf("altura: %f m\n", aerolinhas.altura);
    printf("velocidade: %f km/h\n", aerolinhas.velocidade);
    printf("altitude: %f m\n", aerolinhas.altitude );

    system ("PAUSE");
    return 0;
}
