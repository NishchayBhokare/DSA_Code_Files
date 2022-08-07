// Example to check given tree is binary tree or not.
// link-
// https://practice.geeksforgeeks.org/problems/check-for-bst/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

 bool isValid(Node *root,int min,int max){
        if(root==NULL) return true; //when root is null return true.
        
        if(root->data <= max && root->data >= min){ //checking data of node is liest between min and max or not.
            
            bool left=isValid(root->left,min,root->data); //moving to left and changing max value as current root->data.
            bool right=isValid(root->right,root->data,max); //moving to right and changing min value as current root->data.
            return left && right; //returning left & right. i.e if 1 && 1 then result is 1. if 1 && 0 then result is 0.
        }
        else{
            return false; //if data not lies between min or max then we will return simply false.
        }
        
    }
    
    bool isBST(Node* root) 
    {
        int min=INT8_MIN;
        int max=INT8_MAX;
        return isValid(root,min,max);
        //calling isValid function and passing root,INT_MIN and INT_MAX as parameters.
    }