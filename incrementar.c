#include <stdio.h>

void EditarApartamento(informacoesa cadap[]){
    printf("Lista de Casa/n");
    for(int i=0;i<=iCasa;i++){
        printf("\nCasa %d:", i+1),
        CaracteristicasCasa(i);
    }
    int j;
    printf("Digite o casa, o qual você deseja editar:");
    scanf("%d",&j);
    j--;
    CadastroCasa(j);

}

void EditarCasa(informacoesc cadcasa[]){
    printf("Lista de Apartamentos/n");
    for(int i=0;i<=iApartamento;i++){
        printf("\nApartamento %d:", i+1),
        CaracteristicasApartamento(i);
    }
    int j;
    printf("Digite o apartamento, o qual você deseja editar:");
    scanf("%d",&j);
    j--;
    CadastroApartamento(j);

}

void EditarTerreno(informacoest cadterreno[]){
    printf("Lista de Terreno/n");
    for(int i=0;i<=iTerreno;i++){
        printf("\nTerreno %d:", i+1),
        CaracteristicasTerreno(i);
    }
    int j;
    printf("Digite o terreno, o qual você deseja editar:");
    scanf("%d",&j);
    j--;
    CadastroTerreno(j);

}

void EditarCasa (informacoesc cadcasa[]){
    printf("Lista de Casas/n");
    for(int i=0;i<=iCasa;i++){
        printf("\nCasa %d:", i+1),
        CaracteristicasCasa(i);
    }
}
void EditarTerreno(informacoest cadterreno[]){
    printf("Lista de Terrenos/n");
    for(int i=0;i<=iTerreno;i++){
        printf("\nTerreno %d:", i+1);
        CaracteristicasTerreno(i);
    }
}

int main(){


    return 0;
}
