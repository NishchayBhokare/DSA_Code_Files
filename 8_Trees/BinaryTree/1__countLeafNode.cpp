//Count the leaf nodes present in binary tree.
//gfg
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//TC-O(N) SC-O(1)
void solve(Node *root, int &count){ //use any traversal, here using preorder and take count as reference variable
    if(root == NULL){
        return; //if root is null then return 
    } 
    solve(root->left,count); //calling for left node
    solve(root->right,count); //for right node
    if(root->left == NULL and root->right== NULL) count++; //if current node's left and right both child is null that means current node is leaf node so increment count.
    
}

int countLeaves(Node* root)
{
  int count=0;
  solve(root,count); //calling function
  return count;
}