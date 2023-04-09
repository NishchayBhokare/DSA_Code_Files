//Boundary Traversal of binary tree

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


void leftBoundaryNodes(Node *root, vector<int>& ans){
//In this left boundaries we will iterate over all left side nodes except left side leaf node
    
    if(root->left == NULL and root->right==NULL){ //looping till second last node in left side. i.e if current node is leaf node then simply return
        return;
    }
    
    ans.push_back(root->data); //push the current left side nodes data
    
    if(root->left == NULL){ //if left is null but right is exist, then move to right once and again check for left boundaries.
        leftBoundaryNodes(root->right,ans);
    }
    
    else leftBoundaryNodes(root->left,ans); //if left is exist then move to left side as normal
}
    
    
void leafNodes(Node *root,vector<int>&ans){ //In this function we are collecting all leaf nodes
    
    if(root == NULL){
    return; //if root is null then return 
    } 
    
    leafNodes(root->left,ans); //moving left side
    leafNodes(root->right,ans); //moving right side
    
    if(root->left == NULL and root->right ==NULL){ //if left is null and also right is null then current element is leaf node
        ans.push_back(root->data); //push data of current leaf node and return.
        return;
    }
}

void rightBoundaryNodes(Node *root, vector<int>& ans){
//similarly like left boundary function, In this right boundaries we will iterate over all right side nodes except right side leaf node
 
    if(root->right == NULL and root->left==NULL){ //condition for leaf node
        return;
    }
    
    
    if(root->right == NULL){ //if right is null then move to left once and again check for right boundaries
        rightBoundaryNodes(root->left,ans);
    }

    else rightBoundaryNodes(root->right,ans); //if right is exist then check normally to right side
    
    ans.push_back(root->data); // as we want answer from deppest right node to top right node so, once we reached to deepest node then push that node data in ans vector, and one by one while returning insert remaining root's data
}


vector <int> boundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data); //pushing root's data as it will be our minimum answer, beacuse minimum length of tree will be 1.
    
    if(root->left == NULL and root->right == NULL) //if size of tree is 1 then simply return answer as we push root in ans vector.
        return ans;
    
    if(root->left != NULL)  //if root's left is not exist then dont go for left boundaries
        leftBoundaryNodes(root->left,ans); //if left exist, then calculate left boundaries from root's left node beacuse root node is already pushed in the ans vector.

    leafNodes(root,ans); //then calculate all leaf nodes and pushed into ans vector.
    
    if(root->right != NULL)  //similarly like left boundaries for right boundaries
        rightBoundaryNodes(root->right,ans);
    
    return ans; //finally return answer.
}