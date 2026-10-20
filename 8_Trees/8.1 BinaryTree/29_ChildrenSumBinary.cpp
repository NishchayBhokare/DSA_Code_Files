
//Approach 1: Simple and optimised approach. TC-O(N) Sc-O(N)
class Solution {
  public:
    
    bool isSumProperty(Node *root) {
        
        if(!root or !root->left and !root->right)
            return true;
            
        int leftSum=0, rightSum=0;
        
        if(root->left)
            leftSum = root->left->data;
        
        if(root->right)
            rightSum = root->right->data;
            
            
        if(leftSum+rightSum==root->data and isSumProperty(root->left) and 
            isSumProperty(root->right))
            return true;
        
        return false;
    }
};


//Approach 2: My approach. TC-O(N) SC-O(N-If tree has only left child then height will equals to number of nodes)
class Solution {
  public:
    int solve(Node *root){
        
        if(!root) return 0;
        
        if(!root->left and !root->right) return root->data;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == -1 or right == -1)
            return -1;
        
        if(left+right == root->data)
            return root->data;
        
        return -1;
    }
  
    bool isSumProperty(Node *root) {
        // code here
        
        return solve(root) != -1;   
    }
};

//or 
class Solution {
  bool status = true;
  public:
    
    int solve(Node *root){
        
        if(!root)
            return 0;
            
        if(!root->left and !root->right)
            return root->data;
            
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(!status or root->data != (left + right)){
            status = false;
            return -1;
        }

            
        return root->data;
    }
    
    bool isSumProperty(Node *root) {
   
        solve(root);
        return status;
    }
};