#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#define TAM 30

typedef struct node{
    int chave;
    struct node *proximo;
}node;

typedef struct{
    node *inicio;
    int tam;
}Hash;

void initHash(Hash *table){
    table->inicio = NULL;
    table->tam = 0;
}

void getHash(Hash *table, int valor){
    node *novo = malloc(sizeof(node));

    if(novo){
        novo->chave = valor;
        novo->proximo = table->inicio;
        table->inicio = novo;
        table->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

int searchTable(Hash *table, int valor){
    node *aux = table->inicio;
    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

void displayTable(Hash *table){
    node *aux = table->inicio;
    printf(" Tam: %d: ", table->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void initTable(Hash t[]){

    for(int i = 0; i < TAM; i++)
        initHash(&t[i]);
}

int keyHash(int chave){
    return chave % TAM;
}

void insertValue(Hash t[], int valor){
    int id = keyHash(valor);
    getHash(&t[id], valor);
}

int search(Hash t[], int chave){
    int id = keyHash(chave);
    return searchTable(&t[id], chave);
}

void display(Hash t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        displayTable(&t[i]);
        printf("\n");
    }
}

int main(){

    int op, valor, boolean;
    Hash tabela[TAM];

    initTable(tabela);

    do{
        printf("\t\tTABELA HASH\n");
        printf("\n\t(0) - Sair\n\t(1) - Inserir\n\t(2) - Buscar\n\t(3) -Imprimir\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            insertValue(tabela, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            boolean = search(tabela, valor);
            if(boolean != 0)
                printf("\tValor encontrado: %d\n", boolean);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            display(tabela);
            getchar();
            break;
        default:
            printf("Opcao invalida!\n");
        }
        printf("\nEscolha: ");
        system("clear || cls");
    }while(op != 0);

    return 0;
}
