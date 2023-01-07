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
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

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
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

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
    //if name match then update ranks[] that the voter has the candidate as the rank preference
    //ranks[i] is user's i'th preference
    // true if recorded
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    //update preferences[i][j]
    //ranks[i]
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {
            if (j > i)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
            //printf("%s over %s: %d\n", candidates[ranks[i]], candidates[ranks[j]], preferences[ranks[i]][ranks[j]]);

        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    //add all pairs with winner-loser to pairs[]
    //tied not added
    //update pair_count
    //pairs stored between pairs[0] to pairs[pair_count-1]
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // printf("winner: %s\n", candidates[i]);
                // printf("loser: %s\n\n", candidates[j]);
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // printf("pair count: %d\n", pair_count);
    for (int i = 0; i < pair_count; i++)
    {
        int max_idx = i;
        for (int j = i; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max_idx].winner][pairs[max_idx].loser])
            {
                max_idx = j;
            }
        }
        int temp = pairs[max_idx].winner;
        pairs[max_idx].winner = pairs[i].winner;
        pairs[i].winner = temp;
        temp = pairs[max_idx].loser;
        pairs[max_idx].loser = pairs[i].loser;
        pairs[i].loser = temp;
        // printf("winner #%d: %s (%d)\n", i, candidates[pairs[i].winner], preferences[pairs[i].winner][pairs[i].loser]);
        // printf("loser #%d: %s (%d)\n\n", i, candidates[pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // while (there's still pairs left to go through, or cycle is false)
        // pair = T
        // pair = T
        // cycle = T

        //

    // for (all the pairs in the pair array)
        // start = winner, next = loser
        // cycle = false
        // while(cycle is false and locked[winner][next] == True)
        //      set to next in cycle here
        //      if next == start then cycle is true
        // if cycle is false, set original to true, else donot set



    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int start = pairs[i].winner; // b
        int next = pairs[i].loser; // c // a //b
        printf("pairs[%d].winner: %s\n", i, candidates[pairs[i].winner]);
        printf("pairs[%d].loser: %s\n", i, candidates[pairs[i].loser]);
        printf("start: %s\n", candidates[start]);
        bool cycle = false;
        bool cycle_can = false;
        int og_j;
        for (int j = 0; j < pair_count; j++)
        {

            printf("i: %d, j: %d\n", i, j);
            if (locked[next][j] == true && cycle == false)
            {
                printf("%s and %s are locked, next = %s\n", candidates[next], candidates[j], candidates[j]);
                next = j;
                og_j = j;
                j = -1;
                cycle_can = true;
            }
            else
            {
                printf("%s and %s are not locked, next = %s\n", candidates[next], candidates[j], candidates[next]);
            }
            if (next == start)
            {
                cycle = true;
                printf("there is a cycle\n");
                break;
            }
            if (cycle == true)
            {
                printf("there is a cycle");
            }
            if (cycle_can == true && pair_count == j + 1)
            {
                next = pairs[i].loser;
                j = og_j;
                cycle_can = false;
            }
        }
        if (cycle == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            printf("[%s, %s] locked\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
            cycle = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int source = 0;
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[j][i] == false)
            {
                source++;
            }
            if (source == pair_count)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}
