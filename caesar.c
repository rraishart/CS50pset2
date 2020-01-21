/**
 * caesar.c
 * 
 * Ryan Raishart on 4/13/2016
 * rraishart@gmail.com
 * 
 * Encrypts messages using Caesar's cipher.
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define CAP_A_ASCII 65
#define LOW_A_ASCII 97
#define ALPHA_SIZE 26
 
void Encrypt(string x, int k);
int CheckKey(int num);
int CheckArgC(int count);
 
int main(int argc, string argv[])
{
    // validates arg count
    if (CheckArgC(argc))
    {
        return 1;
    }
    
    // converts key to int
    int key = atoi(argv[1]);
    
    // ensures key # is in bounds
    if (CheckKey(key))
    {
        return 1;
    }
    
    // store phrase
    string phrase = GetString();
    
    Encrypt(phrase, key);
    printf("\n");
}

/**
 * Prints encrypted phrase passed to it by converting each letter to 0 based
 * index and using an array of the alphabet.
 */
void Encrypt(string phrase, int key)
{
    // Store uppercase ascii alphabet in array
    int alpha[26];
    for (int i = 0, n = CAP_A_ASCII; i < ALPHA_SIZE; i++, n++)
    {
        alpha[i] = n;
    }
    
    // traverse string
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        // checks for non-letters and prints them unchanged
        if (isalpha(phrase[i]) == 0)
        {
            printf("%c", phrase[i]);
        }
        else
        {
            // checks if lowercase
            int upper = isupper(phrase[i]);
            if (upper == 0)
            {
                // puts letter on 0 based index and finds value to increment by
                int letter = ((phrase[i] - LOW_A_ASCII) + key) % ALPHA_SIZE;
                // stores and prints encrypted letter
                char new_char = alpha[letter];
                printf("%c", tolower(new_char));
            }
            else
            {
                // handles/prints encrypted uppercase
                int letter = ((phrase[i] - CAP_A_ASCII) + key) % ALPHA_SIZE;
                char new_char = alpha[letter];
                printf("%c", new_char);
            }
        }
    }
    
}

/**
 * Returns 1 if not passed 2, otherwise returns 0.
 */
int CheckArgC(int count)
{
    if (count != 2)
    {
        printf("Please pass only two arguments.\n");
        return 1;
    }
    else 
    {
        return 0;
    }
}

/**
 * Returns 1 if passed an invalid key, otherwise 0.
 */
int CheckKey(int num)
{
    if (num < 1 || num > pow(2, 31) - ALPHA_SIZE)
    {
        printf("Please use a valid key\n");
        return 1;
    }
    else 
    {
        return 0;
    }
}