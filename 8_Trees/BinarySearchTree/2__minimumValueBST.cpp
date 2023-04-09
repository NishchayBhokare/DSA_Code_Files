// Find minimum value in binary search tree.
//GFG
// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

//TC-O(H) SC-O(1)
int minValue(Node* root) {
    // Code here
    if(root==NULL) return -1; //if initially root is null we will return -1.
    while(root->left!=NULL){  //looping till last element of left subtree. (i.e left most element is minmum element in BST) 
        root=root->left;
    }
    return root->data; //returning last element of left subtree.
}

// int maxValue(Node* root) {
//     // Code here
//     if(root==NULL) return -1; //if initially root is null we will return -1.
//     while(root->right!=NULL){ //looping till last element of right subtree. (i.e right most element is maximum element in BST) 
//         root=root->right;
//     }
//     return root->data; //returning last element of right subtree.
// }