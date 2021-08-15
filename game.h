#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "interface.h"
#include "snake.h"

void IniciaJogo();
void Mover(TSnake *Snake, int Sentido);
int VerificaJogada(TSnake *Snake, TSnakeBody *Comida, int x, int y, int *GameOver,int *Score, int SentidoAtual);
int VerificaSeExisteNaSnake(TSnake *Snake, int x, int y);


#endif // GAME_H_INCLUDED

