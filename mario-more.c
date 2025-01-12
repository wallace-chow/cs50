#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height:");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < (2 * n + 2); j++)
         {
              if (j < n - i - 1 || j == n|| j == n + 1)
              {
                printf(" ");
              }
              else if ( j < n || j < n + 3 + i)
              {
                printf("#");
              }
         }
         printf("\n");
    }
}
