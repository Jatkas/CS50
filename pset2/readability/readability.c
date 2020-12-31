#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{

    int ind;
    float L, S, index, letters = 0, spaces = 0, words = 0, sent = 0;

    string text = get_string("Paste text here: \n");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]))
        {
            letters++;
        }
        if (text[i] == ' ')
        {
            spaces++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sent++;
        }

    }
    words = spaces + 1;
    
    
    L = letters / words * 100;
    S = sent / words * 100;
    
    
    index = 0.0588 * L - 0.296 * S - 15.8;
    ind = round(index);
    if (ind > 15)
    {
        printf("Grade 16+\n");
    }
    else if (ind < 2)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", ind);
    }
}