#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

typedef struct node{
    int value;
    struct node * next;
}node;

typedef struct queue{

    node * first;
    node * last;
    int tam;
}queue;

node * getnode(){
    return malloc(sizeof(node));
}

void getQueue(queue * root){
    root->first = NULL;
    root->last = NULL;
    root->tam = 0;
}

void insertQueue(queue * root, int num){
    node * aux = getnode();

    if(aux){
        aux->value = num;
        aux->next = NULL;

        if(root->first == NULL){
            root->first = aux;
            root->last = aux;
        }
        else{
            root->last->next = aux;
            root->last = aux;
        }
        root->tam++;
    }
}

int removeQueue(queue *  root){
    node * aux = NULL;

    if(root->first){
        aux = root->first;
        root->first = aux->next;
        root->tam--;
    }

    return (aux) ? aux->value : -1;

}

void displayQueue(queue * root){
    node * aux = root->first;
    printf("Values in queue: ");
    if(aux == false){
        printf("Queue empty!\n");
    }else{
        while(aux != NULL){
            printf("%i ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
}

void main(){

    queue fila;
    getQueue(&fila);

    int op, value, peek;
    
    do{
        printf("\tQUEUE OPERATIONS!");
        printf("\t0 - Quit\n\t1 - Insert\n\t2 - Remove\n\t3 - Print\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("Insert a value: ");
            scanf("%d", &value);
            insertQueue(&fila, value);
            break;
        case 2:
            peek = removeQueue(&fila);
            if(peek){
                printf("Removed: %d\n", peek);
            }
            getchar();
            break;
        case 3:
            displayQueue(&fila);
            break;
        default:
            if(op != 0)
                printf("\nInvalid!\n");
        }
        system("clear || cls");
    }while(op != 0);
}
