#include <cs50.h>
#include <stdio.h>

int draw(int h);

int main(void)
{
    int height = get_int("\n\nHeight: ");
    printf("\n\n");
    draw(height);
}

int draw(int h)
{
    for (int l = 0; l < h; l++)
    {
        for (int b = 0; b < l + 1; b++)
        {    
            printf("# ");
        }

        for (int bn = 0; bn < (h - l - 1); bn++)
        {    
            printf("* ");
        }

        printf("\n");
    }
    printf("\n\n");
    return 0;
}

