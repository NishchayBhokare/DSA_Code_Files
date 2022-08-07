#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node * InsertIntoBST(node *root,int data){
    if(root==NULL){ //when given node is null that time we will create new node.
        root=new node(data);
        return root;
    }

    if(data > root->data){ //if data is greater than root->data then go to right subtree.
        root->right=InsertIntoBST(root->right,data);
    }
    else{ //if data is smaller than root->data then go to right subtree.
        root->left=InsertIntoBST(root->left,data);
        
    }
       return root; //returning root (either to root->left or root->right) so that we can finally return main root.
}
void takeInput(node* &root){
    int data;
  cout<<"Enter a data"<<endl;
  cin>>data;
  while (data!= -1) //till user not get -1 i.e NULL, we will loop.
  {
  root=InsertIntoBST(root,data); 
  cin>>data; 
  }
  
}

void inorder(node *root){
    if(root!=NULL){ //looping till root is not null and till it will reach to last node.
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
    }
    // return;
}

void normalLevelOrderTraversal(node *root){
    queue<node *> q;
    q.push(root); //pushing initially root in queue.
    while (!q.empty())
    {
        node *temp = q.front(); // getting first node from queue.
        q.pop();                // popping out that particular node.
        cout<<temp->data<<" ";  // outputing temp's data i.e front element of queue.

        if(temp->left) q.push(temp->left); // if temp's left is exist then push it in queue.

        if(temp->right) q.push(temp->right); // if temp's right is exist then push it in queue.
    }
}

void levelOrderTraversal(node *root) // this is one kind of traversing out of 4.
{
    queue<node *> q;
    q.push(root); //pushing initially root in queue.
    q.push(NULL); // pushing null as line sepertor cause at level 0 only one node will be there i.e root node.
    while (!q.empty())
    {
        node *temp = q.front(); // getting first node from queue.
        q.pop();                // popping out that particular node.

        if (temp == NULL)
        {                 // if temp is null that means particular level is finished and by line seperator we will move next level.
            cout << endl; // line seperating.
            if (!q.empty())
            { // if there are elements in queue then pushing null in queue.
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

int minValue(node* root) {
    if(root==NULL) return -1; //if initially root is null we will return -1.
    while(root->left!=NULL){  //looping till last element of left subtree. (i.e left most element is minmum element in BST) 
        root=root->left;
    }
    return root->data; //returning last element of left subtree.
}

node *DeletionInBST(node *root,int val){
    if(root==NULL) return root; //when root is null simply return root.

    if(val > root->data){ //When value is greater than current node then search in right of subtree.
        root->right=DeletionInBST(root->right,val); //moving in right direction
        return root; //after completing we will return root.
    }
    else if(val < root->data){//When value is lesser than current node then search in left of subtree.
        root->left=DeletionInBST(root->left,val); //moving in left direction
        return root;
    }
    else if(val == root->data){//condition where, when we find the element to be deleted.

        //1st case when 0 child.
        if(root->left==NULL && root->right==NULL){ 
            delete root; //just delete node and return null so that they we will connect.
            return NULL;
        }

        //2nd case when 1 child 
            //a) when only left child and right is null.
            if(root->left!=NULL && root->right==NULL){
                node *temp=root->left; //assigning root's left child to temp so that we can return it for connect. 
                delete root; //deleting root.
                return temp;
            }

             //b) when only right child and left is null.
           if(root->left==NULL && root->right!=NULL){
                node *temp=root->right; //assigning root's right child to temp so that we can return it for connect.
                delete root; //deleting root.
                return temp;
            } 


        //3rd case when 2 child is there.
        if(root->left!=NULL && root->right!=NULL){
            int key=minValue(root->right); //we will serch for minimum element from right subtree. so that after deleting sequenece of inorder will not get change.
            root->data=key; //changing root's data to minimum data.
            root->right=DeletionInBST(root->right,key); //we are going to delete for that minimum element.
            return root;
        }
    }
}

int main(){
// 10 21 5 8 9 14 30 2 1 -1
    node *root=NULL;
    takeInput(root);
    // inorder(root);
    cout<<"Level Order Traversal is "<<endl;
    // normalLevelOrderTraversal(root);
    levelOrderTraversal(root);

    root=DeletionInBST(root,1);

    cout<<"After Deletion Level Order Traversal is "<<endl;
    levelOrderTraversal(root);
    
    return 0;
}