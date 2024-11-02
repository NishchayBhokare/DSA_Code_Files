//Example for flatten linked list.
//GFG


//Approach 1: Optimised approach TC-O(O(N*N*M)) SC-O(M)
//Just use two merge linked list technique i.e merge curr and curr's next linked list, till curr'next not equals to null.
Node *merge(Node *first,Node *second){ //Merging linked list.
    
     if(first == NULL) return second;
     if(second == NULL) return first;
     
     Node *ans=new Node(-1);
     Node *tail=ans;
     while(first != NULL and second != NULL){
         if(first->data <= second->data){
             tail->bottom=first;
             tail=first;
             first=first->bottom;
         }
         else{
             tail->bottom=second;
             tail=second;
             second=second->bottom;
         }
     }
     
     while(first != NULL){
         tail->bottom=first;
         tail=first;
         first=first->bottom;
     }
     
     while(second != NULL){
         tail->bottom=second;
         tail=second;
         second=second->bottom;
     }
     
     ans=ans->bottom;
     return ans;
}

 Node *flatten(Node *&root) {
    if(root == NULL and root->next == NULL) return root;
    Node *first=root;
    Node *second=root->next; //pointing first to root node and second to next of root.
    while(second){ //looping till second not becomes to null.
        first = merge(first,second); //merging first and second
        Node *temp=second; //pointing temp to second.
        second=second->next; //shifting second.
        temp->next=NULL; //pointing temp's next to null because temp's next i.e original second's next points to next of it. so to remove that link point temp's next to null.
    }
    return first; //return root.
}
    


//Approach 2: Using recursion
Node *mergeTwoLinkedList(Node *first, Node *second){
        Node *ans = new Node(-1); 
        Node *tail = ans;
        
        while(first && second){
            if(first->data <= second->data){
                tail->bottom = first;
                tail = tail->bottom;
                first = first->bottom;
            }
            else{
                tail->bottom = second;
                tail = tail->bottom;
                second = second->bottom;
            }
        }
        
        if(first) tail->bottom = first;
        if(second) tail->bottom = second;
        
        return ans->bottom;
    }

    Node *flatten(Node *root) {
        
      if(root == NULL or root->next == NULL) return root;
      
      Node *first = root;
      Node *second = flatten(first->next); //flatten right part.
      
      return mergeTwoLinkedList(first,second); //then just do merge two sorted linked list.
    }