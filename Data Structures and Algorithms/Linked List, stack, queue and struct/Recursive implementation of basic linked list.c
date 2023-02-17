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
typedef struct Node
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

void midItem(Node **list, int num, int before)// search the mid element
{
    if((*list)->info not_eq before and (*list)->proximo)
    {
        midItem(&(*list)->proximo, num, before);
    }
    else 
    {
        Node *item = getnode();
        Node *aux;
        aux = *list;

        item->info = num;
        item->proximo = aux->proximo;
        aux->proximo = item;
    }
}

void InsertAny(Node **list, int num, int before)//Function to insert element at the anyway of the list
{
    Node *aux;
    Node *item = getnode();

    item->info = num;
    if(*list == NULL)
    {
        item->proximo = NULL;
        *list = item;
    }
    else
    {
        midItem(list, num, before);
    }
}

void lastItem(Node **list, int num)// search the last number
{
    
    if((*list)->proximo != NULL;
        lastItem(&(*list)->proximo, num);
    
    else
    {
        Node * aux;
        Node * item = getnode();
        
        if(item)
        {
            item->info = num;
            item->proximo = NULL;
            aux = *list;
            aux->proximo = item;
        }
    }
}

void InsertEnd(Node **list, int num)//Function to insert element at the end of list
{
    Node *aux;
    Node *item = getnode();

    item->info = num;
    item->proximo = NULL;
    if(*list == NULL)
    {
        *list = item;
    }
    else
    {
        lastItem(list, num);
    }
}

void display(Node * no) //Function to print list
{
	if(no)
	{
		printf("%d ",no->info);
		display(no->proximo);
	}
	else printf("\n");
}

int length(Node * no) //Function to count the list
{
	if(no)
	{
        return 1 + length(no->proximo);
    }
    return 0;
}

void input(Node *lista)// Recursive function to made a loop in menu
{
    int opcao, valor, anterior;

    system("clear || cls");
    printf("\n\t(0) - Sair\n\t(1) - InserirI\n\t(2) - inserirF\n\t(3) - InserirM\n\t(4) - Mostrar tamanho\n\t(5) - Imprimir\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
        case 0:
            return;
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
        case 5:
            printf("Lista: ");
            display(lista);
            break;
        case 4:
            printf("Tamanhho da lista: %d\n", length(lista));
            break;
        default:
            if(opcao != 0) printf("Opcao invalida!\n");
    }
    input(lista);
}

void main()
{
    Node *lista = NULL;
    input(lista);
}
