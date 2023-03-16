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

int countNode(tree *root)
{
    return (not root) ? 0 : 1 + countNode(root->left) + countNode(root->right);
}

void printTreeBraqOne(tree* root) { 

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

void solve()
{
    tree *arvore = NULL;

    int num;

    while(scanf("%d", &num) and num != 0)
        inserTree(&arvore, num);


    int nodes = countNode(arvore);

    printf("THE NUMBER OF NODES IN YOUR TREE IS %d\n\n", nodes);
    printf("YOUR TREE: ");
    printTreeBraqOne(arvore);
}

void main()
{
    printf("\tPROGRAM TO COUNT NODES IN BINARY TREE SEARCH\n");
    printf("INSERT THE VALUES TO YOUR TREE UNTIL CHOOSE 0: ");
    solve();
}