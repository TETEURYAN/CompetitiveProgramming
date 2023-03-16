#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

typedef struct tree{
    int info;
    struct tree *right, *left;
}tree;

void geTree(tree **list, int num)
{
        tree *src = malloc(sizeof(tree));
        src->info = num;
        src->left = NULL;
        src->right = NULL;
        
        *list = src;
}

void inserTree(tree **src, int num){
    if(not *src)
        geTree(src, num);
    
    else
    {
        if(num < (*src)->info)
            inserTree(&((*src)->left), num);
        else
            inserTree(&((*src)->right), num);
    }
    
}

void display(tree *raiz)
{
    if(raiz)
    {
        printf("%d ", raiz->info);
        display(raiz->left);
        display(raiz->right);
    }
}

void main()
{
    tree *arvore = NULL;

    int num;

    while(scanf("%d", &num) and num != 0)
        inserTree(&arvore, num);

    display(arvore);
}