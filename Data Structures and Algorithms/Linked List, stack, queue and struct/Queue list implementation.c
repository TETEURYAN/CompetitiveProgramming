#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
 
//Including SO
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
 
//Code
typedef struct node
{
    int info;
    char name[50];
    struct node *proximo;
    struct node *anterior;
}Node;
 

Node * getnode()//Function to alcoate memory
{
    return malloc(sizeof(Node));
}

void inputchar(char *nickname, int i, int tam) 
{
    char c = getchar();
    if(c == '\n' || i == tam) nickname[i] = '\0';
    else 
    {
        nickname[i] = c;
        inputchar(nickname, i + 1, tam);
    }   
}
 

void insert(Node **list, int num, char nick[]){
    Node *aux, *item = getnode();

    if(item){
        item->info = num;
        strcpy(item->name, nick);
        
        if(*list == NULL){
            item->proximo = NULL;
            *list = item;
        }
        else if(item->info < (*list)->info){
            item->proximo = *list;
            *list = item;
        }
        else{
            aux = *list;
            while(aux->proximo && item->info > aux->proximo->info)
                aux = aux->proximo;
            item->proximo = aux->proximo;
            aux->proximo = item;
        }
    }
    else
        printf("Error !\n");
}

 
void display(Node * no) //Function to print list
{
    printf("Ordem de atendimento: \n");
    int i = 1;
	while(no!=NULL)
	{
		printf("%d. %s | Prioridade %d\n",i, no->name, no->info);
		no=no->proximo;
		i++;
	}
	printf("\n");
}
 
void input()
{
    Node *lista = NULL;
    int opcao, valor, anterior;
    char name[50];
 
    do{
        system("clear || cls");
        printf("\n\t(0) - Sair\n\t(1) - Inserir\n\t(2) - Imprimir\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();
 
        switch(opcao)
        {
 
        case 1:
            printf("Digite um nome: ");
            inputchar(name, 0, 50);
            printf("Digite a prioridade: ");
            scanf("%d", &valor);
            getchar();
            insert(&lista, valor, name);
            break;
        case 2:
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
