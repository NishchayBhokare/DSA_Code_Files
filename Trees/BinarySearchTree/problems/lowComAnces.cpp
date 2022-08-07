// Example for deletion Binary Search Tree.
// link-
    // https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL) return NULL; //when root is NULL then we will return null.
   //Your code here
   if(root->data > n1 && root->data > n2) return LCA(root->left,n1,n2); 
   //if root'data is greater than both n1 & n2 then lowest ancestors of n1 & n2 will lies in left subtree.
   
   else if(root->data < n1 && root->data < n2) return LCA(root->right,n1,n2);
   //if root'data is smaller than both n1 & n2 then lowest ancestors of n1 & n2 will lies in right subtree.
   
   else return root; //if root's is either greater than n1 or less than n2 and vice versa. then definitely current node is lowes ancestors cause current node is meet up point for those n1 & n2. 
    //returning current node.
}