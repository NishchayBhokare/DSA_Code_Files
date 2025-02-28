//Flatten binary tree to linked list 
https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
//In this flatten example we have to return head or original tree so this is just flatten linked list not by inorder way like in bst.
//GFG


//Approach 1: Most optimised Approach Using Morris traversal. TC-O(N) SC-O(1)
Node * findPredecessor(Node *curr){ //Finding predecessor
    Node *pred = curr;
    pred = pred->left; //once move to left 
    while(pred->right != NULL){ //and move to right till right's right not get null
        pred = pred->right;
    }
    return pred; //return predecessor.
}

void flatten(Node *root)
{   
    Node *curr = root;
    while(curr != NULL){
        if(curr->left != NULL){ //if left exist.
            Node *predecessor = findPredecessor(curr); //then find predecessor for current node
            
            predecessor -> right = curr->right; //point predecessor's right to current right
            curr->right = curr->left; //and current right to current left.
            curr->left = NULL; //now there is no use of curent left pointer so point it to null
        }
        curr = curr->right; //and move to current right to process next nodes.
    }
}



//Approach 2: Using Recursion. TC-O(N) SC-O(N)
//Similar approach as morris traversal just we're doing with recursion. so space will be Big oh of N
Node * findPredecessor(Node *root){
    Node *pred = root;
    pred = pred->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;
}

void flatten(Node *root)
{
    if(root == NULL) return;
    Node *curr = root;
    if(root->left != NULL) { 
        Node *predecessor = findPredecessor(curr);
        
        predecessor -> right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
    }
    
    flatten(curr->right);  //call for right node. similar as morris traversal.
}


//NOt much readable.
//Approach 3: Using level order traversal with stack TC-O(N) SC-O(N)
 void flatten(Node *root)
{   
    stack<Node *> st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        
        if(temp->right) st.push(temp->right); //first insert right then left
        if(temp->left) st.push(temp->left); 
        
        if(!st.empty()){ //we inserted first right then left so top node will be left, 
        // so now connect right to top of stack node and there is no use of left so connect it with null.
            temp->left = NULL;
            temp->right = st.top();
        } //Do same for every node.
    }
}