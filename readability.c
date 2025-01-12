#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// find L average number of letters per 100 words ()
// find S average number of sentence per 100 words (maybe count the number of ends?)

int letters(string l);
int words(string s);
int sentences(string S);

int main(void)
{
    string sample = get_string("text: ");
    float X1 = letters(sample);
    float X2 = words(sample);
    float X3 = sentences (sample);

    float L1 = (X1 / X2) * 100.0;
    float S1 = (X3 / X2) * 100.0;
    int index = round (0.0588 * L1 - 0.296 * S1 - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
       printf("Grade %i\n", index);
}

int letters(string l)
{
    int x1 = 0;
    int x = strlen(l);
    for (int i = 0; i < x; i++)
    {
        if (isalpha (l[i]) != 0)
        {
            x1 ++;
        }
    }
    return x1;
}

int words(string s)
{
    int x2 = 0;
    int y = strlen(s);
    for (int j = 0; j < y; j++)
    {
        if (isspace (s[j]) != 0)
        x2++;
    }
    x2 = x2 + 1;
    return x2;
}

int sentences(string S)
{
    int x3 = 0;
    int z = strlen(S);
    for (int k = 0; k < z; k++)
    {
        if (S[k] == '.' || S[k] == '?' || S[k] == '!')
        {
            x3++;
        }
    }
    return x3;
}
