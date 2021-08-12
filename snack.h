#ifndef SNACK_H_INCLUDED
#define SNACK_H_INCLUDED

typedef struct coordenada {
    int x;
    int y;
} TCoordenada;

typedef struct comida {
    int cor;
    TCoordenada coordenada;
} TComida;

typedef struct celula {
    TComida item;
    struct celula* prox;
} TCelula;

typedef struct snack {
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TSnack;

int Vazia(TSnack Snack);
void IniciaSnack(TSnack *Snack);
void ImprimirSnack(TSnack *Snack);
void LiberarFila(TSnack *Snack);
void Desenfileirar(TSnack *Snack, TComida *Comida);
void Enfileirar(TSnack *Snack,TComida Comida);
TComida CriaComida(int valor, int x, int y);
int VerificaSeExisteNaSnack(TSnack *Snack, int x, int y);
void andarSnack(TSnack *Snack, int Sentido);
void CriarCabeca(TSnack *Snack);

#endif // SNACK_H_INCLUDED
