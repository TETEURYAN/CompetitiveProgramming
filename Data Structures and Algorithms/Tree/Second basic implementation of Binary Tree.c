#include<stdio.h>
#include<stdlib.h>
#include<iso646.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

typedef struct tree{
    int value;
    struct tree *right, *left;
}tree;

tree * getnode(int num){

    tree * aux = malloc(sizeof(tree));

    aux->value = num;
    aux->left = NULL;
    aux->right = NULL;
    
    return aux;
}

tree * putnode(tree *root, int num){
    if(not root){
        return getnode(num);;
    }
    else{
        if(num < root->value)
            root->left = putnode(root->left, num);
        else
            root->right = putnode(root->right, num);
        return root;
    }
}

void displayTree(tree * root){
    if(root){
        printf("%d(", root->value);
            displayTree(root->left);
            displayTree(root->right);
        printf(")");
    }
}

int main(){

    tree *raiz = NULL;
    int op, value;

    do{
        printf("\n0 - Quit\n1 - Insert\n2 - Print\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\nPut a value: ");
            scanf("%d", &value);
            raiz = putnode(raiz, value);
            break;
        case 2:
            printf("\nValues in a tree: \n");
            displayTree(raiz);
            printf("\n");
            break;
        default:
            if(op != 0)
                printf("\nOpcao invalida!!!\n");
        }
    }while(op != 0);

    return 0;
}
