#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int n = 512;
int x = 0;
int main(int argc, char *argv[])

{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could Not Open File\n");
        return 1;
    }

    uint8_t buffer[n];
    char *filename = malloc(8 * sizeof(char));
    FILE *outptr = NULL;
    while (fread(buffer, sizeof(uint8_t), n, inptr) == n)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        // if start of jpeg is found
        {
            if (x > 0)
                fclose(outptr);
            sprintf(filename, "%03i.jpg", x);
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                //if found but outptr glitched
                fclose(inptr);
                free(filename);
                return 3;
            }
            x++;
        }
        if (outptr != NULL)
            fwrite(buffer, sizeof(uint8_t), 512, outptr);
    }
    if (inptr != NULL)
        fclose(inptr);
    if (outptr != NULL)
        fclose(outptr);
    free(filename);
}
