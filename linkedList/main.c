#include <stdio.h>
#include <stdlib.h>

#include "linkedList.c"

int main(int argc, char *argv[])
{
    list *l = newList();
    int len;
    for (int i = 1; i < argc; i++)
    {
        len = insertNode(l, atoi(argv[i]), i - 1);
        if (len != -1)
        {
            printf("length => %d\n", len);
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("value => %d\n", getNode(l, i));
    }

    printf("negative index %d, value %d\n", -2, getNode(l, -2));
    printf("delete that node\n");

    len = removeNode(l, -2);
    for (int i = 0; i < len; i++)
    {
        printf("value => %d\n", getNode(l, i));
    }
}