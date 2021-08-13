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
    exit(1);
}

void IniciaJogo(TSnake *Snake, TSnakeBody *Comida){
  int opcao =0;
  int sentidoOld = 119;
  int sentidoAtual = 119;
  int sentido, inverso;
  int score = 0;
  int gameOver= 0;

  int *pontGameOver;
  pontGameOver = &gameOver; 
  int *pontScore;
  pontScore = &score; 

  do{
    switch(sentidoAtual){
      case 119:        //w
        inverso= 115;  //s
        break;
      case 97:         //a
        inverso=100;   //d
        break;
      case 115:        //s 
        inverso=119;   //w
        break;
      case 100:        //d
        inverso=97;    //a
        break;
    }

    if(kbhit()){
      sentido = getchar() ;
      if(sentido == 112 ){
        if(sentidoAtual == 112){
          sentidoAtual = sentidoOld;
        } else {
          sentidoOld = sentidoAtual;
          sentidoAtual = sentido;
        }
      } else if ((
        sentido == 119 ||
        sentido == 115 || 
        sentido == 97 || 
        sentido == 100) 
        && sentido != inverso && sentidoAtual !=112){
        MoverSnake(Snake, sentidoAtual);
        sentidoAtual = sentido;
      } 
      fflush(stdout);
    } else if(sentidoAtual == 112 ) {
      fflush(stdout);
    } else {
      fflush(stdout);
      MoverSnake(Snake, sentidoAtual);
    }
    
    usleep(100000);

    if(sentidoAtual != 112){
      Imprime_mapa(Snake, Comida, pontScore, pontGameOver);
      // Imprime_placar(pontScore);
    }
  } while(gameOver == 0);

  GameOver(pontScore, Snake);
}
