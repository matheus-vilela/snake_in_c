#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "snake.h"

void IniciaJogo(TSnake *Snake, TSnakeBody *Comida);
void Mover_Snake(TSnake *Snake, int SentidoAtual, TSnakeBody *Comida);
void GameOver(int *score, TSnake *Snake);

#endif // GAME_H_INCLUDED

