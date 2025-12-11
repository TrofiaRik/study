#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
    */
    int *x;
    int *y;

    x = malloc(sizeof(int));
    
    *x = 42;
    printf("my x is %i\n", *x);
    
    y = x;
    printf("my y is %i\n", *y);

    *y = 13;
    printf("my y is now %i\n", *y);
    printf("my x is now %i\n", *x);
}
