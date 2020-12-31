void print(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
        printf("%i -asis laimejo pries %i -aji, ant tasku : %i\n", i , j , preferences[i][j]);
        }
    }
    return;
}

    for (int l = 0; l < pair_count; l++)
    {
    printf("%i -oji pora laimejo: %i\n", l, pairs[l].winner);
    printf("%i -oji pora lost: %i\n", l, pairs[l].loser);
    }


    void lock_pairs(void)
{
    for (int i = 0; i < (candidate_count * (candidate_count - 1)) / 2; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].loser][pairs[i].winner] = false;
        locked[i][i] = false;
    }

    int lygiosios[candidate_count - 1];
    for (int j = 0; j < candidate_count; j++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if(locked[j][k] == false)
            {
                lygiosios[j]++;
            }
        }
    }

    for (int l = 0; l < candidate_count; l++)
    {
        if (lygiosios[l] == candidate_count)
        {
            locked[pairs[candidate_count - 1].winner][pairs[candidate_count - 1].loser] = false;
        }
    }

    return;
}



void print_winner(void)
{
    int laimetojas[candidate_count];
    int victor = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                laimetojas[i]++;
            }
        }
    }

    for (int k = 0; k < candidate_count - 1; k++)
    {
        if (laimetojas[k] < laimetojas[k + 1])
        {
            victor = k + 1;
        }
    }

    printf("%s\n", candidates[victor]);
    return;
}


            locked[pairs[k].winner][pairs[k].loser] = true;
            locked[pairs[k].loser][pairs[k].winner] = false;
            locked[k][k] = false;