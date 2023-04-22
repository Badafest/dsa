#include <stdio.h>
#include "../utils/main.c"

void partition(int *numbers, int low, int high);

int main(void)
{
    int numbers[] = {4, 0, 7, 5, 8, 22, 8, 9, 3, 1, 2, 6};
    const int N = sizeof numbers / sizeof numbers[0];
    partition(numbers, 0, N - 1);
    printNumbers(N, numbers);
}

void partition(int *numbers, int low, int high)
{
    int pivot = numbers[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (numbers[i] <= pivot)
        {
            i++;
        }
        while (numbers[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&numbers[i], &numbers[j]);
        };
    } while (i < j);
    if (low < j)
    {
        swap(&numbers[low], &numbers[j]);
    }
    if (low < high)
    {
        partition(numbers, low, j - 1);
        partition(numbers, j + 1, high);
    }
}