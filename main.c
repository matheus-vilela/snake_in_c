
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "snack.h"

int main(){

    TSnack Snack;
    IniciaSnack(&Snack);
    CriarCabeca(&Snack);
    TComida Comida = CriaComida(6,16,3);
    Imprime_mapa(&Snack, Comida);
    Andar_snack(&Snack, 1, Comida);

    return 0;
}
