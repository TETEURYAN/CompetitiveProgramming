#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iso646.h>

typedef struct tree{
    int info;
    struct tree *right, *left;
}tree;

void iniTree(tree **list, int num)
{
        tree *src = malloc(sizeof(tree));
        src->info = num;
        src->left = NULL;
        src->right = NULL;
        
        *list = src;
}

void inserTree(tree **src, int num){
    if(not *src)
        iniTree(&src, num);
    
    else
    {
        if(num < (*src)->info)
            inserTree(&((*src)->left), num);
        else
            inserTree(&((*src)->right), num);
    }
    
}

void display(tree *raiz){
    if(raiz){
        printf("%d ", raiz->info);
        display(raiz->left);
        display(raiz->right);
    }
}

void main()
{
    tree *arvore = NULL;

    int num;
    scanf("%d", &num);

    iniTree(&arvore, num);
    iniTree(&arvore, ++num);
    iniTree(&arvore, --num);

    display(tree, num);
}
