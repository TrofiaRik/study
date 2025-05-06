#include <cs50.h>
#include <stdio.h>

void rc(int hval);

int main(void)
{
    int hval;
    do
    {
        hval = get_int("Height: ");
    }
    while (hval < 1 || hval > 8);

    rc(hval);
}

void rc(int hval)
{
    for (int row = 0; row < hval; row++)
    {

        for (int sp = hval - 1 - row; sp > 0; sp--)
        {
            printf(" ");
        }

        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }

        printf("  ");

        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }

        printf("\n");
    }
}

