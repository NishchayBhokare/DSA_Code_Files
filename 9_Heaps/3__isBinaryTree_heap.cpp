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

//Approach 1: optimised approach by me.
//similar like approach 2..but the thing is..instead comparising with left and right child.
//i am passing parent data for current node..so now we just need to check..
//if current node less than parent or not..for max heap property..
//rest everything is same like approach 2.
pair<bool,int> solve(struct Node *tree, int maxi){
    if(tree == NULL)
        return {true,0};
    
    pair<bool,int> curr = {false, -1}; 
    
    int data = tree->data;
    if(data > maxi) return curr; //checking current node..is less than or not..if not return false pair.
    
    pair<bool,int> leftAns = solve(tree->left, data);
    pair<bool,int> rightAns = solve(tree->right, data);
    
    //updating values for current node.
    int height = max(leftAns.second, rightAns.second) + 1;
    curr.second = height; //updating height. 
    
    
    //checking cbt completeness.
    int heightDiff = leftAns.second - rightAns.second;
    //not complete binary tree.
    if(heightDiff < 0 || heightDiff > 1) return curr; //i have explained for this below.
    
    
    if(leftAns.first && rightAns.first){
            curr.first = true;
            return curr; //apart from this condition and null condition..everything is false for returning.
    }
    
    return curr;
}


bool isHeap(struct Node* tree) {
    
    pair<bool,int> pr = solve(tree, INT_MAX);
    
    return pr.first;
}

//Approach 2: solving within one function only.
//on every node..we are passing pair..in which first field represent...heap till that node 
//is max heap or not and second field represent height..so that we can use it to check cbt or not.
 pair<bool,int> solve(struct Node *tree){
    if(tree == NULL)
    return {true,0};
    
    pair<bool,int> leftAns = solve(tree->left);
    pair<bool,int> rightAns = solve(tree->right);
    
    //updating values for current node.
    int height = max(leftAns.second, rightAns.second) + 1; //storing maximum height from left or right.
    int data = tree->data;
    pair<bool,int> curr = {false, height}; //creating pair to return for current node.
    
    
    //checking completeness.
    int heightDiff = leftAns.second - rightAns.second;
    if(heightDiff < 0 || heightDiff > 1) return curr; //not complete binary tree.
    //above two statement checking..whether it is cbt or not..
    //see, for CBT (expalining 2nd if cond.) leftHeight - rightHeight should not be greater than 1 because..we can allow
    //only last level to be not filled..other than this level every level should fill okay.
    
    //and first if condition is, when right part is exist but left part is not..
    //so in this case..right part height will be greater than left part..so different will be negative.
    //so this is also not cbt..so return false; 

    
    if(leftAns.first && rightAns.first){ //now..if left and right part is true.
        
        if((tree->left && data < tree->left->data) || //then check..current node is max heap or not..by comaparing with child nodes.
            (tree->right && data < tree->right->data))
                return curr; //if not..then return curr..which is false.
                
        else {
            curr.first = true; //if it's max heap..then return true by updating first field.
            return curr; //apart from this condition and null condition..everything is false for returning.
        }
    }
    
    return curr; //this is also false condition..it get's called when any of the left or right part is false.
}


//Approach 3: using counting nodes for cbt. TC-O(N) SC-O(N)
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
