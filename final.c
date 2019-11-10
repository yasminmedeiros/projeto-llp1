/*

Projeto da Disciplina de Introdu��o � Prorama��o e da Disciplina de Laborat�rio de Introdu��o � Programa��o

    Autores: Yasmin Kely Lucena de Medeiros
             Raissa da Silva Vieira
             Victoria Monteiro Pontes

    Objetivo: Programa que cripta e decripta em morse, cifra de C�sar e uma linguagem criada pelas participantes do grupo.

    Entrada: A sele��o de acordo com o menu e a mensagem a ser criptada ou decriptada.

    Sa�da: Mensagem criptada ou decriptada, de acordo com a sele��o do usu�rio.

*/
#include <stdio.h>
#include <ctype.h>
#include <conio.h>


//Galeria de fun��es:

/*
EncriptarVicyra(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem encriptada de acordo com a cifra Vicyra]

    Par�metro:
        *codigo : [Array que carrega a mensagem a ser encriptada na cifra Vicyra]

*/

void EncriptarVicyra(char *codigo){
            int i, l;
             // Declaracao de arrays que possuem o alfabeto em portugues e o traduzido para Vicyra
            char letra[]={"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
            char nosso[]={"ooccffkkttaaxxpphhssqqbbwwyyzznnlljjuuiivveeddggrrmm"};

            for (i=0; codigo[i]!= '\0' ;i++){ //Pecorre o "codigo" ate o \0 fazendo comparacoes
                if (codigo[i]==' '){
                        printf(" ");
                }else{
                    for(l=0;l<sizeof(letra)-1;l++){
                        if (codigo[i]==letra[l]){ // Se o elemento analisado for igual ao do elemento do alfabeto, pegara o indice dele e entao sera printado o do codigo Vicyra correspondente
                            printf("%c", nosso[l]);
                        }
                    }
                }
            }
}
/*
EncriptarCesar(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem encriptada de acordo com a cifra de C�sar,
                   e a chave tamb�m inserida pelo usu�rio]

    Par�metros:
        chave(entrada): [Par�metro que vai indicar qual a letra, a partir de sua posi��o indicada pelo respectivo n�mero inteiro,
                         ir� representar a primeira letra, e come�ar� o novo alfabeto deslocado chave vezes do alfabeto normal]
        mensagem[](entrada): [Array que carrega a mensagem a ser encriptada na cifra de C�sar]

*/

 void EncriptarCesar (int chave, char mensagem[]) {
            int i, j;
            int alfabetoLength = 26;
            char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
            'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            /*H� 26 letras (elementos) nesse array que ser�o utilizadas juntamente com a chave para definir por qual elemento do array
            a letra da mensagem ser� trocada*/

            char Encriptado[1000];

            for(i = 0; mensagem[i] != '\0'; i++) {
                if(mensagem[i] == ' '){
                    Encriptado[i] = ' ';
                    continue;
                }
                for(j = 0; j < alfabetoLength; j++) {
                /* Essa parte do c�digo ir� analisar e comparar a mensagem digitada (vetor de caracateres mensagem[]) com o vetor
                caracteres alfabeto[]) */

                    if (mensagem[i] == alfabeto[j]) {

                        if (j + chave < alfabetoLength) {
                            Encriptado[i] = alfabeto[j + chave];

                        }else if (j + chave > alfabetoLength - 1){
                            int v, chave2;
                            v = alfabetoLength - j;
                            chave2 = chave - v;
                            Encriptado[i] = alfabeto[chave2];

                        }
                    }
                }
            }
            Encriptado[i] = '\0';

            printf("%s\n", Encriptado);
    }

/*
EncriptarMorse(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem encriptada de acordo com o codigo Morse]

    Par�metro:
        *codigo : [Array que carrega a mensagem a ser encriptada no codigo Morse]

*/

void EncriptarMorse(char *codigo){
        int j, l;
        // Declaracao de arrays que possuem o alfabeto em portugues e o traduzido para codigo Morse
        static char Alfabeto[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
        static char morse[][11] = {".- ", ".- ", "-... ", "-... ", "-.-. ", "-.-. ", "-.. ", "-.. ", ". ", ". ", "..-. ", "..-. ",
                                   "--. ", "--. ", ".... ", ".... ", ".. ", ".. ", ".--- ", ".--- ", "-.- ", "-.- ", ".-.. ", ".-.. ",
                                   "-- ", "-- ", "-. ", "-. ", "--- ", "--- ", ".--. ", ".--. ", "--.- ", "--.- ", ".-. ", ".-. ", "... ", "... ",
                                   "- ", "- ", "..- ", "..- ", "...- ", "...- ", ".-- ", ".-- ", "-..- ", "-..- ","-.-- ","-.-- ", "--.. ", "--.. "};

       for(j=0;codigo[j] != '\0';j++){ //Pecorre o "codigo" ate o \0 fazendo comparacoes
            if (codigo[j] == ' ')
                    printf("// ");

            else {
                for(l=0; l < sizeof(Alfabeto)-1; l++){
                    if (codigo[j] == Alfabeto[l]){
                        codigo[j] = l; // Se o elemento analisado for igual ao do elemento do alfabeto, pegara o indice dele e entao sera printado o do codigo morse correspondente
                        printf("%s", morse[l]);
                    }
                }
           }
        }
}

/*
DecriptarVicyra(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem deecriptada de acordo com a cifra Vicyra]

    Par�metros:
        *codigo [Array que carrega a mensagem a ser decriptada na cifra Vicyra]

*/

void DecriptarVicyra(char *codigo){
        int i, l;
        char letra[]={"abcdefghijklmnopqrstuvwxyz"};
        char nosso[]={"ocfktaxphsqbwyznljuivedgrm"};

        for (i=0; codigo[i]!='\0';i++){ //Pecorre o "codigo" ate o \0 fazendo comparacoes
            if (codigo[i]==' '){
                    printf(" ");
            }else{
                for(l=0;l<sizeof(letra)-1;l++){ // Se o elemento analisado for igual ao do elemento do Vicyra, pegara o indice dele e entao sera printado o do alfabeto correspondente
                    if (codigo[i]==nosso[l]){
                        printf("%c", letra[l]);
                    }
                    if (codigo[i]==' '){
                        printf(" ");
                    }
                }
            }
        }
}

/*
decriptarCesar(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem deecriptada de acordo com a cifra de C�sar e com a chave
                   informada pelo usu�rio]

    Par�metros:
        chave(entrada): [Par�metro que vai indicar qual a letra, a partir de sua posi��o indicada pelo respectivo n�mero inteiro,
                         ir� representar a primeira letra, e formar� o novo alfabeto deslocado chave vezes do alfabeto normal,
                         este que ser� utilizado para decriptar a mensagem do usu�rio]
        mensagem[](entrada): [Array que carrega a mensagem a ser decriptada na cifra de C�sar]

*/

void DecriptarCesar1 (int chave, char *Encriptado)
{
    int i, j;
    int alfabetoLength = 26;
    char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    //H� uma mensagem que ser� decriptada de acordo com a chave, fazendo o caminho reverso da fun��o encriptarCesar/

    char mensagem[100000];

    for(i = 0; Encriptado[i] != '\0'; i++){
        if (Encriptado[i] == ' '){
            mensagem[i] = ' ';
            continue;
        }
        for(j = 0; j < alfabetoLength; j++){
            if (Encriptado[i] == alfabeto[j]){
                int reversao = j - chave;

                if ( reversao >= 0){
                    mensagem[i] = alfabeto[reversao];

                }
                else if (reversao < 0){
                    mensagem[i] = alfabeto[alfabetoLength + reversao];

                }
            }
        }
    }
    printf("%s", mensagem);
}

/*
DecriptarMorse(): [Fun��o que se utiliza de um algoritmo para retornar a mensagem deecriptada de acordo com o codigo Morse]

    Par�metros:
        *codigo [Array que carrega a mensagem a ser decriptada no codigo Morse]

*/

void DecriptarMorse(char *codigo){
    int j, l;
    char Alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    static char *codigo2 = NULL;
    char morse[][11] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--..","//"};

    codigo2 = strtok(codigo, " "); // Separa o "codigo" em varias strings a serem analisadas

        while(codigo2){

            for(l=0; l < sizeof(Alfabeto)-1; l++){
                if (strcmp(codigo2, morse[l]) == 0){ // A partir de comparacoes, vai ser printado o elemento correspondente
                    printf("%c", Alfabeto[l]);
                }
            }

            if (strcmp(codigo2, "//") == 0){
                printf(" ");
            }

            codigo2 = strtok( NULL, " " );
        }
}

/*
menu1(): [Ser� exposto na tela o primeiro menu, no qual o usu�rio ir� selecionar
          se ir� criptar ou decriptar]

    resultado(sa�da):[Retorna qual entre as op�o�es foi selecionada pelo usu�rio]

*/

int menu1(){
    char selecao;
    int resultado;

    printf("Selecione uma das opcoes abaixo para continuar\n"); //Selecionar a op�ao que o usuario que usar
    printf("\t  [1] Criptografar\n"
           "\t  [2] Decriptar\n");
    while(1){
        selecao = getch();
        if(selecao == 224)
            selecao = getch();

        if(selecao == 80){
            system("cls");
            printf("-=-=-=-=-=-= BEM VINDO AO CRIPTSCRIPT =-=-=-=-=-=-\n");
            printf("Selecione uma das opcoes abaixo para continuar\n"); //Selecionar a op�ao que o usuario quer usar
            printf("\t  [1] Criptografar\n"
                   "\t->[2] Decriptar\n");
            resultado = 2;
        }
        if(selecao == 72){
            system("cls");
            printf("-=-=-=-=-=-= BEM VINDO AO CRIPTSCRIPT =-=-=-=-=-=-\n");
            printf("Selecione uma das opcoes abaixo para continuar\n"); //Selecionar a op�ao que o usuario quer usar
            printf("\t->[1] Criptografar\n"
                   "\t  [2] Decriptar\n");
            resultado = 1;
        }

        if(selecao == '\r'){
            return resultado;
            break;
        }
    }

}

/*
menu2(): [Ser� exposto na tela o segundo menu, no qual o usu�rio ir� selecionar
          selecionar em qual linguagem ele ir� criptar ou decriptar]

    resultado(sa�da):[Retorna qual entre as op�o�es foi selecionada pelo usu�rio]

*/

int menu2 (void){
    int selecao1, selecao2,selecao3;
    int resultado;

    printf("Selecione a cifra/codigo: \n");
    printf("\t  [1] Vicyra\n"
           "\t  [2] Cesar\n"
           "\t  [3] Morse\n");

    while(1){
        selecao1 = getch();
        if(selecao1 == 224)
            selecao1 = getch();

        if(selecao1==80){
            system("cls");
            printf("Selecione a cifra/codigo: \n");
            printf("\t->[1] Vicyra\n"
                   "\t  [2] Cesar\n"
                   "\t  [3] Morse\n");
            resultado=1;
        }
        if(selecao1 == '\r' || selecao2 == '\r' ||selecao3 == '\r'){
            system("cls");
            return resultado;
            break;
        }
        selecao2 = getch();

        if(selecao2 == 224)
            selecao2 = getch();

        if(selecao2==80){
            system("cls");
            printf("Selecione a cifra/codigo: \n");
            printf("\t  [1] Vicyra\n"
                   "\t->[2] Cesar\n"
                   "\t  [3] Morse\n");
            resultado=2;
        }
        if(selecao1 == '\r' || selecao2 == '\r' ||selecao3 == '\r'){
            system("cls");
            return resultado;
            break;
        }
        selecao3 = getch();

        if(selecao3 == 224)
            selecao3 = getch();

        if(selecao3==80){
            system("cls");
            printf("Selecione a cifra/codigo: \n");
            printf("\t  [1] Vicyra\n"
                   "\t  [2] Cesar\n"
                   "\t->[3] Morse\n");

            resultado=3;
        }
        if(selecao1 == '\r' || selecao2 == '\r' ||selecao3 == '\r'){
            system("cls");
            return resultado;
            break;
        }
    }
}

//  Entrada na fun��o main, onde ir� se desenrolar todo o c�digo

int main(){

    int opcao1, opcao2;
    int chave;
    char codigo[1000];

    printf("-=-=-=-=-=-= BEM VINDO AO CRIPTSCRIPT =-=-=-=-=-=-\n"); //incializa��o do programa

    opcao1= menu1(); //chamada de funcao do primeiro menu, op��o 1 ir� receber qual entres as  op��es foi selecionada

    system("cls"); //limpeza de tela

    opcao2=menu2();//chamada de funcao do segundo menu, op��o 2 ir� receber qual entres as  op��es foi selecionada

    //chamada de funcao
    //opcao2 = tipo(opcao1);

    if (opcao1 == 1){ //Criptar

        printf("Digite a mensagem a ser encriptada: ");
        fgets(codigo,1000,stdin); // Leitura de "codigo" que vai ser usado como paramentro

        // Dependendo da escolha do usuario, uma determinada funcao de criptar vai ser chamada
        if(opcao2 == 1){ // Vicyra
            printf("Mensagem encriptada:\n");
            EncriptarVicyra(codigo);
        }
        else if (opcao2 == 2){ // Cifra de Cesar
            printf("Digite a chave: ");
            scanf("%d%*c", &chave);

            //strlwr(mensagem);

            printf("Mensagem encriptada:\n");
            EncriptarCesar (chave, codigo);
        }
        else if(opcao2 == 3){ // Codigo Morse
            printf("Mensagem encriptada:\n");
            EncriptarMorse(codigo);
        }
        printf("\n");
    }
    else if(opcao1 == 2){ // Decriptar
        printf("Digite a mensagem a ser decriptada: ");
        fgets(codigo, 1000, stdin); // Leitura de "codigo" que vai ser usado como paramentro

        if(opcao2 == 1){ // Vicyra
            printf("Mensagem decriptada:\n");
            DecriptarVicyra(codigo);
        }
        else if (opcao2 == 2){ // Cifra de Cesar
            printf("Digite a chave: ");
            scanf("%d%*c", &chave);

            //strlwr(mensagem);

            printf("Mensagem decriptada:\n");
            DecriptarCesar1(chave, codigo);
        }
        else if(opcao2 == 3){ // Codigo Morse
            codigo[strlen(codigo)-1] = '\0'; // Substituicao do \n lido por \0
            printf("Mensagem decriptada:\n");
            DecriptarMorse(codigo);
        }
        printf("\n");
    }

    return 0;
}
