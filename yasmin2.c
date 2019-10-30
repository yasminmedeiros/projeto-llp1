#include <stdio.h>
#include <string.h>
#include<locale.h>
#include<stdlib.h>

typedef struct{
    char nomeDaRua[100], bairro[100], cidade[100], cep[11];
    int numero, valor;
}geral;
typedef struct{
    geral geral;
    int area;
}_terreno;

_terreno terreno[100];
int iTerreno = 0;

void CadastroTerreno(int i){

    printf("\t\tCADASTRO DE TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(terreno[i].geral.cidade, 100, stdin);
    printf("Número do CEP: ");
    fgets(terreno[i].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(terreno[i].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(terreno[i].geral.nomeDaRua, 100, stdin);
    printf("Número da terreno: ");
    scanf("%d%*c", &terreno[i].geral.numero);
    printf("Área do Terreno: ");
    scanf("%d%*c", &terreno[i].area);
    printf("Área do Terreno: ");
    scanf("%d%*c", &terreno[i].geral.valor);
    i++;
}
void BuscaBairro (_terreno terreno, _casa casa, _apartamento apartamento) {
    char bairro[100];
    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(bairro, 100, stdin);

    printf("/nTerrenos Encontrados Neste Bairro: /n");

    for (int i=0;i<100;i++){
        if(strcmp(bairro, terreno[i].geral.bairro) == 0){
            printf("Nome da rua: ");
            printf("%s", terreno[i].geral.nomeDaRua);
            printf("Nome do bairro: ");
            printf("%s", terreno[i].geral.bairro);
            printf("Nome da cidade: ");
            printf("%s", terreno[i].geral.cidade);
            printf("CEP: ");
            printf("%s", terreno[i].geral.cep);
            printf("Número: ");
            printf("%d\n", terreno[i].geral.numero);
            printf("Área do terreno: ");
            printf("%d\n", cadcasa[j].areat);
            printf("Valor: ");
            printf("%.2f\n", cadcasa[i].valor);
            printf("Tipo de imovel: Terreno");
            printf("\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
            printf("\n");
        }
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    CadastroTerreno(iTerreno);
    return 0;
}
