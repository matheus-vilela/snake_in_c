
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <pthread.h>
#include "interface.h"
#include "snake.h"
#include "game.h"

int main(){
    // pthread_t s_thread, i_thread;
    TSnake Snake;
    IniciaSnake(&Snake);
    CriarCabeca(&Snake);
    TSnakeBody Comida = CreateBody(1+rand()%6,1+rand()%39,1+rand()%19);

    // pthread_create(&s_thread, NULL, Imprime_mapa(&Snake, Comida), NULL);
    // pthread_create(&i_thread, NULL, Mover_Snake(&Snake, 1, Comida), NULL);

    // pthread_join(i_thread, NULL);
    // pthread_join(s_thread, NULL);

    srand(time(NULL));
    int opcao =0;
    int start_game;
    int velocidade = NORMAL;


   do {
        opcao = Menu(start_game);

        switch(opcao){
            case 1: IniciaJogo(&Snake, &Comida); 
            break;
            case 2: ; 
            break;
            case 3: ; 
            break;

        }
    } while(opcao != 3);
}