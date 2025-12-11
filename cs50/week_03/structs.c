#include <stdio.h>
#include <cs50.h>

// Define Candidate struct
typedef struct 
{
    string name;
    int vote;
} candidate;

int main(void)
{
    // Define nr. of Candidates
    const int nr = 3;
    candidate candidates[nr];

    // Populate the array with user's input
    for (int i = 0; i < nr; i++)
    {
        candidates[i].name = get_string("Name: ");
        candidates[i].vote = get_int("Vote: ");
    }
    int hv = 0;
    for (int i = 0; i < nr; i++)
    {
        if (candidates[i].vote > hv)
        {
            hv = candidates[i].vote;
        }
    }
    printf("HV is: %i\n", hv);
    for (int i = 0; i < nr; i++)
    {
        if (candidates[i].vote == hv)
        {
            printf("Candidate is: %s\n", candidates[i].name);
        }
    }
}

