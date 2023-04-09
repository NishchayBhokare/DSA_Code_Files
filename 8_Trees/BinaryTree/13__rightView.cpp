//Right view of binary tree.

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


//Approach 1: optimised approach TC-O(N) SC-O(n)
 void solve(Node *root, int level,vector<int> & ans){
    if(root == NULL) return;
    
    if(level == ans.size()){ //once we moved to next level check this is first node of new level, if yes then level will equals to size of ans becuase we're inserting one element at a time so size of vector will increase 1 on every level
        ans.push_back(root->data); //so push current node's data in answer vector.
    }
    
    solve(root->right,level+1,ans); //just one change first move to right
    solve(root->left,level+1,ans);
}

    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       int level=0; //current level is 0
       solve(root,level,ans);
       return ans; //finally returning ans
    }