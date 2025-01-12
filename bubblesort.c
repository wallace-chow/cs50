#include <cs50.h>
#include <stdio.h>
#include <string.h>
int limbo[8];
void bubble_sort(int* a, int size);
int main (void)
{
    int array[7] = {7, 10, 8, 17, 2, 4, 0};
    bubble_sort(array, 7);
    for(int i = 0; i < 7; i++)
    {
        printf("%i ", array[i]);
    }
    return 0;
}

void bubble_sort(int* a, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
         for (int i = 0; i < size - 1 - j; i++)
            {
            if (a[i] > a[i + 1])
                {
                    limbo[0] = a[i + 1];
                    a[i + 1] = a[i];
                    a[i] = limbo[0];
                }
            }
    }
}
