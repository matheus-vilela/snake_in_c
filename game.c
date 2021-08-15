#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "snake.h"
#include "interface.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void GameOver(int *score, TSnake *Snake){
    int input,delay=0;
    int y,x;
    int opt;
    int existe =0;

    system("clear");
    for(y=0; y < HEIGHT; y++){
        for(x=0; x < WIDTH; x++){
            existe = VerificaSeExisteNaSnake(Snake,x,y);

            if(y==0 || y==20 || x==0 || x==40 ){
                if(existe != 0) {
                    printf("\033[0;45m *\033[0;3%dm", existe);
                } else {
                    printf("\033[0;45m  \033[0;37m");
                }
            }else if(y == 6){
                switch(x){
                    case 15:
                       printf("\033[0;35m G\033[0;37m");
                       break;
                    case 16:
                       printf("\033[0;35m A\033[0;37m");
                           break;
                    case 17:
                       printf("\033[0;35m M\033[0;37m");
                           break;
                    case 18:
                       printf("\033[0;35m E\033[0;37m");
                           break;
                    case 20:
                       printf("\033[0;35m O\033[0;37m");
                       break;
                    case 21:
                       printf("\033[0;35m V\033[0;37m");
                           break;
                    case 22:
                       printf("\033[0;35m E\033[0;37m");
                           break;
                    case 23:
                       printf("\033[0;35m R\033[0;37m");
                           break;
                    default:
                       printf("\033[0;35m  \033[0;37m"); 
                }
            }else if ( y== 12){
                switch(x){
                    case 15:
                       printf("\033[0;35m S\033[0;37m");
                       break;
                    case 16:
                        printf("\033[0;35m C\033[0;37m");
                           break;
                    case 17:
                        printf("\033[0;35m O\033[0;37m");
                           break;
                    case 18:
                        printf("\033[0;35m R\033[0;37m");
                           break;
                    case 19:
                        printf("\033[0;35m E\033[0;37m");
                            break;
                    case 20:
                        printf("\033[0;35m: \033[0;37m");
                            break;
                    case 23:
                        if(*score > 9){
                            printf("\033[0;35m%d\033[0;37m", *score);
                        } else {
                            printf("\033[0;35m %d\033[0;37m", *score);

                        }
                           break;
                    default:
                       printf("\033[0;35m  \033[0;37m"); 
                }
            }
            else if(existe != 0) {
                printf("\033[0;3%dm *\033[0;37m", existe);
            }
            else {
                printf("\033[0;35m  \033[0;37m"); 
            }
        }
        printf("\n");
    }

    Sub_Menu(score, 2);

}

void IniciaJogo(){
    int opcao = 0, exit = 0;
    int sentidoOld = 119;
    int sentidoAtual = 119;
    int sentido;
    int score = 0;
    int gameOver= 0;
    TSnake Snake;
    IniciaSnake(&Snake);
    CriarCabeca(&Snake);
    TSnakeBody Comida = CreateBody(1+rand()%6,1+rand()%39,1+rand()%19);

    int *pontGameOver;
    pontGameOver = &gameOver; 
    int *pontScore;
    pontScore = &score; 

    do{
        if(kbhit()){
            sentido = getchar() ;
            if(sentido == 112 &&gameOver == 0){
                if(sentidoAtual == 112){
                sentidoAtual = sentidoOld;
                } else {
                sentidoOld = sentidoAtual;
                sentidoAtual = sentido;
                }
            } 
            else if (
                (sentido == 'w' && sentidoAtual != 's') ||
                (sentido == 's' && sentidoAtual != 'w') ||
                (sentido == 'a' && sentidoAtual != 'd') ||
                (sentido == 'd' && sentidoAtual != 'a')
                ) {
                if (sentido == 'w' || sentido == 'a'|| sentido == 's' || sentido == 'd'){
                    sentidoAtual = sentido;
                }
                fflush(stdout);
            }
                while (kbhit() != 0)
                    getchar();
        } else {
            fflush(stdout);
        }

        if(sentidoAtual != 112 && gameOver == 0){
            MoverSnake(&Snake, sentidoAtual);
        }
        
        usleep(100000);

        if(sentidoAtual != 112 && gameOver == 0){
            Imprime_mapa(&Snake, &Comida, pontScore, pontGameOver, sentidoAtual);
        }

    } while(gameOver == 0);
    
    GameOver(pontScore, &Snake);
    do{
        while(!kbhit()){
            fflush(stdout);
            usleep(100000);
        }

        sentido = getchar();
        if(sentido == 49){
            LiberarSnake(&Snake);
            IniciaJogo();
        }
    }while(sentido != 49 && sentido != 50);
}
