/*
 ============================================================================
 Name        : teste ponteiros.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description : exemplo da aula n 63, 64 de aluno para aluno
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {

struct horario{
	int hora;
	int minuto;
	int segundo;
};

int somatorio=30;
struct horario agora, *depois, antes;

depois = &agora;

(*depois).hora=20; // usa-se o parentese por causa da precedência do ponto é maior
depois->minuto=20; //equivalente ao de cima
depois->segundo=20;

antes.hora = somatorio + depois->segundo; // exemplo de operações com ponteiros
antes.minuto = agora.hora + depois->minuto;
antes.segundo = depois->minuto + depois->segundo;

printf("%i:%i:%i\n", antes.hora, antes.minuto, antes.segundo);
printf("%i:%i:%i\n", agora.hora, agora.minuto, agora.segundo);
printf("%i:%i:%i\n", depois->hora, depois->minuto, depois->segundo);

system ("PAUSE");
return 0;
}

