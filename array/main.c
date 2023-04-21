#include <stdio.h>
#include <stdlib.h>

#include "array.c"
#include "search.c"

int main(int argc, char *argv[])
{
    array marks;
    int *values = malloc(sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; i++)
    {
        values[i - 1] = atoi(argv[i]);
    }

    createArray(&marks);

    printf("PUSH VALUES\n");
    pushValues(&marks, argc - 1, values);
    printArray(&marks);

    printf("INSERT IN ORDER\n");
    insertInOrder(&marks, 3, 5);
    printArray(&marks);

    printf("QUICK INSERT\n");
    quickInsert(&marks, 3, 8);
    printArray(&marks);

    printf("DELETE IN ORDER\n");
    deleteInOrder(&marks, 3);
    printArray(&marks);

    printf("QUICK DELETE\n");
    quickDelete(&marks, 3);
    printArray(&marks);

    printf("POP VALUES\n");
    popValues(&marks, 3);
    printArray(&marks);

    printf("LINEAR SEARCH\n");
    int index = linearSearch(&marks, 8);
    if (index == -1)
    {
        printf("%d not found\n", 8);
    }
    else
    {
        printf("%d found at index %d\n", 8, index);
    }

    printf("BINARY SEARCH\n");
    index = binarySearch(&marks, 6);
    if (index == -1)
    {
        printf("%d not found\n", 6);
    }
    else
    {
        printf("%d found at index %d\n", 6, index);
    }

    free(values);
    freeArray(&marks);

    return 0;
}