//Lowest Common Ancestor
//GFG
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

//Approach 1: More optimised approach TC-O(Height of the BST) SC-O(1).
Node* LCA(Node *root, int n1, int n2)
{
    while(root != NULL){
        if(n1 < root->data and n2 < root->data){
            root = root->left;
        }
        else if(n1 > root->data and n2 > root->data)
            root = root->right;
            
        else return root;
    }
    return root;
}

//Approach 2: Optimised Approach. TC-O(Height of the BST).SC-O(Height of the BST).
//As we know left part is smaller than root and right part is larger than root;
Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL) return NULL; //when root is NULL then we will return null.
   //Your code here
   if(root->data > n1 && root->data > n2) return LCA(root->left,n1,n2); 
   //if root'data is greater than both n1 & n2 then lowest ancestors of n1 & n2 will lies in left subtree.
   
   else if(root->data < n1 && root->data < n2) return LCA(root->right,n1,n2);
   //if root'data is smaller than both n1 & n2 then lowest ancestors of n1 & n2 will lies in right subtree.
   
   else return root; //if root's is either greater than n1 or less than n2 and vice versa. then definitely current node is lowest ancestors cause current node is meet up point for those n1 & n2. 
    //returning current node.
}