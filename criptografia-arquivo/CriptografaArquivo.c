#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *f, *fc, *fd;

int verificaArquivo(FILE *f)
{
    if (!f)
    {
        printf("Arquivo nao encontrado!\n");
        system("pause");
        return 1;
    }

    return 0;
}

char criptoCaractere(char caractere, int senha)
{
    int numASC;
    char ASC;

    if (caractere == 32 || caractere == 0 || caractere == 10)
        return caractere;
    if (caractere == -1)
        return ' ';

    numASC = caractere + senha;
    ASC = numASC;

    return ASC;
}

char descriptoCaractere(char caractere, int senha)
{
    int numASC;
    char ASC;

    if (caractere == 32 || caractere == 0 || caractere == 10)
        return caractere;
    if (caractere == -1)
        return ' ';

    numASC = caractere - senha;
    ASC = numASC;

    return ASC;
}

void criptografaArquivo(char nome[], int senha)
{
    f = fopen(nome, "r");
    fc = fopen("cripto.txt", "w");

    if (verificaArquivo(f))
        return;

    char c;
    rewind(f);
    while (!feof(f))
    {
        c = criptoCaractere(fgetc(f), senha);
        putc(c, fc);
    }

    printf("Criptografia completa!\n");
    fclose(f);
    fclose(fc);
}

void descriptografaArquivo(int senha)
{
    fc = fopen("cripto.txt", "r");
    fd = fopen("descripto.txt", "w");

    if (verificaArquivo(f))
        return;

    rewind(fc);
    char c;
    while (!feof(fc))
    {
        c = descriptoCaractere(fgetc(fc), senha);
        putc(c, fd);
    }

    printf("Descriptografia completa!\n");
    fclose(fd);
    fclose(fc);
}

int main()
{
    char nome[100], c, opcao;
    int senha;

    printf("Bem vindo, escolha uma das opcoes a seguir: \n");
    while (opcao != 'S' && opcao != 's')
    {
        printf("(C) - Criptografar\n(D) - Descriptografar\n(S) - Sair\n\n");
        scanf("%c", &opcao);

        switch (opcao)
        {
        case 'c':
        case 'C':
            printf("Digite o nome do arquivo para a criptografia: \n");
            scanf("%s", &nome);

            printf("Digite a senha numerica (a mesma senha devera ser usada para descriptografar): \n");
            c = getchar();

            while ((c = getchar()) != '\n')
            {   
                printf("entrou no while");
                if (!isdigit(c))
                {
                    printf("Erro: a senha deve ser um numero inteiro.\n");
                    c = 's';
                    break;
                }
            }

            if(c == 's') break;
            scanf("%d", &senha);

            criptografaArquivo(nome, senha);
            break;
        case 'd':
        case 'D':
            printf("Digite a senha: \n");
            scanf("%d", &senha);

            descriptografaArquivo(senha);
            break;
        case 's':
        case 'S':
            printf("Ok! Ate logo!\n\n");
            break;
        default:
            printf("Opcao invalida! Escolha uma das opcoes listadas!\n\n");
            break;
        }

        fflush(stdin);
        system("cls");
    }

    fclose(f);
    fclose(fc);
    fclose(fd);

    system("pause");
    return 0;
}