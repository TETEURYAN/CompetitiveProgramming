# Sorting Algorithms
<img src = "https://user-images.githubusercontent.com/91018438/218816864-53c2cf0b-1ac6-49df-aff8-26d25ff47426.gif" alt = "Cover" width="320" align="right" hspace="10" vspace="5" style="border: 1px solid black;">
Sorting algorithms are used to put a list or vector in order.In the concept of data structure, it is common to ask for the ordering of structures for better handling of them.There are several ways to order a list, just change the application of these ways as you will see in this repository.

- Bubble Sort
- Merge Sort
- Insertion Sort
- Comb Sort
- Quick Sort
- Heap Sort

## Recursive Bubble Sort

Bubble sort is a rounding algorithm based on sorting lists based on comparing their indices. Its premise is to count from the first index and compare with other following ones. This algorithm can be done recursively and interactively. Below I have followed a recursive example of the algorithm. It has the nickname bubble because of its logic that the less dense, the easier it goes up, just like a bubble. It is a slow algorithm and has complexity O(n²)

<img src = "https://user-images.githubusercontent.com/91018438/218826198-ab04ea52-4fe0-4ee4-b6b7-503a47dc6748.gif" alt = "Cover" width="320" align="left" hspace="10" vspace="300" style="border: 1px solid black;">

```c
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
				if (array[j] < array[j + 1])
					swap(&array[j], &array[j + 1]);
				
			bubble_sort(i, j + 1, array, n);
		}
		else bubble_sort(i, i, array, n - 1);
	}
}
```

## Interactive Bubble Sort

The interactive bubble sort is composed of the same logic as the recursive, however, using loops of repetition to minimally increase the sorting result. It is still slow compared to other more advanced sorting algorithms.
```C

void bubble_sort (int array[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) 
    {
        for (j = 0; j < n - 1; j++)
	{
            if (array[j] > array[j + 1]) {
                aux          = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

```

## Merge Sort
Merge Sort is an efficient, recursive sorting algorithm. Its premise is to break the array into unitary pieces in order to compare and exchange their positions. Due to its speed, it presents O(n log n) complexity.

```c
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

```

```c
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
```
