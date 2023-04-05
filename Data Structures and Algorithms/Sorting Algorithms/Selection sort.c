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

void SelectionSort(int arr[], int n){

    int min;

    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[min] > arr[j]){
                min=j;
            }
        }
        if(i!=min){
            swap(&arr[i], &arr[menor]);
        }
    }
}

void main()
{
    srand(time(NULL));

    int tam = 10;
    int *array = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam; //Add random values to array

    SelectionSort(array, tam);

    for(int i = 0; i < tam; i++)
        printf("%d ", array[i]);
	
}
