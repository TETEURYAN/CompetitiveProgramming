#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iso646.h>

#define MAX 10
#define EMPTY -1

typedef struct Pilha{
    int topo;
    int vetor[10];
    
}Pilha;

Pilha stack;

int push (Pilha * stack, int value);
int pop (Pilha * stack);
int fullStack(Pilha stack);
int emptyStack(Pilha stack);
void printStack(Pilha stack);
bool operator(char x);
void posFix(Pilha stack, char * expr);
int priorityTerm(char x);


int main(){
   int opcao,valor;
   char string[50];
   stack.topo = EMPTY;
  
    while(1)
    {
        printf("\nOPRECAOES COM PILHA\n\n");
        printf("(1)Converser infix para posfix\n\n");
        printf("(2)Sair\n\n");
        printf("Opcao: ");

        scanf("%d",&opcao); 
        fflush(stdin);
        
        switch(opcao)
        {
                case 1 :
                    printf("Digite sua expressao: ");
                    fgets(string, 50, stdin);
                    posFix(stack, string);
                    break;        
                case 2:
                    exit(0);
                    break; 

                default:
                    printf("insira um valor valido\n");
                    break;    
        }
    }    
}   

    

int push (Pilha * stack, int value){
    stack->topo++;  
    stack->vetor[stack->topo] = value; 
    return stack->topo;
}
 
int pop (Pilha * stack){
    
    int auxvalor=stack->vetor[stack->topo];
    stack->topo--;
    return auxvalor;
} 

int fullStack(Pilha stack){
    
    if(stack.topo<MAX)
        return false;  
    else
        return true;
}

int emptyStack(Pilha stack){
    if(stack.topo == EMPTY)	
        return true;
   else
        return false;
}

int peek(Pilha stack)
{
    return stack.vetor[stack.topo];
}

void printStack(Pilha stack)
{
    printf("\nElementos da pilha: ");
    for(int i = 0; i <= stack.topo; i++)
        printf("%d ", stack.vetor[i]);
    return (void) printf("\n");    
}

int priorityTerm(char x) {
    switch (x) { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

bool operator(char x) {
    return (x >= '0' && x <= '9');
} 

void posFix(Pilha stack, char * expr) { 
    int i, j;

    for (i = 0, j = -1; expr[i]; ++i) { 
        if (operator(expr[i])){
            expr[++j] = expr[i];
        } else if (expr[i] == '(') {
            push(&stack, expr[i]);
        } else if (expr[i]==')') {
            if(expr[i]==')'){  
                while (not emptyStack(stack) && peek(stack) != '(') {
                    expr[++j] = pop(&stack);
                }     
                pop(&stack);
            }
        } else { 
            while (not emptyStack(stack) && priorityTerm(expr[i]) <= priorityTerm(peek(stack))) {
                expr[++j] = pop(&stack); 
            }
            push(&stack, expr[i]); 
        } 
    } 
    while (not emptyStack(stack)) {
        expr[++j] = pop(&stack);
    } 
    expr[++j] = '\0'; 
    printf("\nOrdem posfixa: ");
    printf( "%s", expr); 
} 
