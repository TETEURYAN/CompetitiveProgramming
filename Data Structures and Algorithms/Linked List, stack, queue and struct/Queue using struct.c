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
typedef struct queue
{
    int id;
    char name[50];
}queue;

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

void copy( queue fila[], queue array[], int index, int qtd, int * k, int i)// Function to copy array to struct
{
    if(i < qtd)
    {
        if(fila[i].id == index)
        {
            array[*k] = fila[i];
            *k = *k + 1;
        }
        copy(fila, array, index, qtd, k, ++i);
    }
}

void iqueue(queue fila[], int qtd, int i)
{
    if( i < qtd)
    {
        char nick[50]; int prioridade;

        printf("Digite o nome do paciente %d: ", i+1);
        inputchar(nick, 0, 50);
        strcpy(fila[i].name, nick);

        printf("Digite a prioridade do paciente %d: ", i+1);
        scanf("%d", &prioridade);
        getchar();
        fila[i].id = prioridade;

        iqueue(fila, qtd, ++i);
    }
    
}

void sort(queue * cliente, queue * p, int index, int qtd, int *i)
{
    if(*i < qtd and p[*i].id == index)
    {
        cliente[*i] = p[*i];
        *i = *i + 1;
        sort(cliente, p, index, qtd, i);
    }
}

void swap(queue cliente[], int qtd)
{
    queue P1[qtd];
    queue P2[qtd];
    queue P3[qtd];

    int tamP1 = 0;
    int tamP2 = 0;
    int tamP3 = 0;

    copy(cliente, P1, 1, qtd, &tamP1, 0);
    copy(cliente, P2, 2, qtd, &tamP2, 0);
    copy(cliente, P3, 3, qtd, &tamP3, 0);

    for(int i = 0; i < qtd; i++)
    {
        sort(cliente, P1, 1 , i+2, &i);
        sort(cliente, P2, 2 , i+2, &i);
        sort(cliente, P3, 3 , i+1, &i);

    }
    
}


void display(queue * cliente, int qtd, int i)
{
    if(i < qtd)
    {
        printf("%d. %s | Prioridade %d\n", i+1, cliente[i].name, cliente[i].id);
        display(cliente, qtd, ++i);
    }
}

void main()
{
    int qtd;
    scanf("%d", &qtd);
    getchar();
    
    queue fila[qtd];
    iqueue(fila, qtd, 0);

    swap(fila, qtd);
    
    printf("Ordem de atendimento:\n");
    display(fila, qtd, 0);
}