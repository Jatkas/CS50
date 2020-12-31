#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int avg = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue)/3);


            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sepiaRed = round(((float)image[i][j].rgbtRed) * 0.393 + ((float)image[i][j].rgbtGreen) * 0.769 + ((float)image[i][j].rgbtBlue) * 0.189);
            int sepiaGreen = round(((float)image[i][j].rgbtRed) * 0.349 + ((float)image[i][j].rgbtGreen) * 0.686 + ((float)image[i][j].rgbtBlue) * 0.168);
            int sepiaBlue = round(((float)image[i][j].rgbtRed) * 0.272 + ((float)image[i][j].rgbtGreen) * 0.534 + ((float)image[i][j].rgbtBlue) * 0.131);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE reflect;

            reflect = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = reflect;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur[height][width];
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int blurRed = 0;
            int blurGreen = 0;
            int blurBlue = 0;
            int dal = 0;
            int mindy = -1;
            int mindx = -1;
            int maxdy = 1;
            int maxdx = 1;

            if (y == 0)
            {
                mindy = 0;
            }
            if (x == 0)
            {
                mindx = 0;
            }
            if (y == height - 1)
            {
                maxdy = 0;
            }
            if (x == width - 1)
            {
                maxdx = 0;
            }

                for (int dy = mindy; dy <= maxdy; dy++)
                    {
                        for (int dx = mindx; dx <= maxdx; dx++)
                        {
                            blurRed = blurRed + image[y + dy][x + dx].rgbtRed;
                            blurGreen = blurGreen + image[y + dy][x + dx].rgbtGreen;
                            blurBlue = blurBlue + image[y + dy][x + dx].rgbtBlue;
                            dal++;
                        }
                    }

            blur[y][x].rgbtRed = round(((float)blurRed) / dal);
            blur[y][x].rgbtGreen = round(((float)blurGreen) / dal);
            blur[y][x].rgbtBlue = round(((float)blurBlue) / dal);
        }
    }
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x].rgbtRed = blur[y][x].rgbtRed;
            image[y][x].rgbtGreen = blur[y][x].rgbtGreen;
            image[y][x].rgbtBlue = blur[y][x].rgbtBlue;
        }
    }
    
    return;
}

