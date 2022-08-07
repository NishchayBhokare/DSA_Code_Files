//Example for deleting nod greater than k
//link-
    // https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


 Node* deleteNode(Node* root, int k)
    {
        if(root==NULL) return NULL; //if given root is NULL then we will return and also while traversing if root becomes null then we will return NULL.
        
       if(root->data >= k){ //IF root's data greater than or equal to k then move to left for getting  lesser value than k. 
           return deleteNode(root->left,k);
       }
       else{ //if root's data is bigger than k, so move to right side.
           root->right = deleteNode(root->right,k); 
//after going to right when we get element lesser than k , then we will remove that element and will attached to root->right of recent call.
       }
       
       return root; //returninig root.
    }