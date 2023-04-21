#include <stdio.h>

const int numbers[] = {3, 5, 2, 1, 9, 7, 6};

int main(int argc, char **argv)
{
    int search = atoi(argv[1]);
    // linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == search)
        {
            printf("%d Found\n", search);
            return 0;
        }
    }
    printf("%d Not Found\n", search);
    return 1;
}