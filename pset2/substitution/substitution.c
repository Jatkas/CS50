#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char converter(char letter, string key);

int main(int argc, string argv[])
{
    const int keylength = 26;
    char key[keylength];

    if (argc != 2) // takes only two string arguments.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    int ilgis = strlen(argv[1]);
    if (ilgis != keylength) // checks key if its correct lengh
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    bool go = true;
    for (int i = 0; i < keylength; i++)
    {
        if (!isalpha(argv[1][i])) // checks if key is all alphabetic
        {
            go = false;
        }
        
        if (islower(argv[1][i]))
        {
            argv[1][i] = toupper(argv[1][i]);
        }

        key[i] = argv[1][i];
        
        for (int j = 0; j <= i; j++) // checks are there no letters repeating
        {
            if (i != j && key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    if (!go)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
// Validation part above and working
    
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int k = 0, m = strlen(plain); k < m; k++)
    {
        if (isalpha(plain[k])) // converting if alphabetic
        {
            if (isupper(plain[k])) // uppercase
            {
                char raide = converter(plain[k], argv[1]);
                printf("%c", raide);
            }
            else // lowercase
            {
                char raide = plain[k] - 32;
                raide = converter(raide, argv[1]);
                printf("%c", raide + 32);
            }
        }
        else // skipping non-alphabetic stmbols
        {
            printf("%c", plain[k]);
        }
    }
    printf("\n");

}


char converter(char letter, string key)
{
    int j = letter - 65;
    
    letter = key[j];
    
    return letter;
}