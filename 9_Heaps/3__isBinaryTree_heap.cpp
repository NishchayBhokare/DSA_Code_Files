//Example for checking whether given binary tree is heap or not.
//GFG
// link- 
    // https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
 
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *left; Node *right ; int data;
};

//TC-O(N) SC-O(N)
//we have to check 2 conditions for whether given tree is heap or not.
//  1. given tree should be complete binary tree. i.e it should be start from left.
//  2. root element is greater than all its child elements.
  int size(Node *tree){
      if(tree==NULL) return 0;
      
      int left=size(tree->left);
      int right=size(tree->right);
      return left+right+1; //Traversing over the all the node and by adding 1 to it we will return.
  }
  
  bool solve(Node *tree, int nodeCount,int index,int maxi){
      if(tree==NULL) return true; //if tree is NULL then we will return true.
      
      if(index >= nodeCount) return false;// if index >= size of array that means somewhere it has right node but don't have left node. cause index becomes equal to or greater than size. //if tree is complete binary tree when current node index is less than number of nodes. 
      
        int data = tree->data;
        if( data > maxi ){ //also checking current node's data less than parent node or not.
            return false; //if not then return false;
        } 
      
      bool left = solve(tree->left,nodeCount,2*index+1, data);
      bool right = solve(tree->right,nodeCount, 2*index+2,data);

      return (left and right);
      //moving to left side of tree and right side of tree along with index.
      //if both give true && true then it will return true;
      //if true && false then it will return false.
      //in zero base indexing left child is- 2*index+1 and right child is- 2*index+2.
  }
  
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int nodeCount=size(tree);  //calling size function.
        bool val=solve(tree,nodeCount, index, INT_MAX); //storing return value in val.
        return val; //and finally returning our answer.
    }
