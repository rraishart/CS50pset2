/**
 * vigenere.c
 * 
 * Ryan Raishart on 4/16/2016
 * rraishart@gmail.com
 * 
 * Encrypts messages using Vigenere's cipher.
 */
 
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define CAP_A_ASCII 65
#define LOW_A_ASCII 97
#define ALPHA_SIZE 26

bool CheckArg2(int count);
bool IsLetters(string arg);
void EncryptVig(string phrase, string key);
 
int main(int argc, string argv[])
{
    if (CheckArg2(argc) == false)
    {
        return 1;
    }
    
    if (IsLetters(argv[1]) == false)
    {
        return 1;
    }
    
    
    // store phrase
    
    
    EncryptVig(phrase, argv[1]);
    printf("\n");
}

void EncryptVig(string phrase, string key)
{
    // Store uppercase ascii alphabet in array
    int alpha[26];
    for (int i = 0, n = CAP_A_ASCII; i < ALPHA_SIZE; i++, n++)
    {
        alpha[i] = n;
    }
    
     // traverse string and track key index(j)
    for (int i = 0, j = 0, n = strlen(phrase); i < n; i++)
    {
        // checks for non-letters and prints them unchanged
        if (isalpha(phrase[i]) == 0)
        {
            printf("%c", phrase[i]);
            
        }
        else
        {
            // finds appropriate key index
            int rot = j % strlen(key);
            // checks if lowercase
            int upper = isupper(phrase[i]);
            if (upper == 0)
            {
                
                // puts letter on 0 based index and finds value to increment by
                int letter =
                ((phrase[i] - LOW_A_ASCII) + (tolower(key[rot]) - LOW_A_ASCII)) 
                % ALPHA_SIZE;
                // stores and prints encrypted letter
                char new_char = alpha[letter];
                printf("%c", tolower(new_char));
            }
            else
            {
                // handles/prints encrypted uppercase
                int letter = ((phrase[i] - CAP_A_ASCII) + (toupper(key[rot]) - 
                CAP_A_ASCII)) % ALPHA_SIZE; 
                char new_char = alpha[letter];
                printf("%c", new_char);
            }
            j++;    
        }
    } 
}


/**
 * Returns true if all characters of passed string are alphabetical, otherwise
 * displays error message and returns false.
 */
bool IsLetters(string arg)
{
    bool letters = true;
    for (int i = 0; i < strlen(arg); i++) 
    {
        if (isalpha(arg[i]) == 0)
        {
            letters = false;
        }
    }
    
    if (letters == false)
    {
        printf("Please only use letters of the alphabet for the key.\n");
    }
    return letters;
}

/**
 * Returns true if passed 2, otherwise otherwise displays an error message and
 * returns false.
 */
bool CheckArg2(int count)
{
    bool two = true;
    if (count != 2)
    {
        printf("Please pass two arguments.\n");
        two = false;
    }
    return two;
}