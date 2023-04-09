//Find Predecessor and Successor
//GFG
#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int data;
};


//Approach 1: Simple iterative approach. TC-O(N) SC-O(1)

//For a node (except leaf node) Successor will be go to once right and then move to left most node.
void inOrderSuccessor(Node* root, Node*& suc, int key){
    suc=NULL; //Initially keeping pre as NULL.
    while(root!=NULL){ //looping till, we not reach to the NULL. or if first time root is null no need to enter.
        if(key>=root->data){ //if key is greater than or equal to current node then no need to move left of current node. 
            root=root->right; //so move to right of current node.
        }
        else{
            suc=root; //now when key is small than current node, then we know current node can be our one of the ans. that's why we are storing it in succ.
            root=root->left; //also we can't sure we got answer so we will move to left of current node so that we can get lesser element than current node and greater than key i.e (immediate next of key).
        }
    }
}

//For a node (except leaf node) predecessor will be go to once left and then move to right most node.
//For leaf node predecessor will be one of the its ancestor.
void inOrderPredecessor(Node* root, Node*& pre, int key){
    pre=NULL; //Initially keeping pre as NULL.
    while(root!=NULL){ //looping till, we not reach to the NULL. or if first time root is null no need to enter.
        if(key <= root->data){ //if key is less than or equal to current node then no need to move right of current node. 
            root=root->left; //so move to left of current node.
        }
        else{
            pre=root; //now when key is greater than current node, then we know current node can be our one of the ans. that's why we are storing it in pre.
            root=root->right; //also we can't sure we got answer so we will move to right of current node so that we can get greater element than current node and less than key i.e (immediate previous of key).
        }
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
    inOrderPredecessor(root,pre,key); //calling inOrderPredecessor function.
    inOrderSuccessor(root,suc,key); //calling inOrderSuccessor function.

}



//Approach 2: Recursive approach. TC-O(N) SC-O(1)
Node *findMaximum(Node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}


Node *findMinimum(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

void findPredecessor(Node *root, Node *&pre,int key){
    if(root == NULL){
        return;
    }
    
    if(key == root->key){
        if(root->left){
            pre = findMaximum(root->left);
        }
        return;
    }
    
    if(key < root->key){
        findPredecessor(root->left,pre,key);
    }
    
    else if(key > root->key){
        pre = root;
        findPredecessor(root->right,pre,key);
    }  
}


void findSuccessor(Node *root,Node*&suc,int key){
    if(root == NULL){
        return;
    }
    
    if(key == root->key){
        if(root->right){
            suc = findMinimum(root->right);
        }
        return;
    }
    
    if(key > root->key){
        findSuccessor(root->right,suc,key);
    }
    
    else if(key < root->key){
         suc = root;
         findSuccessor(root->left,suc,key);
    }  
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
  findPredecessor(root,pre,key);
  findSuccessor(root,suc,key);
}