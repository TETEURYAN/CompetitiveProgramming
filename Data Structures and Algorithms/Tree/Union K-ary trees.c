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

kary * search( kary * root, int value)
{

	if (root != NULL) 
    {
		if (root->num == value) 
			return root;
		else 
        {
			kary *son = root->firstChild;

			while (son != NULL) 
            {
				kary *looking = search( son, value);
				
                if (looking != NULL) 
					return looking;
				son = son->nextBro;
			}
		}
	}

	return NULL;
}

bool unionKary(kary * first, kary * second)
{
    if(not second or not first or not search(first, second->num))
        return false;

    else{
        kary * aux = search(first, second->num);
        aux = aux->firstChild;
        
        while(aux->firstChild)
            aux = aux->firstChild;
        aux->nextBro = second->firstChild;    
        return true;
    }    
    
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
    kary * firstTree = initKaryTree(25);
    insertKary(firstTree, 10,25);
    insertKary(firstTree, 15,25);
    insertKary(firstTree, 16,25);
    insertKary(firstTree, 24,10);
    insertKary(firstTree, 32,16);


    kary * secondTree =  initKaryTree(16);
    insertKary(secondTree, 89,16);
    insertKary(secondTree, 78,16);
    insertKary(secondTree, 96,16);
    insertKary(secondTree, 50,78);
    insertKary(secondTree, 53,96);
    insertKary(secondTree, 24,96);
    
    unionKary(firstTree, secondTree);

    display(firstTree);
}
