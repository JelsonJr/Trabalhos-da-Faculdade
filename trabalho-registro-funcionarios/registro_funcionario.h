#define N 100

/* Trabalho de Algoritmos e Progração
 * 
 * Jelson Rodrigues Antônio Jr.
 * Lucas Vinícius M. P. S. L. Morais
 * Otávio Luís Dal Molin Folador
 */

typedef struct {
    int registro;
    char CPF[12]; //usar sem pontos e travessï¿½o ex: 73943265598
    char nome[100];
    float salario;
    char sit; //0-ativo; 1-excluido
} tfuncionario;

void imprime_menu();
void mostra(int ind, char sit);
void deleta(int ind);
void altera(int ind);
void salva(int ind);
void consulta_funcionario(int ind);
int consulta(char CPF[12], int ind);
int entrada(int ind);
int leitura_arquivo();
int verificaCPF(char strCPF[]);
