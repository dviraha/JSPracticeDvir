void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int start = pairs[i].winner; // b
        int loser = pairs[i].loser; // c // a //b
        // printf("pairs[%d].winner: %s\n", i, candidates[pairs[i].winner]);
        // printf("pairs[%d].loser: %s\n", i, candidates[pairs[i].loser]);
        // printf("start: %s\n", candidates[start]);
        bool cycle = false;
        bool cycle_can = false;
        int og_j;
        for (int j = 0; j < pair_count; j++)
        {

            // printf("i: %d, j: %d\n", i, j);
            if (locked[loser][j] == true && cycle == false)
            {
                // printf("%s and %s are locked, next = %s\n", candidates[loser], candidates[j], candidates[j]);
                loser = j;
                og_j = j;
                j = -1;
                cycle_can = true;
                if (loser == start)
                {
                    cycle = true;
                    printf("there is a cycle\n");
                    break;
                }
            }
            // else
            // {
            //     printf("%s and %s are not locked, next = %s\n", candidates[loser], candidates[j], candidates[loser]);
            // }
            // if (cycle == true)
            // {
            //     printf("there is a cycle");
            // }
            if (cycle_can == true && pair_count == j + 1)
            {
                loser = pairs[i].loser;
                j = og_j;
                cycle_can = false;
            }
        }
        if (cycle == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            // printf("[%s, %s] locked\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
            cycle = false;
        }
    }
    return;
}

**right**

void lock_pairs()
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!makes_circle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the pair unless it makes a circle
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

bool makes_circle(int cycle_start, int loser)
{
    if (loser == cycle_start)
    {
        // If the current loser is the cycle start
        // The entry makes a circle
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (makes_circle(cycle_start, i))
            {
                // Forward progress through the circle
                return true;
            }
        }
    }
    return false;
}
