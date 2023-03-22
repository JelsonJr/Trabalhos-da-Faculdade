#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/forca.h"
#include "../headers/chutesErrados.h"
#include "../headers/enforcou.h"
#include "../headers/revelaPalavraComposta.h"
#include "../headers/adicionaPalavra.h"

char palavraSecreta[TAMANHO_PALAVRA];
char chute;
char errosChute[26];
char chutes[28];
int chutesDados = 0;
int contadorErros = 0;

void chuta()
{
    printf("\n\nQual letra? ");
    scanf(" %c", &chute);

    system("cls");

    int existe = letraExiste(chute, palavraSecreta);
    printf("Voce %s: a palavra%stem a letra %c",
           existe ? "acertou" : "errou",
           existe ? " " : " nao ", chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
        if (!jaChutou(palavraSecreta[i]))
            return 0;

    return 1;
}

int jaChutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesDados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void mostraLetrasChutadas(int erros)
{
    while (contadorErros < erros)
    {
        errosChute[contadorErros] = chute;
        contadorErros++;
    }
    printf("\n Letras erradas ja usadas: ");
    for (int i = 0; i < erros; i++)
        printf("%c ", errosChute[i]);
}

void desenhaForca()
{

    int erros = chutesErrados(chutesDados, chutes, palavraSecreta);

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (jaChutou(palavraSecreta[i]))
            printf("%c ", palavraSecreta[i]);
        else if (palavraSecreta[i] == ' ' || palavraSecreta[i] == '-')
            printf("%c ", palavraSecreta[i]);
        else
            printf("_ ");
    }
    printf("\n");

    mostraLetrasChutadas(erros);
}

int main()
{
    abertura();
    adicionaPalavra(palavraSecreta);
    system("cls");

    do
    {
        desenhaForca();
        revelaPalavraComposta(palavraSecreta, chutes, chutesDados);
        chuta();
    } while (!ganhou() && !enforcou(chutesDados, chutes, palavraSecreta));

    if (ganhou())
    {
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
    }
    else
    {
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