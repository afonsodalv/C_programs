#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int menu(){
    int x;

    puts("1. Introduzir novo contacto");
    puts("2. Mostrar todos os contactos");
    puts("3. Atualizar contacto");
    puts("4. Eliminar contacto");
    puts("5. Terminar");

    scanf("%d", &x);

    while(x<1 || x>5){
        printf("Introduza um numero de 1 a 5");
        scanf("%d", &x);
    }

    return x;
}

int altera_letra(char *pal){
    int x;

    if(*pal >='a' && *pal<='z')
       *pal-=32;

    x=*pal-'A';

    return x;
}

pct preenche(){

    pct novo;

    novo=malloc(sizeof(ct));

    if(novo==NULL){
        printf("Erro a adicionar contacto");
        return NULL;
    }
    printf("Insira o nome: ");
    scanf(" %99[^\n]", novo->nome);

    printf("Insira o numero: ");
    scanf(" %d", &(novo)->n);
    novo->prox=NULL;

    return novo;
}

void adiciona(pct cont[], int *n){
    int index;
    pct novo, ant, atual;

    novo = preenche();

    index = altera_letra(novo->nome);

    (*n)++;

    if(cont[index] == NULL)
        cont[index] = novo;

    else{

        ant = NULL;
        atual = cont[index];

        while(atual != NULL && strcmp(atual->nome, novo->nome) < 0){
            ant = atual;
            atual = atual->prox;
        }

        while(atual!=NULL && strcmp(atual->nome, novo->nome) == 0){
            printf("O nome %s ja existe. Insira outro.", novo->nome);
            scanf(" %99[^\n]", novo->nome);

            if(novo->nome[0] >='a' && novo->nome[0]<='z')
                novo->nome[0]-=32;

            index = novo->nome[0]-'A';
            ant = NULL;
            atual = cont[index];

            while(atual != NULL && strcmp(atual->nome, novo->nome) < 0){
                ant = atual;
                atual = atual->prox;
            }

        }

        if(ant == NULL){
            novo->prox = atual;
            cont[index] = novo;
        }
        else{
            ant->prox = novo;
            novo->prox = atual;
        }
    }
}

void mostra(pct cont[], int tam){

    int i;
    pct aux=NULL;

    for(i=0;i<tam;i++){

        aux=cont[i];

        while(aux != NULL){
            printf("Nome: %s\nNumero: %d\n\n", aux->nome, aux->n);
            aux=aux->prox;
        }
    }
}

void atualiza(pct cont[], char *pal){

    int index;
    pct aux=NULL;

    index=altera_letra(pal);

    aux=cont[index];

    while(aux != NULL && strcmp(aux->nome, pal)<0)
           aux=aux->prox;

    if(strcmp(aux->nome, pal)!=0)
        printf("Esse nome nao esta na sua lista de contactos\n");

    else{
        printf("Insira o novo numero: ");
        scanf(" %d", &(aux)->n);
    }
}


void elimina(pct cont[], char *pal, int *n){

    int index;
    pct ant, atual;

    index=altera_letra(pal);

    atual=cont[index];
    ant=NULL;

    while(atual != NULL && strcmp(atual->nome, pal)<0){
          ant=atual;
          atual=atual->prox;
    }

     if(strcmp(atual->nome, pal)!=0)
        printf("Esse nome nao esta na sua lista de contactos\n");

    else{

        if(ant==NULL)
            cont[index]=atual->prox;
        else
            ant->prox=atual->prox;

        free(atual);
        (*n)--;
    }
}

