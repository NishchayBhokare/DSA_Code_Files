// Example for Height of Binary Tree 
//GFG
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

//Approach 1: TC-O(N) SC-O(height)
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


//Approach 2: TC-O(N) SC-O(height)
void solve(struct Node* root, int height, int &maxHeight){
    if(root == NULL){
        maxHeight = max(height,maxHeight); //get max height between two hights.
        return;
    }
    height++; //on every node increment height
    solve(root->left,height,maxHeight);
    solve(root->right,height,maxHeight);
}

int height(struct Node* node){
    int height=0,maxHeight=0;
    solve(node, height,maxHeight);
    return maxHeight; //return answer
}