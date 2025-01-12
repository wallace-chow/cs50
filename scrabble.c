// implement a program in C that determines the winner of a short Scrabble-like game.
// Your program should prompt for input twice: once for “Player 1” to input their word and once for
// “Player 2” to input their word. Then, depending on which player scores the most points, your
// program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two
// players score equal points).

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int n = 2;
string s[n];
int y[n];

int scrabble(char a);

int main(void)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = get_string("Player %i: ", i + 1);
        int x = strlen(s[i]);
        // capitalise (maybe can outsource?)
        for (int j = 0; j < x; j++)
        {
            s[i][j] = toupper(s[i][j]);
            y[i] += scrabble(s[i][j]);
        }
        // initialise,compute and compare s[1] and s[2]
    }

    if (y[0] > y[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (y[0] < y[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int scrabble(char a)
{
    if ((a == 'A') || a == 'E' || a == 'I' || a == 'L' || a == 'N' || a == 'O' ||
        (a >= 'R' && a <= 'U'))
    {
        return 1;
    }
    else if (a == 'D' || a == 'G')
    {
        return 2;
    }
    else if (a == 'B' || a == 'C' || a == 'M' || a == 'P')
    {
        return 3;
    }
    else if (a == 'F' || a == 'H' || a == 'V' || a == 'W' || a == 'Y')
    {
        return 4;
    }
    else if (a == 'K')
    {
        return 5;
    }
    else if (a == 'J' || a == 'X')
    {
        return 8;
    }
    else if (a == 'Q' || a == 'Z')
    {
        return 10;
    }
    else
        return 0;
}
