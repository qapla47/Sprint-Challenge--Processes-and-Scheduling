#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Write a function that allocates a two-dimensional array of ints of a specified size. (The rows parameter is how many rows in the array, and cols is how many columns per row.)



int **alloc_2d(int rows, int cols)
{
	int **arr = (int **)malloc(sizeof(int *)*rows);
  for (int i = 0; i< rows; i++) {
    arr[i] = (int*)malloc(sizeof(int)*cols);
  }
  return arr;
}

int main() {
	int **my_array = alloc_2d(5, 10);

	// First array index is row, second is column:
	my_array[2][3] = 3490;
	
	printf("my_array[2][3] = %d\n", my_array[2][3]);

return 0;
}