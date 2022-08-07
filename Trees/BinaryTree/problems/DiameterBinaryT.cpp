// Example for Height of Binary Tree
// link-
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

int maxi = 0; // initially maxi i.e diameter is 0;
int height(struct Node *node)
{
    // base case
    if (node == NULL)
    { // if root is null or after travering to depth any node, if it is empty then that time we will return 0;
        return 0;
    }

    int lh = height(node->left);  // moving towards left side of tree.
    int rh = height(node->right); // moving towards right side of tree.

    maxi = max(maxi, lh + rh + 1); // by comparing just taking max diameter of any node. (1 refers to current node);

    return 1 + max(lh, rh); // taking max from left & right and adding 1 to it. (1 refers to current node);
    //  return maxHeight;
}

int diameter(Node *root)
{
    // Your code here
    height(root); // calling height function
    return maxi;  // return maximum diameter of any node i.e lh+rh+1 of any max node.
}