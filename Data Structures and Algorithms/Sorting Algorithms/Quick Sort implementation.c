#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int pivot( int i, int k){
    return (i+k)/2;
}

void QuickSort(int * arr,int init,int tam){
    if (init>=tam) return;
	
    int med = arr[pivot(init, tam)];

    int pointer = init;
    for (int i=init; i < tam; i++) {
        if (arr[i]<med) {
            if (pointer!=i) {
                swap(&arr[i], &arr[pointer]);
            }
            pointer++;
        }
    }

    swap(&arr[tam], &arr[pointer]);

    QuickSort(arr,init,pointer-1);
    QuickSort(arr,pointer+1,tam);

}

int main(){

    srand(time(NULL));

    int tam = 50;
    int * array = calloc(tam,  sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;
    
    QuickSort(array, 0, tam-1);

    for(int i = 1; i < tam; i++)
        printf("%d ", array[i]);
        
    return 0;
}
