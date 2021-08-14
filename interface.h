#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h> 
#include <termios.h>
#include <stdbool.h>

#include "game.h"
#include "snake.h"

#define WIDTH 41
#define HEIGHT 21

#define LENTO 1
#define NORMAL 2
#define RAPIDO 3
#define ULTRA 4

void Imprime_mapa(TSnake *Snake, TSnakeBody *Comida, int *Score, int *GameOver, int SentidoAtual);
void Sub_Menu(int *Score, int opcao);
void TxtPlacar(int x, int y, int *Score);
void TxtContinue(int x, int y);
int Menu();
int kbhit(void);
void Creditos();

#endif // INTERFACE_H_INCLUDED
