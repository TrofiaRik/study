#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    
    int n = get_int("What number to search for? ");

    // Implementing a Linear Search, from left to right
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("%i has been found at position %i!\n", n, i);
            return 0;
        }        
    }
    printf("Not Found :-((\n");
    // return 1;


    string words[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string w = get_string("Word: ");
    for (int i = 0; i < 6; i++)
    {
        if ( strcmp(words[i], w) == 0 )
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
