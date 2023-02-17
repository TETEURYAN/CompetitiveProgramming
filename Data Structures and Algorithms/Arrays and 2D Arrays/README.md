# Arrays and 2D Arrays
In this folder you will find a brief summary about the study of Arrays in the C language.
## Array
* Array is a static list in which data types can be stored in sequence.
* An array can be understood as a pointer to the first item in the list, that is, the memory address of the first item.

### Initializing an array

```c
 //Interenger array
 int Array[10];
 int Array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
 //Double array
 double Array[10];
 double Array[] = {1.3, 2.5, 6.3};
 
 //Char array or string
 char Array[10];
 char Array[] = {"This is an array"};
```
### How to fill a array?

* An array can be filled in any way you want, here will be demonstrated two ways to put values in an array.

* Recursive way

```c
void InsertArray( int *array, int tam, int i)
{
    if( i < tam)
    {
        scanf("%d", &array[i]);
        InsertArray(array, tam, ++i);
    }
}

```

* Interactive way

```c
void InsertArray( int *array, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        scanf("%d", &array[i]);
    }
}

```

### Didactic demonstration of an array

<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/217667316-601006e8-77f4-47cf-82b3-73ac85641ef9.png" alt="animated" />
</p>

## 2D Array
* 2D Array is a static list like the common Array, however, with two indexes that also refer to the pointer of the first item.
* 2D Array is nothing more than a table of data in its memory.

### Initializing an 2D array

```c
 //Interenger array
 int Array[3][3]
 int Array[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

```

### How to fill a array?

* Recursive way

```c
void Insertmatrix (int i, int linha, int coluna, int matrix[][coluna])
{
	if (i < linha * coluna)
	{
		scanf("%d", &matrix[i / coluna][i % coluna]);
		input_matrix(i + 1, linha, coluna, matrix);
	}
	return;
}

```

* Interactive way

```c
void Insertmatrix (int linha, int coluna, int matrix[][coluna])
{
    for(int i = 0; i < linha; i++)
      for(int j= 0; j < coluna; i++)
        scanf("%d", &matrix[i][j]);
}

```

### Didactic demonstration of an 2D array

<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/217672025-10e7b8e1-7645-48fa-98da-d0e242bd1f2c.png" alt="animated" />
</p>

# Thanks for see this! ;)
