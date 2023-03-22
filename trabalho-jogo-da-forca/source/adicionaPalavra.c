#include "../headers/adicionaPalavra.h"

void adicionaPalavra(char palavraSecreta[TAMANHO_PALAVRA])
{
    printf("Digite a nova palavra, em letras maiusculas: ");
    fgets(palavraSecreta, TAMANHO_PALAVRA, stdin);

    palavraSecreta[strcspn(palavraSecreta, "\n")] = '\0';
}