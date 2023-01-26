#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool search(int index, int *array, int tam_array, int i)
{
    if(i < tam_array)
    {
        if(*(array+i) == index)
        {
            return true;
        }
        search(index, array, tam_array, ++i);
    }
    return false;
}

void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void bubble_sort(int i, int j, int *array, int n)
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
		else
		{
			bubble_sort(i, i, array, n - 1);
		}
	}
}

void interseccao(int *array1, int *array2, int *array3, int tam_array1, int tam_array2)
{
  for(int i=0; i<tam_array1; i++)
  {
    for(int k=0; k < tam_array2; k++)
    {
        if(array1[i] == array2[k] && array1[i] != array2[k-1] && array1[i] != array1[i-1])
        {
            *(array3+i)=*(array1+i);
            printf(" %d",*(array3+i));
        }
    } 
  }
}

void uniao(int i, int *array, int tam_array)
{
    if( i < tam_array)
    {
        if(*(array+i) != *(array+(i-1)))
        {
            printf("%d ", *(array+i));
        }
        uniao(++i, array, tam_array);
    }
}

void complemento(int *array1, int *array2, int tam_array1, int tam_array2, int i)
{
    if(i < tam_array2)
    {
        if(!search((*(array2+i)), array1, tam_array1, 0))
        {
            printf(" %d", *(array2+i));
        }
        complemento(array1, array2, tam_array1, tam_array2, ++i);
    }
}

void input_array( int i, int vdd, int tam_array, int *array, int *array2, int *count)
{
    int num;
    scanf("%d", &num);
    
    if(num != -1)
    {
        array[i] = num;
        if(!vdd) *(array2+(i+tam_array)) = *(array+i);
        else *(array2+i) = *(array+i);
        
        *count+= 1;
        i++;
        
        input_array(i, vdd, tam_array, array, array2, count);
    }
    return;
}

int main() 
{
    int array1[10];
    int array2[10];
    int array3[20];

    int tam_array1 = 0;
    int tam_array2 = 0;

    input_array(0, 1, 0, array1, array3, &tam_array1);
    bubble_sort(0,0, array1, tam_array2);

    input_array(0, 0, tam_array1, array2, array3, &tam_array2);
    bubble_sort(0,0, array2, tam_array2);   


    printf("interseccao:");
    interseccao(array1, array2, array3, tam_array1, tam_array2);

    printf("\nuniao: ");
    bubble_sort(0,0, array3, tam_array1+tam_array2);
    uniao(0, array3, tam_array1 + tam_array2);
    
    printf("\ncomplemento a por b:");
    complemento(array2, array1, tam_array2, tam_array1, 0);

    
	return 0;
}