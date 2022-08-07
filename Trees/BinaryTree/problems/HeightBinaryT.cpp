// Example for Height of Binary Tree
// link-
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

int height(struct Node *node)
{
    // code here
    // base case
    if (node == NULL)
    { // if root is null or after traversing to depth any node & if it is empty then that time we will return 0;
        return 0;
    }

    int lh = height(node->left);  // moving towards left side of tree.
    int rh = height(node->right); // moving towards right side of tree.

    int maxHeight = 1 + max(lh, rh); // taking max of left & right and adding 1 to it. (1 refers to current node);
    return maxHeight;
}