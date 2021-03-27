/*
 ============================================================================
 Name        : batalha campal.c
 Author      : Grupo da turma
 Version     : 1.0
 Description : trabalho da Alessandra
 ============================================================================
*/

/*
1� objetivo
	- criar matriz bidimensional 7x7
	- poder acrescentar valores em qualquer posi��o da matriz
	- escanear e imprimir os valores na matriz
2� objetivo
	-criar la�o de repeti��o para interromper o processo a qualquer momento
	-definir final do processo, quando nao mais possivel incrementar dados
	-criar la�o de repeti��o para restartar todo o programa
3� objetivo
	-mostrar na tela a estrutura da matriz
	-exibir na tela os espa�os que ja foram preenchidos
	-criar metodo que impe�a de preencher um mesmo espa�o duas vezes
4� objetivo
	-criar metodo que insira um determinado valor aleatoriamente nos espa�os vazios da matriz
	-criar estrutura condicional para quando o valor inserido pelo metodo e o valor inserido pelo usuario forem iguais o programa termine
	-imprimir na tela a posi��o aonde os dois dados coincidem 
5� objetivo
	-cirar um la�o de repeti��o que limite o numero de vezes que o usuario pode preencher espa�os da matriz
	-retornar (no caso de expirar o numero de tentativas) a posi��o da matriz aonde o metodo inseriu o valor e imprimir na tela
	-retornar (no caso de NAO expirar o numero de tentativas) a posi��o da matriz aonde o metodo e o usuario coinsidem 
6� objetivo
	-"simular" interface grafica para, de modo visual acompanhar todo o processo
	-inserir niveis de dificuldade, aumentando a matriz e o numero de metodos que inserem valores aleatoriamente

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//fun��es 
char interface();
char campoBatalha();

//vari�veis globais
char escolha;
int campo[7][7];


int main(void) {
setlocale (LC_ALL,"Portuguese"); // necess�rio para usar acentua��o

 	interface();

    switch(escolha){
        case 'Y':
            printf("\nVamos come�ar !");
             printf("\n\n\n---------------------------------------------------------------------------------------------");

             campoBatalha();

        break;
        case 'N':
            printf("\nAlto, cessar fogo, mudar posi��o!");
            printf("\n\n\n---------------------------------------------------------------------------------------------");

        break;
    };


system ("PAUSE");
return 0;
} // fim main


char interface(){

    printf("\n--------------------------Jogo batalha campal-------------------------------- ");
    printf("\n\n\nDeseja come�ar ? (Y/N): ");
    scanf("%c", &escolha);
    getchar();
    escolha=toupper(escolha);

    return escolha;
}

char campoBatalha(){

    int i, j, y;
    char decisao[2];

    printf("\n  A B C D E F G\n--------------------------------------------------");
    printf("\n1|\n2|\n3|\n4|\n5|\n6|\n7|");
    
    for (i=0;i<7;i++){
		for (j=0;j<7;j++){
			
		}
	}
    
    
    printf("\n-------------------------------------------------------------------");
    printf("\nEscolha uma posi��o: ");
    scanf("%s", decisao);

    gets(decisao);
    strupr(decisao);

    switch(decisao[2]){
	    case ('A1'):
	            printf("\n Posi��o A1");
	            campo[0][0] = 11;
	        break;
	    case ('A2'):
	        break;
	    case ('A3'):
	        break;
	    case ('A4'):
	        break;
	    case ('A5'):
	        break;
	    case ('A6'):
	        break;
	    case ('A7'):
	        break;
	    case ('B1'):
	        break;
	    case ('B2'):
	        break;
	    case ('B3'):
	        break;
	    case ('B4'):
	        break;
	    case ('B5'):
	        break;
	    case ('B6'):
	        break;
	    case ('B7'):
	        break;
	    case ('C1'):
	        break;
	    case ('C2'):
	        break;
	    case ('C3'):
	        break;
	    case ('C4'):
	        break;
	    case ('C5'):
	        break;
	    case ('C6'):
	        break;
	    case ('C7'):
	        break;
	    case ('D1'):
	        break;
	    case ('D2'):
	        break;
	    case ('D3'):
	        break;
	    case ('D4'):
	        break;
	    case ('D5'):
	        break;
	    case ('D6'):
	        break;
	    case ('D7'):
	        break;
	    case ('E1'):
	        break;
	    case ('E2'):
	        break;
	    case ('E3'):
	        break;
	    case ('E4'):
	        break;
	    case ('E5'):
	        break;
	    case ('E6'):
	        break;
	    case ('E7'):
	        break;
	    case ('F1'):
	        break;
	    case ('F2'):
	        break;
	    case ('F3'):
	        break;
	    case ('F4'):
	        break;
	    case ('F5'):
	        break;
	    case ('F6'):
	        break;
	    case ('F7'):
	        break;
	    case ('G1'):
	        break;
	    case ('G2'):
	        break;
	    case ('G3'):
	        break;
	    case ('G4'):
	        break;
	    case ('G5'):
	        break;
	    case ('G6'):
	        break;
	    case ('G7'):
	        break;
	    default:
	        printf("\nN�o � uma entrada v�lida !");
	        break;
    }

  //exibir as posi��es
 // for ( i=0; i<3; i++ )
  //  for ( y=0; y<3; y++ )
    //{
      // printf ("\n%c",campo[ i ][ y ]);
    //}

  //  return decisao;
}
