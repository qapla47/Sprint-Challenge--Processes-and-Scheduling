#include <stdio.h>
#include <stdlib.h>

// Write a function that allocates an array of ints of a specified size. (The cols parameter holds the size.)

int *alloc_1d(int cols)
{
  // allocate space in the heap for the array based on the columns requested
  int *arr = (int *)malloc(sizeof(int) * cols);
  return arr;
}

int main()
{
  int *my_array = alloc_1d(12);

  my_array[8] = 3490;

  printf("array[8] = %d\n", my_array[8]);

  return 0;
}