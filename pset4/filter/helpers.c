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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edge[height][width];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int mult[3] = {1, 2, 1};

            int GxRed = 0;
            int GxGreen = 0;
            int GxBlue = 0;
            int GyRed = 0;
            int GyGreen = 0;
            int GyBlue = 0;
            int red = 0;
            int green = 0;
            int blue = 0;
            int mindy = -1;
            int mindx = -1;
            int maxdy = 1;
            int maxdx = 1;
            int multminY = 0;
            int multminX = 0;

             if (y == 0)
            {
                mindy = 0;
                multminY = 1;
            }
            if (x == 0)
            {
                mindx = 0;
                multminX = 1;
            }
            if (y == height - 1)
            {
                maxdy = 0;
            }
            if (x == width - 1)
            {
                maxdx = 0;
            }

                for (int dy = mindy, my = multminY; dy <= maxdy; dy++, my++)
                    {
                        for (int dx = mindx , mx = multminX; dx <= maxdx; dx++, mx++)
                        {
                            GxRed = GxRed + (mult[my] * dx * image[y + dy][x + dx].rgbtRed);
                            GxGreen = GxGreen + (mult[my] * dx * image[y + dy][x + dx].rgbtGreen);
                            GxBlue = GxBlue + (mult[my] * dx * image[y + dy][x + dx].rgbtBlue);

                            GyRed = GyRed + (mult[mx] * dy * image[y + dy][x + dx].rgbtRed);
                            GyGreen = GyGreen + (mult[mx] * dy * image[y + dy][x + dx].rgbtGreen);
                            GyBlue = GyBlue + (mult[mx] * dy * image[y + dy][x + dx].rgbtBlue);
                        }
                    }

                red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
                green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
                blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));

                if (red > 255)
                {
                    red = 255;
                }
                if (green > 255)
                {
                    green = 255;
                }
                if (blue > 255)
                {
                    blue = 255;
                }

                edge[y][x].rgbtRed = red;
                edge[y][x].rgbtGreen = green;
                edge[y][x].rgbtBlue = blue;
        }
    }


     for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x].rgbtRed = edge[y][x].rgbtRed;
            image[y][x].rgbtGreen = edge[y][x].rgbtGreen;
            image[y][x].rgbtBlue = edge[y][x].rgbtBlue;
        }
    }
    return;
}
