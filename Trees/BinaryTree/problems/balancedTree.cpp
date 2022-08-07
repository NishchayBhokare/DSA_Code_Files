
// Example for checking given binary tree is balanced or not.
// link-
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

int f = 1; // initially flag is one i.e assuming it iS balanced binary tree.

int solve(struct Node *root)
{
    if (!root)
        return 0; // if root is null or after traversing to depth any node, if it is empty then that time we will return 0;

    if (f == 0)
        return 0; // now at any point if flag is zero then no need to check further nodes.

    int lh = solve(root->left);  // moving towards left side of tree.
    int rh = solve(root->right); // moving towards right side of tree.

    if (abs(lh - rh) > 1)
        f = 0; // if difference between left height and right height is > 0 then flag is 0. i.e unbalanced.

    return 1 + max(lh, rh); // taking max of left & right and adding 1 to it. (1 refers to current node); and also returning it.
}

// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    solve(root); // calling to the solve function
    return f;    // returning flag value either 0 or 1.
}