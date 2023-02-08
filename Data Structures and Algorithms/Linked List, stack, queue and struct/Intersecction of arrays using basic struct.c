#include<stdio.h>
#include<stdbool.h>
#include<iso646.h>

//Arrays interseccion with struct

typedef struct 
{
    int array[10];
}vector;
 
void input_array(int *array, int tam,  int i)// Recursive function to input array
{
    if( i < tam)
    {
        scanf("%d", &array[i]);
        input_array(array, tam,  ++i);
    }
}
 
void print_array(int *array, int tam, int i)// Recursive function to print array
{
    if( i < tam)
    {
        printf("%d ", array[i]);
        print_array(array, tam, ++i);
    }
}
 
void repeat(vector * arr, int tam, int i)
{
    if( i < tam)
    {
        arr->array[i] = arr->array[i + 1];
        repeat(arr, tam, ++i);
    }
}
 
void removed(vector * arr, int * tam)// Function to remove repeating elements in array
{
    for( int i = 0; i < *tam; i++ )
    {
        for( int j = i + 1; j < *tam; )
        {
            if( arr->array[j] == arr->array[i] )
            {
                repeat(arr, *tam, j);
                *tam = *tam -1;
            }
            else j++;
        }
    }
}
 
void intersec(vector arr1, vector arr2, int *intersec, int tam_arrayOne, int tam_arrayTwo, int * tam_intersec, int o)
{
  for(int i=0; i<tam_arrayOne; i++)
  {
    for(int k=0; k < tam_arrayTwo; k++)
    {
        if(arr1.array[i] == arr2.array[k] and arr1.array[i] not_eq arr2.array[k-1] and arr1.array[i] not_eq arr1.array[i-1] )
        {
            *(intersec+o)= arr1.array[i]; 
            o++;
        }
    } 
  }
  *tam_intersec = o;
}
 
vector copy( vector * X, int *array, int i)// Function to copy array to struct
{
    if(i < 10)
    {
        X->array[i] = array[i];
        copy(X, array, ++i);
    }
}
 
void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}
 
void bubble_sort (int i, int j, int * array, int n)//Function to sort array
{
	int aux;
	if (i < n)
	{
		if (j < n)
		{
			if (n != j + 1)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
		   	bubble_sort(i, j + 1, array, n);
		}
		else bubble_sort(i, i, array, n - 1);
	}
}
 
void config(int *array, vector * vet, int * tam)//Function to input, sort and copy array to struct array.
{
    input_array(array, *tam, 0);
    copy(vet, array, 0);
    bubble_sort(0, 0, vet->array, *tam);
    removed(vet, tam);
}
 
void main()
{
 
    int arrayOne[10]; vector listOne; 
    int arrayTwo[10]; vector listTwo;
 
    int tamOne = 10;
    int tamTwo = 10;
 
    printf("Digite 20 elementos para o primeiro array:");
    config(arrayOne, &listOne, &tamOne);
 
    printf("Digite 20 elementos para o segundo array:");
    config(arrayTwo, &listTwo, &tamTwo);
 
    int intersecction[10];
    int tam_intersec = 0;
 
    printf("\ninterseccao: ");
    intersec(listOne, listTwo, intersecction, tamOne, tamTwo, &tam_intersec, 0);
    print_array(intersecction, tam_intersec, 0);
 
}