#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // Change s[i] to upper case
            printf("%c", s[i] - 32); // or - ('a' - 'A')
        }
        else 
        {
            // Print s[i] as it is
            printf("%c", s[i]);
        }      
    }
    printf("\n");

    string s2 = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n2 = strlen(s2); i < n2; i++)
    {
        printf("%c", toupper(s2[i]));   
    }
    printf("\n");
}
