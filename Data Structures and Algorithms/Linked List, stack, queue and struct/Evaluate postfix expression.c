#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<iso646.h>

typedef struct structure{
    int topo;
    int vetor[30];
    
}structure;

structure stack;

void push (int value){
    stack.topo++;  
    stack.vetor[stack.topo] = value; 
}
 
int pop (void){
    
    int auxvalor=stack.vetor[stack.topo];
    stack.topo--;
    return auxvalor;
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

    int numberOne, numberTwo;

    expression = strtok(x, " ");
    while(expression){
        if(isOperator(*(expression))){
            numberOne = pop();
            numberTwo = pop();
            num = aritmetic(numberTwo, numberOne, *(expression));
            push(num);
        }
        else{
            num = strtol(expression, NULL, 10);
            push(num);
        }
        expression = strtok(NULL, " ");
    }
    pop();
    numberOne = pop();
    num = numberOne;
    return num;
}

void main(){
    char postfix[30];
    
    printf("Insert your postfix expression: ");
    fgets(postfix, 30, stdin);

    printf("Evalute: %d\n", evaluatePostfix(postfix));

}
