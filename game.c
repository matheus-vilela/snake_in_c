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


void Mover_Snake(TSnake *Snake, int SentidoAtual, TSnakeBody Comida){
  int acao;

  switch (SentidoAtual){
    case 119:
      acao = 1;
      break;
    case 97:
      acao = 2;
      break;
    case 115:
      acao = 3;
      break;
    case 100:
      acao = 4;
      break;
  }

  MoverSnake(Snake, acao);

}

void IniciaJogo(TSnake *Snake, TSnakeBody Comida){
  int opcao =0;
  int sentidoAtual = 119;
  int sentido, inverso, aux;
  do{
    Imprime_mapa(Snake, Comida);
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

    while (!kbhit()) {
      fflush(stdout);
      // Mover_Snake(Snake, sentidoAtual, Comida);
      MoverSnake(Snake, sentidoAtual);
      Imprime_mapa(Snake, Comida);
      usleep(100000);
    }

    sentidoAtual = getchar();

    if((sentidoAtual == 119 ||sentidoAtual == 115 || sentidoAtual == 97 || sentidoAtual == 100) && sentidoAtual != inverso){
      MoverSnake(Snake, sentidoAtual);
    } 
    usleep(100000);
  } while(1);
}
