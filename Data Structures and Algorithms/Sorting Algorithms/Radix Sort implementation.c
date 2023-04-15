#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //


void radixSort(int a[], int n){
	int i;
	int max = 0;

	for(i = 0; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}

	int rest = 1;

	while(rest <= max){

		int reamainder[10] = {0};
		int t[n];

		for(i = 0; i < n; i++)
			reamainder[a[i] / rest % 10]++;
		for(i = 1; i < 10; i++)
			reamainder[i] += reamainder[i-1];
		for(i = n-1; i >= 0; i--)
			t[--reamainder[a[i]/rest%10]] = a[i];
		for(i = 0; i < n; i++)
			a[i] = t[i];

		rest *= 10;
	}

}
void main()
{
    srand(time(NULL));

    int tam = 10;
    int *array = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){
         array[i] = rand() % tam;
    }

    radixSort(array, tam);

    for(int i = 0; i < tam; i++)
        printf("[%d] ", array[i]);
    printf("\n\n");
}
