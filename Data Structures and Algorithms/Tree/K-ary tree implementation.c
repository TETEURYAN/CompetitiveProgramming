
#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct kary
{
    int num;
    struct kary * firstChild;
    struct kary * nextBro;
}kary;

kary * newNode(int value)
{
    kary * aux = malloc(sizeof(kary));

    aux->firstChild = NULL;
    aux->nextBro = NULL;
    aux->num = value;

    return aux;
}

kary * initKaryTree(int firstValue)
{
    return newNode(firstValue);
}

kary * search(int value, kary * root)
{

	if (root != NULL) 
    {
		if (root->valor == elemento) 
			return root;
		else 
        {
			kary *son = root->firstChild;

			while (son != NULL) 
            {
				No *looking = search(value, son);
				
                if (looking != NULL) 
					return looking;
				son = son->irmao;
			}
		}
	}

	return NULL;
}


bool insertKary(kary * root, int value, int father)
{
    kary * Pai = search(root, father);

    if(Pai != NULL)
    {
        if(Pai->firstChild == NULL)
        {
            Pai->firstChild = newNode(value);
            return true;
        }
        else
        {
            kary * son = Pai->firstChild;

            while(son->nextBro != NULL)
                son = son->nextBro;

            son->nextBro = newNode(value);
            return true;
        }
    }
    else return false;
}

void display(kary * root){
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
    kary * tree = initKaryTree(25);
}
