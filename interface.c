#include "interface.h"
#include <string.h>
#include <stdio.h>  
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h> 
#include <termios.h>
#include <stdbool.h>

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

void Imprime_mapa(TSnake *Snake, TSnakeBody Comida){
    int existe=0;
    system("clear");
    for(int y=0; y < HEIGHT; y++){
        for(int x=0; x < WIDTH; x++){
            existe = VerificaSeExisteNaSnake(Snake,x,y);
            if(y==0 || y==20 || x==0 || x==40 ){
                printf("\033[0;45m  \033[0;37m");
            } else if(existe != 0) {
                printf("\033[0;3%dm *\033[0;37m", existe);
            } else if(x==Comida.coordenada.x && y==Comida.coordenada.y) {
                printf("\033[0;36m *\033[0;37m");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int Menu(){
    int input,delay=0;
    int y,x;
    int opt;

    system("clear");
    for(y=0; y < HEIGHT; y++){
        for(x=0; x < WIDTH; x++){
            if(y==0 || y==20 || x==0 || x==40 ){
                printf("\033[0;45m  \033[0;37m");
            }else if(y == 6){
                switch(x){
                    case 18:
                       printf("\033[0;44m M\033[0;37m");
                       break;
                    case 19:
                       printf("\033[0;44m E\033[0;37m");
                           break;
                    case 20:
                       printf("\033[0;44m N\033[0;37m");
                           break;
                    case 21:
                       printf("\033[0;44m U\033[0;37m");
                           break;
                    default:
                       printf("\033[0;44m  \033[0;37m"); 
                }

            }else {
                printf("\033[0;44m  \033[0;37m"); 
            }
        }
        printf("\n");
    }

    while (!kbhit()) {
        fflush(stdout);
        usleep(100000);
    }
 
    return getchar();
}

