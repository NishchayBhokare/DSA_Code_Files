//kth Ancestor
//GFG
https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

//Approach : TC-O(N) SC-O(1)
//First find given node in binary tree, once we find node then backtrack k times 
// till we not reach condition of k equals to 0, 
// once reached to this condition store current node's data in ans and return from function
void solve(Node *root,int &k, int node, int &ans,int &flag){ //passing k,ans and flag as reference.
    if(flag == 1) return; //at any point flag is 1 then return no need for further checking in left or right.
    if(root == NULL) return;
    
    
    if(root->data == node){ //once we find element make flag 1 and return
        flag = 1;
        return;
    }
    
    solve(root->left,k,node,ans,flag);
    
    solve(root->right,k,node,ans,flag);
    
    if(flag == 1) k--; //if flag is 1 that means current node is one of the ancestor, so decrement k.
    if(k == 0) ans = root->data;   //once we reach to kth node that means k become 0, so update ans to root's data and return.  
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1; //initially ans will be -1.
    int flag = 0; //flag will be 0.
    solve(root,k,node,ans,flag);
    return ans;
}