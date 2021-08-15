#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

int Vazia(TSnake Snake) {
    return (Snake.frente == Snake.tras);
}

void Desenfileirar(TSnake *Snake, TSnakeBody *Item){
    TCelula* aux;
    if (!Vazia(*Snake)){
        aux = Snake->frente->prox;
        Snake->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Snake->frente->prox == NULL)
            Snake->tras = Snake->frente;
        Snake->tamanho--;
    }
}

void Enfileirar(TSnake *Snake, TSnakeBody x) {
    Snake->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Snake->tras = Snake->tras->prox;
    Snake->tras->item = x;
    Snake->tras->prox = NULL;
    Snake->tamanho++;
}

void IniciaSnake(TSnake *Snake) {
    Snake->frente = (TCelula*) malloc(sizeof(TCelula));
    Snake->tras = Snake->frente;
    Snake->frente->prox = NULL;
    Snake->tamanho = 0;
}

TSnakeBody CreateBody(int cor, int x, int y) {
    TSnakeBody body;
    body.coordenada.x = x;
    body.coordenada.y = y;
    body.cor = cor;
    return body;
}

void CriarCabeca(TSnake *Snake) {
    TSnakeBody headerSnake;
    srand(time(NULL));
    for(int i=0; i<4;i++){
        headerSnake = CreateBody(1+(rand()%5),15,15+i);
        Enfileirar(Snake, headerSnake);
    }
}

void LiberarSnake(TSnake *Snake){
    TSnakeBody auxItem;
    while(!Vazia(*Snake)){
        Desenfileirar(Snake, &auxItem);
    }
    free(Snake->frente);
}

