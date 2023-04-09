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


//Approach 1: Most optimised approach TC-O(N) SC-O(1)
//Using morris traversal, similar as we did in kth smallest element just instead moving to left, we are moving to right first

 int kthLargest(Node *root, int k)
{
    int ans = -1;
    while(root != NULL){
        
        if(root->right == NULL){
            k--;
            if(k == 0) ans = root->data;
            root = root->left;
        }
        else{
            Node *suc = root->right;
            while(suc->left != NULL and suc->left!=root) 
                suc = suc->left;
            
            if(suc->left == NULL){
                suc->left = root;
                root = root->right;
            }
            else{
                suc->left = NULL;
                k--;
                if(k == 0) ans = root->data;
                root = root->left;
            }
        }
        
    }
    
    return ans;
}


//Approach 2: Using Recursion TC-O(N) SC-O(N)
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