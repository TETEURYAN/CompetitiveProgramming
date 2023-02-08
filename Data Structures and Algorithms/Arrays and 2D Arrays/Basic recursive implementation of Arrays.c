#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

void InsertArray( int *array, int tam, int i)//Function to insert elements at Array
{
    if( i < tam)
    {
        scanf("%d", &array[i]);
        InsertArray(array, tam, ++i);
    }
}

void InsertArray( int *array, int tam, int i)//Function to print elements of Array
{
    if( i < tam)
    {
        scanf("Na posicao %d esta o elemento %d.\n", i, &array[i]);
        InsertArray(array, tam, ++i);
    }
}

void main()
{   
    int array[10];//Array init

    InsertArray(array, tam, 0);
    PrintArray(array, tam, 0);
}

