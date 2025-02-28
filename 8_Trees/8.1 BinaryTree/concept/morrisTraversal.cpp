
#include <bits/stdc++.h>
using namespace std;

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
    int data;
};

//1. Morris In order Traversal. GFG SOLUTION.
void MorrisTraversal(struct tNode* root)
{
    struct tNode *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 

            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left; //and move current to left.
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL; 
                cout << current->data << " ";
                current = current->right;
            } 
        } 
    } 
}


//2. Morris Pre order Traversal. GFG SOLUTION.
void MorrisTraversal(struct tNode* root)
{
    struct tNode *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 

            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                cout << current->data << " "; //This is one change in print statement i.e before moving to left first print current node data.
                pre->right = current;
                current = current->left; //and move current to left.
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL; 
                current = current->right;
            } 
        } 
    } 
}


//3. Morris post order traversal
//Same as preorder just initially we are moving to right first
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    TreeNode* current = root;
 
    while (current != NULL) {
        // If right child is null,
        // put the current node data
        // in res. Move to left child.
        if (current->right == NULL) {
            res.push_back(current->key);
            current = current->left;
        }
        else {
            TreeNode* predecessor = current->right;
            while (predecessor->left != NULL
                   && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            // If left child doesn't point
            // to this node, then put in res
            // this node and make left
            // child point to this node
            if (predecessor->left == NULL) {
                res.push_back(current->key);
                predecessor->left = current;
                current = current->right;
            }
            // If the left child of inorder predecessor
            // already points to this node
            else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    // reverse the res
    reverse(res.begin(), res.end());
    return res;
}