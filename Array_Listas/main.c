#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define N 26

int main()
{
    int x, i, n=0;
    char nome[100];
    pct cont[N]= {NULL};


    do{
        x=menu();
        switch (x){
            case 1:adiciona(cont, &n);break;
            case 2:
                if(n)
                    mostra(cont, N);
                else
                    printf("Ainda nao existem contactos na sua lista\n");
                    break;
            case 3:
                if(n){
                    printf("Insira o nome a atualizar: ");
                    scanf(" %99[^\n]", nome);
                    atualiza(cont, nome);
                }
                else{
                    printf("A sua lista encontra-se vazia\n");
                }
                break;

            case 4:
                 if(n){
                    printf("Insira o nome a eliminar: ");
                    scanf(" %99[^\n]", nome);
                    elimina(cont, nome, &n);
                }
                else{
                    printf("A sua lista encontra-se vazia\n");
                }
                break;
        }
    }while(x != 5);

    free(cont);

    return 0;
}
