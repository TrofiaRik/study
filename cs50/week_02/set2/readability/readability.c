#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_chars(string text);
int count_words(string text);
int count_sent(string text);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: "); 
    // Analyze text count numbers of letters, words, sentences
    // ** Number of Letters **
    int n_chars = count_chars(text);
    // printf("Total Number of Letters is: %i\n", n_chars);
    // ** Number of words **
    int n_words = count_words(text);
    // printf("Total Number of Words is: %i\n", n_words);
    // ** Number of sentences **
    int n_sentences = count_sent(text);
    // printf("Total Number of Sentences is: %i\n", n_sentences);
    
    // Calc Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    // L = avr. num of letters (chars) per 100 words
    // S = avr num of sentences per 100
    int cli = round(0.0588 * (((float) n_chars / n_words) * 100) - 0.296 * (((float) n_sentences / n_words) * 100) - 15.8);

    printf("Coleman-Lieu index is: %i\n", cli);
    // Print the Grade Level
    if (cli < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cli >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", cli);
    }
}

// ** Function to Count Letters//
int count_chars(string text)
{
    int n_chars = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            n_chars++;
        }
    }
    return n_chars;
}

// ** Function to Count words//
int count_words(string text)
{
    int n_words = 0;
    int s_e = 0;
    // word = any sequence of chars separated by a space
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (s_e == 0 || s_e == 9)
        {
            if (isalnum(text[i]))
            {
                s_e = 5;
                n_words++;
            }
            else 
            {
                continue;
            }
        }
        else if (s_e == 5)
        {
            if (isspace(text[i]))
            {
                s_e = 9;
            }
            else 
            {
                continue;
            }
        }
    }
    return n_words;  
}

// ** Function to count sentences//
int count_sent(string text)
{
    int n_sentences = 0;
    int s_e = 0;
    // any sequence of characters that ends with a . or a ! or a ?
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (s_e == 0 || s_e == 9)
        {
            if (isalnum(text[i]))
            {
                s_e = 5;
                n_sentences++;
            }
            else 
            {
                continue;
            }
        }
        else if (s_e == 5)
        {
            if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                s_e =9;
            }
            else 
            {
                continue;
            }
        }
    }
    return n_sentences;
}
