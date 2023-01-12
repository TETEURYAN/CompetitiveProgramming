#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Algorithm
void sorting(int *array, int right, int mid, int left){
    int i, j, k;
    int fim1 = 0, fim2 = 0;
    int tam = left-right+1;
    int aux1 = right;
    int aux2 = mid+1;

    int *temp = (int *) malloc(tam*sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i<tam; i++){
            if(!fim1 && !fim2)
            {
                if(array[aux1] < array[aux2]) temp[i]=array[aux1++];
                else temp[i] = array[aux2++];

                if(aux1>mid) fim1 = 1;
                if(aux2>left) fim2 = 1;
            }
            else
            {
                if(!fim1) temp[i] = array[aux1++];
                else temp[i] = array[aux2++];
            }
        }
        for(j=0, k = right; j < tam; j++, k++) array[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int *array, int right, int left)
{
    
    if(right < left)
    {
        int mid = floor((right+left)/2);

        mergeSort(array,right,mid);
        mergeSort(array,mid+1,left);
        sorting(array,right,mid,left);
    }
}
//Algorithm execution
void main()
{
    srand(time(NULL));

    int tam = 50000;
    int array[tam];

    for(int i = 0; i < tam; i++)
         array[i] = rand() % tam;

    mergeSort(array, 0, tam);

    for(int i = 0; i < tam; i++)
        printf("%d ", array[i]);
}