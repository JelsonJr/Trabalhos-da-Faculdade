#define TAMANHO_PALAVRA 30

void abertura();
void desenhaForca();
void adicionaPalavra();
void mostraLetrasChutadas(int erros);
int jaChutou(char letra);
void chuta();

inline void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n\n");
}
