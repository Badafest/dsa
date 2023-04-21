#include <stdio.h>
#include "../utils/main.c"

int main(void)
{
    int numbers[] = {4, 0, 7, 5, 8, 22, 8, 9, 3, 1, 2, 6};
    const int N = sizeof numbers / sizeof numbers[0];
    for (int i = 0; i < N - 1; i++)
    {
        int j = i + 1;
        while (j > 0 && numbers[j - 1] > numbers[j])
        {
            swap(&numbers[j], &numbers[j - 1]);
            j--;
        }
    }
    printNumbers(N, numbers);
}
