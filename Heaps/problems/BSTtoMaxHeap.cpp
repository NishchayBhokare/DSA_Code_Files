// Example- convert binary search tree in max heap.
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

/*some special cases and observation from exmaple.
  -default condition for max heap is parent elements should greater than its child elements.
  -tree should be complete binary tree.
  and in this example they provide one more condition is-
     -All the values in the left subtree of a node should be less than all the values in the right subtree of the node for every node. so we can say that 'R' > 'L' and we have default condition is 'N' > 'R' and 'N' > 'L'.
     So, by combining above three conditions we got ['N' > 'R' > 'L'].
     -so in code we will first look for descending order array and then with "NRL" condition we will create tree and that tree will be our maxHeap.
*/
vector<int> v;
int i = 0;
void convertToMaxHeapUtil(Node *root)
{
    reverseInorder(root); // we want array in descending order so we execute reverse inorder on binary tree.
    NRL(root);            // after getting reverse inorder we will call NRL so that so that we can modify in existing binary tree to achieve max heap with given condition.
}
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