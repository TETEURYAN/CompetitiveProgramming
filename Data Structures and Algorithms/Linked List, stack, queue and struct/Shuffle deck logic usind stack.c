#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>
#include<time.h>

struct stack{
    int value;
    struct stack * next;
};

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

int pop(struct stack ** list){
    struct stack * aux = *list;
    int value = (*list)->value;
    (*list) = (*list)->next;
    free(aux);
    return value;
}

struct stack * push(struct stack * list, int num){
    if(not list){
        return insertNode(num);
    }
    else{
        struct stack * aux = getnode();
        aux->value = num;
        aux->next = list;
        return aux;
        }
}

void display(struct stack * list){
    if(list){
        printf("[%d]", list->value);
        display(list->next);
    }
}

struct stack * shuffle(struct stack * peek, int size){
    struct stack * newPeek = NULL;
    
    while(peek){
        struct stack * aux = NULL;
        int crtl = random() % size;
        size--;
        while(peek and crtl){
            aux = push(aux, pop(&peek));
            crtl--;
        }
        newPeek = push(newPeek, pop(&peek));
        while(aux){
            peek = push(peek, pop(&aux));
        }
    }
    return newPeek;
}

void randon(struct stack ** peek, int tam, int i){
    if(i < tam){
        (*peek) = push((*peek), random()%tam);
        randon(peek, tam, ++i);
    }
}

void solve(int num){
    struct stack * PilhaOne = NULL; randon(&PilhaOne, num, 0);
    struct stack * PilhaTwo = NULL; randon(&PilhaTwo, num, 0);

    int winner;

    int sizeOne = num;
    int sizeTwo = num;

    int PointsOne = 0;
    int PointsTwo = 0;

    while(sizeOne and sizeTwo){
        int ChoseOne = pop(&PilhaOne);
        int ChoseTwo = pop(&PilhaTwo);

        if(ChoseOne > ChoseTwo){
            winner = 1;
            PilhaOne = push(PilhaOne, ChoseOne);
            sizeTwo--; PointsOne++;
        }
        if(ChoseOne < ChoseTwo){
            winner = 2;
            PilhaTwo = push(PilhaTwo, ChoseTwo);
            sizeOne--;PointsTwo++;
        }
        else if(ChoseOne == ChoseTwo){
            winner = 0;
            sizeOne--;sizeTwo--;
        }
        PilhaOne = shuffle(PilhaOne, sizeOne);
        PilhaTwo = shuffle(PilhaTwo, sizeTwo);
        printf("Vencedor da rodada: %d | Jogador A -> %d e Jogador B -> %d\n", winner, ChoseOne, ChoseTwo);

    }
    printf("\nJogador A: %d pontos\nJogador B: %d Pontos\n", PointsOne, PointsTwo);
}

void main(){
    srand(time(NULL));
    
    int tam;
    scanf("%d", &tam);
    
    solve(tam);
    
    // struct stack * pilha = NULL;
    // randon(&pilha, 10, 0);
    
    // display(pilha);
    
    // pilha = shuffle(pilha, 10);
    // display(pilha);
}
