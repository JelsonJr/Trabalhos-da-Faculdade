#include "..\headers\criptografaArquivo.h"
#include "..\headers\validacao.h"

char criptoCaractere(char caractere, int senha)
{
    int numASC;
    char ASC;

    if (caractere == ESPACO || caractere == NULO || caractere == LINHA)
        return caractere;

    if (caractere == FIM)
        return ' ';

    numASC = caractere + senha;
    ASC = numASC;

    return ASC;
}

char descriptoCaractere(char caractere, int senha)
{
    int numASC;
    char ASC;

    if (caractere == ESPACO || caractere == NULO || caractere == LINHA)
        return caractere;
    if (caractere == FIM)
        return ' ';

    numASC = caractere - senha;
    ASC = numASC;

    return ASC;
}

void criptografaArquivo(char nome[], int senha, FILE** f, FILE** fc)
{
    *f = fopen(nome, "r");
    *fc = fopen("cripto.txt", "w");

    if (verificaArquivo(*f))
        return;

    char c;
    rewind(*f);
    while (!feof(*f))
    {
        c = criptoCaractere(fgetc(*f), senha);
        putc(c, *fc);
    }

    printf("Criptografia completa!\n");
    fclose(*f);
    fclose(*fc);
}

void descriptografaArquivo(int senha, FILE** fd, FILE** fc)
{
    *fc = fopen("cripto.txt", "r");
    *fd = fopen("descripto.txt", "w");

    if (verificaArquivo(*fc))
        return;

    rewind(*fc);
    char c;
    while (!feof(*fc))
    {
        c = descriptoCaractere(fgetc(*fc), senha);
        putc(c, *fd);
    }

    printf("Descriptografia completa!\n");
    fclose(*fd);
    fclose(*fc);
}
