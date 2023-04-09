
// Example for Determine if two trees are identical
//GFG
// link-
// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


//Approach 1: TC-O(N) SC-O(Height).
bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
    if (r1 == NULL && r2 == NULL)
    { // checking initially NULL or not. and also after moving to end checking both ends to null or not.
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    { // if r1 is null after r2 is not then that time both are not identical
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    { // if r1 is not null after r2 is null then that time both are not identical
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);    // moving to the left side of subtree in both r1 & r2.
    bool right = isIdentical(r1->right, r2->right); // moving to the right side of subtree in both r1 & r2.

    bool value = r1->data == r2->data; // now checking current node data are same or not. if same then value = 1 & if not same then value = 0.

    if (left && right && value)
        return true; // if all three are true i.e left subtree, right subtree and current node. then we will return true.
    return false;    // otherwise false.
}


//Approach 2: using flag variable. TC-O(N) SC-O(Height).
 bool flag=true;
    void solve(Node *r1, Node *r2){
        if((r1 == NULL and r2 != NULL) or (r1 != NULL and r2 == NULL)) flag=false; //if one is null and another is false then maked flag as false
        if(r1 == NULL) return;
        if(r2 == NULL) return; //return null.
        
        if(r1->data != r2->data) flag=false; //if data is not same then mark flag as false
        
        solve(r1->left,r2->left); //move towards left in both trees at same time
        solve(r1->right,r2->right); //similarly move to right in both trees.
    }
    
    bool isIdentical(Node *r1, Node *r2)
    {
        solve(r1,r2);
        return flag;
    }