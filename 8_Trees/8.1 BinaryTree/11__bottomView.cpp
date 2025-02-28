//Bottom view of binary tree.

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

//TC-O(Nlogn) SC-O(N)
//Almost same as top view just one change that is dont check whether node is present for current distance, 
//just push new node for that distance and at last only bottom node will points to those distance.
vector <int> bottomView(Node *root) {
    vector<int> ans;
    queue<pair<Node *,int> > q;
    map<int,int> mp;
    
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node *,int> pr = q.front();
        Node *temp = pr.first;
        int distance = pr.second;
        q.pop();
        
        mp[distance] = temp->data;  //dont check previously visited or not, just push current data into the map.
        
        if(temp->left) q.push(make_pair(temp->left,distance-1));
        
        if(temp->right) q.push(make_pair(temp->right,distance+1));
        
    }

    for(auto i : mp){
        ans.push_back(i.second);
    }
    
    return ans;
}