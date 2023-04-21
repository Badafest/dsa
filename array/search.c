int linearSearch(array *a, int value)
{
    int len = a->length;
    for (int i = 0; i < len; i++)
    {
        if ((a->ptr)[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int midSearch(int *nums, int start, int end, int value)
{
    int mid = (start + end) / 2;
    if (start == mid || end == mid)
    {
        return -1;
    }
    if (value == nums[mid])
    {
        return mid;
    }
    else if (value == nums[start])
    {
        return start;
    }
    else if (value == nums[end])
    {
        return end;
    }
    else if (nums[mid] > value)
    {
        return midSearch(nums, start, mid, value);
    }
    else
    {
        return midSearch(nums, mid, end, value);
    }
}

int binarySearch(array *a, int value)
{
    return midSearch(a->ptr, 0, a->length - 1, value);
}