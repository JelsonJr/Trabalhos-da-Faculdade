#include "..\headers\validacao.h"

int verificaArquivo(FILE *f)
{
    if (f == NULL)
    {
        printf("Arquivo nao encontrado!\n");
        system("pause");
        return 1;
    }

    return 0;
}

int validaSenha(char c)
{
    while ((c = getchar()) != '\n')
    {
        if (!isdigit(c))
        {
            printf("Erro: a senha deve ser um numero inteiro.\n");
            c = 's';
            return 1;
        }
        return 0;
    }
}