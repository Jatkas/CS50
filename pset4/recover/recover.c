#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char* input_file = argv[1];
    FILE* input_pointer = fopen(input_file, "r");

    if (input_file == NULL)
    {
        printf("Unable to open: %s\n", input_file);
        return 1;
    }

    unsigned char buffer[BLOCKSIZE];
    int counter = 0;
    FILE* output_pointer = NULL;
    bool first = true;

    while (fread(&buffer, BLOCKSIZE, 1, input_pointer) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (first == false)
            {
                fclose(output_pointer);
            }
            else
            {
                first = false;
            }
            
            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            output_pointer = fopen(filename, "w");
            counter++;
            
            if (first == false)
            {
                fwrite(&buffer, BLOCKSIZE, 1, output_pointer);
            }
        }
        else
        {
            if (counter != 0)
            {
                fwrite(&buffer, BLOCKSIZE, 1, output_pointer);
            }
        }
    }
    
    if (output_pointer == NULL)
    {
        fclose(output_pointer);
    }

    if (input_pointer == NULL)
    {
        fclose(input_pointer);
    }

}
