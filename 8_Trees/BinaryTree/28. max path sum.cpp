//GFG. Maximum path sum from any node to any node.

//Approach 1: It is more similar like finding diameter.
int maxi=INT_MIN; //create max varaible.
int solve(Node *root){
    if(root==NULL) return 0;
    
    int left = max(0,solve(root->left)); //to neglect -ve sum from left part. we're taking max of leftsum and 0.
    
    int right = max(0,solve(root->right)); //same for right.
    
    maxi = max(maxi, root->data+left+right); //now on every node..store maximum sum. this max sum will be node's data+left's sum and right sum.
    
    return (root->data + max(left,right)); //return max sum from left part or right part.
    //returning this to caller function becaseu..we should know...from where to where path goes from root node.
}

int findMaxSum(Node* root)
{
    solve(root);
    return maxi;

}