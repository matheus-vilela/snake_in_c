#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "snake.h"

void IniciaJogo(TSnake *Snake, TSnakeBody Comida);
void Mover_Snake(TSnake *Snake, int SentidoAtual, TSnakeBody Comida);

#endif // GAME_H_INCLUDED

