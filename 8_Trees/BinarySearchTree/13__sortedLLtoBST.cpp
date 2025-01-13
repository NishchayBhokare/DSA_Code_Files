//Convert sorted linked list to binary search tree.
///GFG

//Approach 1: Optimised approach TC-O(N) SC-O(N)
int CountNodes(LNode *head){
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

TNode* solve(LNode * &head,int size){
    
    if(size <= 0 or head == NULL) return NULL; //if size gets less than 0 or head reahces to null that is next of last node then return null.
    
    //constructing left side bst (L)
    TNode *Left = solve(head,size/2);
    
    //creating node (N)
    TNode* root = new TNode(head->data);
    root->left = Left; //once left part is prepared..connect current root's left to left part.
    head = head->next;
    
    //constructing right side bst. (R)
    TNode *Right = solve(head, size-size/2-1); //except mid node..give size so suppose size is 5 then here we will pass size as 2. 
    //because,  left part is 2 + current node 1 + right part 2 ====> 5.
    root->right = Right; //same once right done..then connect right to right part.
    
    return root; //and return root; i.e head;
}


TNode* sortedListToBST(LNode *head) {
    int size = CountNodes(head); //first calculating length of given linked list.
    return solve(head,size); //calling solve function which will finally return head or root node of constructed binary search tree.
}


//Approach 2: Using extra space. i.e storing nodes with respective its index in map.
//TC-O(N) SC-O(N)
TNode* solve(LNode * head,int start, int end, unordered_map<int, LNode *> &indexToNode){
        
    if(start > end) return NULL; //looping till start less than end
    
    int middle = (start+end+1)/2; //doing + 1 becuase to handle with even case like if 1 3 these are the nodes then answer should be 3 1 not 1 3 because we are printing preorder.
    
    LNode *middleNode = indexToNode[middle]; //getting middle linked list node.
    TNode *root = new TNode (middleNode->data); //creating root node for given data of node.
    
    root->left = solve(head,start,middle-1,indexToNode); //constructing left part
    
    root->right = solve(head,middle+1,end,indexToNode); //constructing right part.
   
    return root;
}

void mapping(LNode*head, unordered_map<int, LNode *> &indexToNode){ //mapping index with nodes
    int index = 0; 
    while(head != NULL){
        indexToNode[index++] = head; //mapping nodes with index
        head = head->next;
        size++; //also calculating  size of linked list.
    }
}

TNode* sortedListToBST(LNode *head) {
    unordered_map<int,LNode *> indexToNode;
    mapping(head,indexToNode);
    
    int start = 0, end = size-1;
    return solve(head,start,end,indexToNode);
}



//Approach 3 : Brute force solution
int CountNodes(LNode *head){ //counting length of linked list
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}


LNode* getNode(LNode *head, int mid){ //getting middle node
    while(mid and head != NULL){
        mid--;
        head = head->next;
    }
    return head;
}

TNode* solve(LNode * head,int start, int end){
        
    if(start > end) return NULL;
    
    int middle = (start+end+1)/2;  //getting middle node. 
    
    LNode *dataNode = getNode(head,middle); 
    TNode *root = new TNode (dataNode->data);
    
    root->left = solve(head,start,middle-1);
    
    root->right = solve(head,middle+1,end);
   
    return root;
}

    TNode* sortedListToBST(LNode *head) {
        int size = CountNodes(head);
        int start = 0, end = size-1;
        return solve(head,start,end);
    }