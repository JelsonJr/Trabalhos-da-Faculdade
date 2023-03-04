#include "../headers/arquivo.h"

int abreArquivo(FILE **farquivo, char *nome) {
    *farquivo = fopen(nome, "r");
    if (!(*farquivo)) {
        printf("Erro ao abrir arquivo, verifique se o nome ou diretorio passado esta correto!\n");
        return 1;
    }

    printf("Arquivo aberto com sucesso! (Pressione qualquer tecla para prosseguir)");
    getch();
    return 0;
}

int verificaArquivo(FILE *farquivo) {
    if (!farquivo) {
        printf("Erro, arquivo inexistente!");
        system("pause");
        return 1;
    }

    return 0;
}