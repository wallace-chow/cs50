#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Change owed:");
    }
    while (n < 1);
    int q = n / 25;
    n -= 25 * q;
    int d = n / 10;
    n -= 10 * d;
    int N = n / 5;
    n -= 5 * N;
    printf("%i\n", n + N + q + d);
}
