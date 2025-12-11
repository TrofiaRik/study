#include <stdio.h>
#include <stdlib.h>

int main(void)
{


// Statically obtain an integer:
int x;

// Dynamically allocate an integer:
int *px = malloc(4);
// or
int *px = malloc(sizeof(int));
// or
int *px = malloc(sizeof *px);

// FREE FREE FREE
free(px);

// Get (cs50 func) an integer from the user - static allocation on the stack:
int x = get_int();

// Statically allocate a variable array of floats on the stacks (c99+):
float stack_array[x];

// Array of floats on the HEAP:
float *heap_array[] = malloc(x * sizeof(float));
float *heap_array[] = malloc(x * sizeof *heap_array);

// FREE FREE FREE 
free(heap_array);

}
