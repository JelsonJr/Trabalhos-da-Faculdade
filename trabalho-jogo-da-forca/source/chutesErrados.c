#include "../headers/chutesErrados.h"

int chutesErrados(int chutesDados, char* chutes, char* palavraSecreta)
{
    int erros = 0;

    for (int i = 0; i < chutesDados; i++)
        if (!letraExiste(chutes[i], palavraSecreta))
            erros++;

    return erros;
}
