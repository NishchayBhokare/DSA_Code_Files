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


Node * insertIntoBST(Node *root, int data){
    if(root == NULL){
        Node *temp = new Node(data);
        return temp;
    }

    if(data < root->data) 
        root->left = insertIntoBST(root->left, data);

    else 
        root->right = insertIntoBST(root->right,data);

    return root;
}

void takingInput(Node* &root){
    cout<<"Enter data "<<endl;
    int data; 
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node *root) // levelOrderTraversal with cout statement to change line.
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // pushing null as line sepertor cause at level 0 only one node will be there i.e root node.
    while (!q.empty())
    {
        Node *temp = q.front(); // getting first node from queue.
        q.pop();                // popping out that particular node.

        if (temp == NULL)
        {                 // if temp is null that means previous level is finished and by line seperator we will move next level.
            cout << endl; // line seperating.
            if (!q.empty())
            { // if there are elements in queue then pushing null in queue i.e next level is also completed in queue.
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // if null is not then print temp's data.
            if (temp->left)
            { // if temp's left is exist then push it in queue.
                q.push(temp->left);
            }
            if (temp->right)
            { // if temp's right is exist then push it in queue.
                q.push(temp->right);
            }
        }
    }
}

int minElementInBst(Node *root){
    if(root == NULL) return -1;

    if(root->left == NULL) return root->data;

    return minElementInBst(root->left);
}

int maxElementInBst(Node *root){
    if(root == NULL) return -1;

    if(root->right == NULL) return root->data;

    return maxElementInBst(root->right);
}

Node* deletionInBst(Node * root, int key){
    Node *temp = root;
    if(temp == NULL) return NULL;

    if(key < temp->data)
        temp->left = deletionInBst(temp->left, key);

    else if(key > temp->data)
        temp->right = deletionInBst(temp->right,key);
    else{

        //if zero child
        if(!temp->left && !temp->right){
            cout<<"Node "<<temp->data<<" is deleted "<<endl;
            delete temp;
            return NULL;
        }

        //if one child
        else if(temp->left && !temp->right){
            Node *leftPart = temp->left;
            cout<<"Node "<<temp->data<<" is deleted "<<endl;
            delete temp;
            return leftPart;
        }
        else if(!temp->left && temp->right){
            Node *rightPart = temp->right;
            cout<<"Node "<<temp->data<<" is deleted "<<endl;
            delete temp;
            return rightPart;
        }

        //if two child.
        else{
            int maxi = maxElementInBst(root->left);
            temp->data = maxi;
            temp->left = deletionInBst(temp->left,maxi);
            return temp;
        }
    }

    return temp;
}

int main(){
    // 10 7 9 5 15 13 14 -1
    Node *root = NULL;
    takingInput(root);
    cout<<endl;
    // cout<<minElementInBst(root)<<endl;
    // cout<<maxElementInBst(root);

    Node *ptr = deletionInBst(root, 10);
    // cout<<"hey";
    // cout<<ptr->data<<endl<<endl;

    levelOrderTraversal(root);
}