/* programa_pilha_01.c */

#include <stdio.h>

void push(int valor);
int pop(void);
int size(void);
int stacktop(void);
int pilha[10];
int pos=0;  // topo da pilha


void push(int valor) {
  pilha[pos]=valor;
  /* Empilha um novo elemento no topo da pilha. Repare que não é verificada a capacidade máxima da pilha.*/
  pos++;  // Atualiza o topo da pilha
  return;
}

int pop() {
    /* Retorna o elemento do topo da ilha. Não é verificado o final da pilha. */
   return (pilha[--pos]);
}

int size() {
  return pos; /* retorna o topo da pilha */
}

int stacktop() /* retorna o elemento do topo da pilha sem desempilhar */
{
return pilha[pos];
}

int main(int argc, char ** argv ) {

    printf("\nColoca dados na pilha");
    push(1);
    push(2);
    push(3);

    printf("\nTamanho da pilha %d", size());


    printf("\nPegando dado da pilha: %d", pop());
    printf("\nPegando dado da pilha: %d", pop());
    printf("\nPegando dado da pilha: %d", pop());
    printf("\nTamanho da pilha %d", size());
    return 0;
}


