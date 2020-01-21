/**
 * initials.c
 * 
 * Ryan Raishart on 4/13/2016
 * rraishart@gmail.com
 * 
 * Outputs initials of agiven name.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
void ShowInitials(string x);
 
int main(void)
{
    string name = GetString();
    ShowInitials(name);
} 
 
/**
* Prints initials of name passed to it
*/
void ShowInitials(string x)
{
    // prints first initial
    printf("%c", toupper(x[0]));
     
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        // checks for spaces between names
        if (isspace(x[i]) != 0)
        {
            // prints initial of each name after first in caps
            printf("%c", toupper(x[i + 1]));
        }
    }
    printf("\n");
}