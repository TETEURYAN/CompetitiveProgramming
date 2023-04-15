#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Algorithm version of book Data Structures and Algorithm Analysis of Clifford A. Shaffer //

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void radixSort(int a[], int n){
	int i;
	int max = 0;

	for(i = 0; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}

	int dif_dist = 1;

	while(dif_dist <= max){

		int dist[10] = {0};
		int t[n];

		for(i = 0; i < n; i++)
			dist[a[i] / dif_dist % 10]++;
		for(i = 1; i < 10; i++)
			dist[i] += dist[i-1];
		for(i = n-1; i >= 0; i--)
			t[--dist[a[i]/dif_dist%10]] = a[i];
		for(i = 0; i < n; i++)
			a[i] = t[i];

		dif_dist *= 10;
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
