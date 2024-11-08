#include <iostream>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;           // getting data for the node.

    if (data == -1)
    {
        return NULL; // if -1 is enter then return to the caller function i.e either root->left or root->right.
    }

    root = new node(data); // calling constructor and creating node.

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left); // recursion for setting left child.

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right); // recursion for setting right child.

    return root; //returning root (either to root->left or root->right) so that we can finally return main root.
}

void preOrder(node *root)
{
    if (root != NULL)
    { // follows NLR
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void iterativePreOrder(node *root)
{
    stack <node *> s; //creting a stack to store nodes.
    s.push(root); //first pushing root node into the stack.
    while (!s.empty()) //till stack is not empty loop will executed
    {
        node *temp=s.top(); //getting top most element of stack & storing it into temp.
        s.pop();  //popping out that top most element.
        cout<<temp->data<<" "; //cout that poped node.
        if(temp->right!=NULL){ //if that poped node contain right child then push that child into the stack
            s.push(temp->right); //pushing right child into the stack
        }
        if(temp->left!=NULL){ //if that poped node contain left child then push that child into the stack
            s.push(temp->left); //pushing left child into the stack
        }
    }
    //in above we are pushing temp->right before left cause of stack LIFO behaviour. so that we can easily print that left element.
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        // follows LNR
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void iterativeInOrder(node *root){
    stack <node *> s;
    node *temp=root;
    while (true)
    {
        if(temp!=NULL){ //when node does'nt have any left child anymore.
            s.push(temp); //push that particular node.
            temp=temp->left; //moving towards the left
        }
        else{
            if(s.empty()==true) break; //checking here stack is empty or not.
            temp=s.top(); //taking top element from stack
            cout<<temp->data<<" ";
            s.pop(); //and popping out from the stack
            temp=temp->right; //moving towards the right 
        }
    }  
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        // follows LRN
        postOrder(root->left);
         Order(root->right);
        cout << root->data << " ";
    }
}

void iterativePostOrder(node *root){
    stack <node *> s1;
    stack<node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL){
            s1.push(temp->left);
        }
        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }  
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL; // creating just node pointer.
    root = buildTree(root);
    // Traversing
    // cout << "preOrder Traversal is " << endl;
    // preOrder(root);
    // iterativePreOrder(root);

    cout<<endl<<"inOrder Traversal is "<<endl;
    inOrder(root); cout<<endl;
    iterativeInOrder(root);

    // cout<<endl<<"postOrder Traversal is "<<endl;
    // postOrder(root);
    // iterativePostOrder(root);
}