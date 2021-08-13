
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

    TSnakeBody Comida = CreateBody(6,16,3);

    // pthread_create(&s_thread, NULL, Imprime_mapa(&Snake, Comida), NULL);
    // pthread_create(&i_thread, NULL, Mover_Snake(&Snake, 1, Comida), NULL);

    // pthread_join(i_thread, NULL);
    // pthread_join(s_thread, NULL);

    srand(time(NULL));
    int opcao =0;
    int start_game;
    int velocidade = NORMAL;

    start_game = FALSE;
    IniciaJogo(&Snake, Comida);

    // opcao = Menu(start_game);
    // usleep(50000);
 

    while(opcao == 1){
          switch(opcao){
            case 1:  IniciaJogo(&Snake, Comida); 
            break;
            // case 2: dificuldade(); 
            // break;
            // case 3: recordes(); 
            // break;
            // case 4: ajuda(); 
            // break;
            // case 5: sair(); 
            // break;
            //  default: 
        }
    }
}