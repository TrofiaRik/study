#include "helpers.h"
#include <endian.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int av = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 + 0.5;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = av;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Sepia algo:
    // Each pixel
    // +------------------------------------------------------------+
    // | sepia_red = (red * .393) + (green * .769) + (blue * .189)  |
    // | sepia_green = (red * .349) + (green * .686) + (blue * .168)|
    // | sepia_blue = (red * .272) + (green * .534) + (blue * .131) |
    // +------------------------------------------------------------+
    // 0 < cap < 255 inclusive
    
    // Defining symbolic constants for the algo parameters:
    #define red_r .393 
    #define red_g .769
    #define red_b .189

    #define green_r .349 
    #define green_g .686
    #define green_b .168

    #define blue_r .272 
    #define blue_g .534
    #define blue_b .131
     
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepia_red = (image[i][j].rgbtRed * red_r + image[i][j].rgbtGreen * red_g + image[i][j].rgbtBlue * red_b) + 0.5;
            int sepia_green = (image[i][j].rgbtRed * green_r + image[i][j].rgbtGreen * green_g + image[i][j].rgbtBlue * green_b) + 0.5;
            int sepia_blue = (image[i][j].rgbtRed * blue_r + image[i][j].rgbtGreen * blue_g + image[i][j].rgbtBlue * blue_b) + 0.5;

            if (sepia_red > 255 )
            {
                int dkpr = ( (sepia_red - 255) / (float)sepia_red ) * 100.0;
                sepia_red = 255;
                sepia_green = sepia_green - (sepia_green * dkpr / 100.0);
                sepia_blue = sepia_blue - (sepia_blue * dkpr / 100.0);
            }
            if (sepia_green > 255)
            {
                int dkpg = ( (sepia_green - 255) / (float)sepia_green ) * 100.0;
                sepia_green = 255;
                sepia_red = sepia_red - (sepia_red * dkpg / 100.0);
                sepia_blue = sepia_blue - (sepia_blue * dkpg / 100.0);
            }
            if (sepia_blue > 255)
            {
                int dkpb = ( (sepia_blue - 255) / (float)sepia_blue ) * 100.0;
                sepia_blue = 255;
                sepia_red = sepia_red - (sepia_red * dkpb / 100.0);
                sepia_blue = sepia_blue - (sepia_blue * dkpb / 100.0);
            }
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < ((width -1) / 2); j++)
        {
            int mir = (width - 1) - j;
            RGBTRIPLE temp_mir = image[i][mir];
            image[i][mir] = image[i][j];
            image[i][j] = temp_mir;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // First I need to duplicate the image array:
    RGBTRIPLE ic[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ic[i][j] = image[i][j];
        }
    }

    // main loop for avarage and substitution
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ct = 0;
            int sum_r = 0;
            int sum_g = 0;
            int sum_b = 0;
            // second 2d loop to scan the surrounding all the 9 pixels in the grid
            for (int di = - 1; di < 2; di++)
            {
                for (int dj = - 1; dj < 2; dj++)
                {                   
                    int ni = i + di;
                    int nj = j + dj;
                     
                    if (nj < 0 || nj > (width - 1) || ni < 0 || ni > (height - 1)) 
                    {
                        ct++;
                    }
                    else 
                    {
                        sum_r += ic[ni][nj].rgbtRed; 
                        sum_g += ic[ni][nj].rgbtGreen;
                        sum_b += ic[ni][nj].rgbtBlue;
                    }
                }
            }
            // def divisor variable
            float dv = (9.0 - ct);
            // calculating avarage values
            //int av_red = sum_r / dv;
            //int av_green = sum_g / dv;
               
            image[i][j].rgbtGreen = (sum_g / dv) + 0.5;
            image[i][j].rgbtRed = (sum_r / dv) + 0.5;
            image[i][j].rgbtBlue = (sum_b / dv) + 0.5;
        }
    } 
    return;
}
