#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

/* About: Heap Sort is an efficient sorting algorithm of O(NlogN) notation. 
This is an assumption based on the idea of a binary tree, in which each child node is
in relative positions i+1 and i+2. */

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void MakeHeap(int *arr, int init, int end){
    int aux = arr[init];
    int j = init * 2 + 1;

    while (j <= end){
        if(j < end){
            if(arr[j] < arr[j + 1]){
                j = j + 1;
            }
        }
        if(aux < arr[j]){
            arr[init] = arr[j];
            init = j;
            j = 2 * init + 1;
        }else{
            j = end + 1;
        }
    }
    arr[init] = aux;
}

void HeapSort(int *arr, int tam){
    int i;
    for(i=(tam - 1)/2; i >= 0; i--)
        MakeHeap(arr, i, tam-1);
    
    for (i = tam-1; i >= 1; i--){
        swap(&arr[0], &arr[i]);
        MakeHeap(arr, 0, i - 1);
    }
}
 
void main()
{
    srand(time(NULL));

    int tam = 100;
    int *array = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;
    

	HeapSort(array, tam);

    for(int i = 0; i < tam; i++)
        printf("[%d] ", array[i]);
    printf("\n\n");
}
