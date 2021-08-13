#ifndef SNAKe_H_INCLUDED
#define SNAKe_H_INCLUDED

typedef struct coordenada {
    int x;
    int y;
} TCoordenada;

typedef struct comida {
    int cor;
    TCoordenada coordenada;
} TSnakeBody;

typedef struct celula {
    TSnakeBody item;
    struct celula* prox;
} TCelula;

typedef struct snake {
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TSnake;

int Vazia(TSnake Snake);
void IniciaSnake(TSnake *Snake);
void LiberarFila(TSnake *Snake);
void Desenfileirar(TSnake *Snake, TSnakeBody *Comida);
void Enfileirar(TSnake *Snake,TSnakeBody Comida);
TSnakeBody CreateBody(int valor, int x, int y);
int VerificaSeExisteNaSnake(TSnake *Snake, int x, int y);
void MoverSnake(TSnake *Snake, int Sentido);
void CriarCabeca(TSnake *Snake);

#endif // SNAKe_H_INCLUDED
