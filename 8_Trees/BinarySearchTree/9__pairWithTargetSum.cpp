// Find a pair with given target in BST
//GFG
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

//Approach 1: Most optimised approach TC-O(N) SC-O(H)
int nextElements(stack<Node*>&st1){
    Node *temp = st1.top(); //storing top element in x
    st1.pop(); //popping that elements
    int x = temp->data; 
    temp = temp->right; //move one step to right.
    while(temp != NULL){ //and loop towards left till temp not gets null this is because to maintain flow of normal inorder traversal.
        st1.push(temp);
        temp = temp->left;
    }
    return x; //at the end return x 
}

int previousElements(stack<Node*>&st2){ //exactly opposte or normal inorder 
    Node *temp = st2.top();
    st2.pop();
    int x = temp->data;
    temp = temp->left;
    while(temp != NULL){
        st2.push(temp);
        temp = temp->right;
    }
    return x;
}

int isPairPresent(struct Node *root, int target)
{
    stack<Node *> st1,st2; //create two stack
    
    Node *temp = root;
    while(temp != NULL){ //first traversing root to left most node and store this node in stack
        st1.push(temp);
        temp=temp->left;
    }
    
    temp=root;
    while(temp != NULL){ //similarly for right side and store in second stack
        st2.push(temp);
        temp=temp->right;
    }
    
    int i = nextElements(st1); //getting one by one elements in normal inorder way
    int j = previousElements(st2); //getting one by one elements in reverse inorder way
    
    while(i < j){ //loop till i less than j.
        
        if(i+j == target) return true; //if sum equals to target then return true
        
        if(i+j < target){ //if sum less than target then we need greater value from i, so call next inorder element function
            i = nextElements(st1);
        }
        else j = previousElements(st2);  //if sum greter than target then we need lesser value from j so call previouse inorder element function.
    }
    
    return false; //else return false;
}


//Approach 2: Using temporary vector for inorder TC-O(N) SC-O(N)
void solve(Node *root, vector<int>&ans){
        if(root == NULL) return;
        
        solve(root->left,ans);
        ans.push_back(root->data); //store inorder in vector.
        solve(root->right,ans);
    }
    int isPairPresent(struct Node *root, int target)
    {
        vector<int> ans;
        solve(root,ans);
        int i=0,j=ans.size()-1;
        while(i < j){ //using two pointer approach calculate sum and answer.
            if(ans[i] + ans[j] == target) return 1;
            
            if(ans[i] + ans[j] > target) j--;
            else i++;
        }
        return 0;
    }


//Approach 3: using hashmap. Tc-O(N) SC-O(N)
bool solve(BinaryTreeNode<int>* root, int target, unordered_map<int,bool> &ump){
    if(root == NULL) return false;

    if(ump[target - root->data]) //checking for current node.. if it get minus by target..then required value is presnet in 
    //map or not..if present ...then pair can be possible else not.
        return true;
    else    
        ump[root->data] = true; //if not..then push current node data to map and marked as true.
    
    bool leftAns = solve(root->left,target,ump);
    bool rightAns = solve(root->right,target,ump);

    if(leftAns || rightAns)  //if anyof the answer is true ..return true.
        return true;
    
    return false;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	unordered_map<int,bool> ump;
    return solve(root,target,ump);
}