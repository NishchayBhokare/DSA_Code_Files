//Top view of binary tree.
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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

//using unordered map. TC-O(N) SC-O(1).
 vector<int> topView(Node *root)
{
    vector<int> ans;
    queue< pair<Node*, int>>q;
    unordered_map<int,int> ump; //using unordered map and min, max index..we can solve this question in big oh of N. Tc
    int minIndex = 0, maxIndex = 0;
    
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*,int>pr = q.front();
        
        Node *temp = pr.first;
        int index = pr.second;
        q.pop();
        
        minIndex = min(minIndex, index); //storing min distance..i.e index.
        maxIndex = max(maxIndex, index); //similarly for maxdistance.
        
        // if(!ump[index]) ump[index] = temp->data;
        if(ump.find(index) == ump.end()) ump[index] = temp->data; //as we are dealing with only first element of every distance...
        // so checking..if for that distance...element is already added or not..if not..then add current element.
        
        if(temp->left){
            q.push({temp->left, index-1}); //move to left part.
        }
        
        if(temp->right){
            q.push({temp->right, index+1}); //right
        }
    }
    
    for(int i = minIndex; i<=maxIndex; i=i+1){ //now..we will start from minIndex to max index..these are the range of distance for every node.
        ans.push_back(ump[i]); //pushing element..standing on ith distance.
    }
    
    return ans;
}

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