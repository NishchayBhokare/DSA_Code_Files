// Lowest Common Ancestor in a Binary Tree
// GFG

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

//TC - O(N) SC-O(height)
 Node* lca(Node* root ,int n1 ,int n2 )
    { 
       if(root==NULL) return NULL;//when n1 or n2 not found;
       if(root->data==n1 or root->data==n2) return root; //we got node either n1 or n2 then we will return it to parent node.
    
       Node *ln=lca(root->left,n1,n2);//traversing to left subtree.
       Node *rn=lca(root->right,n1,n2); //treaversing to right subtree.
       
       if(ln and rn) return root; // case when we got ancestor. i.e if node coming from left and right are non NULL then we will return current node as their ancestor.
       
       if(ln) return ln; //if left node is non null but right node is NULL then simpley return non NULL node. cause current node can't be ancestor of n1 & n2.
       else return rn; //else right node is non null but left node is NULL then simpley return non NULL node. cause current node can't be ancestor of n1 & n2.   
}

//using iteration. Tc-O(N) SC-O(N)
 bool flag = false;
void findAncestor(Node *root, int val, vector<Node*>&path){
    if(root == NULL) return;
    
    if(!flag) path.push_back(root); //first store path till the element not found.
     
    if(root->data == val){
        flag = true; //once found..mark flag as true..so that..no need to store further elements.
        return;
    }
    
    findAncestor(root->left,val,path);
    findAncestor(root->right,val,path);
    
    if(!flag) path.pop_back(); //if we not found element..then pop back current path.
}


Node* lca(Node* root ,int n1 ,int n2 )
{
    Node *ans = NULL;
    vector<Node*> path1, path2;
    
    findAncestor(root,n1,path1); //find path for n1
    flag = false;
    findAncestor(root,n2,path2); //for n2.
    
    int i = 0;
    //here logic is...we are iterating from left to right (i.e top to bottom of nodes)...so initially..there will be
    //common nodes which are ancestors..but we have to find..lest common ancestor..so we are iterating..till
    //both nodes are common...once nodes are mismatched..then..last common node is least ancestor.
    for(; i<path1.size() && i<path2.size(); i++){
        if(path1[i]->data != path2[i]->data)  
        break;
    }
    
    if(flag) return path1[i-1]; //so return last common node..and flag mentioning that..we have 
    //found n1 and n2 in tree.
    
    return ans;
}