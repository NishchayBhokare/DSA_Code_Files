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

void buildFromLevelOrderTraversal(Node * &root){
    queue<Node *> q;
    cout<<"enter data for root node "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild != -1){
            Node *leftNode = new Node(leftChild);
            temp->left = leftNode;
            q.push(leftNode);
        }

        cout<<"Enter data for right of "<<temp->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild != -1){
            Node *rightNode = new Node(rightChild);
            temp->right = rightNode;
            q.push(rightNode);
        }
    }
}

void iterativePreOrder(Node *root){
    stack<Node *>st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        //print
        cout<<temp->data<<" ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }cout<<endl;
}

void iterativePostOrder(Node *root){
    stack<Node*>st;
    stack<Node*>ans;

    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        ans.push(temp);

        if(temp->left)
            st.push(temp->left);
        
        if(temp->right)
            st.push(temp->right);
    }

    while(!ans.empty()){
        cout<<ans.top()->data<<" ";
        ans.pop();
    }cout<<endl;
}

void iterativeInOrderTraversal(Node *root){
    stack<Node *>st;
    Node *temp = root;
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

int main(){
    Node *root = NULL;

    // 3 5 7 -1 -1 9 -1 -1 8 2 -1 -1 -1
    //3 5 -1 -1 8 -1 -1
    //3 -1 2 -1 -1
    
    root = buildTree(root);

    // vector<int> arr = {3,5,8,7,9,-1,-1,-1,-1,-1,-1};
    // buildFromLevelOrderTraversal(root);

        // traverseTree(root);
    // iterativePreOrder(root);
    // iterativePostOrder(root);
    levelOrderTraversal(root);
    cout<<endl;
    iterativeInOrderTraversal(root);

    return 0;
}