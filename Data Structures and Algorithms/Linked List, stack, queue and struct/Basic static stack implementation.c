#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define EMPTY -1

typedef struct Pilha{
    int topo;
    int vetor[10];
    
}Pilha;

int push (int value);
int pop (void);
int fullStack(void);
int emptyStack(void);
void printStack(void);

Pilha stack;

int main(){
   int opcao,valor;
   stack.topo=-1;
  
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
                    if(fullStack() == true)
                    {
                        printf("Pilha cheia");
                        break;
                    }
                    
                    printf("Digite o valor que deseja push\n");
                    scanf("%d",&valor); 
                    
                    push(valor); 
                    printf("O valor %d foi empilhado na posicao %d\n",stack.vetor[stack.topo],stack.topo); 
                    break;    

                case 2:
                    if(emptyStack() == true) 
                    {
                        printf("Pilha vazia");
                        break;
                    }

                    int valorfun = pop();             
                    printf("O valor %d foi desempilhado da posicao %d\n",valorfun,stack.topo+1); 
                    break;      

                case 3:
                    printf("A pilha atualmente possui %d elementos.\n", stack.topo);
                    break; 
                
                case 4:
                    printStack();
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

    

int push (int value){
    stack.topo++;  
    stack.vetor[stack.topo] = value; 
    return stack.topo, stack.vetor[stack.topo];  
}
 
int pop (void){
    
    int auxvalor=stack.vetor[stack.topo];
    stack.topo--;
    return auxvalor;
} 

int fullStack(void){
    
    if(stack.topo<MAX)
        return false;  
    else
        return true;
}

int emptyStack(void){
    if(stack.topo == EMPTY)	
        return true;
   else
        return false;
}

void printStack(void)
{
    printf("\nElementos da pilha: ");
    for(int i = 0; i <= stack.topo; i++)
        printf("%d ", stack.vetor[i]);
    return (void) printf("\n");    
}
