#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

//Including SO
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

//Code
typedef struct 
{
    int info;
    struct Node *proximo;
}Node;

Node * getnode()//Function to alcoate memory
{
    return malloc(sizeof(Node));
}

void InsertInit(Node **list, int num)//Function to insert element at the start of the list
{
    Node *item = getnode();

    item -> info = num;
    item -> proximo = *list;
    *list = item;

}

void InsertAny(Node **lista, int num, int before)//Function to insert element at the anyway of the list
{
    Node *aux;
    Node *item = getnode();

    item->info = num;
    if(*lista == NULL)
    {
        item->proximo = NULL;
        *lista = item;
    }
    else{
        aux = *lista;
        while(aux->info not_eq before and aux->proximo)
            aux = aux->proximo;
        item->proximo = aux->proximo;
        aux->proximo = item;
    }
}

void InsertEnd(Node **list, int num)//Function to insert element at the end of list
{
    Node *aux;
    Node *item = getnode();

    item->info = num;
    item->proximo = NULL;
    if(*list == NULL) *list = item;
    else
    {
        aux = *list;
        while(aux->proximo)
            aux = aux->proximo;
        aux->proximo = item;
    }

}

void display(Node * no) //Function to print list
{
    printf("Lista: ");
	while(no!=NULL)
	{
		printf("%d ",no->info);
		no=no->proximo;
	}
	printf("\n");
}

void input()
{
    Node *lista = NULL;
    int opcao, valor, anterior;

    do{
        system("clear || cls");
        printf("\n\t(0) - Sair\n\t(1) - InserirI\n\t(2) - inserirF\n\t(3) - InserirM\n\t(4) - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            InsertInit(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            InsertEnd(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d %d", &valor, &anterior);
            InsertAny(&lista, valor, anterior);
            break;
        case 4:
            display(lista);
            break;
        default:
            if(opcao != 0) printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

}

void main()
{
    input();
}

