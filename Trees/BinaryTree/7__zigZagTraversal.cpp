//ZigZag Tree Traversal

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


//TC - O(N), SC- O(N)
vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans; //final ans vector
    bool leftToRight=true; //initially left to right is true for first node because for first node we move to left to right.
    
    queue<Node *> q;
    q.push(root); //pushing this root node in queue
    
    while(!q.empty()) //looping till q not gets empty
    {
        int size = q.size(); //calculating size of queue, which is nothing but size of current level
        vector<int> temp(size); //creating one temporary vector for storing current level nodes answer.
        
        for(int i=0; i<size; i++){ //looping over size of current level.
            Node *frontNode = q.front(); //taking front node from tree
            q.pop(); //then popping out that node from queue
            
            if(leftToRight){ //if left to right is true then move to left to right
                int index = i; //so index will be i like if i = 2 then index will be 2 that is moving from left to right --->
                temp[index] = frontNode->data; //at temp index pushing current node data
            }
            else{ //if in case lefttoRight is false that means we have to move from right to left <---
                int index = size - i - 1; //In this case index will point from back, that is index will be size - i -1. 
                temp[index] = frontNode->data; //on that index insert front nodes data.
            }
            
            if(frontNode->left) q.push(frontNode->left); //if left node exist then insert in queue
            if(frontNode->right) q.push(frontNode->right); //similarly for right node
        }
        
        leftToRight = !leftToRight; //once we iterate over one level then for next level, reverse the value of leftToRight i.e true to false, and false to true.
        
        for(auto i:temp){ //pushing all the elements of current node in final answer vector, before moving to next level.
            ans.push_back(i);
        }
    }
    
    return ans; 
}