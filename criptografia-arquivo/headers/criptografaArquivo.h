#include <stdio.h>
#include <stdlib.h>
#include "..\headers\constantes.h"

char descriptoCaractere(char caractere, int senha);
char criptoCaractere(char caractere, int senha);
void criptografaArquivo(char nome[], int senha, FILE** f, FILE** fc);
void descriptografaArquivo(int senha, FILE** fd, FILE** fc);