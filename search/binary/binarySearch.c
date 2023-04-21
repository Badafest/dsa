#include <stdio.h>
#include <stdlib.h>

const int numbers[] = {1, 3, 5, 7, 9, 12, 15};
int binarySearch(int search, int from, int to);

int main(int argc, char **argv)
{
    int search = atoi(argv[1]);

    // binary search
    if (binarySearch(search, 0, 7))
    {
        printf("%d Found\n", search);
        return 0;
    }
    else
    {
        printf("%d Not Found", search);
        return 1;
    };
}

int binarySearch(int search, int from, int to)
{
    int middle = (from + to) / 2;
    if (middle == from || middle == to)
    {
        return 0;
    }
    if (search == numbers[middle])
    {
        return 1;
    }
    else if (search < numbers[middle])
    {
        binarySearch(search, from, middle);
    }
    else
    {
        binarySearch(search, middle, to);
    }
}