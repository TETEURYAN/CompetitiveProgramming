#include<stdio.h>
#include<stdlib.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

int * binsort(int * a, int n){
    int * b = calloc(n, sizeof(int));
    
    for(int i = 0 ; i < n-1; i++){
        b[a[i]] = a[i];
    }
    return b;
}

int main(){

    int tam = 50;
    int * array = calloc(tam,  sizeof(int));

    /* About : The Bin Sort will be used only if all elements in array exists in range(0, n-1) */

    for(int i = 0; i < tam-1; i++)
         array[i] = tam-i;

    array = binsort(array, tam);

    for(int i = 1; i < tam; i++)
        printf("%d ", array[i]);
        
    return 0;
}
