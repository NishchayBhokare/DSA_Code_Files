// Example for checking given binary tree is sum tree or not.
// link-
// https://practice.geeksforgeeks.org/problems/sum-tree/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

int f = 1; // initially flag is one i.e assuming given binary tree is sum tree..
int solve(Node *root)
{
    if (!root)
        return 0; // if root is null we will return 0;
        
    if (!root->left && !root->right)
        return root->data; // when we will reach to child node that time we will return data of that child node. cause no need to check sum of left and right for that child node.

    if (f == 0)
        return 0; // now at any point if flag is zero then no need to check further nodes.

    int left = solve(root->left);   // moving towards left side of tree.
    int right = solve(root->right); // moving towards right side of tree.

    if (root->data != (left + right))
        f = 0; // now if current node's data != sum of it's left and right subtrees then we will keep flag as 0 i.e not a sumTree.

    return (left + right + root->data); // we're returning sum of left + right subtrees + current node's data so that ancestors can check sum is equal or not.
}
bool isSumTree(Node *root)
{
    solve(root); // calling to the solve function
    return f;    // returning flag value either 0 or 1.
}