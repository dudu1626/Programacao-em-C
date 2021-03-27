/*
 ============================================================================
 Name        : exercicio_sala02.c
 Author      : Eduardo Ferreira
 RA			 : 5012699818
 ============================================================================
 */

/* Enunciado do exercício:


    Faça um programa de cálculo de custo de energia de dois aparelhos de
    um estabelecimento comercial.
    O usuário entrará com o valor da potência do aparelho (em watts)
     e o tempo de utilização (em horas) diário de ambos os aparelhos.
    O programa deverá apresentar o nome do aparelho, o seu custo em reais
    por hora, por dia e por mês.
    (Obs: a CEMIG estabelece que um aparelho de 1000 watts de potência ligado
      por uma hora custa
      0,642 reais para o estabelecimento).  */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	    float watt1,watt2, tempo1, tempo2, resultado1h,resultado1d,resultado1m, resultado2d,resultado2m,resultado2h;
	    printf("\n \t \t programa CEMIG de custo de energia\n\n\n");
	    printf("\n digite o valor da potencia do primeiro aparelho em watts \n");
	    scanf("%f", &watt1);
	    printf("\n digite o valor tempo de utilizacao do primeiro aparelho em horas\n");
	    scanf("%f", &tempo1);
	    printf("\n digite o valor da potencia do segundo aparelho em watts \n");
	    scanf("%f", &watt2);
	    printf("\n digite o valor tempo de utilizacao do segundo aparelho em horas\n");
	    scanf("%f", &tempo2);
	    resultado1h=(watt1*0.642)/1000;
	    resultado1d=resultado1h*tempo1;
	    resultado1m=resultado1d*30;
	    resultado2h=(watt2*0.642)/1000;
	    resultado2d=resultado2h*tempo2;
	    resultado2m=resultado2d*30;
	    printf("\n \t o custo do primeiro aparelho e %f por hora, %f por dia e %f por mes\n", resultado1h,resultado1d,resultado1m);
	    printf("\n \t o custo do segundo aparelho e %f por hora, %f por dia e %f por mes\n", resultado2h,resultado2d,resultado2m);

	    return 0;


}
