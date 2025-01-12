#include<cs50.h>
#include<stdio.h>

//int variable for pyramid height
//prompt reader if input is not an int or less than 1

int main(void)
{
    int n;
       do
{
    n = get_int("size:");
}
while ( n<1);
for (int i=0; i<n; i++)
{
    for (int j=0; j<n; j++)
    {
        if(i+j+1<n)
        {
            printf(" ");
        }
        else
            {
                printf("#");
            }



    }
        printf("\n");
}
}

