//Merge two BST 's 
//Coding ninja, GFG.



//Coding ninja
//Approach 1: optimised approach TC-O(N) SC-O(h1+h2);
void flatten(TreeNode<int> * root, TreeNode<int> *&head){
    if(root == NULL) return;

    flatten(root->right, head);

    root->right = head;
    if(head) head->left = NULL;
    head = root;

    flatten(root->left,head);
}


TreeNode<int> * merge(TreeNode<int> * root1, TreeNode<int> * root2){
    TreeNode<int> * ans = NULL, *head=NULL;
    if(root1->data <= root2->data){
        head=root1;
        ans = root1;
        root1 = root1->right;
    }
    else{
        head=root2;
        ans = root2;
        root2 = root2->right;
    }

    while(root1 and root2){
        if(root1->data <= root2->data){
            ans->right = root1;
            ans = root1;
            root1 = root1->right;
        }
        else{
            ans->right = root2;
            ans = root2;
            root2 = root2->right;
        }
    }

    if(root1) ans->right = root1;
    if(root2) ans->right = root2;
    
    return head;
}


int CountNodes(TreeNode<int> * head){
    int count = 0;
    while(head != NULL){
        count++;
        head=head->right;
    }
    return count;
}

TreeNode<int> * build(TreeNode<int> * &head, int size){
    if(size <= 0 or head == NULL) return NULL;

    TreeNode<int> * Left = build(head,size/2);

    TreeNode<int> * root = head;
    root->left = Left;
    head = head->right;

    TreeNode<int> * Right = build(head,size-(size/2)-1);
    root->right = Right;

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //Step 1:flatten both bst. so that we get inorder linked list.
    TreeNode<int> * head1 = NULL, *head2 = NULL;
    flatten(root1,head1);
    flatten(root2,head2);
    head1->left = NULL;
    head2->left = NULL;

    //step 2: merge both sorted linked list
    TreeNode<int> * head = merge(head1,head2);

    
    //step 3: Build BST from inorder.
    int size = CountNodes(head);
    return build(head,size);
}



//Approach 2: TC-O(N) SC-O(N)
void traverse(TreeNode<int> *root,vector<int> &inorder){
    if(root == NULL) return;
    
    traverse(root->left,inorder);
    inorder.push_back(root->data);
    traverse(root->right,inorder);
}
    
    
vector<int> mergeBothInorders(vector<int>&inorder1,vector<int>&inorder2){
    vector<int>ans;
    int i=0,j=0;
    while(i < inorder1.size() and j<inorder2.size()){
        if(inorder1[i] <= inorder2[j]) 
            ans.push_back(inorder1[i++]);
        
        else ans.push_back(inorder2[j++]);
    }
    
    while(i < inorder1.size() ) ans.push_back(inorder1[i++]);
    while(j < inorder2.size() ) ans.push_back(inorder2[j++]);
    return ans;
}


TreeNode<int> * BSTFromInorder(int start, int end, vector<int>&inorder){
    if(start > end) return NULL;

    int mid = (start + end)/2;
    TreeNode<int> *curr = new TreeNode<int>(inorder[mid]);

    curr->left = BSTFromInorder(start, mid-1, inorder);
    curr->right = BSTFromInorder(mid+1, end, inorder);

    return curr;
}  

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
       //step 1: Store inorder of both BST.
       vector<int>inorder1,inorder2;
       traverse(root1,inorder1);
       traverse(root2,inorder2);
       
       //Step 2: Merge both inorders (Merge two sorted array)
       vector<int> inorder = mergeBothInorders(inorder1,inorder2);
       
       //step 3: Build BST from inorder.
       int start = 0, end = inorder.size()-1;
       TreeNode<int> * root = BSTFromInorder(start,end,inorder);

       return root;
}



//GFG  version -In GFG version just return mergerd inorder of both bst, no need to creat bst of both inorders like in the case of coding ninja problem
void traverse(Node *root,vector<int> &inorder){
        if(root == NULL) return;
        
        traverse(root->left,inorder);
        inorder.push_back(root->data);
        traverse(root->right,inorder);
}
    
    
vector<int> mergeBothInorders(vector<int>&inorder1,vector<int>&inorder2){
    vector<int>ans;
    int i=0,j=0;
    while(i < inorder1.size() and j<inorder2.size()){
        if(inorder1[i] <= inorder2[j]) 
            ans.push_back(inorder1[i++]);
        
        else ans.push_back(inorder2[j++]);
    }
    
    while(i < inorder1.size() ) ans.push_back(inorder1[i++]);
    while(j < inorder2.size() ) ans.push_back(inorder2[j++]);
    return ans;
}
    
vector<int> merge(Node *root1, Node *root2)
{
    //step 1: Store inorder of both BST.
    vector<int>inorder1,inorder2;
    traverse(root1,inorder1);
    traverse(root2,inorder2);
    
    //Step 2: Merge both inorders (Merge two sorted array)
    vector<int> inorder = mergeBothInorders(inorder1,inorder2);

    // return inorder.
    return inorder;
}