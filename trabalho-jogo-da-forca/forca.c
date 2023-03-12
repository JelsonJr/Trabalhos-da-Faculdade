#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavraSecreta[TAMANHO_PALAVRA];
char chute; char errosChute[26]; char chutes[26];
int chutesDados = 0; int contadorErros = 0;

int letraExiste(char letra) {
    for(int j = 0; j < strlen(palavraSecreta); j++) 
        if(letra == palavraSecreta[j])
            return 1;

    return 0;
}

int chutesErrados() {
    int erros = 0;

    for(int i = 0; i < chutesDados; i++)
        if(!letraExiste(chutes[i]))
            erros++;

    return erros;
}

int enforcou() {
    return chutesErrados() >= 5;
}

int ganhou() {
    for(int i = 0; i < strlen(palavraSecreta); i++)
        if(!jaChutou(palavraSecreta[i]))
            return 0;

    return 1;
}

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n\n");
}

void revelaPalavraComposta() {
    int tamanho;
    char chute;
    tamanho = strlen(palavraSecreta) - 1;

    for(int i = 0; i<=tamanho; i++){
        if(palavraSecreta[i] == '-'){
            chute = '-';
            chutes[chutesDados] = chute;
            chutesDados++;
        }
        if(palavraSecreta[i] == ' '){
            chute = ' ';
            chutes[chutesDados] = chute;
            chutesDados++;
        }
    }
}

void chuta(){
    printf("\n\nQual letra? ");
    scanf(" %c", &chute);

    system("cls");

    if(letraExiste(chute))
        printf("\nVoce acertou: a palavra tem a letra %c\n\n", chute);
    else
        printf("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void mostraLetrasChutadas(int erros) {
     while(contadorErros<erros){
        errosChute[contadorErros] = chute;
        contadorErros++;
    }
    printf("\n Letras erradas ja usadas: ");
    for(int i = 0; i<erros; i++)
        printf("%c ", errosChute[i]);
}

void desenhaForca() {

    int erros = chutesErrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavraSecreta); i++) {
        if(jaChutou(palavraSecreta[i]))
            printf("%c ", palavraSecreta[i]);
        else if(palavraSecreta[i] == ' ' || palavraSecreta[i] == '-')
            printf("%c ", palavraSecreta[i]);
        else
            printf("_ ");
    }
    printf("\n");

   mostraLetrasChutadas(erros);
}

void adicionaPalavra() {
    printf("Digite a nova palavra, em letras maiusculas: ");
    gets(palavraSecreta);
}

int main() {
    abertura();
    adicionaPalavra();
    system("cls");

    do {
        desenhaForca();
        revelaPalavraComposta();
        chuta();
    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        desenhaForca();

        printf("\nParabens, voce ganhou!\n\n");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        system("cls");

        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);
        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    return 0;
}