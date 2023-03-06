#include "../headers/LeituraDeArquivoMain.h"
#include "../headers/arquivo.h"
#include "../headers/constantes.h"

void numPalavras_char_ln(FILE *farquivo) {
    int linhas = 1, caracteres = 0, charEspaco = 0, palavras = 0;

    rewind(farquivo);
    while (!feof(farquivo)) {
        char c;
        c = getc(farquivo);

        if (c == LINHA) linhas++;

        if (c == ESPACO) charEspaco++;

        if (c != LINHA && c != NULO && c != ESPACO && c != FIM) caracteres++;
    }

    rewind(farquivo);
    while (!feof(farquivo)) {
        char *palavra = malloc(sizeof(char) * caracteres);
        fscanf(farquivo, "%s ", palavra);
        palavras++;
    }

    printf("\n\nlinhas: %d \npalavras: %d \ncaracteres(sem espaco): %d \ncaracteres(espaco): %d \n",
           linhas,
           palavras,
           caracteres,
           charEspaco);
}

int main(int argc, char *argv[]) {
    FILE *farquivo = NULL;

    if (argc != 2) {
        printf("Parametros invalidos, passe apenas o nome do arquivo!");
        return -1;
    }

    if(abreArquivo(&farquivo, argv[1])) exit(1);
    if (verificaArquivo(farquivo)) exit(1);

    numPalavras_char_ln(farquivo);

    fclose(farquivo);
    getch();
    
    return 0;
}
