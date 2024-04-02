#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flightlog.h"

int main()
{
    int x, total=0;
    tempo t=hora_atual();
    voo lista_voo[100];

    printf("Neste momento sao %2.2d:%2.2d\n", t.h, t.m);
    do{
        x=menu();
        switch (x){
        case 1:adiciona_voo(lista_voo, &total);break;
        case 2:mostra_voo(lista_voo, total);break;
        case 3:proximo_voo(lista_voo, total, t);break;
        case 4:atualiza_tabela(lista_voo, &total, t);break;
        case 5:
            t=hora_atual();
            printf("Neste momento sao %2.2d:%2.2d\n", t.h, t.m);
            break;
        }

    }while(x!=6);

    return 0;
}
