#include <stdio.h>
#include <stdlib.h>

int *copyNumbers(int size, int *nums);
int main(void)
{
    int nums1[] = {1, 5, 4, 3, 2};
    int size = sizeof nums1 / sizeof nums1[0];
    int *nums2 = copyNumbers(size, nums1);
    nums2[0] = 10;
    printf("After copy => %d, %d", nums1[0], nums2[0]);
    free(nums2);
}

int *copyNumbers(int size, int *nums)
{
    int *copy = malloc(size);
    for (int i = 0; i < size; i++)
    {
        copy[i] = nums[i];
    }
    return copy;
};