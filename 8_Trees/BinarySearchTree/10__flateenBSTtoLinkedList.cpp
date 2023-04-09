//Flatten binary search tree to linked list.
//Coding ninja

//Approach 1: Most optimised approach TC-O(N) SC-O(H)
//Using dummy pointer we are pointing dummy to previous of root then changin links
void solve(TreeNode<int>* root,TreeNode<int>* &dummy ){ //Doing inorder
    if(root == NULL) return;

    solve(root->left,dummy);

    dummy->right = root; //changing links pointing dummy's right to root.
    dummy = root; //and update dummy to root
    dummy->left = NULL; //and new node left to null

    solve(root->right,dummy);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
   TreeNode<int>* dummy = new TreeNode<int>(-1); //creating dummy node
   TreeNode<int>* prev = dummy;
   solve(root,dummy);
   
   TreeNode<int>*Root = prev->right; //ponting root to prev's right, because prev is nothing but starting dummy node.

   return Root;
}


//Approach 2: TC-O(N) SC-O(h)
//Without using dummy node, for this do reverse inorder traversal
//so that at last head will point to left most node of inorder traversal.
void solve(TreeNode<int>* root,TreeNode<int>* &head ){ //Doing inorder
    if(root == NULL) return;

    solve(root->right,head); //first move to right

    root->right = head; //connect root's right to head
    if(head) head->left = NULL; //if head exist, then head's left points to null, initially head is pointing to null.

    head = root; //then pointing head to root

    
    solve(root->left,head); //moving to left.
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
   TreeNode<int>* head = NULL;
   solve(root,head);
   head->left = NULL;
   return head;
}


//Approach 3: TC-O(N) SC-O(N)
//Storing inorder  in array and then updating left and right.
void solve(TreeNode<int>* root,vector<TreeNode<int>*> &vec ){
    if(root == NULL) return;
    solve(root->left,vec);
    vec.push_back(root);
    solve(root->right,vec);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root == NULL) return NULL;
    vector<TreeNode<int>*> ans;
    solve(root,ans);

    TreeNode<int>* Mainroot = ans[0];
    for(int i=0; i<ans.size()-1; i++){
        ans[i]->right = ans[i+1];
        ans[i]->left = NULL;
    }
    ans[ans.size()-1]->left = NULL;
    ans[ans.size()-1]->right = NULL;
    return Mainroot;
}