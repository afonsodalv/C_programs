#ifndef LISTA_H
#define LISTA_H

typedef struct dados ct, *pct;

struct dados{

    char nome[100];
    int n;
    pct prox;
};

int menu();

pct preenche(pct cont[]);

int altera_letra(char *pal);

void adiciona(pct cont[], int *n);

void mostra(pct cont[], int tam);

void atualiza(pct cont[], char *pal);

void elimina(pct cont[], char *pal,int *n);


# endif
