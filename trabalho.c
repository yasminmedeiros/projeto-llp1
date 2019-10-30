#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
    char nomerua[100], bairro[100], cidade[100], cep[15];
    int numero; 
    float valor;
}geral;

typedef struct {
    geral casa;
    char titulo[100], tipo[100];
    int numquart, numpav, areat, areac;
} informacoesc;

typedef struct{
    geral geral;
    int area;
    char titulo[100], tipo[100];
}informacoest;

informacoesc cadcasa[1000];
informacoest cadterreno[1000];

int iTerreno = 0;
int iCasa=0;
void CaracteristicasTerreno(int iTerreno){
        printf("Nome da rua: ");
        printf("%s",cadterreno[iTerreno].geral.nomeDaRua);
        printf("Nome do bairro: ");
        printf("%s", cadterreno[iTerreno].geral.bairro);
        printf("Nome da cidade: ");
        printf("%s", cadterreno[iTerreno].geral.cidade);
        printf("CEP: ");
        printf("%s", cadterreno[iTerreno].geral.cep);
        printf("Número: ");
        printf("%d\n", cadterreno[iTerreno].geral.numero);
        printf("Área do terreno: ");
        printf("%d\n", cadterreno[iTerreno].area);
        printf("Ti'tulo: ");
        printf("%s", cadterreno[iTerreno].titulo);
        printf("Valor: ");
        printf("%.2f\n", cadterreno[iTerreno].geral.valor);
        printf("Tipo de imovel: ");
        printf("%s\n", cadterreno[iTerreno].tipo);
        printf("\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n");
        
}

void CaracteristicasCasa(int iCasa){
        printf("Nome da rua: ");
        printf("%s", cadcasa[iCasa].casa.nomerua);
        printf("Nome do bairro: ");
        printf("%s", cadcasa[iCasa].casa.bairro);
        printf("Nome da cidade: ");
        printf("%s", cadcasa[iCasa].casa.cidade);
        printf("CEP: ");
        printf("%s", cadcasa[iCasa].casa.cep);
        printf("Nu'mero: ");
        printf("%d\n", cadcasa[iCasa].casa.numero);
        printf("Nu'mero de pavimentos: ");
        printf("%d\n", cadcasa[iCasa].numpav);
        printf("Nu'mero de quartos: ");
        printf("%d", cadcasa[iCasa].numquart);
        printf("Area do terreno: ");
        printf("%d\n", cadcasa[iCasa].areat);
        printf("Area construida: ");
        printf("%d\n", cadcasa[iCasa].areac);
        printf("Ti'tulo: ");
        printf("%s", cadcasa[iCasa].titulo);
        printf("Valor: ");
        printf("%.2f\n", cadcasa[iCasa].geral.valor);
        printf("Tipo de imovel: ");
        printf("%s",cadcasa[iCasa].tipo);
        printf("\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n");
}
void CadastroTerreno(int iTerreno){

    printf("\t\tCADASTRO DE TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(terreno[iTerreno].geral.cidade, 100, stdin);
    printf("N�mero do CEP: ");
    fgets(terreno[iTerreno].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(terreno[iTerreno].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(terreno[iTerreno].geral.nomeDaRua, 100, stdin);
    printf("N�mero da terreno: ");
    scanf("%d%*c", &terreno[iTerreno].geral.numero);
    printf("�rea do Terreno: ");
    scanf("%d%*c", &terreno[iTerreno].area);
    printf("�rea do Terreno: ");
    scanf("%d%*c", &terreno[iTerreno].geral.valor);
    iTerreno++;
}


void CadastroCasa(int iCasa){

    printf("\t\tCADASTRO DE CASA(S)\n");

    printf("Nome da rua: ");
    fgets(cadcasa[iCasa].casa.nomerua, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadcasa[iCasa].casa.bairro, 100, stdin);
    printf("Nome da cidade: ");
    fgets(cadcasa[iCasa].casa.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadcasa[iCasa].casa.cep, 100, stdin);
    printf("Nu'mero: ");
    scanf("%d", &cadcasa[iCasa].casa.numero);
    printf("Nu'mero de pavimentos: ");
    scanf("%d", &cadcasa[iCasa].numpav);
    printf("Nu'mero de quartos: ");
    scanf("%d", &cadcasa[iCasa].numquart);
    printf("Area do terreno: ");
    scanf("%d", &cadcasa[iCasa].areat);
    printf("Area construida: ");
    scanf("%d%*c", &cadcasa[iCasa].areac);
    printf("Ti'tulo: ");
    fgets(cadcasa[iCasa].titulo, 100, stdin);
    printf("Valor: ");
    scanf("%f%*c", &cadcasa[iCasa].geral.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[iCasa].tipo, 100, stdin);
    cadcasa[iCasa].tipo[strlen(cadcasa[iCasa].tipo)-1] = '\0';
    iCasa++;
    printf("\e[H\e[2J");
}
void TituloCasa(int i){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=i; j++){
        if(strcmp(titulo1, cadcasa[j].titulo) == 0){
            CaracteristicasCasa(j);
        }
    }
}
void TituloApartamento(int i){
    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");
}
void TituloTerreno(int i){
    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");
    
    for (int i=0;i<100;i++){
        if(strcmp(titulo1, terreno[i].) == 0){
        }
    }
}
void BuscarTitulo(int i){
    char titulo1[100];
    int resposta;

    printf("Estilo do imo'vel: \n");
    printf("\t[1] Casa\n\t[2] Apartamento\n\t[3] Terreno\n");
    scanf("%d%*c", &resposta);

    if(resposta == 1){
        TituloCasa(i);
    }else if (resposta == 2){
        printf("Digite o titulo do imovel que deseja procurar: ");
        fgets(titulo1, 100, stdin);
        TituloApartamento(i);
    }else{
        printf("Digite o titulo do imovel que deseja procurar: ");
        fgets(titulo1, 100, stdin);
        TituloTerreno(i);
    }
}
void VendaCasa(int i){


    for(int j=0; j<=i; j++){

        if(strcmp("venda", cadcasa[j].tipo) == 0){
            CaracteristicasCasa(j);

        }
    }
}
void VendaApartamento(int i){
}
void VendaTerreno(int i){

}
void BuscarVenda(int i){
    int resposta;

    printf("Estilo do imo'vel: \n");
    printf("\t[1] Casa\n\t[2] Apartamento\n\t[3] Terreno\n");
    scanf("%d%*c", &resposta);

    if(resposta == 1){
        VendaCasa(i);
    }else if (resposta == 2){
        //VendaApartamento(i);
    }else{
        //VendaTerreno(i);
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    
    return 0;
}
