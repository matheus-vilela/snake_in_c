#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "snack.h"
#include "interface.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void Imprime_mapa(TSnack *Snack, TComida Comida){

    int existe=0;
    system("clear");
    for(int x=0; x<20; x++){
        for(int y=0; y<30; y++){
            existe = 7;
            existe = VerificaSeExisteNaSnack(Snack,x,y);
            if(x==0 || x==19 || y==0 || y==29 ){
                printf(" \033[1;33m*\033[0;37m");
            } else if(existe != 7){
                printf(" \033[1;3%dm*\033[0;37m", existe);
            } else if(x==Comida.coordenada.x && y==Comida.coordenada.y){
                printf(" \033[1;36m*\033[0;37m");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

}

void Andar_snack(TSnack *Snack, int SentidoAtual, TComida Comida){
    int aux = SentidoAtual;
    int aux1;
    int inverso = (aux == 3) ? 1 : (aux == 2) ? 4: (aux ==1) ? 3: (aux == 4)? 2: 4;
    aux1 = inverso;

    while(aux1 == inverso){
        aux1 = rand()%4;
    }

    sleep(1);
    andarSnack(Snack, aux1);
    Imprime_mapa(Snack, Comida);
    Andar_snack(Snack, aux1, Comida);
}
