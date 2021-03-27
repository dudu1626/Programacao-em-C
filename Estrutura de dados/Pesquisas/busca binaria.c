// busca binária

#include <stdio.h>
#include <stdlib.h>
#define total 10

int main()
{ int v[total];
    int x,inicio,meio , fim ;
    int num; //número a ser buscado.
    printf("\nPreencha o vetor na forma ordenada\n");
    for(x=0;x<10;x++)
        { printf("insira o elemento %d do vetor\n",x);
        scanf("%d",&v[x]);
        }
    printf("\nInsira o numero que deseja fazer a busca binaria\n");
    scanf("%d",&num);
    inicio=0;
    fim=9;

    if(v[inicio]==num){
        printf("numero encontrado no indice %d\n",inicio);
    }
    else if(v[fim]==num){
    printf("numero encontrado no indice %d\n",fim);
    }
    else{
        while(inicio<fim)
        { meio=(inicio+fim)/2; //aqui no caso estou fazendo um typecasting, irei truncar o valor do quociente para pegar somente a parte inteira.
            if ( v[meio]==num)
            { printf("numero encontrado no indice %d\n",meio);break;
            }
            else
                if(num>v[meio])
                { inicio=meio+1;
                }
                else
                { fim=meio;
}
                }
    }
    printf("\nPressione uma tecla para sair\n");
    system("pause");
    fflush(stdin);
    return 0;
}
