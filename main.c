#include <stdio.h>
#include <stdlib.h>

typedef struct endereco 
{
    char cidade[100];
    char rua[100];
    char bairro[100];
    int num;
}t_endereco;

typedef struct casa
{
    int id;
    char titulo[100];
    int areaDoTerreno;
    int numeroDeQuartos;
    float preco;
    int opcao;
    t_endereco enderecoDaCasa;
}t_casa;

typedef struct terreno
{
    int id;
    float area;
    float preco;
    int opcao;
    t_endereco enderecoDoTerreno;
}t_terreno;

typedef struct apartamento
{
    int id;
    int opcao;
    int area;
    int numeroDeQuartos;
    int andar;
    int vagasNaGaragem;
    float preco;
    t_endereco enderecoDoApartamento;
}t_apartamento;

t_casa casas[500];
t_terreno terrenos[500];
t_apartamento apartamentos[500];
t_apartamento apartamentos[].id = {0};

int cadastrarApartamento(t_apartamento &apartamentos, int id)
{
    // Pega o dado referente a alugar ou vender
    printf("1 - Vender\n2 - Alugar\nDigite: ");
    scanf("%i", &apartamentos[id]->opcao);
    // Pega a área
    printf("Digite a area do apartamento: ");
    scanf("%i", &apartamentos[id]->area);
    // Pega o andar o apartamento
    printf("Digite o andar: ");
    scanf("%i", &apartamentos[id]->andar);
    // Pega o endereço
    printf("Digite o endereco: \nRua: ");
    fgets(apartamentos[id]->enderecoDoApartamento.rua, 100, stdin);
    printf("Digite o numero: ");
    scanf("%i", &apartamentos[id]->enderecoDoApartamento.num);
    printf("Digite o bairro: ");
    fgets(apartamentos[id]->enderecoDoApartamento.bairro, 100, stdin);
    printf("Digite a cidade: ");
    fgets(apartamentos[id]->enderecoDoApartamento.cidade, 100, stdin);
    // Pega o numero de quartos
    printf("Digite o numero de quartos: ");
    scanf("%i", &apartamentos[id]->numeroDeQuartos);
    // Pega o preco
    printf("Digite o preco: ");
    scanf("%f", &apartamentos[id]->preco);
    // Pega a quantidade de vagas na garagem
    printf("Digite a quantidade de vagas na garagem: ");
    scanf("%i", &apartamentos[id]->vagasNaGaragem);
}

int idDisponivel(int id){
    for(int i = 0; i < 0; i++){
        if(apartamentos[id].id == 0){
            id = i;
        }
    }
    return apartamentos[id].id;
}

int main(void){

int id;
idDisponivel(id);
printf("%i", id);

    return 0;
}
