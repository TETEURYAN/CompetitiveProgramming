#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>

#define MAX 10
#define EMPTY -1

typedef struct node{
    int value;
    struct node * next;
}node;

typedef struct stack{
    node * peek;
}stack;

node * getNode(){
    return malloc(sizeof(node));
}

bool isEmpty(stack * root){
    return (root->peek == NULL);
}

void startStack(stack * root){
    root->peek = NULL;
}

stack * getStack(stack * root){
    root = malloc(sizeof(stack));
    startStack(root);
    return root;
}

void noded(node ** root, int num){
    (*root)->value = num;
    (*root)->next = NULL;
}

int pop(stack * root){
    if(not isEmpty(root)){
        node * aux = root->peek;
        root->peek = root->peek->next;

        int peeked = root->peek->value;
        free(aux);

        return peeked;
    }
    
}

int peekNumber(stack * root){
    node * aux = root->peek;

    while(aux->next)
        aux = aux->next;
    return aux->value;

}

void push(stack * root, int num){
    node * aux = getNode();

    if(aux){
        aux->value = num;
        aux->next = root->peek;
        root->peek = aux;
    }
}

void pull(stack * root, int num){
    if(not isEmpty(root)){
        root->peek->value = num;
    }
}

void displayStack(stack * root){
    node * aux = root->peek;
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

    push(pilha, 73);
    push(pilha, 22);
    push(pilha, 96);
    push(pilha, 40);
    
    pop(pilha);

    displayStack(pilha);

}
