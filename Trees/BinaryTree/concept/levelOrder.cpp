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

void reverseLevelOrderTraversal(node *root){ //same as level order traversal just we need extra stack
    stack<node *> st;
    queue<node *>q;
    st.push(root);
    st.push(NULL);
    q.push(root);
    q.push(NULL); //pushing root element along with null in stack and queue
    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp == NULL){ //if temp is null 
            if(!q.empty()){ //and q is not empty
            st.push(NULL); //then push null in both 
            q.push(NULL);
            }
        }
        else{ //if not null then push its right and lest child in stack and queue
            if(temp->right){
                q.push(temp->right);
                st.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
                st.push(temp->left);
            }
        }

    }

    while(!st.empty()){ //looping till stack not gets empty
        if(st.top() == NULL) cout<<endl; //if top is null then move to next line
        else cout<<st.top()->data<<" "; //else print node's data.
        st.pop(); //pop out node.
    }
}


void NormalLevelOrTr(node *root){ //This is one kind of level order Traversal out of 4.
    queue<node *> q;
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

void reverseNormalLevelOrTr(node *root){ //it is reverse of normal level order taversal.
    queue<node *> q;
    stack<int> st;
    q.push(root);
    while (!q.empty())
    {
        node *temp=q.front();
        st.push(temp->data); //pushing front data of queue in stack
        q.pop();//after pushed in vector, pop out from queue.
        if(temp->right){ //at this time travelling from right to left.
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void buildFromLevelOrder(node *&root) // building tree from level order
{
    queue<node *> q; // creating queue.
    int data;
    cout << "Enter data for root " << endl;
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
    reverseLevelOrderTraversal(root);
    reverseNormalLevelOrTr(root);
    cout<<endl;
    reverseNormalLevelOrTr(root);
}