#include <stdio.h>

//Algorithm
int binary_search(int array[], int elem, int right, int left)
{
   int mid;
   if(right <= left)
   {
       mid = (right + left)/2;
       if(elem == array[mid])
       {
           return mid;
       }
       else
       {
           if(elem < array[mid])
           {
               return binary_search(array, elem, right, mid-1);
           }
           else
           {
               return binary_search(array, elem, mid+1, left);
           }
       }
   }
       return -1;
}

//Algorithms complement
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

//Algorithm aplication

int main()
{
    int array[5] = {7, 4, 2, 5, 3};
    bubble_sort(0, 0, array, 5);

    //to use binary search, the array needs to be sorted
    printf("Sorted array: ");
    for(int i = 0; i< 5; i++)
        printf("%d ", array[i]);
    
    // i want to search number 3, the algorithm return position. If no find the number, return -1.
    int find  = binary_search(array, 16, 0, 5);

    printf("\nPosition of number: %d", find);
}

