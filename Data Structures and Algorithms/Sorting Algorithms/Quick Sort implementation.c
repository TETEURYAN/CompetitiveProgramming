#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int pivot(int * arr, int i, int k){
    return (i+k)/2;
}

void QuickSort(int * arr,int init,int tam){
    if (init>=tam) {
        return;
    }
    int med = arr[pivot(arr, init, tam)];

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

    int tam = 50;
    int * array = calloc(tam,  sizeof(int));

    for(int i = 0; i < tam-1; i++)
         array[i] = tam-i;

    QuickSort(array, 0, tam-1);

    for(int i = 1; i < tam; i++)
        printf("%d ", array[i]);
        
    return 0;
}
