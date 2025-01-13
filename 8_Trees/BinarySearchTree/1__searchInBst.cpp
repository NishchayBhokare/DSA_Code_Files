// Search element in Binary Search Tree.
// link-
// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


//Approach 1: Optimised Approach TC-O(LogN) SC-O(1)
bool search(Node* root, int x) {
   while(root != NULL){ //loop till root not becomes null
       if(x == root->data) return true; //if we found element then simply return true.
       
       if(x < root->data) //if x element is less than root element then search in left part.
            root=root->left;
       
       else  //else right part or sub tree.
            root=root->right;
   }
   return false; //if we reach till here that means element is not present in binary search tree.
}


//Approach 2: Recursive Approach TC-O(logn) SC-O(h)
bool search(Node* root, int x) {
    // Your code here
    if(root==NULL) return false; //if root is initially is null or after traversing to the end and element is not found that time we will return false; 

    if(root->data==x) return true; //if element is found then we will return true.

    if(x > root->data) return search(root->right,x); //if element is greater than root's data then search in right subtree of node.
    
    else return search(root->left,x); //if element is smaller than root's data then search in left subtree of node.
}