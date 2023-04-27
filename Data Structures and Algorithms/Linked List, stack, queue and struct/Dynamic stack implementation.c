#include<stdio.h>
#include<iso646.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int value;
    struct stack * next;
};

struct stack * getnode(struct stack * node,  int num){

    struct stack * aux = malloc(sizeof(struct stack));

    aux->value = num;
    aux->next = node;
    
    return aux;
}

struct stack * pop(struct stack * stack){

    if(not stack){
        return NULL;
    }
    else{
        struct stack * aux = stack;
        aux = stack;
        stack = stack->next;
        free(aux);
        return stack;
    }
}

struct stack * push(struct stack *node, int value){
    return getnode(node, value);
}

int peek(struct stack * node){
    return (node->value);
}

bool isEmpty(struct stack * node){
    return node;
}


int sizeStack(struct stack * node){
    if(node){
        return 1 + sizeStack(node);
    }
}

bool isFull(struct stack * node,int size){
    return (size < sizeStack(node));
}

void display(struct stack * node){
    if(node){
        printf("%d ", node->value);
        display(node->next);
    }
}

int main(){

    struct stack * pilha = NULL;

   int opcao,valor;

  
    while(1)
    {
        printf("\nOPRECAOES COM PILHA\n\n");
        printf("(1)Empilhar\n\n");
        printf("(2)Desimpilhar\n\n");
        printf("(3)Tamanho da pilha\n\n");
        printf("(4)Imprimir pilha\n\n");
        printf("(5)Sair\n\n");
        printf("Opcao: ");

        scanf("%d",&opcao); 
        fflush(stdin);
        
        switch(opcao)
        {
                case 1 :
                    if(isFull(pilha, 10))
                    {
                        printf("Pilha cheia");
                        break;
                    }
                    
                    printf("Digite o valor que deseja push\n");
                    scanf("%d",&valor); 
                    
                    pilha = push(pilha, valor); 
                    printf("O valor %d foi empilhado na posicao %d\n",pilha->value,sizeStack(pilha)); 
                    break;    

                case 2:
                    if(isEmpty(pilha)); 
                    {
                        printf("Pilha vazia");
                        break;
                    }

                    printf("O valor %d foi desempilhado!\n", pilha->value); 
                    pilha = pop(pilha);
                    break;      

                case 3:
                    printf("A pilha atualmente possui %d elementos.\n", sizeStack(pilha));
                    break; 
                
                case 4:
                printf("Elementos na pilha: ");
                    display(pilha);
                    break; 
                
                case 5:
                    exit(0);
                    break; 

                default:
                    printf("insira um valor valido\n");
                    break;    
        }
    }    
}   
