#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a = get_int("a = ");
    int b = get_int("b = ");
    if (a == b)
    {
        printf("Same!\n");
    }
    else 
    {
        printf("Different :-((\n");  
    }

    char *s1 = get_string("s1 = ");
    char *s2 = get_string("s2 = ");
    for (int i = 0; i < strlen(s1); i++)
        if (s1[i] == s2[i])
        {
            //printf("Same!\n");
            continue;
        }
        else 
        {
            //printf("Different :-((\n");
            return printf("DIFF!\n");
        } 
    printf("Same!\n");

    char *s3 = get_string("s3 = ");
    char *s4 = get_string("s4 = ");
    if (s3[0] == s2[0])
    {
        printf("Same!\n");
    }
    else 
    {
        printf("Different :-((\n");
    }


}
