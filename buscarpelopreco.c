#include <stdio.h>

void BuscarPeloPrecoAp(){

float precoParaBuscar;
int i;

printf("Digite o valor a ser buscado: ");
scanf("%f", &precoParaBuscar);
printf("\n");

    for(i = 0; i <= iApartamento; i++){

        if(cadap[i].ap.valor  > precoParaBuscar){
            CaracteristicasApartamento();
        }
    }
}

void BuscarPeloPrecoCasa(){

float precoParaBuscar;
int i;

printf("Digite o valor a ser buscado: ");
scanf("%f", &precoParaBuscar);
printf("\n");

    for(i = 0; i <= iCasa; i++){

        if(cadcasa[i].casa.valor > precoParaBuscar){
            CaracteristicasCasa();
        }
    }
}

void BuscarPeloPrecoTerreno(){

float precoParaBuscar;
int i;

printf("Digite o valor a ser buscado: ");
scanf("%f", &precoParaBuscar);
printf("\n");

    for(i = 0; i <= iTerreno; i++){

        if(cadterreno[i].geral.valor > precoParaBuscar){
            CaracteristicasTerreno();
        }
    }
}
