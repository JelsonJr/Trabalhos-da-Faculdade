#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../headers/registro_funcionario.h"

/* Trabalho de Algoritmos e Programacao
 *
 * Jelson Rodrigues Antonio Jr.
 * Lucas Vincius M. P. S. L. Morais
 * Otavio Luis Dal Molin Folador
 * 
 * refatorado por: Jelson Rodrigues Antonio Jr.
 */

FILE *fp;
tfuncionario *cadafuncionario;

int main() {
    int ind = 0, op;
    ind = leitura_arquivo("cadfun.dad");
    do {
        imprime_menu();
        printf("Informe sua escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                ind = entrada(ind);
                break;
            case 2:
                mostra(ind, '1');
                break;
            case 3:
                consulta_funcionario(ind);
                break;
            case 4:
                altera(ind);
                break;
            case 5:
                deleta(ind);
                break;
            case 6:
                mostra(ind, '0');
                break;
            case 7:
                break;
            default:
                printf("Escolha incorreta\n");
                Sleep(2000);
        }
    } while (op != 7);

    salva(ind);
    return 0;
}

void consulta_funcionario(int ind) {
    char CPF[12];
    int i;

    printf("Insira o CPF do funcionario: ");
    fflush(stdin);
    gets(CPF);

    int posicao = consulta(CPF, ind);

    if (posicao == -1) {
        printf("Erro\n");
        Sleep(2000);
        return;
    }

    printf("Registro             CPF             Nome               Salario        Situacao\n");
    for (i = 0; i < ind; i++)
        if (strcmpi(cadafuncionario[i].CPF, CPF) == 0)
            printf("%d                %s         %s              %.2f           %c\n", cadafuncionario[i].registro, cadafuncionario[i].CPF, cadafuncionario[i].nome, cadafuncionario[i].salario, cadafuncionario[i].sit);

    system("pause");
}

void imprime_menu() {
    system("cls");
    printf("Menu \n1 - Cadastro de funcionarios\n");
    printf("2 - Lista cadastro de funcionarios\n");
    printf("3 - Consulta situacao funcionario\n");
    printf("4 - Fazer alteracao de cadastro de funcionario\n");
    printf("5 - Excluir funcionario\n");
    printf("6 - Lixeira\n");
    printf("7 - Salvar e Sair\n");
}

int entrada(int ind) {
    char opcao;
    int i, j;

    while (opcao != 'N' && opcao != 'n' && ind < N) {
        system("cls");

        printf("CPF: ");
        fflush(stdin);
        gets(cadafuncionario[ind].CPF);
        opcao=verificaCPF(cadafuncionario[ind].CPF);

        if(opcao==0){
            printf("Nome do funcionario: ");
            fflush(stdin);
            cadafuncionario[ind].sit = '0';
            gets(cadafuncionario[ind].nome);

            printf("Salario: ");
            fflush(stdin);
            scanf("%f", &cadafuncionario[ind].salario);
            cadafuncionario[ind].registro = ind + 1;
            ind++;

            printf("Deseja cadastrar outro funcionario? (S) - SIM | (N) - Nao\n");
            fflush(stdin);
            scanf("%c", &opcao);
        }
    }
    for(i = 0, j = 0; i <ind; i++){
        if(cadafuncionario[i].sit != '1'){
            j++;
            cadafuncionario[i].registro = j;
        }
    }
    return ind;
}

int verificaCPF(char strCPF[]){
    int i;

    if(strlen(strCPF)!=11) return 1;

    for(i=0; i<11; i++){
        if(strCPF[i]<48 || strCPF[i]>57){
            printf("\nErro ao digitar CPF (Apenas numeros, sem ponto ou travessao)\n");
            Sleep(3000);
            return 1;
        }
    }
    
    return 0;
}

void deleta(int ind) {
    char CPF[12];
    int i, j;

    mostra(ind, '1');
    printf("Digite o CPF do funcionario que deseja excluir: ");
    fflush(stdin);
    gets(CPF);

    for (i = 0; i < ind; i++)
        if (strcmpi(cadafuncionario[i].CPF, CPF) == 0) cadafuncionario[i].sit = '1';

    for (i = 0, j = 0; i < ind; i++) {
        if (cadafuncionario[i].sit != '1'){
            j++;
            cadafuncionario[i].registro = j;
        }
    }

}

void altera(int ind) {
    int posicao, escolha;
    float salario;
    char CPF[12], situacao;
    int i, j;

    fopen("cadfun.dad", "rb+");

    printf("Ativos ou inativos?\n");
    printf("1 - Ativos\n");
    printf("2 - Inativos\n");
    scanf("%d", &escolha);

    switch(escolha){
        case 1: mostra(ind, '1');
            break;
        case 2: mostra(ind, '0');
            break;
        default:
            return;
    }
    printf("\nInsira o CPF do funcionario que deseja alterar (caso nao haja, digite 0 para sair): ");
    fflush(stdin);
    gets(CPF);

    posicao = consulta(CPF, ind);

    if (posicao != 1) {
        printf("Funcionario nao encontrado! \n");
        system("pause");
        fclose(fp);
        return;
    }

    printf("Escolha o que deseja mudar: \n");
    printf("1 - Salario\n");
    printf("2 - Situacao\n");
    printf("3 - Sair\n");
    fflush(stdin);
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
        printf("Insira o novo salario: ");
        scanf("%f", &salario);
        for (i = 0; i < ind; i++) {
            fread(&cadafuncionario[i], sizeof(tfuncionario), 1, fp);
            if (strcmpi(cadafuncionario[i].CPF, CPF) == 0) {
                cadafuncionario[i].salario = salario;
                break;
            }
        }
        
        fwrite(&cadafuncionario[i], sizeof(tfuncionario), 1, fp);
        break;
    case 2:
        printf("Insira a nova situacao: ");
        fflush(stdin);
        scanf("%c", &situacao);
        fseek(fp, (posicao - 1) * sizeof(tfuncionario), SEEK_SET);
        for (i = 0; i < ind; i++) {
            fread(&cadafuncionario[i], sizeof(tfuncionario), 1, fp);
            if (strcmpi(cadafuncionario[i].CPF, CPF) == 0) {
                cadafuncionario[i].sit = situacao;
                break;
            }
        }
        fwrite(&cadafuncionario[i], sizeof(tfuncionario), 1, fp);
        for (i = 0, j = 0; i < ind; i++) {
            if (cadafuncionario[i].sit != '1') {
                j++;
                cadafuncionario[i].registro = j;
            }
        }
        break;
    case 3:
        break;
    default:
        printf("Escolha incorreta\n");
        Sleep(2000);
    }
    fclose(fp);
}

int consulta(char CPF[12], int ind) {
    fopen("cadfun.dad", "rb");
    int i;

    for (i = 0; i < ind; i++) {
        fread(&*cadafuncionario, sizeof(cadafuncionario), 1, fp);

        if (strcmpi(cadafuncionario[i].CPF, CPF) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("Funcionario nao encontrado! \n");
    return -1;
}

void mostra(int ind, char sit) {
    int i;

    system("cls");
    printf("Registro             CPF             Nome               Salario        Situacao\n");
    for (i = 0; i < ind; i++) {
        if (cadafuncionario[i].sit != sit) 
            printf("%d                %s         %s              %.2f           %c\n", cadafuncionario[i].registro, cadafuncionario[i].CPF, cadafuncionario[i].nome, cadafuncionario[i].salario, cadafuncionario[i].sit);
    }
    system("pause");
}

int leitura_arquivo() {
    int qtdDeRegistro, ind, i;
    fp = fopen("cadfun.dad", "rb"); //"r" vai ler o arquivo

    if (fp == NULL) {
        printf("Arquivo nao encontrado");
        cadafuncionario = (tfuncionario *)malloc(1000 * sizeof(tfuncionario));
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    int bytes = ftell(fp); // quantidade de bytes no arquivo
    ind = bytes / sizeof(tfuncionario);

    qtdDeRegistro = ind + 1000;
    cadafuncionario = (tfuncionario *)malloc(qtdDeRegistro * sizeof(tfuncionario));

    if (cadafuncionario == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET); // ponteiro fp est� apontando pro come�o novamente
    for (i = 0; i < ind; i++) fread(&cadafuncionario[i], sizeof(tfuncionario), 1, fp); //?

    fclose(fp);
    return ind;
}

void salva(int ind) {
    int i, j;
    fp = fopen("cadfun.dad", "wb");

    if (fp == NULL) {
        printf("Erro ao gravar o arquivo!");
        exit(1);
    }
    for(i = 0, j = 0; i <ind; i++){
        if(cadafuncionario[i].sit != '1'){
            j++;
            cadafuncionario[i].registro = j;
        }
    }

    for(i = 0; i < ind; i++){
        if (cadafuncionario[i].sit != '1' || cadafuncionario[i].sit != '0') fwrite(&cadafuncionario[i], sizeof(tfuncionario), 1, fp);
    }
        
    fclose(fp);
}
