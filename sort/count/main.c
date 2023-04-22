#include <stdio.h>
#include <stdlib.h>
#include "../utils/main.c"

int main(void)
{
    int numbers[] = {4, 0, 7, 5, 8, 22, 8, 9, 3, 1, 2, 6};
    const int N = sizeof numbers / sizeof numbers[0];

    int max = maxNum(N, numbers);

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
    {
        free(count);
        return 1;
    }

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        count[numbers[i]]++;
    }
    int j = 0;
    int i = 0;
    while (j < N)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            numbers[j] = i;
            j++;
            count[i]--;
        }
    }
    printNumbers(N, numbers);
    free(count);
}
