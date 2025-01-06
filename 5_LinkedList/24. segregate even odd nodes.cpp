//GFG. 

//Approach 1: simple approach TC-O(N) SC-O(1).
//Seperate even and odd list and at last connect even list to odd. and return head of even list.
Node* divide(Node* head) {
        
    Node *dumOdd = new Node(-1);
    Node * tailOdd = dumOdd;
    
    Node * dumEven = new Node(-1);
    Node * tailEven = dumEven;
    
    Node *temp = head;
    
    while(temp){
        
        if((temp->data % 2) == 0){ //even case.
            
            tailEven->next = temp;
            tailEven = temp;
        }
        else{
            
            tailOdd->next = temp;
            tailOdd = temp;
        }
        
        temp = temp->next;
    }
    
    tailEven->next = dumOdd->next;
    tailOdd->next = NULL;
    
    head = dumEven->next;
    return head;
}



//Approach 2: Little complex. TC-O(N) SC-O(1).
Node* divide(Node* head) {

    struct Node *tempHead = head, *evenEnd = NULL; //even end pointing to the end of even list.
    
    while(tempHead && (tempHead->data % 2) == 0){ //skipping first even values nodes.
        evenEnd = tempHead;
        tempHead = tempHead->next;
    }
    
    if(tempHead == NULL) return head; //if at this point temphead is null that means. only even values are preseint in list.
    //so return original head as it is.
    
    struct Node *curr=tempHead, *prev=NULL, *forward; //create three nodes, curr, prev, and forward.
    //curr will points to temporary head.
    
    while(curr){ //loop till curr not gets null.
        
        if((curr->data % 2) == 0){ //even value case.
            
            forward = curr->next; //store curr's next for future use.
            
            if(evenEnd){ //if even end is exist that means. earlier even values nodes are found.
                //if found...
                struct Node *temp = evenEnd->next; //then point current temp to evenend's next. which will be start of odd nodes.
                evenEnd->next = curr; //now point evenend to current. which is even node.
                curr->next = temp; //now connect curr to stored temp.
                evenEnd = curr; //and move evenend to curr.
            }
            else{
                //we will came in else block only once or not even that too.
                //becaue if we found even nodes earlier then we won't came in this else block. but for first time.
                curr->next=head; //point first even value node to head.
                head=curr; //point head to newhead.
                evenEnd=curr; //and update evenend.
            }
            
            prev->next = forward; //also point prev's next to forward which we stored.
            curr=forward; //and move curr to forward.
        }
        else{
            //if odd case.
            prev=curr; //then simply updated prev to curr.
            curr=curr->next; //and curr to it's next.
        }
    }
    
    
    return head; //return head.
}