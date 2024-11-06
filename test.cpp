#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

 Node* buildTree(Node *root){
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;
    
    root = new Node(data);

    cout<<"Enter data to insert in left part of "<<data<<endl;

    root->left = buildTree(root->left);

    cout<<"Enter data to insert in right part of "<<data<<endl;

    root->right = buildTree(root->right);

    return root;
}

void traverseTree(Node *root){

    if(!root) return;

    traverseTree(root->left);
    
    traverseTree(root->right);
    cout<<root->data<<' ';
}

void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        if(temp) cout<<temp->data<<" ";
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;

    // 3 5 7 -1 -1 9 -1 -1 8 2 -1 -1 -1
    
    root = buildTree(root);

    // traverseTree(root);
    levelOrderTraversal(root);

    return 0;
}