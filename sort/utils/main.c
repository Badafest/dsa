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

int maxNum(int n, int *nums)
{
    int mx = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > mx)
        {
            mx = nums[i];
        }
    }
    return mx;
}