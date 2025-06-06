//Example for deleting nod greater than k
//GFG
//link-
    // https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1

//Approach 1: TC-O(size) SC - O(1).
 Node* deleteNode(Node* root, int k)
{
    if(root==NULL) return NULL; //if given root is NULL then we will return and also while traversing if root becomes null then we will return NULL.
    
    if(root->data >= k){ //IF root's data greater than or equal to k then move to left for getting  lesser value than k. 
        return deleteNode(root->left,k);
    }
                        //  or  if(data >= k){
                        //         Node *temp = root;
                        //         root = root->left;
                        //         delete temp;
                        //         return solve(root,k);
                        //     } we can do this also


    else{ //if root's data is bigger than k, so move to right side.
        root->right = deleteNode(root->right,k); 
//after going to right when we get element lesser than k , 
// then we will go to right part of it. and at the end. 
//will connect updated part of root's right to root->right. do dry run u will understand.
//mostly on smalle example we will get null as root's right so will connect that with root's right.
    }
    
    return root; //returninig root.
}



//Approach 2: Using postorder traversal. TC-O(size) SC-O(1)
 Node* deleteNode(Node* root, int k)
{
    if(root == NULL) return NULL;
    
    root->right = deleteNode(root->right, k); //moving to right and left.
    root->left = deleteNode(root->left, k);
    
    int data = root->data; //once right and left gets processed we will reach here
    if(data >= k){ //if data greater than k 
        Node *temp = root; //point temp to root
        root = root->left; //as current node is greater than k, so right part will offcourse greater than k, so point root to left of it.
        delete temp; //and delete previous root node i.e temp pointing
    }
    return root; //and return new root
}