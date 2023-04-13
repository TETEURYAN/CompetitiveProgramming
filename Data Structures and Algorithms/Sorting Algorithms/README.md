# Sorting Algorithms
<img src = "https://user-images.githubusercontent.com/91018438/218816864-53c2cf0b-1ac6-49df-aff8-26d25ff47426.gif" alt = "Cover" width="320" align="right" hspace="10" vspace="5" style="border: 1px solid black;">
Sorting algorithms are used to put a list or vector in order.In the concept of data structure, it is common to ask for the ordering of structures for better handling of them.There are several ways to order a list, just change the application of these ways as you will see in this repository.

- Bubble Sort
- Merge Sort
- Insertion Sort
- Comb Sort
- Quick Sort
- Heap Sort
- Bin Sort

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

<img src = "https://cdn-images-1.medium.com/fit/t/1600/480/1*GUkhhrPDfgdvvwVFo-il1g.gif" alt = "Cover" width="360" align="left" hspace="10" vspace="5" style="border: 1px solid black;">

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

<img src = "https://blog.boot.dev/img/800/merge_sort_gif.gif" alt = "Cover" width="1000" align="center" hspace="10" vspace="200" style="border: 1px solid black;">

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

## Selection Sort

Selection sort is an algorithm whose idea persists in selecting and sorting from the smallest term. Thus, he will always be looking for a smaller number than another to make the exchange. As a result, it turns out to be a costly algorithm of O(n²) complexity.

<img src = "https://thumbs.gfycat.com/SnappyMasculineAmericancicada-size_restricted.gif" alt = "Cover" width="1000" align="center" hspace="10" vspace="200" style="border: 1px solid black;">

```C
void swap (int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void SelectionSort(int arr[], int n){

    int min;

    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[min] > arr[j]){
                min=j;
            }
        }
        if(i!=min){
            swap(&arr[i], &arr[menor]);
        }
    }
}
```

## Insertion Sort

<img src = "https://user-images.githubusercontent.com/91018438/231626359-9f54df81-3a45-480b-9535-aadc0bfeabe2.gif" alt = "Cover" width="500" align="right" hspace="0" vspace="200" style="border: 1px solid black;">

Imagine that you have a stack of phone bills from the past two years and that you wish to organize them by date. A fairly natural way to do this might be to look at the first two bills and put them in order. Then take the third bill and put it into the right order with respect to the first two, and so on. As you take each bill, you would add it to the sorted pile that you have already made. This naturally intuitive process is the inspiration for our first sorting algorithm, called Insertion Sort. Insertion Sort iterates through a list of records. Each record is inserted in turn at the correct position within a sorted list composed of those records already processed.

```C

void InsertionSort(int * arr,int tam){
    for(int i = 0; i < tam; i++){
        int j = i;
        while((arr[j] < arr[j-1]) and (j >= 0)){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}
```
