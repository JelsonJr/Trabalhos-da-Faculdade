#include "../headers/enforcou.h"

int enforcou(int chutesDados, char* chutes, char* palavraSecreta)
{
    return chutesErrados(chutesDados, chutes, palavraSecreta) >= 5;
}