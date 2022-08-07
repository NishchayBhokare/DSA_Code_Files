// Example for deletion Binary Search Tree.
// link-
    // https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
    

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

 Node* lca(Node* root ,int n1 ,int n2 )
    { 
       if(root==NULL) return NULL;//when n1 or n2 not found;
       if(root->data==n1 or root->data==n2) return root; //we got node either n1 or n2 then we will return it to parent node.
    
       Node *ln=lca(root->left,n1,n2);//traversing to left subtree.
       Node *rn=lca(root->right,n1,n2); //treaversing to right subtree.
       
       if(ln and rn) return root; // case when we got ancestor. i.e if node coming from left and right are non NULL then we will return current node as their ancestor.
       
       if(ln) return ln; //if left node is non null but right node is NULL then simpley return non NULL node. cause current node can't be ancestor of n1 & n2.
       else return rn; //else right node is non null but left node is NULL then simpley return non NULL node. cause current node can't be ancestor of n1 & n2.
       
    }