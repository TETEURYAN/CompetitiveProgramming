#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iso646.h>
#include<math.h>

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void SelectionSort(int * arr,int n){
    for(int j = 0; j < n/2; j++){
        int maior = n-j-1, menor = j;
        
        for(int i = j; i < n; i++){
            if(arr[maior] < arr[i]){
                maior = i;
            }
            else if(arr[menor] > arr[i]){
                menor = i;
            }
        }
        if(maior == j && menor == n-1-j){
            swap(&arr[maior], &arr[menor]);
        }
        else{
            swap(&arr[maior], &arr[n-1-j]);
            swap(&arr[menor], &arr[j]);
        }
    }
}

int main(){

    srand(time(NULL));

    int tam = 50;
    int * array = calloc(tam,  sizeof(int));

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;
    
    SelectionSort(array, tam);

    for(int i = 1; i < tam; i++)
        printf("%d ", array[i]);
        
    return 0;
}
