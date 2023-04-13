#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iso646.h>
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

void InsertionSort(int * arr,int tam){
    for(int i = 0; i < tam; i++){
        int j = i;
        while((arr[j] < arr[j-1]) and (j >= 0)){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

int main(){

    srand(time(NULL));

    int tam = 50;
    int * array = calloc(tam,  sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;
    
    InsertionSort(array, tam);

    for(int i = 1; i < tam; i++)
        printf("%d ", array[i]);
        
    return 0;
}
