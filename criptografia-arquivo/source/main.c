#include "..\headers\CriptografaArquivo.h"
#include "..\headers\validacao.h"
#include "..\headers\constantes.h"

int main()
{
    FILE *f = NULL, *fc = NULL, *fd = NULL;
    char nome[100], validador, opcao;
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
            
            validador = getchar();
            if (validaSenha(validador)) break;

            scanf("%d", &senha);
            criptografaArquivo(nome, senha, &f, &fc);
            break;
        case 'd':
        case 'D':
            printf("Digite a senha: \n");

            validador = getchar();
            if (validaSenha(validador)) break;

            scanf("%d", &senha);
            descriptografaArquivo(senha, &fd, &fc);
            break;
        case 's':
        case 'S':
            printf("Ok! Ate logo! ");
            system("pause");
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

    return 0;
}