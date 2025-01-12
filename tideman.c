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
    int strength_victory;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
pair limbo[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int highest_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle_track(int first_victim, int cycle_start);

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
// Update ranks given acew vote. ranks i is the voters ith pref
bool vote(int rank, string name, int ranks[])
{
    // TODO look througccandidates, if name matches candidates[i].name then update ranks[rank] = i
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
// Update preferences given one voter's ranks. preferehce i j is how many voters prefer i over j
// preferences [ranks[0]][all j except itself]++ ranks0 = 0 0,1;0,2;0,3....  ranks1 = 2 2,
void record_preferences(int ranks[])
{
    // TODO update preferencs array based on this rank
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i; j < candidate_count - 1; j++)
        {
            preferences[ranks[i]][ranks[j + 1]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other. | look at each pair, determine
// winner and add to pairs array add each pair if pref [i][j] > pref [j][i], pairs[k].winner is i
// pairs[k].loser is j, if < , j is prefered, if =, no pair update pair_count
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        pairs[i].strength_victory = preferences[pairs[i].winner][pairs[i].loser] -
                                    preferences[pairs[i].loser][pairs[i].winner];
    }
    for (int i = 0; i < pair_count - 1; i++)
    {

        for (int j = 0; j < pair_count - 1 - i; j++)
        {
            if (pairs[j].strength_victory < pairs[j + 1].strength_victory)
            {
                limbo[0].winner = pairs[j + 1].winner;
                limbo[0].loser = pairs[j + 1].loser;
                limbo[0].strength_victory = pairs[j + 1].strength_victory;
                pairs[j + 1].winner = pairs[j].winner;
                pairs[j + 1].loser = pairs[j].loser;
                pairs[j + 1].strength_victory = pairs[j].strength_victory;
                pairs[j].winner = limbo[0].winner;
                pairs[j].loser = limbo[0].loser;
                pairs[j].strength_victory = limbo[0].strength_victory;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //
    // TODO locked i j True means we have locked the edge pointing from candidate i to j
    for (int i = 0; i < pair_count; i++)
    {
        if (cycle_track(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}
// cycle_start = pairs[i].loser
bool cycle_track(int first_victim, int cycle_start)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[j][first_victim])
        {
            if (j == cycle_start)
                return false;
            else
            {
                int k = j;
                if (!cycle_track(k, cycle_start))
                    return false;
            }
        }
    }
    return true;
}
// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int x = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
                x++;
        }
        if (x == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}
