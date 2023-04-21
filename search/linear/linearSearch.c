#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int search = atoi(argv[1]);
    printf("%d ", search);
    int numbers[] = {3, 5, 2, 1, 9, 7, 6};

    // linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == search)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}