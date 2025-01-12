#include <cs50.h>
#include <math.h>
#include <stdio.h>

long x;
int s1;
int card(int a);
int d(long b);

int main(void)
{
    do
    {
        x = get_long("card number:");
    }
    while (x < 1);
    s1 = 0;
    for (int i = 2; i < 17; i = i + 2)
    {
        s1 = s1 + d(2 * card(i));
    }
    int s2 = 0;
    for (int j = 1; j < 17; j = j + 2)
    {
        s2 = card(j) + s2;
    }
    if ((s1 + s2) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (card(16) == 4 || (card(13) == 4 && card(16) == 0 && card(15) == 0))
    {
        printf("VISA\n");
    }
    else if (card(16) == 5 &&
             (card(15) == 1 || card(15) == 2 || card(15) == 3 || card(15) == 4 || card(15) == 5))
    {
        printf("MASTERCARD\n");
    }
    else if (card(16) == 0 && (card(15) == 3 && (card(14) == 4 || card(14) == 7)))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
int card(int a)
{
    long y = x / pow(10, a - 1);
    return y % 10;
}
int d(long b)
{
    int g = 0;
    while (b != 0)
    {
        g = g + b % 10;
        b = b / 10;
    }
    return g;
}
