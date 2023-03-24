// Example to check given tree is binary tree or not.
// link-
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

 int ans=-1; //initially setting ans as -1.
  int i=0; //initially counter is 0.
    // Return the Kth smallest element in the given BST
    void solve(Node *root,int K){ //This is basically inorder. (LNR)
        if(root==NULL) return; //if root null then simply return.
        
        solve(root->left,K); //move to left subtree.
        i++; //increase the counter by one.
        if(i==K){ //if i==k that means we got kth smallest element.
           ans=root->data; //putting data of root in ans.
           return;//and simply return to avoid further recursive calls.
        }
        solve(root->right,K); //move to right subtree.
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        solve(root,K); //calling solve function.
        return ans; //returning our answer
    }