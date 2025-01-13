//Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
//GFG
https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1


//Approach 1: TC-O(N) SC-O(N)
int maxSum = 0;
int maxLength = 0;
void solve(Node *root,int sum,int length){
    if(root == NULL){ //once we reach to leaf node or root's left is null but right is exist.
        if(length > maxLength) { //if current path length is greater than maxLength 
        // then no need to check whether sum is greater or not. because we want sum of maximum length or nodes.
            maxLength = length; //then just update maxlength 
            maxSum = sum; //and max sum as well
        }
        
        else if(length == maxLength) maxSum = max(maxSum,sum); 
        //if both current path length and max length is equal then take max of curent sum or maxSum.
        
        return;
    }
    
    sum += root->data; //adding sum and length at every node
    length += 1;

    solve(root->left,sum,length); 
    solve(root->right,sum,length);
}
    
int sumOfLongRootToLeafPath(Node *root)
{
    solve(root, 0,0);
    return maxSum; //finally return maxSum
}