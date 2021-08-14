#include "interface.h"
#include <string.h>
#include <stdio.h>  
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <sys/ioctl.h> 
#include <termios.h>
#include <stdbool.h>
#include "game.h"

int kbhit(void) {
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes); 
    return nbbytes;
}

void TxtPlacar(int x, int y, int *Score){
         if(x== 0 || x== 40 ||y==0 || y==6){
                 printf("\033[0;47m  \033[0;37m");
            } else if( y== 2){
                switch(x){
                    case 15:
                        printf("\033[0;37m S C O R E :\033[0;37m");
                        break;
                    case 16 ... 20:
                            break;
                    case 22:
                        if(*Score > 9){
                            printf("\033[0;37m%d\033[0;37m", *Score);
                        } else {
                            printf("\033[0;37m %d\033[0;37m", *Score);
                        }
                            break;
                    default:
                        printf("\033[0;35m  \033[0;37m"); 
                }
            } else if( y== 4){
                switch(x){
                    case 4:
                        printf("\033[0;37mTeclas: \033[0;37m");
                        break;
                    case 5 ... 9:
                            break;
                    case 11:
                        printf("\033[0;37m<W>,<A>,<S>,<D>\033[0;37m");
                            break;
                    case 12 ... 14:
                        printf("\033[0;37m\033[0;37m");
                            break;
                    case 28:
                        printf("\033[0;37mPause:\033[0;37m");
                            break;
                    case 29 ... 32:
                            break;
                    case 33:
                        printf("\033[0;37m<P>\033[0;37m");
                            break;
                    default:
                        printf("\033[0;35m  \033[0;37m"); 
                }
            } else {
                  printf("\033[0;35m  \033[0;37m"); 
            }
}

void TxtContinue(int x, int y){
         if(x== 0 || x== 40 ||y==0 || y==6){
                 printf("\033[0;47m  \033[0;37m");
            } else if( y== 2){
                switch(x){
                    case 15:
                        printf("\033[0;37m JOGAR NOVAMENTE ?\033[0;37m");
                        break;
                    case 16 ... 23:
                            break;
                    default:
                        printf("\033[0;35m  \033[0;37m"); 
                }
            } else if( y== 4){
                switch(x){
                    case 11:
                        printf("\033[0;37mSim Digite: <1>    Não Digite: <2>\033[0;37m");
                        break;
                    case 12 ... 27:
                            break;
                    default:
                        printf("\033[0;35m  \033[0;37m"); 
                }
            } else {
                  printf("\033[0;35m  \033[0;37m"); 
            }
}

void Sub_Menu(int *score, int opcao){
    for(int y=0; y < 7; y++){
        for(int x=0; x < WIDTH; x++){
            if(opcao == 1){

            TxtPlacar(x,y,score);
            }else {
                TxtContinue(x,y);
            }
        }
        printf("\n");
    }
}

void Imprime_mapa(TSnake *Snake, TSnakeBody *Comida, int *score, int *gameOver, int SentidoAtual){
    int existe=0;
    int addComida = 0;
    TSnakeBody cabeca;

    system("clear");
    for(int y=0; y < HEIGHT; y++){
        for(int x=0; x < WIDTH; x++){
            existe = VerificaSeExisteNaSnake(Snake,x,y);
            if(existe != 0 &&(x== 0 || x== 40 ||y==0 || y==20)){
                *gameOver = 1;
                printf("\033[0;3%dm *\033[0;37m", existe);
            } if(y==0 || y==20 || x==0 || x==40 ){
                printf("\033[0;45m  \033[0;37m");
            } else if(existe != 0) {
                if(existe > 10){
                    *gameOver = 1;
                    printf("\033[0;3%dm *\033[0;37m", existe-10);
                } else {
                    printf("\033[0;3%dm *\033[0;37m", existe);
                }
                if(x==Comida->coordenada.x && y==Comida->coordenada.y && addComida == 0){
                    *score = *score +1;
                    if(existe == Comida->cor){
                        if(Snake->tamanho >= 4){
                            MoverSnake(Snake, SentidoAtual);
                            Desenfileirar(Snake, &cabeca);
                        }
                    } else{
                        Enfileirar(Snake, *Comida);
                    }
                    Comida->coordenada.x = 1 + rand()%39;
                    Comida->coordenada.y = 1 + rand()%19;
                    Comida->cor = 1 + rand()%5;
                    addComida = 1;
                }
            } else if(x==Comida->coordenada.x && y==Comida->coordenada.y) {
                printf("\033[0;3%dm *\033[0;37m", Comida->cor);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    Sub_Menu(score, 1);
}

int Menu(){
    int input,delay=0;
    int y,x;
    int opt = 12;
    do{
    system("clear");
    for(y=0; y < HEIGHT; y++){
        for(x=0; x < WIDTH; x++){
            if(y==0 || y==20 || x==0 || x==40 ){
                printf("\033[0;45m  \033[0;37m");
            }else if(y == 6){
                switch(x){
                    case 18:
                        printf("\033[0;40m M E N U\033[0;37m");
                        break;
                    case 19 ... 21:
                        break;
                    default:
                       printf("\033[0;40m  \033[0;37m"); 
                }

            }else if (y == 12){
                switch(x){
                    case 14:
                        if(opt == 12){
                             printf("\033[0;40m\033[1;36m->\033[0;36m"); 
                        } else {
                            printf("\033[0;40m  \033[0;37m");  
                        }
                        break;
                    case 17:
                        if(opt == 12){
                            printf("\033[0;40m\033[1;36m  J O G A R \033[0;37m");
                        } else {
                            printf("\033[0;40m  J O G A R \033[0;37m");
                        }
                        break;
                    case 19 ... 23:
                        break;
                    default:
                       printf("\033[0;40m  \033[0;37m"); 
                }

            }else if(y == 14){
                switch(x){
                    case 14:
                        if(opt == 14){
                            printf("\033[0;40m\033[1;36m->\033[0;36m"); 

                        } else {
                            printf("\033[0;40m  \033[0;37m");  
                        }
                        break;

                    case 16:
                        if(opt == 14){
                            printf("\033[0;40m\033[1;36m C R E D I T O S\033[0;37m");
                        } else {
                            printf("\033[0;40m C R E D I T O S\033[0;37m");
                        }
                        break;
                    case 17 ... 23:
                        break;
                    default:
                        printf("\033[0;40m  \033[0;37m"); 
                }

            }else if(y == 16){
                switch(x){
                    case 14:
                        if(opt == 16){
                            printf("\033[0;40m\033[1;36m->\033[0;36m"); 
                        } else {
                            printf("\033[0;40m  \033[0;37m");  
                        }
                        break;
                    case 18:
                        if(opt == 16){
                            printf("\033[0;40m\033[1;36m S A I R\033[0;37m");

                        } else {
                            printf("\033[0;40m S A I R\033[0;37m");
                        }
                        break;
                    case 19 ... 21:
                        break;
                    default:
                       printf("\033[0;40m  \033[0;37m"); 
                }

            }
            else if(y == 19){
                switch(x){
                    case 28 ... 33:
                    break;
                    case 34:
                        printf("\033[0;40m\033[1;36mCopyright@ UFOP - 2021\033[0;37m");
                        break;
                    case 36 ... 39:
                        break;
                    default:
                       printf("\033[0;40m  \033[0;37m"); 
                }

            }
            
            else {
                printf("\033[1;40m  \033[0;37m"); 
            }
        }
        printf("\n");
    }

    while (!kbhit()) {
        fflush(stdout);
        usleep(100000);
    }

    input = getchar();
    if(input == 115){
        if(opt<16){
         opt =opt+2;
        }
    }else if (input == 119){
        if(opt>12){
         opt =opt-2;
        } 
    } 
    }while(input != '\n');

    return opt = (opt == 12) ? 1 : (opt == 14) ? 2: (opt == 16) ? 3 : 1;
}

