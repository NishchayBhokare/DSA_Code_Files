//Merge two BST 's 
//Coding ninja, GFG.

// void flatten(TreeNode<int>* root,TreeNode<int>* &tail ){ //Doing inorder
//     if(root == NULL) return;

//     flatten(root->left,tail);

//     tail->right = root; //changing links pointing tail's right to root.
//     tail = root; //and update tail to root
//     tail->left = NULL; //and new node left to null

//     flatten(root->right,tail);
// }


//Coding ninja. also we can flatten bst using dummy node too.
//Approach 1: optimised approach TC-O(N) SC-O(h1+h2);
void flatten(TreeNode<int> * root, TreeNode<int> *&head){
    if(root == NULL) return;

    flatten(root->right, head); //first process right part...as we have to 

    root->right = head; //now connect current root to head of flattent tree.
    if(head) head->left = NULL; //if head is non null..then make left as null.
    head = root; //move head to root...so that we can process for left part.

    flatten(root->left,head);
}


TreeNode<int> * merge(TreeNode<int> * root1, TreeNode<int> * root2){ //we can solve using dummy node also.
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

    TreeNode<int> * Left = build(head,size/2); //process first left part..and return root node of left part.

    TreeNode<int> * root = head; //now make current root to head.
    root->left = Left; //root's left is leftpart.
    head = head->right; //move head to right part.

    TreeNode<int> * Right = build(head,size-(size/2)-1); //process right part.
    root->right = Right; //once process right part..make root's right to right part.

    return root; //and return root.
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








//Currently ...this first approach way..is removed from code studio..now we have to send..vector so that is simple way..
//but still to get practice of first approach..i have solved in first approach way...and finally converted answer into the
//vector. and returned it.
void flattenBST(TreeNode * root, TreeNode *&head){
    if(root == NULL) return;

    flattenBST(root->right,head); //firs process left part.

    root->right = head;
    if(head)
        head->left = NULL;
    
    head = root;

    flattenBST(root->left, head);
}

TreeNode * mergeTwoLinkedLIst(TreeNode *head1, TreeNode *head2){
    TreeNode * dummy = new TreeNode(-1);
    TreeNode * head = dummy;
    while(head1 && head2){ 
        if(head1->data <= head2->data){
            dummy->right = head1;
            dummy = dummy->right;
            head1 = head1->right;
        }
        else{
            dummy->right = head2;
            dummy = dummy->right;
            head2 = head2->right;
        }
    }
    if(head1){
        dummy->right = head1;
    }

    if(head2){
        dummy->right = head2;
    }
    return head->right;
}


TreeNode * buildTree(TreeNode * &head, int len){
    if(len <= 0 || head == NULL ) return NULL;

    TreeNode * leftPart = buildTree(head, len/2);

    TreeNode *root = head;
    root->left = leftPart;

    head = head->right;

    TreeNode * rightPart = buildTree(head, len - len/2 - 1);

    root->right = rightPart;

    return root;
}

int getCount(TreeNode * head){
    int len = 0; 
    while(head){
        len++;
        head = head->right;
    }
    return len;
}

void getInOrder(TreeNode * root, vector<int>&ans){
    if(root == NULL) return;

    getInOrder(root->left, ans);
    ans.push_back(root->data);
    getInOrder(root->right, ans);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{   TreeNode * head1 = NULL;
    TreeNode * head2 = NULL;
    flattenBST(root1,head1);
    flattenBST(root2,head2); //first flatten tree like linked list..
   
   TreeNode * head = mergeTwoLinkedLIst(head1,head2); //then merge those two flatten tree..

    int len = getCount(head); //get size of count of nodes prsent in flattent tree.
    head = buildTree(head, len); //now build tree..from sorted flattent tree (linked list.)

    vector<int> ans;
    getInOrder(head,ans); //store node values in ans vector and return.
    return ans;
}