#include "../headers/letraExiste.h"

int letraExiste(char letra, char* palavraSecreta)
{
    for (int j = 0; j < strlen(palavraSecreta); j++)
        if (letra == palavraSecreta[j])
            return 1;

    return 0;
}