#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calc_points(string p_input);

int main(void)
{
    // Prompt p1 for input
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
        
    int p1_pts = calc_points(p1);
    printf("p1 = %i\n", p1_pts);
    int p2_pts = calc_points(p2);
    printf("p2 = %i\n", p2_pts);
    
    if (p1_pts > p2_pts)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_pts < p2_pts)
    {
        printf("Player 2 wins!\n");
    }
    else 
    {
        printf("Tie!\n");
    }
} 

// Function with the alphabet point and relative conversion
int calc_points(string p_input)
{
    const char s1[] = "aeilnorstu";
    const char s2[] = "dg";
    const char s3[] = "bcmp";
    const char s4[] = "fhvwy";
    const char s5[] = "k";
    const char s6[] = "jx";
    const char s7[] = "qz";
    
    const int s1_pts = 1;
    const int s2_pts = 2;
    const int s3_pts = 3;
    const int s4_pts = 4; 
    const int s5_pts = 5; 
    const int s6_pts = 8;  
    const int s7_pts = 10; 
   
    int pp = 0;

    for (int i = 0, n = strlen(p_input); i < n; i++)
    {
        for (int i1 = 0, n1 = strlen(s1); i1 < n1; i1++)
        {
            if (tolower(p_input[i]) == s1[i1])
            {
                pp += s1_pts;
            }
        }
                
        for (int i2 = 0, n2 = strlen(s2); i2 < n2; i2++)
        {
            if (tolower(p_input[i]) == s2[i2])
            {
                pp += s2_pts;
            }
        }

        for (int i3 = 0, n3 = strlen(s3); i3 < n3; i3++)
        {
            if (tolower(p_input[i]) == s3[i3])
            {
                pp += s3_pts;
            }
        }

        for (int i4 = 0, n4 = strlen(s4); i4 < n4; i4++)
        {
            if (tolower(p_input[i]) == s4[i4])
            {
                pp += s4_pts;
            }
        }

        for (int i5 = 0, n5 = strlen(s5); i5 < n5; i5++)
        {
            if (tolower(p_input[i]) == s5[i5])
            {
                pp += s5_pts;
            }
        }

        for (int i6 = 0, n6 = strlen(s6); i6 < n6; i6++)
        {
            if (tolower(p_input[i]) == s6[i6])
            {
                pp += s6_pts;
            }
        }

        for (int i7 = 0, n7 = strlen(s7); i7 < n7; i7++)
        {
            if (tolower(p_input[i]) == s7[i7])
            {
                pp += s7_pts;
            }
        }
    }
    return pp;
}
