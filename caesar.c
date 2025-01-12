#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int argc_check(int a);
int alphabet_check(string b);
int sign_checker(string c);
string encrypt(string word, string e);

int main(int argc, string argv[])
{
    if (argc_check (argc) != 0)
    return 1;
    if (alphabet_check (argv[1]) != 0)
    return 1;
    if (sign_checker (argv[1]) != 0)
    return 1;

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: %s\n", encrypt(plaintext, argv[1]));
}


int argc_check(int a)
{
    int x = 0;
    if (a != 2)
    {
        printf("Usage: ./caesar key\n");
        x = 1;
    }
    return x;
}


int alphabet_check(string b)
{
    int y = 0;
    int x = strlen (b);
    for (int i = 0; i < x; i++)
    {
        if (isalpha (b[i]) != 0)
        {
            y = 1;
        }
    }
    if (y == 1)
    {
        printf("Usage ./caesar key\n");
    }
    return y;
}

int sign_checker(string c)
{
    int k = 0;
    if (c < 0)
    {
        printf("Usage: ./caesar key\n");
        k = 1;
    }
    return k;
}

string encrypt(string word, string e)
{
    int z = strlen (word);
    for (int j = 0; j < z; j++)
    {
        if(isupper(word[j]) != 0)
        {
            word[j] = 'A' + (word[j] - 'A' + atoi(e)) % 26;
        }
        else if(islower(word[j]) != 0)
        {
            word[j] = 'a' + (word[j] - 'a' + atoi(e)) % 26;
        }
        else
        {
            word[j] = word[j];
        }
    }
    return word;
}
