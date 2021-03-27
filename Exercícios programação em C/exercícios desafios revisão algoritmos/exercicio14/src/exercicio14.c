/*
 ============================================================================
 Name        : exercicio14.c
 Author      : Eduardo Ferreira
 RA          :5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int anasci,aatual,idadeh,idade05;
	printf("\n\t Digite o ano de seu nascimento e o ano atual!\n\n");
	scanf("%i",&anasci);
	scanf("%i",&aatual);
	idadeh=aatual-anasci;
	idade05=2005-anasci;
	printf("\tSua idade atual e %i anos\n",idadeh);
	printf("\tSua idade em 2005 era %i anos",idade05);


		return(0);

}
