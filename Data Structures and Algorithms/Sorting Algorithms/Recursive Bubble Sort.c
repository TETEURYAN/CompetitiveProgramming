
//first
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

//second

int bubble(int arr[], int n, int i)
{
    if(i == n-1) return 0;
    if(arr[i] > arr[i+1])
    {
        int aux = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = aux;
    }
    bubble(arr, n, i+1);

int ordenar(int arr[], int n)
{ 
    if(n == 1) return 0;
    bubble(arr, n, 0);
    ordenar(arr, n-1);
}