#include <stdio.h>

void swap(int *a, int *b);
void printNumbers(int n, int *nums);

int main()
{
    int numbers[] = {4, 0, 7, 5, 8, 22, 8, 9, 3, 1, 2, 6};
    const int N = sizeof numbers / sizeof numbers[0];
    int noOfSwaps;
    do
    {
        noOfSwaps = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                swap(&numbers[i], &numbers[i + 1]);
                noOfSwaps++;
            }
        }
    } while (noOfSwaps);
    printNumbers(N, numbers);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printNumbers(int n, int *nums)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}