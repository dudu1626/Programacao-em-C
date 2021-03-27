/*
 ============================================================================
 Name        : exercicio04.c
 Author      : Eduardo Ferreira
 Ra          : 5012699818
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num1, num2, num3, auxiliar;

	printf ("escreva tres numeros diferentes!\n");
	scanf ("%f %f %f", &num1, &num2, &num3);

	if ((num1<num2)&&(num1<num3)){
		if (num2<num3){
			printf ("A ordem crescente e %f, %f, %f " num1,num2,num3);}
		else {
			printf ("A ordem crescente e %f, %f, %f " num1,num3,num2);}}
	if ((num2<num1)&&(num2<num3)){
		if (num1<num3){
			printf ("A ordem crescente e %f, %f, %f " num2,num1,num3);}
		else {
			printf ("A ordem crescente e %f, %f, %f " num2,num3,num2);}}
	if ((num3<num1)&&(num3<num2)){
		if (num1<num2){
			printf ("A ordem crescente e %f, %f, %f " num3,num1,num2);}
		else {
			printf ("A ordem crescente e %f, %f, %f " num3,num2,num1);}}
	
	
	return 0;


}