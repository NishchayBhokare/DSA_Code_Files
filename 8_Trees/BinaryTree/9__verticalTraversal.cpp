//Boundary Traversal of binary tree
https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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

//Approach 1: Most optimised approach.
//Time Complexity : O(N), N is number of nodes in tree.
//Space Complexity : O(N), hashmap is used for each node.

vector<int> verticalOrder(Node *root)
{
    vector<int> ans; //creating ans vector.

    map<int, vector<int> > mp; //craeting map for storing nodes data at particular horizontal distance.
    //int represent horizontal distance and vector represent nodes data of that horizontal distance
    
    queue<pair<Node *, int> > q; //creating queue of pair. because we are counting and storing horizontal distance of particular node, so Node* represent node and int represent horizontal distance.
    q.push(make_pair(root,0)); //initially pushing root node with distance 0 in queue.
    
    while(!q.empty()){ //doing level order traversal
        pair<Node *,int> pr = q.front(); //getting front element of queue which is nothing but pair because we created queue of pair.
        Node *temp = pr.first; //pr.first represent node
        int distance = pr.second; //pr.second represent horizontal distance of that node.
        
        q.pop(); //popping out that first element i.e pair
        
        mp[distance].push_back(temp->data); //at this distance pushing temp's data in mp vector.
        
        if(temp->left) q.push(make_pair(temp->left, distance-1)); //checking if left is exist then push that left node with decrementing distance
        
        if(temp->right) q.push(make_pair(temp->right,distance+1)); //similarly for right, just increment distance
    }
    
    for(auto i : mp){  //iterating over map, i represent current row of map.
        for(auto j: i.second){ //i.second represent that vector.
            ans.push_back(j); //j represent elements of that vector, so pushing all the node data of current distance in ans vector.
            //as map gives elements in sorted order,i.e we will get i.first (distance) in sorted order
        }
    }
    
    // We can iterate like this also over map.
    
    //  for(auto it=mp.begin();it!=mp.end();it++)
    // {
    //     vector<int> temp=it->second; //it.second represent vector so assign this vector to temp
        
    //     for(auto x:temp) //iterate over temp.
    //         ans.push_back (x);
    // }
    return ans;
}


//similar like above using unordered_map
 vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        int minIndex = 0, maxIndex = 0;
        unordered_map<int,vector<int> > ump;

        queue<pair<Node*,int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*,int> pr = q.front();
            
            Node *temp = pr.first;
            int index = pr.second;
            q.pop();
            
            ump[index].push_back(temp->data);
            
            minIndex = min(index, minIndex);
            maxIndex = max(index, maxIndex);
            
            
            if(temp->left){
                q.push({temp->left, index-1});
            }
            if(temp->right){
                q.push({temp->right, index+1});
            }
            
        }
        
        for(int i = minIndex; i<=maxIndex; i++){
            for(auto j:ump[i]){
                ans.push_back(j);
            }
        }
        return ans;
    }


//very brute force. dont' see.
//Approach 2: TC-O(N) SC-O(N)
//first iterate over tree and store horizontal distance of every node.

map<int,vector<int> > mp; //creating map of int->distance and vector->nodes data of that particular distance
    
map<Node *,int> mpDistance; //creating another map for storing current nodes distance

void solve1(Node *root,int distance){ //traversing over tree
    if(root == NULL) return;
    
    mpDistance[root] = distance; //storing current node's distance
    
    solve1(root->left,distance-1); //while going left decrement distance
    solve1(root->right,distance+1); //for right increment distance
}

void solve2(Node *root){ //doing level order traversal
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        
        int distance = mpDistance[temp]; //getting distance of current node from mpDistance map as we stored distance of every node
        
        mp[distance].push_back(temp->data); //and at this distance pushing curent node's data in vector of mp.
        
        if(temp->left) q.push(temp->left); //going to left
        if(temp->right) q.push(temp->right); //right
    }
}

vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    
    int distance = 0;
    solve1(root,distance);
    solve2(root);
    
    for(auto i:mp){ //here i representing whole mp row i.e map<int,vector<int>> mp
        for(auto j:i.second){ //i.second representating vector so we are iterating over vector i.e j representating elements of those vector.
            ans.push_back(j);
        }
    }
    
    return ans;
}