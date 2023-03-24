//Construct Tree from Inorder & Preorder
//GFG


//Approach : TC-O(N2) SC-O(N)
//Analogy: The first element of preorder is root node. so search this node in inorder and once root node is find in inorder then left element from it will be in left side of subtree and right elements will be in right side or subtree, so according to that update start index and end index.
int findPosition(int element,int in[],int inorderStart,int inorderEnd){ //elements can be duplicate so search for element in range of inorder start index and end index. so that even if duplicates elements are present then we dont need to worry about that
    for(int i=inorderStart; i<=inorderEnd; i++){
        if(in[i] == element) return i; //once element find return it's index
    }
    return -1; 
}

Node * solve(int in[], int pre[], int n, int &index, int inorderStart, int inorderEnd){
    if((index >= n) or (inorderStart > inorderEnd)){ //if index is out of preorder array range or inorderStart index greater than end index then return NULL.
        return NULL;
    }
    
    int element = pre[index++]; //getting new root index from preorder array and incrementing index for next call
    Node *root = new Node(element); //creating node
    int position = findPosition(element,in,inorderStart,inorderEnd); //finding this element in inorder array
    
    root->left = solve(in,pre,n,index,inorderStart,position-1); //go for left part, while pointing end index to position -1.
    root->right = solve(in,pre,n,index,position+1,inorderEnd); //go for right part, while pointing start index to position +1
    
    return root; //finally return root
}

Node* buildTree(int in[],int pre[], int n)
{
    int index = 0;
    int inorderStart = 0;
    int inorderEnd = n-1;
    Node *ans = solve(in,pre,n,index,inorderStart,inorderEnd); //returingin answer.
    return ans;
}

