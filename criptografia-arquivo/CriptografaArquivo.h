#include <stdio.h>

int verificaArquivo(FILE *f);
char descriptoCaractere(char caractere, int senha);
char criptoCaractere(char caractere, int senha);
void descriptografaArquivo(int senha);
void criptografaArquivo(int senha, char nome[]);