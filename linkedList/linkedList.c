typedef struct node
{
    int number;
    struct node *next;
} node;

typedef struct list
{
    node *head;
    int length;
} list;

list *newList()
{
    list *l = malloc(sizeof(list));
    if (l == NULL)
    {
        printf("memory error in new list\n");
        return NULL;
    }
    l->head = NULL;
    l->length = 0;
    return l;
}

int insertNode(list *l, int number, int index)
{
    int len = l->length;
    if (index < 0)
    {
        index = len + index;
    }
    if (index > len)
    {
        printf("%d index out of bound for list of length %d\n", index, len + 1);
        return -1;
    }
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("memory error in add node\n");
        return -1;
    }
    n->next = NULL;
    n->number = number;

    node *head = l->head;

    if (index == 0)
    {
        l->head = n;
        n->next = head;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            head = head->next;
        }
        n->next = head->next;
        head->next = n;
    }

    l->length++;
    return l->length;
}

int removeNode(list *l, int index)
{
    int len = l->length;
    if (index < 0)
    {
        index = len + index;
    }
    if (index >= len)
    {
        printf("%d index out of bound for list of length %d\n", index, len);
        return -1;
    }

    node *head = l->head;

    if (index == 0)
    {
        l->head = l->head->next;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            head = head->next;
        }
        head->next = head->next->next;
    }
    l->length--;
    return l->length;
}

int getNode(list *l, int index)
{
    int len = l->length;
    if (index < 0)
    {
        index = len + index;
    }
    if (index >= len || index < 0)
    {
        printf("%d index out of bound for list of length %d\n", index, len);
        return 1;
    }
    node *next = l->head;
    for (int i = 0; i < index; i++)
    {
        next = next->next;
    }
    return next->number;
}
