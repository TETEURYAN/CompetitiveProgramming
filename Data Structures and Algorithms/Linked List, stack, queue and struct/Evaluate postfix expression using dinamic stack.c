#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<iso646.h>

struct stack{
    int value;
    struct stack * next;
};

bool isFull(struct stack * list, int tam, int i){
    if(list){
        return isFull(list, tam, ++i);
    }
    else return (i == tam);
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

int pop(struct stack ** list){
    int peek = (*list)->value;
    (*list) = (*list)->next;
    return peek;
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

bool isOperator(char symbol){
    return (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*');
}

int aritmetic(int a, int b, char x){
    return (x == '+') ? (a + b)
         : (x == '-') ? (a - b)
         : (x == '/') ? (a / b)
         : (x == '*') ? (a * b) : 0;

}

int evaluatePostfix(char x[]){
    char *expression;
    int num;

    struct stack *operators;
    int numberOne, numberTwo;

    expression = strtok(x, " ");
    
    while(expression){
        if(isOperator(*(expression))){
            numberOne = pop(&operators);
            numberTwo = pop(&operators);
            num = aritmetic(numberTwo, numberOne, *(expression));
            operators = push(operators, num);
        }
        else{
            num = strtol(expression, NULL, 10);
            operators = push(operators, num);
        }
        expression = strtok(NULL, " ");
    }
    numberOne = pop(&operators);
    return numberOne;
}

void main(){
    char postfix[30];
    
    printf("Insert your postfix expression: ");
    fgets(postfix, 30, stdin);

    printf("Evalute: %d\n", evaluatePostfix(postfix));

}
