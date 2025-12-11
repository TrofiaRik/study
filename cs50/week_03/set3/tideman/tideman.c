#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pref_count;
int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
        printf("Recorded Candidates are: Candidate[%i] = %s\n", i, candidates[i]);
     }

 
    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            printf("locked[%i][%i] = %i\n", i, j, locked[i][j]);
        }
    }
    
    pref_count = 0;
    pair_count = 0;
    printf("Pair count is now = %i\n", pair_count);

    int voter_count = get_int("Number of voters: ");
     
    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        
        printf("Ranks for Voter nr %i:\n", i);
        
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
           
        }
        
        // controll xx ***********************************
        for (int z = 0; z < candidate_count; z++)
        {
            printf("ranks - %i - = %i\n", z, ranks[z]); 
        }
        // controll xx ***********************************

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
           ranks[rank] = i;
           printf("Vote Recorded: Rank nr. %i for %s\n", rank, candidates[i]); 
           return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //int i;
    //int j;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
           if (preferences[ranks[i]][ranks[j]] != 0)
           {
                preferences[ranks[i]][ranks[j]]++;
           }
           else 
           {
                preferences[ranks[i]][ranks[j]]++;
                pref_count++;
           }
            printf("Adding preferences[%i][%i] = %i\n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
            printf("Pref count is now = %i\n", pref_count);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Implementing the main 2d loop on preferences[i(MAX)][j(MAX)] 
    // Implementig a pair index to loop through the pairs array index
    
    // int pi = 0;

    printf("Pair count is now = %i\n", pair_count); // ctrl************************ 
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Implementing the 3 cases of exclusion:
            // a. Identity, i == j, p[s][s]
            // b. No vote received, p[i][j] == 0
            // c. No winner in a given pair, ex. p[0][1] == p[1][0] == n                   // *** new condition to be checked *** //
            if (i == j || preferences[i][j] == 0 || preferences[i][j] == preferences[j][i] || preferences[i][j] < preferences[j][i]) 
            {
                continue;
            }
            else 
            {
            // Add the relevant pairs to the pairs[] array
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                
                               
                // printf("preferences[%i][%i] = %d - Address %p -\n", i, j, preferences[i][j], (void*)&preferences[i][j]);
                printf("Pair nr. %i\n", pair_count);
                printf("- pairs[%i].winner = %i\n", pair_count, i);
                printf("- pairs[%i].loser = %i\n", pair_count, j);
            }
            
            pair_count++;

        }
        printf("\n");
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Selection Sort Style:
    // optimized Version with SINGLE SWAP
    for (int i = 0; i < pair_count; i++)
    {   
        int i_max = i;
        // int j_a = -1;
        // int i_b = -1;

        for (int j = i + 1; j < pair_count; j++)
        {
            if (pairs[j].winner == 0 && pairs[j].loser == 0) // In order to skip the empty pairs[j]
            {
                continue;
            }
            else if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[i_max].winner][pairs[i_max].loser])
            {   
                // j_a = j;
                // i_b = i_max;
                i_max = j;
            }
                
        }   
        
        // Swap. Swapping should happen at the end of each j-cycle of iterations.
        // In case the array is already sorted we do not need any swap, therefore we must exclude this particular case 
        if (i_max != 0)
        {
            int temp_i_winner = pairs[i].winner;
            int temp_i_loser = pairs[i].loser;

            pairs[i].winner = pairs[i_max].winner;
            pairs[i].loser = pairs[i_max].loser;
              
            pairs[i_max].winner = temp_i_winner;
            pairs[i_max].loser = temp_i_loser;
        }  
        
        printf("pairs[%i] = preferences[%i][%i] = %i\npairs[%i].winner = %i - pairs[%i].loser = %i\n\n", i, pairs[i].winner, pairs[i].loser, preferences[pairs[i].winner][pairs[i].loser], i, pairs[i].winner, i, pairs[i].loser); 
        
    }
    return;


}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    /// ++ IMPLEMENTING RECURSIVE FUNCTION ** /////////////////////////////////////
    


    ///////////////////////////////////////////////////////////////////////////////
    int start;
    int cycle = candidate_count;
    
    // Base Case  
      

    for (int i = 0; i < candidate_count; i++)
    {
        if (i == 0)
        {
            locked[ pairs[i].winner ][ pairs[i].loser ] = true;
            start = pairs[i].winner;
        }
        
        if (i != (candidate_count - 1)) 
        {
            if (pairs[i].loser == pairs[i+1].winner)
            {
                cycle--;
            }
            locked[ pairs[i].winner ][ pairs[i].loser ] = true;
        }
        else
        {
            if (pairs[i].loser == pairs[0].winner)
            {
                cycle--;
            }

            if (cycle != 0) // Check and avoid closing a cycle
            {
                locked[ pairs[i].winner ][ pairs[i].loser ] = true;
            }
        } 
        // printf("pairs[%i].winner = %i AND pairs[%i].loser = %i", i, pairs);
        // printf("locked[%i][%i] = %s") 
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("locked[%i][%i] = %i\n", i, j, locked[i][j]);
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    /*for (int i = 0; i < candidate_count; i++)*/
    /*{*/
    /*    for (int j = 0; j < candidate_count; j++)*/
    /*    {*/
    /*        if (locked[i][j] == true && i != j)*/
    /*        {*/
    /*            for (int z = 0; z < candidate_count; z++)*/
    /*            {*/
    /*                if (!(locked[z][i] == true && z != i))*/
    /*                {        */
    /*                    printf("%s", candidates[i]);*/
    /*                }*/
    /*            }*/
    /*        }      */
    /*    }*/
    /*}    */
    return;
}
