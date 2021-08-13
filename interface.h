#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "snake.h"
#include "interface.h"

#define WIDTH 41
#define HEIGHT 21

#define LENTO 1
#define NORMAL 2
#define RAPIDO 3
#define ULTRA 4

#define FALSE 0
#define TRUE 1

// #define VERMELHO     "\x1b[31m"
// #define VERDE   "\x1b[32m"
// #define AZUL    "\x1b[34m"
// #define RESET   "\x1b[0m"

// Foreground:

// 30 Black
// 31 Red
// 32 Green
// 33 Yellow
// 34 Blue
// 35 Magenta
// 36 Cyan
// 37 White

// Background:

// 40 Black
// 41 Red
// 42 Green
// 43 Yellow
// 44 Blue
// 45 Magenta
// 46 Cyan
// 47 White

// 0 Reset all
// 1 Bold

void Imprime_mapa(TSnake *Snake, TSnakeBody Comida);
int Menu();
int kbhit(void);

#endif // INTERFACE_H_INCLUDED
