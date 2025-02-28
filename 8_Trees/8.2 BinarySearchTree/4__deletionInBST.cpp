// Example for deletion Binary Search Tree.
//GFG
// link-
    // https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

//TC-O(N) SC-O(h)
int minValue(Node *root){
    if(root==NULL) return -1;  //if initially root is null we will return -1.
    
    while(root->left!=NULL){ //looping till last element of left subtree. (i.e left most element is minmum element in BST) 
        root=root->left;
    }
    return root->data; //returning last element of left subtree.
}

Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root==NULL) return root; //when root is null, we simply return root.
    
    if(X > root->data){ //When value is greater than current node then search in right of subtree.
        root->right=deleteNode(root->right,X); //moving in right direction
        return root; //after completing we will return root.
    }
    if(X < root->data){ //When value is lesser than current node then search in left of subtree.
        root->left=deleteNode(root->left,X); //moving in left direction
        return root;
    }
    
    if(X == root->data){//condition where, when we find the element to be deleted.
        
        //1st case when 0 children
        if(root->left==NULL && root->right==NULL){
            delete root; //just delete node and return null so that they we will connect.
            return NULL;
        }
        
        //2nd case when 1 childern
        // a)have only left child and right is null
        if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left; //assigning root's left child to temp so that we can return it for connect.
            delete root; //deleting root.
            return temp;
        }
        
         // b)have only right child and left is null
        if(root->left==NULL && root->right!=NULL){
            Node *temp=root->right; //assigning root's right child to temp so that we can return it for connect.
            delete root;
            return temp;
        }
        
        //3rd case when have 2 childs
        if(root->left!=NULL && root->right!=NULL){ //min value is nothing but successor. but we can solve this using predecesor. below solution.
            int minKey=minValue(root->right); //we will serch for minimum element from right subtree. so that after deleting sequenece of inorder will not get change.
            root->data=minKey; //changing root's data to minimum data.
            root->right=deleteNode(root->right,minKey); //we are going to delete for that minimum element.
            return root;
        }
        
    }
}


//same like above..but here..in deletion of two child cases..we're taking maximum element from left subtree

Node * findPredecessor(Node *root){
        root=root->left;
        
        while(root->right != NULL)
            root=root->right;
        
        return root;
    }
    
    Node *deleteNode(Node *root, int x) {
        
        if(root==NULL) return NULL;
        
        if(root->data==x){
            
            if(root->left==NULL && root->right==NULL)
                return NULL;
            
            else if(root->left==NULL)
                return root->right;
            
            else if(root->right==NULL)
                return root->left;
                
            else{
                
                Node *pred = findPredecessor(root);
                root->data = pred->data;
                
                root->left = deleteNode(root->left, pred->data);
            }
        }
        else if(x < root->data)
            root->left = deleteNode(root->left, x);
        else
            root->right = deleteNode(root->right,x);
        
        
        
        
        return root;
    }
