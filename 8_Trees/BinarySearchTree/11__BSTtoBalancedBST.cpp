//Normal BST to Balanced BST.
//GFG
#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int data;
};


//Approach: TC-O(N) SC-O(N)
//first store inorder traversal of bst
void traverse(Node *root, vector<int>&vec){
    if(root == NULL) return;
    
    traverse(root->left,vec);
    vec.push_back(root->data);
    traverse(root->right,vec);
}

//throught inorder traversal, construct balanced binary search tree, by calculating middle node or every call.
Node * solve(int start,int end, vector<int> &vec){
    if(start > end) return NULL;
    
    int middle = (start+end)/2;
    Node *curr = new Node(vec[middle]);
    
    curr->left = solve(start,middle-1,vec);
    curr->right = solve(middle+1,end,vec);
    
    return curr;
    
}

Node* buildBalancedTree(Node* root)
{
	vector<int> vec;
	traverse(root,vec);
	
    int start = 0, end = vec.size()-1;
    return solve(start,end,vec);
}