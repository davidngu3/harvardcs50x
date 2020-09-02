#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int getNumLetters(string word);
int getNumWords(string block);
int getNumSentences(string block);

int main(void)
{
    // seek input paragraph from user
    string input = get_string("Text: ");

    // calculate coleman-liau index of paragraph
    float numWords = getNumWords(input);
    float avgLetters = getNumLetters(input) * (100 / numWords);
    float avgSentences = getNumSentences(input) * (100 / numWords);
    int clindex = round((0.0588 * avgLetters) - (0.296 * avgSentences) - 15.8);

    // return corresponding grade
    string output;
    if (clindex > 16)
    {
        printf("Grade 16+\n");
    }
    else if (clindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", clindex);
    }
}

int getNumLetters(string word)
{
    int letterCount = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            letterCount++;
        }
    }

    return letterCount;
}

int getNumWords(string block)
{
    int wordCount = 1;

    for (int i = 0; i < strlen(block); i++)
    {
        if (isspace(block[i]))
        {
            wordCount++;
        }
    }

    return wordCount;
}

int getNumSentences(string block)
{
    int sentenceCount = 0;

    for (int i = 0; i < strlen(block); i++)
    {
        if (block[i] == '.' || block[i] == '?' || block[i] == '!')
        {
            sentenceCount++;
        }
    }

    return sentenceCount;
}