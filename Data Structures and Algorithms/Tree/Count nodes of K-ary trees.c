#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct kary //Estrutura com os índices da árvore. Implementação do modelo LCRS
{
    int num;
    struct kary * firstChild;
    struct kary * nextBro;
}kary;

kary * newNode(int value) //Geração de um novo nó com o valor a ser inserido na ávore N-aria
{
    kary * aux = malloc(sizeof(kary));

    aux->firstChild = NULL;
    aux->nextBro = NULL;
    aux->num = value;

    return aux;
}

kary * initKaryTree(int firstValue) //Função para inicializar a árvore N-aria
{
    return newNode(firstValue);
}

int countNode (kary * root){ //Função para contar nós da minha árvore N-ária
    int i = 1; 
    kary *filho = root->firstChild;
    while (filho != NULL) {
        i += countNode(filho); 
        filho = filho->nextBro;
    }
    return i;
}

void display(kary * root){ //Função recursiva para imprimir árvores N-árias
    if(root == NULL) return;

    printf("%d(",root->num);
    kary * p = root->firstChild;

    while(p)
    {
        display(p);
        p = p->nextBro;
    }
    printf(")");
}

void main()
{
    kary * firstTree = initKaryTree(25);//Criando primeira árvore de raiz 25 e adicionando elementos
    insertKary(firstTree, 10,25);
    insertKary(firstTree, 15,25);
    insertKary(firstTree, 16,25);
    insertKary(firstTree, 24,10);
    insertKary(firstTree, 32,16);

    kary * secondTree =  initKaryTree(16);//Criando segunda árvore de raiz 16 e adicionando elementos
    insertKary(secondTree, 89,16);
    insertKary(secondTree, 78,16);
    insertKary(secondTree, 96,16);
    insertKary(secondTree, 50,78);
    insertKary(secondTree, 53,96);
    insertKary(secondTree, 24,96);
    
    printf("Número de nós da 1ª arvore: %d\n\n", countNode(firstTree));
    printf("Número de nós da 2ª arvore: %d\n\n", countNode(secondTree));

}
