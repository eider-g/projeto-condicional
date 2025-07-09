#include <stdio.h>
#define MAX 100

struct Item {
    int codigo;
    char nome[100];
    int tamanho;
};

struct Item itens[MAX];
int qtd = 0;

void cadastrar() {
    if (qtd >= MAX) {
        printf("\nLimite de itens atingidos (%d cadastros)!\n", MAX);
        return;
    }
    printf("\n--- NOVO CADASTRO ---\n");

    printf("Codigo: ");
    scanf("%d", &itens[qtd].codigo);
    while(getchar() != '\n');

    printf("Nome: ");
    scanf(" %99[^\n]", itens[qtd].nome);
    while(getchar() != '\n');

    printf("Tamanho: ");
    scanf("%d", &itens[qtd].tamanho);
    while(getchar() != '\n');

    qtd++;

    printf("\nCadastro realizado com sucesso!\n");
}

int buscarPorCodigo(int codigo) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (itens[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void editar() {
    int codigo, index;

    printf("\n--- EDITAR CADASTRO ---\n");
    printf("Digite o codigo do Item: ");
    scanf("%d", &codigo);
    while(getchar() != '\n');

    index = buscarPorCodigo(codigo);

    if (index == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    printf("\nEDITANDO CADASTRO:\n");
    printf("Codigo: %d\n", itens[index].codigo);
    printf("Nome atual: %s\n", itens[index].nome);
    printf("Tamanho atual: %d\n\n", itens[index].tamanho);

    printf("Novo Nome: ");
    scanf(" %99[^\n]", itens[index].nome);
    while(getchar() != '\n');

    printf("Novo Tamanho: ");
    scanf("%d", &itens[index].tamanho);
    while(getchar() != '\n');

    printf("\nCadastro atualizado com sucesso!\n");
}

void excluir() {
    int codigo, index;
    char confirmacao;

    printf("\n--- EXCLUIR CADASTRO ---\n");
    printf("Digite o Codigo do Item: ");
    scanf("%d", &codigo);
    while(getchar() != '\n');

    index = buscarPorCodigo(codigo);

    if (index == -1) {
        printf("\nItem Não encontrado!\n");
        return;
    }

    printf("\nCONFIRMAR EXCLUSAO:\n");
    printf("Codigo: %d\n", itens[index].codigo);
    printf("Nome: %s\n", itens[index].nome);
    printf("Tamanho: %d\n", itens[index].tamanho);

    printf("\nTem certeza que deseja excluir? (s/n): ");
    scanf(" %c", &confirmacao);
    while(getchar() != '\n');

    if (confirmacao == 's' || confirmacao == 'S') {
        int i;
        for (i = index; i < qtd - 1; i++) {
            itens[i] = itens[i + 1];
        }
        qtd--;
        printf("\nCadastro excluido com sucesso!\n");
    } else {
        printf("\nOperacao cancelada.\n");
    }
}

void listar() {
    printf("\n--- Itens Cadastrados ---\n");
    printf("Total: %d\n\n", qtd);

    if (qtd == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    printf("CODIGO    NOME                                           TAMANHO\n");
    printf("----------------------------------------------------------------\n");

    int i;
    for (i = 0; i < qtd; i++) {
        printf("%-10d%-50s%d\n",
               itens[i].codigo,
               itens[i].nome,
               itens[i].tamanho);
    }
}

int main() {
    int op;

    printf("\n----------------------------------------");
    printf("\n    SISTEMA DE CADASTRO DE ITENS");
    printf("\n----------------------------------------\n");

    do {
        printf("\n----------- MENU PRINCIPAL -----------\n");
        printf("1. Cadastrar novos itens\n");
        printf("2. Listar todos os itens\n");
        printf("3. Editar cadastro existente\n");
        printf("4. Excluir cadastro\n");
        printf("0. Sair do sistema\n");
        printf("--------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &op);
        while(getchar() != '\n');

        switch (op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: excluir(); break;
            case 0: printf("\nEncerrando sistema...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (op != 0);

    printf("\nObrigado por utilizar o sistema!\n");
    return 0;
}
