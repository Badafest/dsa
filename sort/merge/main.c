#include <stdio.h>
#include <stdlib.h>
#include "../utils/main.c"

void merge(int *nums, int size, int mergeIndex);

int main(void)
{
    int numbers[] = {4, 0, 7, 5, 8, 22, 8, 9, 3, 1, 2, 6};
    const int N = sizeof numbers / sizeof numbers[0];
    merge(numbers, N, N / 2);
    printNumbers(N, numbers);
    return 0;
}

void merge(int *nums, int size, int mergeIndex)
{
    if (size > 2)
    {
        merge(&nums[0], mergeIndex, mergeIndex / 2);
        merge(&nums[mergeIndex], size - mergeIndex, (size - mergeIndex) / 2);
    }

    int *original = malloc(size * sizeof(int));
    if (original == NULL)
    {
        free(nums);
        return 1;
    }
    copy(size, nums, original);

    int i = 0;
    int a = 0;
    int b = mergeIndex;

    while (a < mergeIndex && b < size)
    {
        if (original[a] < original[b])
        {
            nums[i] = original[a];
            a++;
        }
        else
        {
            nums[i] = original[b];
            b++;
        }
        i++;
    }

    while (a < mergeIndex)
    {
        nums[i] = original[a];
        a++;
        i++;
    }

    while (b < size)
    {
        nums[i] = original[b];
        b++;
        i++;
    }

    free(original);
}