// Example for search element in Binary Search Tree.
// link-
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};

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