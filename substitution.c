// turn all the key to upper case
//  argc = 2, print error msg of choice n return 1
//  1. turn all argv2 to caps 2. check for 26 ALPHABETICAL CAPITALISED 3. return false and print
//  error msg 4. else getstring 5. code a cipher and 6. print ciphertext

// 1. for loop transforming key to an array of kth 2. apply if upper and formula to getstr

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int argc_check(int a);
int key_check(string b);
int repeat_check(string key);
string cipher(string input, string key);

int main(int argc, string argv[])
{
    if (argc_check(argc) == 1)
    {
        return 1;
    }
    if (key_check(argv[1]) == 1)
    {
        return 1;
    }
    if (repeat_check(argv[1]) == 1)
    {
        return 1;
    }
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: %s\n", cipher(plaintext, argv[1]));
    return 0;
}

// a , string b, c get string
int argc_check(int a)
{
    int x = 0;
    if (a != 2)
    {
        printf("Usage: ./substitution KEY\n");
        x = 1;
    }
    return x;
}

int key_check(string b)
{
    int z = 0;
    int x = strlen(b);
    int y = 0;
    for (int i = 0; i < x; i++)
    {
        if (islower(b[i]) != 0)
            b[i] = toupper(b[i]);
    }
    for (int j = 0; j < x; j++)
    {
        if (isupper(b[j]) != 0)
        {
            z++;
        }
    }
    if (z != 26)
    {
        printf("Provide 26 ALPHABETS in your cipher key\n");
        z = 1;
    }
    else
        z = 0;
    return z;
}

int repeat_check(string key)
{
    int x = 0;
    for (int g = 0; g < 26; g++)
    {
        for (int f = 0; f < 26; f++)
        {
            if (key[g] == key[f])
            {
                x++;
            }
        }
    }
    if (x != 26)
    {
        return 1;
        printf("do not repeat characters in the key\n");
    }
    else
        return 0;
}

// cipher
//  inspo from scrabble, using 2 arrays/strings, get data on what alphabet it is by if upper, then
//  word[i] = key[word[i] - Aa]
string cipher(string input, string key)
{
    int x = strlen(input);
    for (int k = 0; k < x; k++)
    {
        if (isupper(input[k]) != 0)
        {
            input[k] = key[input[k] - 'A'];
        }
        else if (islower(input[k]) != 0)
        {
            input[k] = tolower(key[input[k] - 'a']);
        }
        else
            input[k] = input[k];
    }
    return input;
}
