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

void copy(int size, int *nums, int *copy)
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = nums[i];
    }
}