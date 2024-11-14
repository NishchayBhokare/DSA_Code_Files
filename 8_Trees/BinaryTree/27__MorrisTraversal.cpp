//Morris traversal
//gfg link -> https://www.geeksforgeeks.org/problems/inorder-traversal/1
//link is for normal traversal..but i have solved question using morris travresal.


//Question -> Inorder output using Morris traversal.
 //Morris traversal. TC-O(N) SC-O(1)
Node *findPredecessor(Node *temp){ //finding predecessor.
    Node *curr = temp;
    
    if(temp->left) temp = temp->left; //one time go left.
    while(temp->right != NULL && temp->right != curr) //then go only right part.
        temp = temp->right;
    
    return temp;
}
    
vector<int> inOrder(Node* root) {
    vector<int> ans;
    Node *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){ //if left is null...then print current node
        //and move on to right part.
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{ //if right not null then first find predecessor.
            
            //find predecessor.
            Node *pred = findPredecessor(curr);
            
            if(pred->right == NULL){ //if pred left is null..then point pred's right to current node.
                pred->right = curr;
                curr = curr->left;
            }
            else{ //if not null. then make pred's right to null. and push curr's data in answer.
            //and move to right part as we already traversed left part.
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    
    return ans;
}



//Question 2: Moris traversal for preorder.
//same like above..just print statement or push back statement is in different place.
Node *findPredecessor(Node *temp){
    Node *curr = temp;
    
    if(temp->left) temp = temp->left; //one time go left.
    while(temp->right != NULL && temp->right != curr) //then go only right part.
        temp = temp->right;
    
    return temp;
}
vector<int> preorder(Node* root) {
    // write code here
        vector<int> ans;
    Node *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){ //if left is null...then print current node
        //and move on to right part.
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{ //if right not null then first find predecessor.
            
            //find predecessor.
            Node *pred = findPredecessor(curr);
            
            if(pred->right == NULL){ //if pred left is null..then point pred's right to current node.
                pred->right = curr;
                ans.push_back(curr->data); //now pushing current node in this if..becuase in this if..
                //we are traversing to right part..so before moving to right part..first print current node.
                curr = curr->left;
            }
            else{ //if not null. then make pred's right to null. and push curr's data in answer.
            //and move to right part.
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    
    return ans;
}