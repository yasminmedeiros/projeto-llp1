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

    fopen("Casa.txt", "w+");

    printf("iCasa = %i \n", iCasa);
    if (fp==NULL){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        printf("Dentro do laco - i = %i \n", i);

        fwrite(&cadcasa[i].casa.nomerua,sizeof(char),1000,fp);
        fwrite(&cadcasa[i].casa.bairro,sizeof(char),1000,fp);
        fwrite(&cadcasa[i].casa.cidade,sizeof(char),1000,fp);
        fwrite(&cadcasa[i].casa.cep,sizeof(char),1000,fp);
        fwrite(&cadcasa[i].casa.numero,sizeof(int),1,fp);
        fwrite(&cadcasa[i].numpav,sizeof(int),1,fp);
        fwrite(&cadcasa[i].numquart,sizeof(int),1,fp);
        fwrite(&cadcasa[i].areat,sizeof(int),1,fp);
        fwrite(&cadcasa[i].areac,sizeof(int),1,fp);
        fwrite(&cadcasa[i].titulo,sizeof(char),1000,fp);
        fwrite(&cadcasa[i].casa.valor,sizeof(float),1,fp);
        fwrite(&cadcasa[i].tipo,sizeof(char),1000,fp);
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
    for (int i = 0; i<iTerreno; i++){
        fwrite(&cadterreno[i].geral.nomerua,sizeof(char),1000,fp);
        fwrite(&cadterreno[i].geral.bairro,sizeof(char),1000,fp);
        fwrite(&cadterreno[i].geral.cidade,sizeof(char),1000,fp);
        fwrite(&cadterreno[i].geral.cep,sizeof(char),1000,fp);
        fwrite(&cadterreno[i].geral.numero,sizeof(int),1,fp);
        fwrite(&cadterreno[i].area,sizeof(int),1,fp);
        fwrite(&cadterreno[i].titulo,sizeof(char),1000,fp);
        fwrite(&cadterreno[i].geral.valor,sizeof(float),1,fp);
        fwrite(&cadterreno[i].tipo,sizeof(char),1000,fp);
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
    for (int i = 0; i<iApartamento; i++){
        fwrite(&cadap[i].ap.nomerua,sizeof(char),1000,fp);
        fwrite(&cadap[i].ap.numero,sizeof(int),1,fp);
        fwrite(&cadap[i].ap.bairro,sizeof(char),1000,fp);
        fwrite(&cadap[i].ap.cidade,sizeof(char),1000,fp);
        fwrite(&cadap[i].ap.cep,sizeof(char),1000,fp);
        fwrite(&cadap[i].numquart,sizeof(int),1,fp);
        fwrite(&cadap[i].numpav,sizeof(int),1,fp);
        fwrite(&cadap[i].areaAp,sizeof(int),1,fp);
        fwrite(&cadap[i].ap.valor,sizeof(float),1,fp);
        fwrite(&cadap[i].titulo,sizeof(char),1000,fp);
        fwrite(&cadap[i].tipo,sizeof(char),1000,fp);
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
    for (int i = 0; i<iApartamento; i++){
        if(feof(fp)){
            break;
        }
        if(cadap[i].ap.nomerua!='\0'){
            fread(&cadap[i].ap.nomerua,sizeof(char),1000,fp);
            fread(&cadap[i].ap.numero,sizeof(char),1000,fp);
            fread(&cadap[i].ap.bairro,sizeof(char),1000,fp);
            fread(&cadap[i].ap.cidade,sizeof(char),1000,fp);
            fread(&cadap[i].ap.cep,sizeof(char),1000,fp);
            fread(&cadap[i].numquart,sizeof(int),1,fp);
            fread(&cadap[i].numpav,sizeof(int),1,fp);
            fread(&cadap[i].areaAp,sizeof(int),1,fp);
            fread(&cadap[i].ap.valor, sizeof(float),1,fp);
            fread(&cadap[i].titulo,sizeof(char),1000,fp);
            fread(&cadap[i].tipo,sizeof(char),1000,fp);
        }
    }

    fclose(fp);
    RepetirOperacao();

}

void LerTerrenoArquivo(){
    //informacoest lista= (cadterreno)malloc(sizeof(informacoest)*tam);

    FILE *fp;

    fp=fopen("Terreno.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iTerreno; i++){
        if(feof(fp)){
            break;
        }
        if(cadterreno[i].geral.nomerua!='\0'){
            fscanf(fp, "%s\n", &cadterreno[i].geral.nomerua);
            fscanf(fp, "%d\n", &cadterreno[i].geral.numero);
            fscanf(fp, "%s\n", &cadterreno[i].geral.bairro);
            fscanf(fp, "%s\n", &cadterreno[i].geral.cidade);
            fscanf(fp, "%s\n", &cadterreno[i].geral.cep);
            fscanf(fp, "%d\n", &cadterreno[i].area);
            fscanf(fp, "%f\n", &cadterreno[i].geral.valor);
            fscanf(fp, "%s\n", &cadterreno[i].tipo);
        }
    }

    fclose(fp);
    RepetirOperacao();

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
        if(cadcasa[i].casa.nomerua!='\0'){
            fscanf(fp, "%s\n", &cadcasa[i].casa.nomerua);
            fscanf(fp, "%s\n", &cadcasa[i].casa.bairro);
            fscanf(fp, "%s\n", &cadcasa[i].casa.cidade);
            fscanf(fp, "%s\n", &cadcasa[i].casa.cep);
            fscanf(fp, "%d\n", &cadcasa[i].casa.numero);
            fscanf(fp, "%d\n", &cadcasa[i].numpav);
            fscanf(fp, "%d\n", &cadcasa[i].numquart);
            fscanf(fp, "%d\n", &cadcasa[i].areat);
            fscanf(fp, "%d\n", &cadcasa[i].areac);
            fscanf(fp, "%s\n", &cadcasa[i].titulo);
            fscanf(fp, "%.2f\n", &cadcasa[i].casa.valor);
            fscanf(fp, "%s", &cadcasa[i].tipo);
        }
    }

    fclose(fp);
    RepetirOperacao();

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

    for(int i=0; i<=iApartamento; i++){
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

void EditarCasa(informacoesa cadcasa[]){
    printf("Lista de Casa\n");
    for(int i=0;i<=iCasa;i++){
        printf("\nCasa %d:", i+1);
        printf("\n");
        CaracteristicasCasa(i);
        printf("\n");

    }
    int j;
    printf("Digite o numero da casa, a qual você deseja editar:");
    scanf("%d",&j);
    j--;
    printf("\t\tEDITAR CASA(S)\n");

    printf("Nome da rua: ");
    fgets(cadcasa[j].casa.nomerua, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadcasa[j].casa.bairro, 100, stdin);
    printf("Nome da cidade: ");
    fgets(cadcasa[j].casa.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadcasa[j].casa.cep, 100, stdin);
    printf("Nu'mero: ");
    scanf("%d", &cadcasa[j].casa.numero);
    printf("Nu'mero de pavimentos: ");
    scanf("%d", &cadcasa[j].numpav);
    printf("Nu'mero de quartos: ");
    scanf("%d", &cadcasa[j].numquart);
    printf("Area do terreno: ");
    scanf("%d", &cadcasa[j].areat);
    printf("Area construida: ");
    scanf("%d%*c", &cadcasa[j].areac);
    printf("Ti'tulo: ");
    fgets(cadcasa[j].titulo, 100, stdin);
    printf("Valor: ");
    scanf("%f%*c", &cadcasa[j].casa.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[j].tipo, 100, stdin);
    cadcasa[j].tipo[strlen(cadcasa[j].tipo)-1] = '\0';

    RepetirOperacao();
}

void EditarApartamento(informacoesa cadap[]){
    printf("Lista de Apartamentos\n");
    for(int i=0;i<=iApartamento;i++){
        printf("\nApartamento %d: ", i+1);
        printf("\n");
        CaracteristicasApartamento(i);
        printf("\n");
    }
    int j;
    printf("Digite o numero do Apartamento, o qual você deseja editar:");
    scanf("%d",&j);
    j--;
    CadastroApartamento(j);
    RepetirOperacao();

}

void EditarTerreno(informacoest cadterreno[]){
    printf("Lista de Terreno\n");
    for(int i=0;i<=iTerreno;i++){
        printf("\nTerreno %d: ", i+1);
        printf("\n");
        CaracteristicasTerreno(i);
        printf("\n");
    }
    int j;
    printf("Digite o terreno, o qual você deseja editar: ");
    scanf("%d",&j);
    j--;

    printf("\t\tEDITAR TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(cadterreno[j].geral.cidade, 100, stdin);
    printf("N�mero do CEP: ");
    fgets(cadterreno[j].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadterreno[j].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(cadterreno[j].geral.nomerua, 100, stdin);
    printf("N�mero da terreno: ");
    scanf("%d%*c", &cadterreno[j].geral.numero);
    printf("�rea do Terreno: ");
    scanf("%d%*c", &cadterreno[j].area);
    printf("�rea do Terreno: ");
    scanf("%f%*c", &cadterreno[j].geral.valor);
    printf("Título: ");
    fgets(cadterreno[j].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadterreno[j].tipo, 100, stdin);
    cadterreno[j].tipo[strlen(cadterreno[pos].tipo)-1] = '\0';

    RepetirOperacao();

}

void CadastroTerreno(int pos){

    printf("\t\tCADASTRO DE TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(cadterreno[pos].geral.cidade, 100, stdin);
    printf("N�mero do CEP: ");
    fgets(cadterreno[pos].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadterreno[pos].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(cadterreno[pos].geral.nomerua, 100, stdin);
    printf("N�mero da terreno: ");
    scanf("%d%*c", &cadterreno[pos].geral.numero);
    printf("�rea do Terreno: ");
    scanf("%d%*c", &cadterreno[pos].area);
    printf("�rea do Terreno: ");
    scanf("%f%*c", &cadterreno[pos].geral.valor);
    printf("Título: ");
    fgets(cadterreno[pos].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadterreno[pos].tipo, 100, stdin);
    cadterreno[pos].tipo[strlen(cadterreno[pos].tipo)-1] = '\0';

    if (cadFlag == 1){
        iTerreno++;
    }
    RepetirOperacao();
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
    scanf("%f%*c", &cadcasa[iCasa].casa.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[iCasa].tipo, 100, stdin);
    cadcasa[iCasa].tipo[strlen(cadcasa[iCasa].tipo)-1] = '\0';
    iCasa++;
    limparTela;
    RepetirOperacao();
}

void CadastroApartamento(int iApartamento){

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
        LerCasaArquivo();
        break;
    case 2:
        CadastroCasa(iCasa);
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
        LerApartamentoArquivo();
        break;
    case 2:
        CadastroApartamento(iApartamento);
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
        LerTerrenoArquivo();
        break;
    case 2:
        CadastroTerreno(iTerreno,1);
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

void SelecionaArquivo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Salvar em Arquivo Casa(s)\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Salvar em Arquivo Apartamento(s)\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Salvar em Arquivo Terreno(s)\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Salvar Todos em Arquivo\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        ArquivoCasa();
        break;
    case 2:
        ArquivoApartamento();
        break;
    case 3:
        ArquivoTerreno();
        break;
    case 4:
        ArquivoApartamento();
        ArquivoCasa();
        ArquivoTerreno();
        break;
    }
}

void SalvarArquivo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf("Deseja salvar em arquivo?\n");
        printf(" %s Sim\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Não\n", (atual.select == 2) ? "->" : "  ");
        Opcoes(2);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        SelecionaArquivo();
        break;
    case 2:
        return 0;
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
        SalvarArquivo();
    }

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
        SalvarArquivo();
    }
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    printf("Aguarde/nProcessando...\n");
    menuPrincipal();
    return 0;
}
