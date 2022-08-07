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

void levelOrderTraversal(node *root) // levelOrderTraversal with cout statement to change line.
{
    queue<node *> q;
    q.push(root);
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

void NormalLevelOrTr(node *root){ //This is one kind of level order Traversal out of 4.
    queue<node *> q;
    vector <int > v;
    q.push(root);
    while (!q.empty())
    {
        node *temp=q.front();
        cout<<temp->data<<" "; //printing element which is front in queue.
        q.pop(); //we are popping element for every iteration
        if(temp->left){ 
            q.push(temp->left);
        }
        if(temp->right){ 
            q.push(temp->right);
        }
    }  
}

void reverseLevelOrTr(node *root){ //it is reverse of normal level order taversal.
    queue<node *> q;
    vector <int > v;
    q.push(root);
    while (!q.empty())
    {
        node *temp=q.front();
        v.push_back(temp->data); //pushing front data of queue in vector.
        q.pop();//after pushed in vector, pop out from queue.
        if(temp->right){ //at this time travelling from right to left.
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    reverse(v.begin(),v.end()); //reversing the vector.
    for(auto i:v){
        cout<<i<<" ";
    }
    
}

void buildFromLevelOrder(node *&root) // building tree from level order
{
    queue<node *> q; // creating queue.
    int data;
    cout << "Enter data " << endl;
    cin >> data;
    root = new node(data);
    q.push(root); // creating and pushing node in queue.

    while (!q.empty()) // till queue not get empty.
    {
        node *temp = q.front(); // creating temp which will take front element of queue.
        q.pop();                // after taken element we must pop it.

        cout << "Enter data for left of " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1) // if user enter -1 then no need to create another child node.
        {
            temp->left = new node(leftData); // creating node for left of temp.
            q.push(temp->left);              // after creating node, pushing it into the queue.
        }

        cout << "Enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData); // creating node for right of temp.
            q.push(temp->right);               // after creating node , pushing it into the queue.
        }
    }
}
int main()
{
    node *root = NULL; // creating just node pointer.
    buildFromLevelOrder(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // Traversing
    levelOrderTraversal(root);
    NormalLevelOrTr(root);
    // reverseLevelOrTr(root);
}