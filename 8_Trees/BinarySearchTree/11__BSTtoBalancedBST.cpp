//Normal BST to Balanced BST.
//GFG
https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1


//Approach: TC-O(N) SC-O(N)
//first store inorder traversal of bst
void traverse(Node *root, vector<int>&vec){
    if(root == NULL) return;
    
    traverse(root->left,vec);
    vec.push_back(root->data);
    traverse(root->right,vec);
}

//through out inorder traversal, construct balanced binary search tree, 
// by calculating middle node or every call.
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