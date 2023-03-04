#include "../headers/arquivo.h"

int abreArquivo(char *nome, FILE **farquivo)
{
    *farquivo = fopen(nome, "r");
    if (*farquivo == NULL)
    {
        printf("Erro ao abrir arquivo, verifique se o nome ou diretorio passado esta correto! ");
        system("pause");
        return 1;
    }

    printf("Arquivo aberto com sucesso! ");
    system("pause");

    return 0;
}

int verificaArquivo(FILE *farquivo)
{
    if (farquivo == NULL)
    {
        printf("Erro, arquivo inexistente! ");
        system("pause");
        return 1;
    }

    return 0;
}