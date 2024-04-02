#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flightlog.h"


int menu(){
    int x;

    puts("1. Introduzir novos voos");
    puts("2. Listar todos os voos");
    puts("3. Listar proximos voos");
    puts("4. Atualizar tabela de voos");
    puts("5. Atualizar hora");
    puts("6. Terminar");

    scanf("%d", &x);

    while(x<1 || x>6){
        printf("Introduza um numero de 1 a 6");
        scanf("%d", &x);
    }

    return x;
}

tempo hora_atual(){

    time_t a;
    struct tm* b;
    tempo atual;

    time(&a);
    b = localtime(&a);
    atual.h = b->tm_hour;
    atual.m = b->tm_min;

    return atual;
}

void adiciona_voo(pvoo lista, int *total){

    int x, i;

    printf("Quantos voos pretende adicionar? ");
    scanf(" %d", &x);

    while(x+*total>100){
        printf("Esse valor ultrapassa o espaco disponivel.\nApenas consegue adicionar %d voos\n", 100-*total);
        scanf(" %d", &x);
    }

    for(i=0; i<x; i++)
        preenche_voo(&lista[*total+i]);

    (*total)+=x;
}

void preenche_voo(pvoo lista){

    printf("Introduza o numero do voo: ");
    scanf(" %d", &(lista->nVoo));

    printf("Introduza o nome da companhia: ");
    scanf(" %199[^\n]", lista->nComp);

    printf("Introduza o destino: ");
    scanf(" %199[^\n]", lista->dest);

    printf("Introduza as horas de partida: ");
    scanf(" %d%d", &(lista->part.h), &(lista->part.m));

    if(lista->part.h == 24)
        lista->part.h=0;

    if(lista->part.m == 60){
    (lista->part.h)++;
    lista->part.m=0;
        if(lista->part.h == 24)
        lista->part.h=0;
    }

    while(lista->part.h<0 || lista->part.h>24 || lista->part.m<0 || lista->part.m>60){
            if(lista->part.h<0 || lista->part.h>24){
                printf("Hora incorreta. Introduza outra: ");
                scanf(" %d", &(lista->part.h));
            }
            if(lista->part.m<0 || lista->part.m>60){
                printf("Minutos incorretos. Introduza outros: ");
                scanf(" %d", &(lista->part.m));
            }
    }
}

void mostra_voo(voo lista[], int total){

    int i;

    if(total==0)
        printf("Ainda nao existem voos registados\n");

    printf("Existem %d voos guardados", total);

    for(i=0;i<total;i++){
        printf("Voo numero %d\nNumero do Voo: %d\t\tNome da Companhia: %s\n", i+1, lista[i].nVoo, lista[i].nComp);
        printf("Destino: %s\t\tHora de partida: %2.2d:%2.2d\n\n", lista[i].dest, lista[i].part.h, lista[i].part.m);
    }
}


void proximo_voo(voo lista[], int total, tempo t){

    int i, x;

    for(i=0;i<total;i++){
        x=verif_hora(lista[i].part, t);
        if(x>0 && x<=30){
         printf("Numero do Voo: %d\nDestino: %s\nSai dentro de %d minutos\n\n",lista[i].nVoo, lista[i].dest, x);
        }
    }
}

int verif_hora(tempo a, tempo t){

    int minA, minT;

    minA=a.h*60+a.m;
    minT=t.h*60+t.m;

    return minA-minT;
}

void atualiza_tabela(voo lista[], int *total, tempo t){

    int i, x;

    for(i=0;i<*total;i++){
        x=verif_hora(lista[i].part, t);
        if(x<0){
            lista[i]=lista[*total-1];
            (*total)--;
            i--;
        }
    }
}
