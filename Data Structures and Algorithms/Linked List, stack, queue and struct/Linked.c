#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>

struct stack{
    int value;
    struct stack * next;
};

bool isFull(struct stack * list, int tam, int i){
    if(list){
        return isFull(list, tam, ++i);
    }
    else return (i == tam) ? true : false;
}

bool isEmpty(struct stack * list){
    return (not list);
}

struct stack * getnode(){
    return malloc(sizeof(struct stack));
}

struct stack * insertNode(int num){
    struct stack * example = getnode();
    
    if(example){
        example->value = num;
        example->next = NULL;
        return example;
    }
}

struct stack * pop(struct stack * list){
    struct stack * aux = list;
    
    while(aux->next->next){
        aux = aux->next;
    }
    aux->next = NULL;
    return list;
}

struct stack * push(struct stack * list, int num){
    if(not list){
        return insertNode(num);
    }
    else{
        struct stack * aux = list;
            
        while(aux->next){
            aux = aux->next;
        }
        aux->next = insertNode(num);
        return list;
        }
}

int peek(struct stack * list){
    if(list->next){
        return peek(list->next);
    }
    return (list->value);
}

void display(struct stack * list){
    if(list){
        printf("%d ", list->value);
        display(list->next);
    }
}

