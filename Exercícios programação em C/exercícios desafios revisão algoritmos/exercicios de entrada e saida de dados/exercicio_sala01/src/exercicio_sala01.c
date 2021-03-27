/*
 ============================================================================
 Name        : exercicio_sala01.c
 Author      : Eduardo Ferreira
 RA          : 5012699818
 ============================================================================
 */

/* Faça um programa que leia a quantidade de fitas que uma locadora de vídeo
	     possui e o valor que ela cobra por cada aluguel, mostrando as informações pedidas a seguir.
	- sabendo que um terço das fitas são alugadas por mês, exiba o faturamento anual da locadora.
	- quando o cliente atrasa a entrega, é cobrada uma multa de 10% sobre o valor do aluguel.
	Sabendo que um décimo das fitas alugadas no mês são devolvidas com atraso,
	calcule o valor ganho com multas por mês.
	- sabendo ainda que 2% de fitas se estragam ao longo do ano, e um décimo do total é comprado para reposição,
	 exiba a quantidade de fitas que a locadora terá no final do ano.  */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

		float fitas, fitasalug,fitasmulta, fitasruim,fitascompradas,aluguel, faturamento, vlrmultas;
	    printf("\n \t Programa de controle de locadora \n");
	    printf("\n\n digite quantidade de fitas da locadora \n");
	    scanf("%f", &fitas);
	    printf("\n digite valor do aluguel \n");
	    scanf("%f", &aluguel);
	    fitasalug=fitas/3;
	    faturamento=(fitasalug*aluguel)*12;
	    printf("\n o faturamento anual da locadora e %8.2f reais\n", faturamento);
	    fitasmulta=(fitasalug*10)/100;
	    vlrmultas=(aluguel*0.1)*fitasmulta;
	    printf("\n o valor ganho com multas por mês e %8.2f reais\n", vlrmultas);
	    fitasruim=fitas*2/100;
	    fitascompradas=fitas*10/100;
	    fitas=fitas-fitasruim+fitascompradas;
	    printf("\n quantidade de fitas que a locadora terá no final do ano sera %8.0f fitas \n", fitas);

	    return(0);

}
