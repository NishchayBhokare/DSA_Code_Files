//Construct Tree from Postorder and Inorder
//GFG


//Approach : TC-O(N2) SC-O(N)
//Approach is Almost similar as previous problem just two changes.
//In case of postorder root element will starts from end of array. 
//So we will iterate from right to left i.e end to start.
//and while function calls, first call will be for right subtree beacuase our next root will be in right subtree incase of postorder traversal and then at last left subtreee.
int findPosition(int element,int in[],int inorderStart,int inorderEnd){
        for(int i=inorderStart; i<=inorderEnd; i++){
            if(in[i] == element) return i;
        }
        return -1;
}

Node *solve(int in[], int post[], int n, int &index,int inorderStart,int inorderEnd){
    
    if(index < 0 or inorderStart > inorderEnd){
        return NULL;
    }
    
    int element = post[index--]; //decrementing index
    Node *root = new Node(element);
    int position = findPosition(element,in,inorderStart,inorderEnd);
    
    root->right = solve(in,post,n,index,position+1,inorderEnd); //first right then left
    root->left = solve(in,post,n,index,inorderStart,position-1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int index = n-1; //indexing will start from end
    int inorderStart = 0;
    int inorderEnd = n-1;
    
    return solve(in,post,n,index,inorderStart,inorderEnd);
}
