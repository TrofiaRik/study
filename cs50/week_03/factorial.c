#include <cs50.h>
#include <stdio.h>

int f(int n);

int main(void)
{
    //Get user Input
    int number;
    
    do 
    {
        number = get_int("Number: ");  
    }
    while (number < 0);

    // Call the factorial function
    int result = f(number);
    printf("Factorial of %i is %i\n", number, result);


}

int f(int n)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }
    else
    {
        // Recursive case 
        return n * f(n - 1);
    }
}
/*
4 * f(3)
3 * f(2)
2 * f(1)
1 * f(0)
*/
