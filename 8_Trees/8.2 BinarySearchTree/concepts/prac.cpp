#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

Node * InsertNode(Node *root, int data){
    if(root == NULL){
        Node *temp = new Node(data);
        return temp;
    }
    if(data < root->data){
        root->left = InsertNode(root->left,data);
    }
    else{
        root->right = InsertNode(root->right,data);
    }

    return root;
}


void traverse(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    Node *root = NULL;
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;
    while(data != -1){
        root = InsertNode(root,data);
        cin>>data;
    }
    traverse(root);
}