//kth smallest element.
//GFG

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


//Approach 1: Most optimised Approach. Morris traversal TC-O(N) SC-O(1)
//Same as morris traversal just instead
int KthSmallestElement(Node *root, int k) {
    int ans = -1;
    while(root != NULL){
        
        if(root->left == NULL){ 
            k--; 
            if(k == 0) ans = root->data; //similarly here also.
            root = root->right;
        }
        else{
            Node *pred = root->left;
            while(pred->right!=NULL && pred->right != root) pred = pred->right;
            
            if(pred->right == NULL){
                pred->right = root;
                root=root->left;
            }
            else{
                pred->right = NULL;
                k--; //instead printing we're decrementing k and checking whether current element is kth or not.
                if(k == 0) ans = root->data; //if k equals to 0 then store answer in ans.
                root = root-> right;
            }
        }
    }
    return ans;
}

//Approach 2: TC-O(N) SC-O(N)
 int ans=-1; //initially setting ans as -1.
  int i=0; //initially counter is 0.
    // Return the Kth smallest element in the given BST
    void solve(Node *root,int K){ //This is basically inorder. (LNR)
        if(root==NULL) return; //if root null then simply return.
        
        solve(root->left,K); //move to left subtree.
        i++; //increase the counter by one.
        if(i==K){ //if i==k that means we got kth smallest element.
           ans=root->data; //putting data of root in ans.
           return;//and simply return to avoid further recursive calls.
        }
        solve(root->right,K); //move to right subtree.
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        solve(root,K); //calling solve function.
        return ans; //returning our answer
    }



    