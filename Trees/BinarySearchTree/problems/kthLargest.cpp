// Example for deletion Binary Search Tree.
// link-
    // https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

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
    
     void solve(Node *root,int K){ //This is basically reverse inorder. (RNL)
        if(root==NULL) return; //if root null then simply return.
        
        solve(root->right,K); //move to right subtree.
        i++; //increase the counter by one.
        if(i==K){ //if i==k that means we got kth smallest element.
           ans=root->data; //putting data of root in ans.
           return;//and simply return to avoid further recursive calls.
        }
        solve(root->left,K); //move to left subtree.
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
         solve(root,K); //calling solve function.
        return ans; //returning our answer
    }