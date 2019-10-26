#include <stdio.h>
#include <string.h>

typedef struct{
    char nomerua[100], bairro[100], cidade[100], cep[15];
    int numero;
}geral;

typedef struct {
    geral casa;
    char titulo[100], tipo[100];
    int numpav, areat, areac;
    float valor;
} informacoesc;

informacoesc cadcasa[1000];


void CadastroCasa(int i){

    printf("\t\tCADASTRO DE CASA(S)\n");

    printf("Nome da rua: ");
    fgets(cadcasa[i].casa.nomerua, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadcasa[i].casa.bairro, 100, stdin);
    printf("Nome da cidade: ");
    fgets(cadcasa[i].casa.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadcasa[i].casa.cep, 100, stdin);
    printf("Nu'mero: ");
    scanf("%d", &cadcasa[i].casa.numero);
    printf("Nu'mero de pavimentos: ");
    scanf("%d", &cadcasa[i].numpav);
    printf("Area do terreno: ");
    scanf("%d", &cadcasa[i].areat);
    printf("Area construida: ");
    scanf("%d%*c", &cadcasa[i].areac);
    printf("Ti'tulo: ");
    fgets(cadcasa[i].titulo, 100, stdin);
    printf("Valor: ");
    scanf("%f%*c", &cadcasa[i].valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[i].tipo, 100, stdin);
    cadcasa[i].tipo[strlen(cadcasa[i].tipo)-1] = '\0';
    printf("\e[H\e[2J");


}
void TituloCasa(int i){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=i; j++){

        if(strcmp(titulo1, cadcasa[j].titulo) == 0){
            printf("Nome da rua: ");
            printf("%s", cadcasa[j].casa.nomerua);
            printf("Nome do bairro: ");
            printf("%s", cadcasa[j].casa.bairro);
            printf("Nome da cidade: ");
            printf("%s", cadcasa[j].casa.cidade);
            printf("CEP: ");
            printf("%s", cadcasa[j].casa.cep);
            printf("Nu'mero: ");
            printf("%d\n", cadcasa[j].casa.numero);
            printf("Nu'mero de pavimentos: ");
            printf("%d\n", cadcasa[j].numpav);
            printf("Area do terreno: ");
            printf("%d\n", cadcasa[j].areat);
            printf("Area construida: ");
            printf("%d\n", cadcasa[j].areac);
            printf("Ti'tulo: ");
            printf("%s", cadcasa[j].titulo);
            printf("Valor: ");
            printf("%.2f\n", cadcasa[i].valor);
            printf("Tipo de imovel: ");
            printf("%s",cadcasa[i].tipo);
            printf("\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
            printf("\n");
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
            printf("Nome da rua: ");
            printf("%s", cadcasa[j].casa.nomerua);
            printf("Nome do bairro: ");
            printf("%s", cadcasa[j].casa.bairro);
            printf("Nome da cidade: ");
            printf("%s", cadcasa[j].casa.cidade);
            printf("CEP: ");
            printf("%s", cadcasa[j].casa.cep);
            printf("Nu'mero: ");
            printf("%d\n", cadcasa[j].casa.numero);
            printf("Nu'mero de pavimentos: ");
            printf("%d\n", cadcasa[j].numpav);
            printf("Area do terreno: ");
            printf("%d\n", cadcasa[j].areat);
            printf("Area construida: ");
            printf("%d\n", cadcasa[j].areac);
            printf("Ti'tulo: ");
            printf("%s", cadcasa[j].titulo);
            printf("Valor: ");
            printf("%.2f\n", cadcasa[i].valor);
            printf("Tipo de imovel: ");
            printf("%s",cadcasa[i].tipo);
            printf("\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
            printf("\n");
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
    int i=0, resposta = 1;
    char titulo1[100];

    // Cadastro de casas

    CadastroCasa(i);

    while(resposta == 1){
        printf("Fazer um novo cadastro?\n"
                "\t[1] SIM\n\t[2] NAO\n");
        scanf("%d%*c", &resposta);

        printf("\e[H\e[2J");
        if (resposta == 1){
            i++;
            CadastroCasa(i);
        }else
            break;
    }

    printf("\e[H\e[2J");

    //BuscarTitulo(i);
    BuscarVenda(i);

    return 0;
}
