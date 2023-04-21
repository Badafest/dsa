typedef struct array
{
    int length;
    int *ptr;
} array;

void createArray(array *a)
{
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("memory error in create array\n");
        return;
    }
    a->ptr = ptr;
    a->length = 0;
}

void setLength(array *a, int length)
{
    int *ptr = realloc(a->ptr, max(1, length) * sizeof(int));
    if (ptr == NULL)
    {
        printf("memory error in set length\n");
        return;
    }
    a->ptr = ptr;
    a->length = length;
}

void freeArray(array *a)
{
    free(a->ptr);
    a->length = 0;
    printf("array freed\n");
}

void printArray(array *a)
{
    printf("[ ");
    int len = a->length;
    for (int i = 0; i < len; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("]\n");
}

void pushValues(array *a, int n, int *values)
{
    int len = a->length;
    setLength(a, len + n);
    for (int i = 0; i < n; i++)
    {
        (a->ptr)[len + i] = values[i];
    }
    printf("%d values pushed\n", n);
}

void popValues(array *a, int n)
{
    int len = a->length;
    if (len == 0)
    {
        printf("can not pop from empty array\n");
        return;
    }
    n = min(n, len);
    setLength(a, len - n);
    printf("%d values popped\n", n);
}

int checkIndex(int index, int len)
{
    if (index > len)
    {
        printf("%d index out of bound for length %d\n", index, len);
        return 1;
    }
    return 0;
}

void insertInOrder(array *a, int index, int value)
{
    int len = a->length;
    if (checkIndex(index, len))
    {
        return;
    }
    setLength(a, len + 1);
    for (int i = len; i > index; i--)
    {
        (a->ptr)[i] = (a->ptr)[i - 1];
    }
    (a->ptr)[index] = value;
    printf("%d inserted at index %d\n", value, index);
}

void quickInsert(array *a, int index, int value)
{
    int len = a->length;
    if (checkIndex(index, len))
    {
        return;
    }
    setLength(a, len + 1);
    (a->ptr)[len] = (a->ptr)[index];
    (a->ptr)[index] = value;
    printf("%d inserted at index %d and %d pushed to end\n", value, index, (a->ptr)[len]);
}

void deleteInOrder(array *a, int index)
{
    int len = a->length;
    if (checkIndex(index, len - 1))
    {
        return;
    }
    int value = (a->ptr)[index];
    for (int i = index; i < len; i++)
    {
        (a->ptr)[i] = (a->ptr)[i + 1];
    }
    setLength(a, len - 1);
    printf("%d deleted from index %d\n", value, index);
}

void quickDelete(array *a, int index)
{
    int len = a->length;
    if (checkIndex(index, len - 1))
    {
        return;
    }
    int value = (a->ptr)[index];
    (a->ptr)[index] = (a->ptr)[len - 1];
    setLength(a, len - 1);
    printf("%d deleted from index %d and replaced by %d \n", value, index, (a->ptr)[index]);
}