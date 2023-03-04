#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* farquivo;

int verificaArquivo() {
    if(!farquivo) {
        printf("Erro, arquivo inexistente!");
        system("pause");
        return 1;
    }

    return 0;
}

void numPalavras_char_ln() {
    int linhas = 1, caracteres = 0, charEspaco = 0, palavras = 0;

    if(verificaArquivo()) return;

    rewind(farquivo);
    while(!feof(farquivo)) {
        char c;
        c = getc(farquivo);

        if(c == 10) linhas++;
        if(c == 32) charEspaco++;
        if(c != 10 && c != 0 && c != 32 && c != -1) caracteres++;
    }

    rewind(farquivo);
    while(!feof(farquivo)) {
        char* palavra = malloc(sizeof(char) * caracteres);
        fscanf(farquivo, "%s ", palavra);
        palavras++;
    }
    
    printf("linhas: %d \npalavras: %d \ncaracteres(sem espaco): %d \ncaracteres(espaco): %d \n",
        linhas,
        palavras, 
        caracteres, 
        charEspaco
    );
    system("pause");
}

void abreArquivo(char *nome) {
    farquivo = fopen(nome, "r");
    if(!farquivo) {
        printf("Erro ao abrir arquivo, verifique se o nome ou diretorio passado esta correto!\n");
        system("pause");
        return;
    } 

    printf("Arquivo aberto com sucesso!\n");
    system("pause");
}

int main() {
    char nome[100], opcao;
    
    while(opcao != 'C' && opcao != 'c') {
        printf("Bem-vindo! Escolha o que deseja fazer: \n");
        printf("A: Registrar arquivo \nB: Visualizar informacoes \nC: Sair \n");
        scanf("%c", &opcao);

        switch(opcao) {
            case 'a':
            case 'A': 
                printf("Digite o nome do arquivo ou diretorio: \n");
                scanf("%s", &nome);
                abreArquivo(nome);
                break;
            case 'b':
            case 'B': 
                numPalavras_char_ln();
                break;
            case 'c':
            case 'C': 
                printf("Ok!, Ate logo! \n");
                break;
            default: 
                printf("Escolha invalida! Digite uma opcao listada.");
        }
    }

    system("pause");
    fclose(farquivo);

    return 0;
}