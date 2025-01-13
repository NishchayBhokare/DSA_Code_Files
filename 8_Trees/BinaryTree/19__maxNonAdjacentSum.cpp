//Maximum sum of Non-adjacent nodes
//GFG
// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

//Approach : TC-O(N) SC-O(1)
//On every node we are making pair of two values, in which at first value we are including current node plus their non adjacent nodes from left and right side. and in second value we're excluding current node, so in this just take max from left values plus max from right values. As we excluding current node so no matter that max from left or right nodes starts from adjacent of current because we excluded current. 
pair<int,int> solve(Node *root){
       if(root == NULL){
           pair<int,int> pr = make_pair(0,0); //once reaches to null then create pair of 0,0.
           return pr; //return that pair
       } 
       
       pair<int,int> left = solve(root->left); //get answer from left
       pair<int,int> right = solve(root->right); //and right
        
       pair<int,int> curr;//create pair for current node

       //Including cuurent node
       curr.first = root->data + left.second + right.second; //while including current node. take addition of left side excluded value and right side excluded value i.e second valude
       
       //Excluding current node 
       curr.second = max(left.first , left.second) + max(right.first,right.second); 
       //while excluding current node, take plus of max from left and max from right.
       return curr; //return current pair.
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second); //finally return max of first or second.
    }