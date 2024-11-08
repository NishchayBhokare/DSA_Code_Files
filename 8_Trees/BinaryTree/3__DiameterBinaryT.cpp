// Example for Height of Binary Tree
//GFG
// link-
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

//Approach 1: Most optimised approach. TC-O(N) SC-O(N)
//Diameter can be hight of left sub tree + height of right sub tree, 
//or somewhere in left subtree or somewhere in right subtree.
int maxDiameter = 0; // initially maxi i.e diameter is 0;
int height(struct Node *node)
{
    // base case
    if (node == NULL)
    { // if root is null or after travering to depth any node, if it is empty then that time we will return 0;
        return 0;
    }

    int lh = height(node->left);  // moving towards left side of tree.
    int rh = height(node->right); // moving towards right side of tree.

    maxDiameter = max(maxDiameter, lh + rh + 1); // by comparing just taking max diameter. (1 refers to current node);

    int maxHeight = 1 + max(lh, rh); // taking max of left & right and adding 1 to it. (1 refers to current node);
    return maxHeight;
}

//we can write like this also. -> this is similar function which works as above.
int findDiameter(Node *root, int &maxDiameter){
    if(root == NULL) return 0;
    
    int lh = findDiameter(root->left,maxDiameter);
    int rh = findDiameter(root->right,maxDiameter);
    
    int diameter = 1 + lh + rh;
    maxDiameter = max(maxDiameter, diameter);
    int height = 1 + max(lh,rh);
    
    return height;
}

int diameter(Node *root)
{
    // Your code here
    height(root); // calling height function
    return maxDiameter;  // return maximum diameter of any node i.e lh+rh+1 of any max node.
}


//Approach 2: TC-O(N) SC-O(N)
//instead returning only diameter we are returning height also, so that no need to call height function. // so loop till last node and then calculate height and diamter.
//first->diameter and second->height.
pair<int,int> diameterFast(Node *root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int op1 = left.first; //option first can be left sub tree
    int op2 = right.first; //option two can be right sub tree
    int op3 = left.second + right.second + 1; //option three can be height of left and right sub tree.
    
    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));  //calculate max of all three options for diameter
    ans.second = max(left.second,right.second) + 1; //for height calculate max between left height and right right +1.
    
    return ans;
}

int diameter(Node* root) {
    pair<int,int> ans = diameterFast(root);
    return ans.first; //returning ans.first that max diameter
}


//Approach 3: Brute force solution. TC-O(N2) SC-O(N)
int height(struct Node* node){
    if(node == NULL) return 0;
    
    int h1=height(node->left);
    int h2=height(node->right);
    
    int ans = max(h1,h2) + 1;
    return ans;
}

int diameter(Node* root) {
    if(root == NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left) + 1 + height(root->right);
    return max(op1,max(op2,op3));
}