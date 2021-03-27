/*
 ============================================================================
 Name        : Aloca��o de mem�ria.c
 Author      : Eduardo Ferreira
 Version     : 1.0
 Description :
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

struct ST_DADOS {
    char nome[40];
    float salario;

    /* estrutura dentro de uma estrutura */
    struct nascimento {
        int ano;
        int mes;
        int dia;
    } dt_nascimento;
};

int main(void) {
    /* ponteiro para a estrutura */
    struct ST_DADOS * p;

    /* aloca��o de mem�ria para o ponteiro da estrutura */
    p = (struct ST_DADOS *) malloc(sizeof(struct ST_DADOS));

    /* Um string (vetor de caracteres) � um ponteiro, por isto a aus�ncia do & no uso da fun��o scanf */
    printf("\nEntre com o nome ->");
    scanf("%s", p->nome);

    printf("Entre com o salario ->");
    scanf("%f", &p->salario);

    /* O -> � chamado de pointer member (apontador de membro). Ele � usado para referenciar um campo da estrutura no lugar do ponto (.) */
    printf("Entre com o nascimento ->");
    scanf("%d%d%d", &p->dt_nascimento.dia, &p->dt_nascimento.mes, &p->dt_nascimento.ano);

    printf("\n===== Dados digitados ====");
    printf("\nNome = %s", p->nome);
    printf("\nSalario = %f", p->salario);
    printf("\nNascimento = %d/%d/%d\n", p->dt_nascimento.dia, p->dt_nascimento.mes, p->dt_nascimento.ano);

    /* Libera memoria alocada para o ponteiro de estrutura */
    free(p);

    getche();
    return 0;
}


