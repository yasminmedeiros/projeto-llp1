#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

//#define limparTela printf("\e[H\e[2J"); //LINUX
#define limparTela system("cls"); //WINDOWS

#define UP 72
#define DOWN 80
#define ENTER 13

typedef struct{
    char nomerua[100], bairro[100], cidade[100], cep[15];
    int numero;
    float valor;
}geral;

typedef struct {
    geral casa;
    char titulo[100], tipo[100];
    int numquart, numpav, areat, areac;
}informacoesc;

typedef struct{
    geral geral;
    int area;
    char titulo[100], tipo[100];
}informacoest;

typedef struct {
    geral ap;
    char titulo[100], tipo[100];
    int numquart, numpav, areaAp;
}informacoesa;

informacoesc cadcasa[1000];
informacoest cadterreno[1000];
informacoesa cadap[1000];

int iTerreno = 0;
int iCasa=0;
int iApartamento=0;

void ArquivoCasa(){

    FILE *fp;

    fopen("Casa.txt", "w");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        fprintf(fp, "%s\n", cadcasa[iCasa].casa.nomerua);
        fprintf(fp, "%s\n", cadcasa[iCasa].casa.bairro);
        fprintf(fp, "%s\n", cadcasa[iCasa].casa.cidade);
        fprintf(fp, "%s\n", cadcasa[iCasa].casa.cep);
        fprintf(fp, "%d\n", cadcasa[iCasa].casa.numero);
        fprintf(fp, "%d\n", cadcasa[iCasa].numpav);
        fprintf(fp, "%d\n", cadcasa[iCasa].numquart);
        fprintf(fp, "%d\n", cadcasa[iCasa].areat);
        fprintf(fp, "%d\n", cadcasa[iCasa].areac);
        fprintf(fp, "%s\n", cadcasa[iCasa].titulo);
        fprintf(fp, "%.2f\n", cadcasa[iCasa].casa.valor);
        fprintf(fp, "%s",cadcasa[iCasa].tipo);
    }

    fclose(fp);
}

void ArquivoTerreno(){

    FILE *fp;

    fopen("Terreno.txt", "w");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        fprintf(fp, "%s\n",cadterreno[iTerreno].geral.nomerua);
        fprintf(fp, "%s\n", cadterreno[iTerreno].geral.bairro);
        fprintf(fp, "%s\n", cadterreno[iTerreno].geral.cidade);
        fprintf(fp, "%s\n", cadterreno[iTerreno].geral.cep);
        fprintf(fp, "%d\n", cadterreno[iTerreno].geral.numero);
        fprintf(fp, "%d\n", cadterreno[iTerreno].area);
        fprintf(fp, "%s\n", cadterreno[iTerreno].titulo);
        fprintf(fp, "%.2f\n", cadterreno[iTerreno].geral.valor);
        fprintf(fp, "%s\n", cadterreno[iTerreno].tipo);
    }

    fclose(fp);
}

void ArquivoApartamento(){

    FILE *fp;

    fopen("Apartamento.txt", "w");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        fprintf(fp, "%s\n", cadap[iApartamento].ap.nomerua);
        fprintf(fp, "%d\n", cadap[iApartamento].ap.numero);
        fprintf(fp, "%s\n", cadap[iApartamento].ap.bairro);
        fprintf(fp, "%s\n", cadap[iApartamento].ap.cidade);
        fprintf(fp, "%s\n", cadap[iApartamento].ap.cep);
        fprintf(fp, "%d\n", cadap[iApartamento].numquart);
        fprintf(fp, "%d\n", cadap[iApartamento].numpav);
        fprintf(fp, "%d\n", cadap[iApartamento].areaAp);
        fprintf(fp, "%f\n", cadap[iApartamento].ap.valor);
        fprintf(fp, "%s\n", cadap[iApartamento].titulo);
        fprintf(fp, "%s\n", cadap[iApartamento].tipo);
    }

    fclose(fp);
}
void LerApartamentoArquivo(){
    //informacoesa lista = (cadap)malloc(sizeof(informacoesa)*tam);

    FILE *fp;

    fp=fopen("Apartamento.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        if(feof(fp)){
            break;
        }
        if(cadap[iApartamento].ap.nomerua!='\0'){
            fscanf(fp, "%s\n", cadap[iApartamento].ap.nomerua);
            fscanf(fp, "%d\n", cadap[iApartamento].ap.numero);
            fscanf(fp, "%s\n", cadap[iApartamento].ap.bairro);
            fscanf(fp, "%s\n", cadap[iApartamento].ap.cidade);
            fscanf(fp, "%s\n", cadap[iApartamento].ap.cep);
            fscanf(fp, "%d\n", cadap[iApartamento].numquart);
            fscanf(fp, "%d\n", cadap[iApartamento].numpav);
            fscanf(fp, "%d\n", cadap[iApartamento].areaAp);
            fscanf(fp, "%f\n", cadap[iApartamento].ap.valor);
            fscanf(fp, "%s\n", cadap[iApartamento].titulo);
            fscanf(fp, "%s\n", cadap[iApartamento].tipo);
        }
    }

    fclose(fp);
}
void LerTerrenoArquivo(){
    //informacoest lista= (cadterreno)malloc(sizeof(informacoest)*tam);

    FILE *fp;

    fp=fopen("Terreno.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        if(feof(fp)){
            break;
        }
        if(cadterreno[iTerreno].geral.nomerua!='\0'){
            fscanf(fp, "%s\n", cadterreno[iTerreno].geral.nomerua);
            fscanf(fp, "%d\n", cadterreno[iTerreno].geral.numero);
            fscanf(fp, "%s\n", cadterreno[iTerreno].geral.bairro);
            fscanf(fp, "%s\n", cadterreno[iTerreno].geral.cidade);
            fscanf(fp, "%s\n", cadterreno[iTerreno].geral.cep);
            fscanf(fp, "%d\n", cadterreno[iTerreno].area);
            fscanf(fp, "%f\n", cadterreno[iTerreno].geral.valor);
            fscanf(fp, "%s\n", cadterreno[iTerreno].tipo);
        }
    }

    fclose(fp);
}
void LerCasaArquivo(){
    //informacoesc lista= (cadcasa)malloc(sizeof(informacoesc)*tam);

    FILE *fp;

    fp=fopen("Casa.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        if(feof(fp)){
            break;
        }
        if(cadcasa[iCasa].casa.nomerua!='\0'){
            fscanf(fp, "%s\n", cadcasa[iCasa].casa.nomerua);
            fscanf(fp, "%s\n", cadcasa[iCasa].casa.bairro);
            fscanf(fp, "%s\n", cadcasa[iCasa].casa.cidade);
            fscanf(fp, "%s\n", cadcasa[iCasa].casa.cep);
            fscanf(fp, "%d\n", cadcasa[iCasa].casa.numero);
            fscanf(fp, "%d\n", cadcasa[iCasa].numpav);
            fscanf(fp, "%d\n", cadcasa[iCasa].numquart);
            fscanf(fp, "%d\n", cadcasa[iCasa].areat);
            fscanf(fp, "%d\n", cadcasa[iCasa].areac);
            fscanf(fp, "%s\n", cadcasa[iCasa].titulo);
            fscanf(fp, "%.2f\n", cadcasa[iCasa].casa.valor);
            fscanf(fp, "%s",cadcasa[iCasa].tipo);
        }
    }

    fclose(fp);
}
void CaracteristicasTerreno(int iTerreno){
    printf("Nome da rua: ");
    printf("%s",cadterreno[iTerreno].geral.nomerua);
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
    printf("%.2f\n", cadcasa[iCasa].casa.valor);
    printf("Tipo de imovel: ");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n");
}

void CaracteristicasApartamento(int iApartamento){
    printf("Nome da rua: ");
    printf("%s", cadap[iApartamento].ap.nomerua);
    printf("Numero: ");
    printf("%d\n", cadap[iApartamento].ap.numero);
    printf("Bairro: ");
    printf("%s", cadap[iApartamento].ap.bairro);
    printf("Cidade: ");
    printf("%s", cadap[iApartamento].ap.cidade);
    printf("CEP: ");
    printf("%s", cadap[iApartamento].ap.cep);
    printf("Quantidade de quartos: ");
    printf("%d\n", cadap[iApartamento].numquart);
    printf("Quantidade de pavimentos: ");
    printf("%d\n", cadap[iApartamento].numpav);
    printf("Area: ");
    printf("%d\n", cadap[iApartamento].areaAp);
    printf("Preço: ");
    printf("%f\n", cadap[iApartamento].ap.valor);
    printf("Titulo: ");
    printf("%s", cadap[iApartamento].titulo);
    printf("Tipo de imovel: [aluguel / venda]");
    printf("%s", cadap[iApartamento].tipo);

}
void VendaTerreno(){
    for(int j=0; j<=iTerreno; j++){
        if(strcmp("venda", cadterreno[j].tipo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

void VendaApartamento(){
    for(int j=0; j<=iApartamento; j++){
        if(strcmp("venda", cadap[j].tipo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

void VendaCasa(){
    for(int j=0; j<=iCasa; j++){
        if(strcmp("venda", cadcasa[j].tipo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

void AlugaTerreno(){
    for(int j=0; j<=iTerreno; j++){
        if(strcmp("aluguel", cadterreno[j].tipo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

void AlugaApartamento(){
    for(int j=0; j<=iApartamento; j++){
        if(strcmp("aluguel", cadap[j].tipo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

void AlugaCasa(){
    for(int j=0; j<=iCasa; j++){
        if(strcmp("aluguel", cadcasa[j].tipo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

void TituloCasa(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iCasa; j++){
        if(strcmp(titulo1, cadcasa[j].titulo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

void TituloApartamento(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iApartamento; j++){
        if(strcmp(titulo1, cadap[j].titulo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

void TituloTerreno(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iTerreno; j++){
        if(strcmp(titulo1, cadterreno[j].titulo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

void BairroCasa(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iCasa; j++){
        if(strcmp(bairro1, cadcasa[j].casa.bairro) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

void BairroApartamento(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iApartamento; j++){
        if(strcmp(bairro1, cadap[j].ap.bairro) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

void BairroTerreno(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iTerreno; j++){
        if(strcmp(bairro1, cadterreno[j].geral.bairro) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

void BuscarPeloPrecoAp(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i <= iApartamento; i++){

            if(cadap[i].ap.valor  >= precoParaBuscar){
                CaracteristicasApartamento(i);
            }
        }

        RepetirOperacao();
}

void BuscarPeloPrecoCasa(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i <= iCasa; i++){

            if(cadcasa[i].casa.valor >= precoParaBuscar){
                CaracteristicasCasa(i);
            }
        }
        RepetirOperacao();
}

void BuscarPeloPrecoTerreno(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i <= iTerreno; i++){

            if(cadterreno[i].geral.valor >= precoParaBuscar){
                CaracteristicasTerreno(i);
            }
        }
    RepetirOperacao();
}

void ListarImoveisAp(){
    int i;

    for(i = 0; i <= iApartamento; i++){
        CaracteristicasApartamento(i);
    }
    RepetirOperacao();
}

void ListarImoveisCasa(){
    int i;

    for(i = 0; i <= iCasa; i++){
        CaracteristicasCasa(i);
    }
    RepetirOperacao();
}

void ListarImoveisTerreno(){
    int i;

    for(i = 0; i <= iTerreno; i++){
        CaracteristicasTerreno(i);
    }
    RepetirOperacao();
}

void RemoverTerreno( informacoest cadterreno[]) {
    printf("Lista de Terrenos/n");

    for(int i=0;i<=iTerreno;i++){
        printf("\nTerreno %d:", i+1);
        CaracteristicasTerreno(i);
    }

    int j;
    printf("Digite o índice do terreno que deseja remover: ");
    scanf("%d", j);

    j--;

    for(; j<iTerreno;j++){
        cadterreno[j] = cadterreno[j+1];
    }

    iTerreno--;
    RepetirOperacao();
}
void RemoverCasa(informacoesc cadcasa[]) {
    printf("Lista de Casas/n");

    for(int i=0;i<=iCasa;i++){
        printf("\nCasa %d:", i+1),
        CaracteristicasCasa(i);
    }

    int j;
    printf("Digite o índice do terreno que deseja remover: ");
    scanf("%d", &j);

    j--;

    for( ; j<iCasa;j++){
        cadcasa[j] = cadcasa[j+1];
    }

    iCasa--;
    RepetirOperacao();
}

void RemoverAp(informacoesc cadap[]) {
    printf("Lista de Apartamentos/n");

    for(int i=0;i<=iApartamento;i++){
        printf("\nApartamento %d:", i+1),
        CaracteristicasApartamento(i);
    }

    int j;
    printf("Digite o índice do terreno que deseja remover: ");
    scanf("%d", j);

    j--;

    for( ; j<iApartamento;j++){
        cadap[j] = cadap[j+1];
    }

    iApartamento--;
    RepetirOperacao();

}

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
    RepetirOperacao();
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
    RepetirOperacao();

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
    RepetirOperacao();

}

void CadastroTerreno(){

    printf("\t\tCADASTRO DE TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(cadterreno[iTerreno].geral.cidade, 100, stdin);
    printf("N�mero do CEP: ");
    fgets(cadterreno[iTerreno].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadterreno[iTerreno].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(cadterreno[iTerreno].geral.nomerua, 100, stdin);
    printf("N�mero da terreno: ");
    scanf("%d%*c", &cadterreno[iTerreno].geral.numero);
    printf("�rea do Terreno: ");
    scanf("%d%*c", &cadterreno[iTerreno].area);
    printf("�rea do Terreno: ");
    scanf("%f%*c", &cadterreno[iTerreno].geral.valor);
    printf("Título: ");
    fgets(cadterreno[iTerreno].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadterreno[iTerreno].tipo, 100, stdin);
    cadterreno[iTerreno].tipo[strlen(cadterreno[iTerreno].tipo)-1] = '\0';
    iTerreno++;
    RepetirOperacao();
}

void CadastroCasa(){

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
    scanf("%f%*c", &cadcasa[iCasa].casa.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[iCasa].tipo, 100, stdin);
    cadcasa[iCasa].tipo[strlen(cadcasa[iCasa].tipo)-1] = '\0';
    iCasa++;
    limparTela;
    RepetirOperacao();
}

void CadastroApartamento(){

    printf("\t\tCADASTRO DE APARTAMENTO(S)\n");

    printf("Nome da rua: ");
    fgets(cadap[iApartamento].ap.nomerua, 100, stdin);
    printf("Numero: ");
    scanf("%i%*c", &cadap[iApartamento].ap.numero);
    printf("Bairro: ");
    fgets(cadap[iApartamento].ap.bairro, 100, stdin);
    printf("Cidade: ");
    fgets(cadap[iApartamento].ap.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadap[iApartamento].ap.cep, 15, stdin);
    printf("Quantidade de quartos: ");
    scanf("%i%*c", &cadap[iApartamento].numquart);
    printf("Quantidade de pavimentos: ");
    scanf("%i%*c", &cadap[iApartamento].numpav);
    printf("Area: ");
    scanf("%i%*c", &cadap[iApartamento].areaAp);
    printf("Digite o preço: ");
    scanf("%f%*c", &cadap[iApartamento].ap.valor);
    printf("Digite o titulo: ");
    fgets(cadap[iApartamento].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadap[iApartamento].tipo, 100, stdin);
    cadap[iApartamento].tipo[strlen(cadap[iApartamento].tipo)-1] = '\0';
    iApartamento++;
    limparTela;
    RepetirOperacao();

}

typedef struct{
    int select;// SETA
    int key; // TECLA
} OpSetas;

OpSetas atual;

void Opcoes (int max){
    atual.key = getch();
    if(atual.key == DOWN) atual.select+= 1;
    if(atual.key == UP) atual.select-= 1;
    if (atual.select > max) atual.select = 1;
    if (atual.select < 1) atual.select = max;
    limparTela;
}

void menuPrincipal(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("----------MOBIL----------");
        puts("");
        printf(" %s Cadastrar\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Remover\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Editar\n", (atual.select == 4) ? "->" : "  ");
        printf(" %s Listar\n", (atual.select == 5) ? "->" : "  ");
        printf(" %s Sair\n", (atual.select == 6) ? "->" : "  ");

        Opcoes(6);

        if(atual.key == ENTER)
            break;

    }

    switch(atual.select)
    {
    case 1:
        Cadastrar();
        break;
    case 2:
        Buscar();
        break;
   case 3:
        Remover();
        break;
    case 4:
        Editar();
        break;
    case 5:
        Listar();
        break;
    case 6:
        return 0;
    }

}
void Listar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Listar Casas\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Listar Apartamentos\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Listar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        ListarImoveisCasa();
        break;
    case 2:
        ListarImoveisAp();
        break;
    case 3:
        ListarImoveisTerreno();
        break;
    case 4:
        menuPrincipal();
        break;

    }
}

void Cadastrar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Cadastrar Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Cadastrar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        SelecionaCasa();
        break;
    case 2:
        SelecionaApartamento();
        break;
    case 3:
        SelecionaTerreno();
        break;

    case 4:
        menuPrincipal();
        break;

    }
}
void SelecionaCasa(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar Casa por Arquivo\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Cadastrar Casa por Teclado\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 3) ? "->" : "  ");
        Opcoes(3);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        //CadastraCasaPorArquivo();
        break;
    case 2:
        CadastroCasa();
        break;

    case 3:
        Cadastrar();
        break;

    }
}
void SelecionaApartamento(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar Apartamento por Arquivo\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Cadastrar Apartamento por Teclado\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 3) ? "->" : "  ");
        Opcoes(3);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        //CadastraApartamentoPorArquivo();
        break;
    case 2:
        CadastroApartamento();
        break;

    case 3:
        Cadastrar();
        break;

    }
}
void SelecionaTerreno(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar Terreno por Arquivo\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Cadastrar Terreno por Teclado\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 3) ? "->" : "  ");
        Opcoes(3);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        //CadastraTerrenoPorArquivo();
        break;
    case 2:
        CadastroTerreno();
        break;

    case 3:
        Cadastrar();
        break;

    }
}
void Remover(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Remover Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Remover Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Remover Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select)
    {

    case 1:
        RemoverCasa(&cadcasa);
        break;
    case 2:
        RemoverAp(&cadap);
        break;
    case 3:
        RemoverTerreno(&cadterreno);
        break;

    case 4:
        menuPrincipal();
        break;

    }
}
void Editar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Editar Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Editar Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Editar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select)
    {

    case 1:
        EditarCasa(&cadcasa);
        break;
    case 2:
        EditarApartamento(&cadap);
        break;
    case 3:
        EditarTerreno(&cadterreno);
        break;
    case 4:
        menuPrincipal();
        break;

    }


}

void Buscar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar por Título\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar por Bairro\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar por Valor\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Buscar Imóvel para Venda\n", (atual.select == 4) ? "->" : "  ");
        printf(" %s Buscar Imóvel para Locação\n", (atual.select == 5) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 6) ? "->" : "  ");

        Opcoes(6);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){
    case 1:
        SelecionaTitulo();
        break;
    case 2:
        SelecionaBairro();
        break;
    case 3:
        SelecionaValor();
        break;
    case 4:
        SelecionaVenda();
    case 5:
        SelecionaLocacao();
    case 6:
        menuPrincipal();
        break;
    }
}
void SelecionaTitulo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Título\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Título\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Título\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        TituloCasa();
        break;
    case 2:
        TituloApartamento();
        break;
    case 3:
        TituloTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}
void SelecionaBairro(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Bairro\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Bairro\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Bairro\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        BairroCasa();
        break;
    case 2:
        BairroApartamento();
        break;
    case 3:
        BairroApartamento();
        break;

    case 4:
        Buscar();
        break;
    }
}
void SelecionaValor(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Valor\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Valor\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Valor\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        BuscarPeloPrecoCasa();
        break;
    case 2:
        BuscarPeloPrecoAp();
        break;
    case 3:
        BuscarPeloPrecoTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}
void SelecionaVenda(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa para Venda\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento para Venda\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno para Venda\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        VendaCasa();
        break;
    case 2:
        VendaApartamento();
        break;
    case 3:
        VendaTerreno();
        break;

    case 4:
        Buscar();
        break;
    }
}
void SelecionaLocacao(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa para Locacao\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento para Locacao\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno para Locacao\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        AlugaCasa();
        break;
    case 2:
        AlugaApartamento();
        break;
    case 3:
        AlugaTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}
void RepetirOperacao(){
    atual.select = 1;

    while (1)
    {
        puts("");
        printf("Deseja Realizar Uma Nova Operação?\n");
        printf(" %s Sim\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Não\n", (atual.select == 2) ? "->" : "  ");
        Opcoes(2);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        menuPrincipal();
        break;
    case 2:
        return 0;
    }

}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    menuPrincipal();
    return 0;
}
