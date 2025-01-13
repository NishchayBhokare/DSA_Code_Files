//Flatten binary search tree to linked list.
//Coding ninja

//Approach 1: Most optimised approach TC-O(N) SC-O(H)
//Using tail pointer we are pointing tail to previous of root then changing links
void solve(TreeNode<int>* root,TreeNode<int>* &tail ){ //Doing inorder
    if(root == NULL) return;

    solve(root->left,tail);

    tail->right = root; //changing links pointing tail's right to root.
    tail = root; //and update tail to root
    tail->left = NULL; //and new node left to null

    solve(root->right,tail);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
   TreeNode<int>* dummyHead = new TreeNode<int>(-1); //creating dummy node
   TreeNode<int>* tail = dummyHead;
   solve(root,tail);
   
   TreeNode<int>*Root = prev->right; 
   //ponting root to prev's right, because prev is nothing but starting dummy node.

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

//similar like above..but in normal way of inorder traversal.
  void solve(Node *root, Node* &head, Node * &tail){
        if(root == NULL) return ;
        
        solve(root->left, head, tail);

        if( head == NULL){
            head = root;
            tail = root;
        }
        
        Node * temp = root->right; //storing right part.
        tail->right = root;
        tail = root;
        tail->left = NULL;
        
        solve(temp,head,tail);
    }
    
    
    Node *flattenBST(Node *root)
    {
        Node *head = NULL;
        Node *tail = NULL;
        solve(root,head, tail);
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