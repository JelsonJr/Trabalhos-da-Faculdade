#include "arquivo.h"

int abreArquivo(char *nome, FILE** farquivo) {
    *farquivo = fopen(nome, "r");
    if(!*farquivo) {
        printf("Erro ao abrir arquivo, verifique se o nome ou diretorio passado esta correto!\n");
        system("pause");
        return;
    } 

    printf("Arquivo aberto com sucesso!\n");
    system("pause");
}