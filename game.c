#include "game.h"

void IniciaJogo(){
    int opcao = 0;
    int sentidoAntigo = 119;
    int sentidoAtual = 119;
    int sentidoNovo;
    int score = 0;
    int gameOver= 0;

    TSnake Snake;
    IniciaSnake(&Snake);
    CriarCabeca(&Snake);
    TSnakeBody Comida = CreateBody(1+rand()%6,1+rand()%39,1+rand()%19);

    int *pontGameOver;
    pontGameOver = &gameOver; 
    int *pontScore;
    pontScore = &score; 

    do{
        if(kbhit()){
            sentidoNovo = getchar() ;
            if(sentidoNovo == 'p'){
                if(sentidoAtual == 'p'){
                sentidoAtual = sentidoAntigo;
                } else {
                sentidoAntigo = sentidoAtual;
                sentidoAtual = sentidoNovo;
                }
            } 
            else if (
                (sentidoNovo == 'w' && sentidoAtual != 's') ||
                (sentidoNovo == 's' && sentidoAtual != 'w') ||
                (sentidoNovo == 'a' && sentidoAtual != 'd') ||
                (sentidoNovo == 'd' && sentidoAtual != 'a')
                ) {
                sentidoAtual = sentidoNovo;
                fflush(stdout);
            }
            while (kbhit() != 0)
                getchar();
        } else {
            fflush(stdout);
        }

        if(sentidoAtual != 'p' && sentidoAtual !='P'){
            Mover(&Snake, sentidoAtual);
        }
        
        usleep(100000);

        if(sentidoAtual != 'p' && sentidoAtual !='P'){
            Imprime_mapa(&Snake, &Comida,  pontScore,  pontGameOver, sentidoAtual);
        }

    } while(gameOver == 0);
    
    do{
        while(!kbhit()){
            GameOver(pontScore, &Snake);
            fflush(stdout);
            usleep(100000);
        }

        opcao = getchar();
        if(opcao == 49){
            LiberarSnake(&Snake);
            IniciaJogo();
        }
    }while(opcao != 49 && opcao != 50);
}

void Mover(TSnake *Snake, int SentidoAtual){
    TSnakeBody aux1;
    TSnake saux1;
    IniciaSnake(&saux1);

    int cabeca = 0;
    TCoordenada coord, coord1;
    
    while(!Vazia(*Snake)){
        Desenfileirar(Snake, &aux1);
        if(cabeca == 0){
            coord = aux1.coordenada;
            if(SentidoAtual == 119){
                aux1.coordenada.y--;
            } else if(SentidoAtual == 115){
                aux1.coordenada.y++;
            } else if(SentidoAtual == 97){
                aux1.coordenada.x--;
            } else {
                aux1.coordenada.x++;
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
        Enfileirar(Snake, aux1);
    }
}

int VerificaJogada(TSnake *Snake, TSnakeBody *Comida, int x, int y, int *gameOver, int *score, int SentidoAtual){
    TSnakeBody cabeca;
    int existe = VerificaSeExisteNaSnake(Snake, x ,y);

    if(existe != 0 &&(x== 0 || x== 40 ||y==0 || y==20) || existe > 10){
        *gameOver = 1;
    }

    if(x==Comida->coordenada.x && y==Comida->coordenada.y && existe != 0){
        *score = *score +1;
        if(existe == Comida->cor){
            if(Snake->tamanho >= 4){
                Mover(Snake, SentidoAtual);
                Desenfileirar(Snake, &cabeca);
            }
        } else{
            Enfileirar(Snake, *Comida);
        }
        Comida->coordenada.x = 1 + rand()%39;
        Comida->coordenada.y = 1 + rand()%19;
        Comida->cor = 1 + rand()%5;
    }

    return existe;
}



