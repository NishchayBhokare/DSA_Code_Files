// Example- convert binary search tree in max heap.
//GFG
//  link-
//  https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

// TC-O(N) SC-O(N)
/*some special cases and observation from exmaple.
  -default condition for max heap is parent elements should greater than its child elements.
  -tree should be complete binary tree.
  and in this example they provide one more condition is-
     -All the values in the left subtree of a node should be less than all the values in the right subtree of the node for every node. so we can say that 'R' > 'L' and we have default condition is 'N' > 'R' and 'N' > 'L'.
     So, by combining above three conditions we got ['N' > 'R' > 'L'].
     -so in code we will first look for descending order array and then with "NRL" condition we will create tree and that tree will be our maxHeap.
     -and as given tree is complete binary tree so structure of our final tree will be same as current tree, so we will update only values of default tree.
*/
vector<int> v;
int i = 0;
void reverseInorder(Node *root)
{ // through this function we will get descending order array.
    if (root != NULL)
    {
        reverseInorder(root->right); // reverse inorder is - "RNL"
        v.push_back(root->data);     // pushing element in vector v.
        reverseInorder(root->left);
    }
}

void NRL(Node *root)
{
    if (root != NULL)
    {
        root->data = v[i++]; // N - we are pushing data from vector to current root.
        NRL(root->right);    // R - Now, we will move to right of binary tree.
        NRL(root->left);     // L - finally, we will move to left of binary tree.
    }
}

void convertToMaxHeapUtil(Node *root)
{
    reverseInorder(root); // we want array in descending order so we execute reverse inorder on binary tree.
    NRL(root);            // after getting reverse inorder we will call NRL so that so that we can modify in existing binary tree to achieve max heap with given condition.
}


//if we don't want to reverse the inorder..we can obsrever this condition as L<R<N
//so for this..we need regular inorder.
//Approach 2:
 void getInOrder(Node *root, vector<int>&in){
        if(root == NULL) 
            return;
            
        getInOrder(root->left,in);
        in.push_back(root->data);
        getInOrder(root->right,in);
    }
    
    void populateData(Node *root, vector<int>&in, int &index){
        if(root == NULL) 
            return;
            
        populateData(root->left,in,index);
        populateData(root->right,in,index);
        
        root->data = in[index++];
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> in;
        getInOrder(root,in);
        
        int index = 0;
        populateData(root,in,index);
    }