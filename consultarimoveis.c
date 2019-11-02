#include <stdio.h>

void ListarImoveisAp(){
int i;

    for(i = 0; i <= iApartamento; i++){
        CaracteristicasApartamento(i);
    }
}

void ListarImoveisCasa(){
int i;

    for(i = 0; i <= iCasa; i++){
        CaracteristicasCasa(i);
    }
}

void ListarImoveisTerreno(){
int i;

    for(i = 0; i <= iTerreno; i++){
        CaracteristicasTerreno(i);
    }
}
