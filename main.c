#include "interface.h"

int main(){
    int opcao =0;
    do {
        opcao = Menu();
        switch(opcao){
            case 1: IniciaJogo(); 
            break;
            case 2: Creditos(); 
            break;
            case 3: exit(1); 
            break;
        }

    } while(1);
}