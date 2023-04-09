//Top view of binary tree.

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
vector<int> topView(Node *root)
{
    vector<int> ans;
    map<int,int> mp; //creating map of distance and node data.
    // map<int, bool> visited; //distance and whether this distance is visited or not
    
    queue<pair<Node *, int> > q;
    q.push(make_pair(root,0));
    
    while(!q.empty()){ //doing level order traversal
        pair<Node*,int> pr = q.front();
        
        Node *temp = pr.first;
        int distance = pr.second;
        q.pop();
        
        // if(visited[distance] != true){ //if current distance not visited previously then only push this curetn data in map for current distance
        //     mp[distance]=temp->data;
        //     visited[distance] = true;
        // }

        if(mp.find(distance) == mp.end()){ //or instead using visited map, we can do this as well to check whether we alredy visited this distance or not.
            mp[distance] = temp->data; //if visited first time, then at current distance mapped current node's data.
        }
        
        if(temp->left) q.push(make_pair(temp->left, distance-1)); //moving left
        if(temp->right) q.push(make_pair(temp->right,distance+1)); //right
    }
    
    for(auto i: mp){ 
        ans.push_back(i.second); //pushing node data of every distance from map. and it will be in sorted order.
    }
    
    return ans;
}