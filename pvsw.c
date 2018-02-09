#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NO_OF_WRITES 1000000

int main()
{
    clock_t start1, end1, start2, end2;
    FILE *fp;
    int i;
    float avg;
    float diffs = 0;
    uint8_t byte = 0x30;

    if ((fp = fopen("file.bin", "w")) == NULL)
    {
            printf("Error opening file for writing");
            exit(-1);
    }
    for (i = 0; i < NO_OF_WRITES; i++)
    {
            start1 = clock();
            fwrite(&byte, 1, 1, fp);
            end1 = clock();

            diffs += (end1 - start1);
    }

    avg = diffs / NO_OF_WRITES;
    printf("Avg. no. of ticks per fwrite() over %d writes: %.4f\n", NO_OF_WRITES, avg);

    diffs = 0;

    for (i = 0; i < NO_OF_WRITES; i++)
    {
            start2 = clock();
            fprintf(fp, "%c", byte);
            end2 = clock();

            diffs += (end2 - start2);
    }

    avg = diffs / NO_OF_WRITES;
    printf("Avg. no. of ticks per fprintf() over %d writes: %.4f\n", NO_OF_WRITES, avg);
    fclose(fp);
}