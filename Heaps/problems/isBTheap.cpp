//Example for checking whether given binary tree is heap or not.
// link- 
    // https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
 
#include <iostream>
#include<vector>
using namespace std;
class Node{
    public:
    Node *left; Node *right ; int data;
};


//we have to check 2 conditions for whether given tree is heap or not.
//  1. given tree should be complete binary tree. i.e it should be start from left.
//  2. root element is greater than all its child elements.
  int size(Node *tree){
      if(tree==NULL) return 0;
      
      int left=size(tree->left);
      int right=size(tree->right);
      return left+right+1; //Traversing over the all the node and by adding 1 to it we will return.
  }
  
  bool solve(Node *tree, int n,int index){
      if(tree==NULL) return true; //if tree is NULL then we will return true.
      
      if(index >= n) return false;// if index >= size of array that means somewhere it has right node but don't have left node. cause index becomes equal to or greater than size. 
      
      if( (tree->left && tree->data <= tree->left->data) || (tree->right && tree->data <= tree->right->data) )
      return false; //if left or right tree exist but if root less > than left and right child then we will return false
      
      return solve(tree->left,n,2*index+1) && solve(tree->right,n, 2*index+2);
      //moving to left side of tree and right side of tree along with index.
      //if both give true && true then it will return true;
      //if true && false then it will return false.
      //in zero base indexing left child is- 2*index+1 and right child is- 2*index+2.
  }
  
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;int n;
        n=size(tree);  //calling size function.
        bool val=solve(tree,n,index); //storing return value in val.
        return val; //and finally returning our answer.
    }