
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
    int opcao =0;
    int velocidade = NORMAL;

   do {
        opcao = Menu();
        switch(opcao){
            case 1: IniciaJogo(); 
            break;
            case 2: Creditos(); 
            break;
            case 3: exit(1); 
            break;
        }

    } while(1);

}