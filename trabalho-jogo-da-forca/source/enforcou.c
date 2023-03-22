#include "../headers/enforcou.h"

int enforcou(int chutesDados, char chutes[28], char palavraSecreta[TAMANHO_PALAVRA])
{
    return chutesErrados(chutesDados, chutes, palavraSecreta) >= 5;
}