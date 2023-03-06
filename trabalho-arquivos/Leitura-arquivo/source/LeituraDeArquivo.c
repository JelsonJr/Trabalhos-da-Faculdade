#include "../headers/LeituraDeArquivo.h"
#include "../headers/arquivo.h"
#include "../headers/constantes.h"

void numPalavras_char_ln(FILE *farquivo)
{
    int linhas = 1, caracteres = 0, charEspaco = 0, palavras = 0;

    rewind(farquivo);
    while (!feof(farquivo))
    {
        char c;
        c = getc(farquivo);

        if (c == LINHA) linhas++;

        if (c == ESPACO) charEspaco++;

        if (c != LINHA && c != NULO && c != ESPACO && c != FIM) caracteres++;
    }

    rewind(farquivo);
    while (!feof(farquivo))
    {
        char *palavra = malloc(sizeof(char) * caracteres);
        fscanf(farquivo, "%s ", palavra);
        palavras++;
    }

    printf("\nlinhas: %d \npalavras: %d \ncaracteres(sem espaco): %d \ncaracteres(espaco): %d \n\n",
           linhas,
           palavras,
           caracteres,
           charEspaco);

    system("pause");
}

int main()
{
    FILE *farquivo = NULL;
    char nome[100], opcao;

    while (opcao != 'C' && opcao != 'c')
    {
        printf("Bem-vindo! Escolha o que deseja fazer: \n");
        printf("A: Registrar arquivo \nB: Visualizar informacoes \nC: Sair \n");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case 'a':
        case 'A':
            printf("Digite o nome do arquivo ou diretorio: \n");
            scanf("%s", nome);
            abreArquivo(nome, &farquivo);
            break;
        case 'b':
        case 'B':
            if (verificaArquivo(farquivo))
                break;

            numPalavras_char_ln(farquivo);
            break;
        case 'c':
        case 'C':
            printf("Ok!, Ate logo! ");
            system("pause");
            break;
        default:
            printf("Escolha invalida! Digite uma opcao listada.\n");
        }

        Sleep(200);
        system("cls");
    }

    if (farquivo)
        fclose(farquivo);

    return 0;
}