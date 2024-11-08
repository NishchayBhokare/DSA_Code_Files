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
                //we are using size-i-1 becuase...for this case..parent i is incremeting and index is decreemnting..
                //so to find position to add element in temp vector..we are doing like this.
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


//Approach 2: using two stack. Tc-O(N) SC-O(N)
//Approach is..for left to right...insert data for first stack..and 
// for right to left...insert data for second stack. while popping element from stack..that elements will be need to insret in ans.
vector <int> zigZagTraversal(Node* root)
{
    // Code here
    stack<Node*> first;
    stack<Node*> second;
    vector<int> ans;
    
    first.push(root); //insert root in first stack.
    
    while(!first.empty() || !second.empty()){ //loop till first or second both stack is not empty
        
        while(!first.empty()){ //if first stack is not empty..then it's time to move right to left.
        //so push element in second stack.
            Node *temp = first.top(); //take top elment of stack
            first.pop(); //pop from it.
            ans.push_back(temp->data); //push that element in stack.
            
            if(temp->left) second.push(temp->left); //now...add left element in second stack then right..becuse of
            //stack's nature...right eleemnt will be on top.
            if(temp->right) second.push(temp->right);
        }
        
        while(!second.empty()){ //similarly, for second stack. if second stack empty..insert element in first stack.
            Node *temp = second.top();
            second.pop();
            ans.push_back(temp->data);
            
            if(temp->right) first.push(temp->right); //insert first right then left.
            if(temp->left) first.push(temp->left);
        }
    }
    
    return ans; //return ans
}