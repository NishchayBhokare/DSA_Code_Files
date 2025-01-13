//Construct Binary Search Tree from given preorder traversal.
//Coding ninja
// https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0


//Approach 1: Most optimised Approach TC-O(N) SC-O(N).
//Set a min and max range and if data lies between this range then create node.
BinaryTreeNode<int>* solve(int &index, int min,int max,vector<int>&preorder){

    if(index >= preorder.size()) return NULL; //if index gets out of range or array then return null and if element not in the range of min and max then also return null.
    if(preorder[index] < min || preorder[index] > max) return NULL; //if current element
    //doesn't fits in this range..then return null and we will check for this element in other subpart
    //of tree.

    int data = preorder[index++]; //store data and increment index
    BinaryTreeNode<int>* curr = new BinaryTreeNode<int>(data); //create node

    curr->left = solve(index,min,data,preorder); //check in left
    curr->right = solve(index,data,max,preorder); //check in right
    
    return curr; //return current node.
}


BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int index = 0;
    return solve(index,INT_MIN,INT_MAX,preorder); //return answer.

}


//Approach 2: sorting TC-O(Nlogn) SC-O(N)
//As we create tree from inorder in previous example similarly we sort preorder to make inorder
BinaryTreeNode<int>* solve(int start,int end, vector<int> &vec){
    if(start > end) return NULL;
    
    int middle = (start+end)/2;
   BinaryTreeNode<int>*curr = new BinaryTreeNode<int>(vec[middle]);
    
    curr->left = solve(start,middle-1,vec);
    curr->right = solve(middle+1,end,vec);
    
    return curr;
    
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    sort(preorder.begin(),preorder.end());
    return solve(0,preorder.size()-1,preorder);
}


//Approach 3: TC-O(N2) SC-O(N)
//As we insert node while creating bst, similarly we are creating bst here.
//but while inserting we are visiting every node thats why it's time complexity is n2.
BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>* root, int data){
    if(root == NULL){
        BinaryTreeNode<int>* curr = new BinaryTreeNode<int>(data);
        return curr;
    }

    if(data < root->data) 
        root ->left = insertNode(root->left,data);
    else 
        root ->right = insertNode(root->right,data);
    
    return root;
    
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    BinaryTreeNode<int>* root = NULL;
    for(int i=0; i<preorder.size(); i++){
        root = insertNode(root,preorder[i]);
    }
    return root;
}