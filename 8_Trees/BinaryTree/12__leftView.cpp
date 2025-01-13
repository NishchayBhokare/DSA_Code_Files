//Left view of binary tree.

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
    
    solve(root->left,level+1,ans); //moving to left 
    solve(root->right,level+1,ans); //moving to right
}

    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       int level=0; //current level is 0
       solve(root,level,ans);
       return ans; //finally returning ans
    }

//Approach 2: TC-O(N) SC-O(N)
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root == NULL) return ans;
   
   queue<Node *>q;
   q.push(root); //push root node in queue
   q.push(NULL); //then push null which shows current level is end
   ans.push_back(root->data); //pushing current root node's data in answer vector.
   
   while(q.size()>1){ //looping till size of queue greater than 1 because at last 1 element will be null which shows last level end
     
       Node *temp = q.front(); //taking front node
       q.pop(); //popping that node
       
       if(temp == NULL){ //current node is null that means current level is finished
           q.push(NULL); //so we inserted all nodes of next level as well so push null which represent end of next level
           temp = q.front(); //getting new node, as we pop so new node will recieve by temp
           q.pop(); //popping out this node from queue

           ans.push_back(temp->data); 
           //and this new node will be the first left most node of new level so , pushing first lefmost element in answer vector.
       }
   
       if(temp->left) q.push(temp->left); //move to left
       if(temp->right) q.push(temp->right); //move to right
       
   } 
   return ans;
}

//Approach 2: using level order traversal..and storing level for every node.
vector<int> leftView(Node *root) {
    // code here
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*, int> pr = q.front();
        Node *temp = pr.first;
        int level = pr.second;
        
        q.pop();
        
        if(mp.find(level) == mp.end()) //if first node of new level then add this node.
            mp[level] = temp->data;
        
        if(temp->left)
            q.push({temp->left, level+1});
            
        if(temp->right)
            q.push({temp->right, level+1});
    }
    
    for(auto i:mp){
        ans.push_back(i.second);
    }
    
    return ans;
}