#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>
#include<time.h>

struct queue{
    int value;
    struct queue * next;
};

struct queue * getnode(){
    return malloc(sizeof(struct queue));
}

struct queue * insertNode(int num){
    struct queue * example = getnode();
    
    if(example){
        example->value = num;
        example->next = NULL;
        return example;
    }
}

struct queue * putValue(struct queue * list, int num){
    if(not list){
        return insertNode(num);
    }
    else{
        struct queue * aux = list;
            while(aux->next){
                aux=aux->next;
            }
            aux->next = insertNode(num);
            return list;
        }
}

int outValue(struct queue ** list){
    int first = (*list)->value;
    struct queue * aux = (*list);
    (*list) = (*list)->next;
    free(aux);
    return first;
}

int sizeQueue(struct queue * list){
    if(list){
        return 1 + sizeQueue(list->next);
    }
    else return 0;
}

bool isEmpty(struct queue * list){
    return list;
}

bool isFull(struct queue * list, int tam){
    return (sizeQueue(list) >= tam);
}

void display(struct queue * list){
    if(list){
        printf("[%d]", list->value);
        display(list->next);
    }
}

void randon(struct queue ** peek, int tam, int i){
    if(i < tam){
        (*peek) = putValue((*peek), random()%tam);
        randon(peek, tam, ++i);
    }
}

void main(){
    srand(time(NULL));
    
    struct queue * fila = NULL;
    randon(&fila, 10, 0);
    display(fila);
}
