#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snack.h"



TComida CriaComida(int valor, int x, int y) {
    TComida newFood;
    newFood.coordenada.x = x;
    newFood.coordenada.y = y;
    newFood.cor = valor;
    return newFood;
}

int VerificaSeExisteNaSnack(TSnack *Snack, int x, int y){
    TComida aux1;
    TSnack saux1;
    IniciaSnack(&saux1);
    int existe = 7;

    while(!Vazia(*Snack)){
        Desenfileirar(Snack, &aux1);
        if(aux1.coordenada.x == x && aux1.coordenada.y == y){
            existe = aux1.cor;
        }
        Enfileirar(&saux1, aux1);
    }
    while(!Vazia(saux1)){
        Desenfileirar(&saux1, &aux1);
        Enfileirar(Snack, aux1);
    }
    return existe;
}

void IniciaSnack(TSnack *Snack) {
    Snack->frente = (TCelula*) malloc(sizeof(TCelula));
    Snack->tras = Snack->frente;
    Snack->frente->prox = NULL;
    Snack->tamanho = 0;
}

void CriarCabeca(TSnack *Snack) {
    TComida headerSnack;
    for(int i=0; i<4;i++){
        headerSnack = CriaComida(1+i,15,15-i);
        Enfileirar(Snack, headerSnack);
    }
}



int Vazia(TSnack Snack) {
    return (Snack.frente == Snack.tras);
}

void Enfileirar(TSnack *Snack,TComida x) {
    Snack->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Snack->tras = Snack->tras->prox;
    Snack->tras->item = x;
    Snack->tras->prox = NULL;
    Snack->tamanho++;
}

void Desenfileirar(TSnack *Snack, TComida *Item){
    TCelula* aux;
    if (!Vazia(*Snack)){
        aux = Snack->frente->prox;
        Snack->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Snack->frente->prox == NULL)
            Snack->tras = Snack->frente;
        Snack->tamanho--;
    }
}

void LiberarSnack(TSnack *Snack){
    TComida auxItem;
    while(!Vazia(*Snack)){
        Desenfileirar(Snack, &auxItem);
    }
    free(Snack->frente);
}

void ImprimirSnack(TSnack *Snack){
    TComida auxItem;
    int N;
    N = Snack->tamanho;
    printf("{ ");
    while(N > 0){
        Desenfileirar(Snack, &auxItem);
        printf(" %d ", auxItem.cor);
        Enfileirar(Snack, auxItem);
        N--;
    }
    printf(" }");
}

void andarSnack(TSnack *Snack, int SentidoAtual){
    TComida aux1;
    TSnack saux1;
    IniciaSnack(&saux1);

    int cabeca = 0;
    TCoordenada coord, coord1;
    while(!Vazia(*Snack)){
        Desenfileirar(Snack, &aux1);
        if(cabeca == 0){
            coord = aux1.coordenada;
            if(SentidoAtual == 1){
                aux1.coordenada.y ++;
                if(aux1.coordenada.y >= 29){
                    aux1.coordenada.y --;
                    aux1.coordenada.x ++;
                }
            } else if(SentidoAtual == 2){
                aux1.coordenada.x ++;
                if(aux1.coordenada.x >19){
                    aux1.coordenada.x --;
                    aux1.coordenada.y ++;
                }
            } else if(SentidoAtual == 3){
                aux1.coordenada.y--;
                if(aux1.coordenada.y < 1){
                    aux1.coordenada.y ++;
                    aux1.coordenada.x --;
                }
            } else {
                aux1.coordenada.x--;
                    if(aux1.coordenada.x < 1){
                    aux1.coordenada.x ++;
                        aux1.coordenada.y --;
                }
            }
            cabeca=1;
        } else {
            coord1 = aux1.coordenada;
            aux1.coordenada = coord;
            coord = coord1;
        }

        Enfileirar(&saux1, aux1);
    }
    while(!Vazia(saux1)){
        Desenfileirar(&saux1, &aux1);
        Enfileirar(Snack, aux1);
    }
}






