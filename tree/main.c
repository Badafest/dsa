#include <stdio.h>
#include <stdlib.h>

#include "tree.c"

// tree to represent:
//                 7
//         5               12
//     3       6       11      13
// 2                                 16

int main(void)
{
    node *root = Node(7);
    node *left1 = Left(root, 5);
    node *right1 = Right(root, 12);
    node *left21 = Left(left1, 3);
    node *right21 = Right(left1, 6);
    node *left22 = Left(right1, 11);
    node *right22 = Right(right1, 13);
    node *left31 = Left(left21, 2);
    node *right34 = Right(right22, 16);

    printf("PRE ORDER => ");
    printPreOrder(root);
    printf("\n");

    printf("POST ORDER => ");
    printPostOrder(root);
    printf("\n");

    printf("IN ORDER => ");
    printInOrder(root);
    printf("\n");

    printf("IS BST? => %s", isBST(root) ? "YES" : "NO");
}