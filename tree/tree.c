typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

node *Node(int value)
{
    node *root = malloc(sizeof(node));
    if (root == NULL)
    {
        printf("MEMORY ERROR IN NODE CREATION\n");
        return NULL;
    }
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node *Left(node *root, int value)
{
    if (root->left == NULL)
    {
        node *left = Node(value);
        root->left = left;
        return left;
    }
    else
    {
        return root->left;
    }
}

node *Right(node *root, int value)
{
    if (root->right == NULL)
    {
        node *right = Node(value);
        root->right = right;
        return right;
    }
    else
    {
        return root->right;
    }
}

void printPreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->value);
    }
}

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->value >= root->value)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}