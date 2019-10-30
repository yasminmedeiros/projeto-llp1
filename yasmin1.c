#include <stdio.h>
#include <locale.h>

#define UP 72
#define DOWN 80
#define ENTER 13

//#define limparTela printf("\e[H\e[2J"); //LINUX
#define limparTela system("cls"); //WINDOWS

typedef struct
{
    int select;// SETA
    int key; // TECLA
} OpSetas;

OpSetas atual;

void Opcoes (int max)
{
    atual.key = getch();
    if(atual.key == DOWN) atual.select+= 1;
    if(atual.key == UP) atual.select-= 1;
    if (atual.select > max) atual.select = 1;
    if (atual.select < 1) atual.select = max;
    limparTela;
}

void menuPrincipal()
{
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Remover\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Editar\n", (atual.select == 4) ? "->" : "  ");
        printf(" %s Sair\n", (atual.select == 5) ? "->" : "  ");

        Opcoes(5);

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
 /*)   case 3:
        Remover();
        break;
    case 4:
        Editar();
        break;
*/
    case 5:
        return 0;
    }

}

void Cadastrar()
{
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

    switch(atual.select)
    {
        /*
    case 1:
        CadastrarCasa();
        break;
    case 2:
        CadastrarApartamento();
        break;
    case 3:
        CadastrarTerreno();
        break;
        */
    case 4:
        menuPrincipal();
        break;

    }


}

void Buscar()
{
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");

        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select)
    {
        /*)
    case 1:
        consultar();
        break;
    case 2:
        consultar();
        break;
    case 3:
        consultar();
        break;
        */
    case 4:
        menuPrincipal();
        break;
    }


}
int main(void){
    menuPrincipal();
    return 0;
}

