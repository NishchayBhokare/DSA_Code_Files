//Diagonal Traversal in binary tree.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Approach 1: Recursive approach TC-O(Nlogn) SC-O(N)
void solve(Node *root,int distance,map<int, vector<int> > &mp){
    if(root == NULL) return;
    
    mp[distance].push_back(root->data); //at current distance pushing root's data in vector at map
    
    solve(root->left,distance+1,mp); //move to left, and while moving to left increment distance
    solve(root->right,distance,mp); //but while moving to right no need to increment distance
}

vector<int> diagonal(Node *root)
{
   map<int, vector<int> > mp; //creating map of horizontal distance and nodes of that distance
   vector<int> ans; //creating ans vector for storing answer
   solve(root,0,mp); //calling function and passing root's distance as 0 
   
   for(auto i : mp){ //iterating over map and pushing all the answer in ans vector
       for(auto j:i.second){
           ans.push_back(j);
       }
   }
   
   return ans;
}


//Approach 2: Iterative approach TC-O(Nlogn) SC-O(N).
vector<int> diagonal(Node *root)
{
  vector<int> ans;
  queue<Node *>q;
  q.push(root); //in queue pushing all left nodes.

  while(!q.empty()){
      Node *temp = q.front(); //getting front node
      q.pop(); //popping out that node
      
      while(temp){ //while temp not get null just iterate over tree
          if(temp->left) q.push(temp->left); //if temp's left exist then push temp's left in queue
          
           //then insert temp's data in answer vector
          ans.push_back(temp->data); //not sure about this

          temp=temp->right; //and move to right.
      } 
  }
  return ans;
}

