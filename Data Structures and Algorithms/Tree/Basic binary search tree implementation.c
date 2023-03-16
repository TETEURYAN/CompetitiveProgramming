#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>

typedef struct tree{
    int info;
    struct tree *right, *left;
}tree;

void geTree(tree **list, int num)
{
        tree *root = malloc(sizeof(tree));
        root->info = num;
        root->left = NULL;
        root->right = NULL;
        
        *list = root;
}

void inserTree(tree **root, int num){
    if(not *root)
        geTree(root, num);
    
    else
    {
        if(num < (*root)->info)
            inserTree(&((*root)->left), num);
        else
            inserTree(&((*root)->right), num);
    }
    
}

void display(tree *root)
{
    if(root)
    {
        printf("%d ", root->info);
        display(root->right);
        display(root->left);
    }
}

void printTreeBraqOne(tree* root) { 
    // bases case 
    if (root == NULL)
    {
        printf("("), printf(")");
        return; 
    }
    
    if(root != NULL)
        printf("(%d", root->info);

    printTreeBraqOne(root->right); 
    printTreeBraqOne(root->left);

    printf(")");
} 

void printTreeBraqTwo(tree *root)
{
    if (root == NULL)
        return;
    
    printf("(%d", root->info);
    if(root->right)
        printTreeBraqTwo(root->right);
    else
        printf("(right null)");
    
    if(root->left)
        printTreeBraqTwo(root->left), printf(")");
    else
        printf( "(left null)");
    return;
}

void main()
{
    tree *arvore = NULL;

    int num;

    while(scanf("%d", &num) and num != 0)
        inserTree(&arvore, num);

   printTreeBraqOne(arvore);
   printf("\n");
   printTreeBraqTwo(arvore);
   printf("\n");
   display(arvore);
}