//k Sum paths problem GFG.
//GFG

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

//Approach 1: Iterative approach, Optimised one. TC - O(N2) SC-O(N)
int count = 0;
void solve(Node *root,int k,vector<int> path){
    if(root == NULL) return;
    
    path.push_back(root->data);
    
    solve(root->left,k,path);
    solve(root->right,k,path);
    
    int sum = 0;
    
    for(int i=path.size()-1; i>=0; i--){ //calculating all path, once reached to root is null 
        sum += path[i]; //then iterate over current path from back side. cause sum path can be formed anywhere between path.
        if(sum == k) count++; //if sum equals to k then increment count
    }
}
    

int sumK(Node *root,int k)
{ 
    vector<int> path;
    solve(root,k,path);
    return count;
}



//Approach 2: Recursive approach TC-O(N2) SC-O(N) 
//In this approach for every node check sum path
int count = 0;
void solve2(Node *root,int k,int sum){
    if(root == NULL) return;
    
    sum += root->data;
    if(sum == k) count++; //if current path is equals to k so increment count.
    
    solve2(root->left,k,sum);
    solve2(root->right,k,sum); 
}
    
void solve1(Node *root,int k){
    if(root == NULL) return;
    
    solve2(root,k,0); //checking for every node path sum, i.e from current node path is exist or not
    
    solve1(root->left,k);
    solve1(root->right,k);
}


int sumK(Node *root,int k)
{ 
    solve1(root,k);
    return count;
}
