#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h> 

#include "game.h"
#include "snake.h"

#define LARGURA 41
#define ALTURA 21

int kbhit(void);

int Menu();
void Creditos();
void Imprime_mapa(TSnake *Snake, TSnakeBody *Comida, int *Score, int *GameOver, int SentidoAtual);
void GameOver(int *score, TSnake *Snake);
void Sub_Menu(int *Score, int opcao);
void TxtPlacar(int x, int y, int *Score);
void TxtContinue(int x, int y);
void TxtMenu(int x, int y);
void TxtCreditos(int x, int y);

#endif
