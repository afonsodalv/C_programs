#ifndef FLIGHTLOG_H
#define FLIGHTLOG_H

typedef struct tempo{
    int h, m;
}tempo;

typedef struct voo voo, *pvoo;

struct voo{
    int nVoo;
    char nComp[200], dest [200];
    tempo part;
} ;


int menu();

tempo hora_atual();

void adiciona_voo(pvoo lista, int *total);

void preenche_voo(pvoo lista);

void mostra_voo(voo lista[], int total);

void proximo_voo(voo lista[], int total, tempo t);

int verif_hora(tempo a, tempo t);

void atualiza_tabela(voo lista[], int *total, tempo t);


#endif
