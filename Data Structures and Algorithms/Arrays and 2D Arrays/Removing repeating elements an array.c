#include<stdio.h>
#include<stdbool.h>
#include<iso646.h>
 
void input_array(int *array, int i)
{
    if( i < 20)
    {
        scanf("%d", &array[i]);
        input_array(array, ++i);
    }
}
 
void print_array(int *array, int tam, int i)
{
    if( i < tam)
    {
        printf("%d ", array[i]);
        print_array(array, tam, ++i);
    }
}
 
void repeat(int * array, int tam, int i)
{
    if( i < tam)
    {
        array[i] = array[i + 1];
        repeat(array, tam, ++i);
    }
}
 
void removed(int * vetor, int * tam_vetor, int tam)
{
    for( int i = 0; i < tam; i++ )
    {
        for( int j = i + 1; j < tam; )
        {
            if( vetor[j] == vetor[i] )
            {
                if(vetor[j] != vetor[j+1]) printf("%d ", vetor[j]);
                repeat(vetor, tam, j);
                tam--;
            }
            else j++;
        }
    }
    *tam_vetor = tam;
}
 
void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}
 
void bubble_sort (int i, int j, int array[], int n)
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
 
void main()
{
    int array[20]; int aux[20]; int tam = 0; int tam_aux = 0;
 
    printf("Digite seu array: ");
    input_array(array, 0);
 
    printf("Array com repeticao: ");
    print_array(array, 20, 0);
 
    bubble_sort(0, 0, array, 20);
 
    printf("\nValores repetidos: ");
    removed(array, &tam, 20);
    print_array(aux, tam_aux, 0);
 
    printf("\nArray sem repeticao: ");
    print_array(array, tam, 0);
 
}
