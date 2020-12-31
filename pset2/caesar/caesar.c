#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key;
// Takes only two strings in terminal input
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
// loops and checks that input is only numeric below
    bool go = true;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(argv[1][i] <= '9' && argv[1][i] >= '0'))
        {
            go = false;
        }
    }
    if (!go)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    else    // converting key to integer
    {
        key = atoi(argv[1]);
    }

    printf("key: %d\n", key);

    string plain = get_string("plaintext: ");
    
    key = key % 26;
    
    printf("ciphertext: ");
    for (int i = 0, m = strlen(plain); i < m; i++)
    {
        char raide = 0;
        
        if (isalpha(plain[i])) // checking if alphabetic
        {
            if (isupper(plain[i])) // checking if uppercase
            {
                if ((plain[i] + key) > 90) // encryption execution
                {
                    raide = plain[i] - (26 - key);
                }
                else
                {
                    raide = plain[i] + key;
                }
            }
            else // encryption execution lowercase
            {
                if ((plain[i] + key) > 122)
                {
                    raide = plain[i] - (26 - key);
                }
                else
                {
                    raide = plain[i] + key;
                }
            }
        }
        else // printing encrypted letter inside the loop
        {
            raide = plain[i];
        }
        printf("%c", raide);
    }
    printf("\n");
}