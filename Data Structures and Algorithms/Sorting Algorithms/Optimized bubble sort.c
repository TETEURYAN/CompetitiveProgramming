#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

/* About : If we know that the "bubble" is already at the top, there is no need to compare again, 
 causing computational expense. Thus, the size is decremented, since the top is already defined. */

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void bubbleSort(int arr[], int n){//Optimized version

    for(int i = 0; i < n - 1; i++){
        for(int j = n-1; j > i; j--){// Optimization that J index, inicialized in N and decremented
            if(arr[j] < arr[j-1]){
                swap(arr+j, arr+(j-1));
            }
        }
    }

}

void main()
{
    srand(time(NULL));

    int tam = 10;
    int *array = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;

    bubbleSort(array, tam);

    for(int i = 0; i < tam; i++)
        printf("%d ", array[i]);
}
