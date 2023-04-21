#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define EMPTY -1

typedef struct node{
    int value;
    struct node * next;
}node;

typedef struct stack{
    node * info;
}stack;

node * getNode(){
    return malloc(sizeof(node));
}

stack * getStack(stack * root){
    root = malloc(sizeof(stack));
    startStack(root);

    return root;
}

void startStack(stack * root){
    root->info = NULL;
}

bool pop(stack * root, int num){
    node * aux = getNode();

    if(aux == false){
        return false;
    }else{
        aux->value = num;
        aux->next = root->info;
        root->info = aux;
        return true;
    }
}

int push(stack * root){
    node * aux = root->info;

    int peek;

    if(aux == false){
        return -1;
    }else{
        root->info = aux->next;
        aux->next = NULL;
        peek = aux->value;
        free(aux);
        return peek;
    }
}

void displayStack(stack * root){
    node * aux = stack->info;
    printf("Valores na pilha: ");
    if(aux == false){
        printf("Stack empty!\n");
    }else{
        while(aux != NULL){
            printf("%i ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
}

void main(){
    stack * pilha = getStack(pilha);


    pop(pilha, 73);
    pop(pilha, 22);
    pop(pilha, 96);
    pop(pilha, 40);

    displayStack(pilha);

}
