#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

/* About : Comparison between optimized and normal versions of the Bubble Sort algorithm */

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void bubbleSort(int arr[], int n){//Optimized version

    int k = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[j-1]){
                swap(arr+j, arr+(j-1));
            }
                k++;
        }
    }
    printf("Num de Loops na versao otimizada %d\n", k);
}

void bubble_sort (int vetor[], int n) {//Normal version
    int k, j, aux;
    
    int i = 0;
    
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j] < vetor[j + 1]) 
            {
                aux   = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
                i++; 
        }
    }
    
    printf("Num de Loops na versao normal %d\n", i);
}

void main()
{
    srand(time(NULL));

    int tam = 26;
    int *array = calloc(tam, sizeof(int));
    int *arrayAux = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){
         array[i] = rand() % tam;
         arrayAux[i] = array[i];
    }
    printf("Vetor original: ");
    for(int i = 0; i < tam; i++)
        printf("[%d] ", array[i]);
    printf("\n\n");

    bubble_sort(arrayAux, tam);
    bubbleSort(array, tam);

}
