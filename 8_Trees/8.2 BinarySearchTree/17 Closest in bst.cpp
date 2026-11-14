
//Approach 1: Optimised Approach. TC-O(H) SC-O(H)
//Idea is to use binary search, where if current node is greater than k then move to left part else right part.
//because it's BST.
class Solution {
  public:
    void solve(Node *root, int k, int &diff){
        
        if(!root) return;
        
        diff = min(diff, abs(root->data - k));
        
        if(k <= root->data){
            solve(root->left, k, diff);
        }
        
        else solve(root->right, k, diff);
    }
  
    int minDiff(Node *root, int k) {
        // code here

        int diff = INT_MAX;
        
        solve(root,k,diff);
        
        return diff;
    }
};




//Approach 2: Naive approach. TC-O(N) SC-O(H)
//Visit every node and then calculate minimum abs diff. 
class Solution {
  public:
    void solve(Node *root, int k, int &diff){
        
        if(!root) return;
        
        
        diff = min(diff, abs(root->data - k));
        
        solve(root->left, k, diff);
        solve(root->right, k, diff);
    }
  
    int minDiff(Node *root, int k) {
        // code here

        int diff = INT_MAX;
        
        solve(root,k,diff);
        
        return diff;
    }
};
