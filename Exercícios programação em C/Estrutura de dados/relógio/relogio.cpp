/*
 ============================================================================
 Name        : Rel�gio.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

/*ideia de um relogio com struct e ponteiro, mas meu computador roda isso � jato.
tem que arrumar outra aneira de fazer o delay ou mudar a l�gica de atualiza��o */


#include <stdio.h>
#include <stdlib.h>

struct relogio{
	int horas;
	int minutos;
	int segundos;	
};

// fun��es
void delay ();
void update (struct relogio *t);
void display (struct relogio *t);


int main(void) {

	struct relogio tempo;

// inicializa��o do rel�gio (poderia come�ar pegando do sistema)
	tempo.horas=0; 
	tempo.minutos=0;
	tempo.segundos=0;
	
// loop infinito poderia ser  "while (1)"
	for (;;){
		
		update (&tempo);
		display (&tempo);
		delay();
		delay();
		delay();
		system ("cls");
		
	}//fim for
	
system ("PAUSE");
return 0;
} // fim main

//fun��es

void delay (){ //atraso do rel�gio
	unsigned long int t;
	
	for (t=1;t>4294967295;t++);// fim for
	  // fun��o apenas para atraso
	 // maior valor para unsigned long int � 4.294.967.295
					
} //fim delay

void update (struct relogio *t){
	
	t->segundos++;
	
	if (t->segundos == 60){
		
		t->minutos++;
		t->segundos=0;
		
	}
	
	if (t->minutos ==60){
		
		t->horas++;
		t->minutos=0;
	
	}

	if(t->horas == 24) t->horas =0;
	
	delay();
	delay();
	
} //fim update

void display (struct relogio *t){
	
	printf ("%d:", t->horas);
	printf ("%d:", t->minutos);
	printf ("%d\n", t->segundos);
	
}
