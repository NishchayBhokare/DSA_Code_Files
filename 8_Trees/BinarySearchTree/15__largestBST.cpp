//Largest BST. 
//check code studio qustion don't see gfg question..u will get confused.

//Approach 1: TC-O(N) SC-O(h)
class info{ //creating one data structure
    public:
        int mini;
        int maxi;
        int size;
        int isBst;
};
    
info solve(TreeNode * root, int &ans){
    if(root == NULL){
        return {INT_MAX,INT_MIN,0,true}; //return data structure which has min as intMax and max as Int_min , size as 0 and isbst as true.
    }
    
    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize); //moving left and right.
    
    //creating object for current node
    info curr;
    int data = root->data; //storing current node data
    curr.mini = min(data, left.mini); //calculating min for current node by comparing with left minimum.
    curr.maxi = max(data, right.maxi); //calculating max for current node by comparing with right maximum.
    curr.size = left.size + 1 + right.size; //updating size by adding left and right plus current node.
    
    if(left.isBst and right.isBst and (data > left.maxi and data < right.mini)){
        curr.isBst = true; //if left and right sub tree is bst and also if current node's data greater than left maximum  and current node's data lesser than right minimum. then current node is bst.
    }
    else curr.isBst = false; //else current node is not bst
    
    
    //if current node is bst then update answer.
    if(curr.isBst){
        maxSize = max(curr.size, maxSize); //updating maxsize.
    }
    
    return curr; //returning current object.
}

int largestBST(TreeNode * root){
{
    int maxSize = 0;
    info head = solve(root,maxSize); 
    return maxSize; //returning max size of nodes.
}



//Approach 2: TC-O(N2) SC-O(h).
int validSubTree(Node *root, int mini, int maxi,int &flag){
        if(root == NULL) return 0;
        
        int data = root->data;
        
        if(data <= mini or data >= maxi) {
            flag=1;
            return 0;
        }
        
        int leftNodes =  validSubTree(root->left, mini, data,flag);
        int rightNodes = validSubTree(root->right,data,maxi,flag);
        
        if(flag == 1) return 0;
        return (leftNodes + rightNodes + 1);
    }
    
    void solve(Node *root,int &maxNodes){
        if(root == NULL) return;
        
        int flag = 0;
        int nodes = validSubTree(root,INT_MIN,INT_MAX, flag);
        
        maxNodes = max(nodes, maxNodes);
        
        solve(root->left,maxNodes);
        solve(root->right,maxNodes);
    }
    
    int largestBst(Node *root)
    {
        int maxNodes = 0;
    	solve(root,maxNodes);
    	return maxNodes;
    }