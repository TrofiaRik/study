#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int st = 0;
int collatz(int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    //int steps = collatz(n);
    printf("Required steps to get back to 1 are %i\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1) // Base case
    {
        return 0;
    }
    else if ((n % 2) == 0) // Even numbers
    {
        collatz(n / 2);
        st++;
    }
    else
    {
        collatz(n*3 + 1); // Odd numbers
        st++;
    }
    return st;
} 
