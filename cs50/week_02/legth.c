#include <cs50.h>
#include <stdio.h>
#include <string.h>

int getlength(string name);

int main(void)
{
    string name = get_string("Name: ");
    int n = 0;
    while (name[n] != '\0') 
    {
        n ++;
        printf("Partial Length is: %i\n", n);
    }
    printf("Length is: %i\n", n);

    string name2 = get_string("Name2: ");
    int length = getlength(name2);
    int length2 = strlen(name2);
    printf("Length is: %i\n", length);
    printf("Length with library is: %i\n", length2);
}

int getlength(string name)
{
    int c = 0;
    while (name[c] != '\0')
    {
        c++;
    }
    return c;
}

