#include "../headers/revelaPalavraComposta.h"

void revelaPalavraComposta(char palavraSecreta[TAMANHO_PALAVRA], char chutes[28], int chutesDados)
{
    int tamanho;
    char chute;
    tamanho = strlen(palavraSecreta) - 1;

    for (int i = 0; i <= tamanho; i++)
    {
        if (palavraSecreta[i] == '-')
        {
            chute = '-';
            chutes[chutesDados] = chute;
            chutesDados++;
        }
        if (palavraSecreta[i] == ' ')
        {
            chute = ' ';
            chutes[chutesDados] = chute;
            chutesDados++;
        }
    }
}