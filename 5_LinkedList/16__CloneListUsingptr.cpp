//Example to Clone a linked list with next and random pointer


//Approach 1: Most optimised approach by changing links. TC-O(N) SC-O(1)
Node *copyList(Node *head)
{
    
    Node *head1=new Node (-1); //creating head for new linked list which initially poiting to dummy node. 
    Node *ptr=head1;
    Node *curr=head;
    
//step 1: Create a clone list except random pointers.

    while(curr != NULL){ //creating copy of given linked list except random pointers.
        Node *temp=new Node(curr->data);
        ptr->next=temp;
        ptr=temp;
        curr=curr->next;
    }
    ptr->next=NULL; //pointing last node to null.
    
    curr=head; //pointing curr to head.
    head1=head1->next; //shifting head1 from dummy node to its. next.
    ptr=head1; //and again poiting ptr to new head1.
    
//step 2: Change next links between curr and next.

    while(curr != NULL){ //connecting curr's next to ptr and ptr's next to curr.
        Node *temp1=curr->next;
        Node *temp2=ptr->next; //storing curr's next and ptr's next in temp1 and temp2 recspectively, so that we can track remaining linked list nodes.
        
        curr->next=ptr; //pointing curr's next to ptr.
        ptr->next=temp1; //ptr's next to temp1, which is nothing but next of curr node in orginal given linkedl list.
        
        curr=temp1; //now updating curr to temp1. which is next of it in original linked list.
        ptr=temp2; //similarly updating temp2.
    }
    
    curr=head;
    ptr=head1; //now again both pointer pointing to its head.
    
    
//step 3: Connect Random pointer.
    while(curr != NULL){ //connecting random pointer i.e arb.
        if(curr->arb == NULL){ //if curr's random pointer is null then simply mark ptr's random pointer as null.
            ptr->arb=NULL;
        }
        else{
            ptr->arb=curr->arb->next; //else, point ptr's random pointer to curr's random pointer's next, which is nothing but node which is pointed by random pointer of ptr.
        }
        curr=curr->next->next; //updating curr to curr's next's next. 
        
        if(ptr->next != NULL) ptr=ptr->next->next; //similarly for ptr, this if condition is just for last node.
    }
    
    
//step 4: Revert back changes done in step 2.
    curr=head;
    ptr=head1; //now again both pointer pointing to its head.
    while(curr != NULL){ //and again back reconstruct links as original linked list. i.e revert changes did in step 2.
        curr->next=curr->next->next; //now point curr's next to curr's next of next which nothing but next node of curr in original given linked list.
        if(ptr->next != NULL) ptr->next=ptr->next->next; //similarly for ptr. and if condition is just for last node.
        
        ptr=ptr->next; 
        curr=curr->next; //shfiting both pointer to its next node.
    }
    
//step 5: finally return head of new copied linked list.
    return head1;
}

//similar like above but only in three loops.
Node *copyList(Node *head) {
        Node *newHead = NULL;
        Node *temp = head, *tail = NULL;
      
        //copying next pointers.
        while(temp){
            if(newHead == NULL){ 
                newHead = new Node(temp->data);
                tail = newHead;
            }
            else{
                Node *ptr = new Node(temp->data);
                tail = ptr; //now tail is ptr.
            }
            
            Node *q = temp;
            temp = temp->next;
            
            q->next = tail; //creating linke between newly created node and existing node.
            tail->next = temp;
        }

        //now traversing for random pointers.
        temp = head;
        tail = newHead;
        while(temp != NULL){
            
          if(temp->random){
             Node *rand = temp->random;
             tail->random = rand->next;
          } 
           
          temp = temp->next->next;
           
          if(tail->next) tail = tail->next->next;
          else tail = tail->next;
        }
        
        //now removing pointers which are linked as next to temp.
        tail = newHead;
        temp = head;
        
        while(tail){
            temp->next = tail->next;
              
            if(tail->next) 
                tail->next = tail->next->next;
            
            temp = temp->next;
            tail = tail->next;
        }

        return newHead; 
    }




//Approach 2: Soution in O(N) TC using Un_Ordered map.  TC-O(N) SC-O(N)
Node *copyList(Node *head)
    {
        Node *head1=new Node (-1);
        Node *ptr=head1;
        Node *curr=head;
    //step 1: Create a clone list except random pointers.
        while(curr != NULL){
            Node *temp=new Node(curr->data);
            ptr->next=temp;
            ptr=temp;
            curr=curr->next;
        }
        ptr->next=NULL; //pointing last node to null.
        
        curr=head; //pointing curr to head.
        head1=head1->next; //shifting head1 from dummy node to its. next.
        ptr=head1; //and again poiting ptr to new head1.
        
    //step 2: Create mapping equation between orginal node list and clone node list.
        unordered_map<Node *,Node *> mapping; //creating mapping equation between orginal node list and clone node list.
        while(curr != NULL){ 
            mapping[curr]=ptr; //creating mapping between original linked list node and copied linked list node.
            curr=curr->next;
            ptr=ptr->next; //shifting both pointer to its next.
        }
    
    //step 3:Connect Random pointer
        curr=head;
        ptr=head1;
        while(curr != NULL){
            ptr->arb = mapping[curr->arb];  //connecting ptr's random pointer with respective mapping of curr's random pointer.
            curr=curr->next;
            ptr=ptr->next; //shifting ptr and curr to its next
        }

    //step 4: finally return ans.    
        return head1;
    }

//similar like above.
Node *copyList(Node *head) {
        // Write your code here
        Node *newHead = NULL;
        Node *temp = head, *tail = NULL;
        unordered_map<Node*,Node*> ump;
        //copying next pointers.
        while(temp){
            if(newHead == NULL){ 
                newHead = new Node(temp->data);
                tail = newHead;
            }
            else{
                Node *ptr = new Node(temp->data);
                tail->next=ptr;
                tail = ptr;
            }

            ump[temp] = tail; //mapping nodes with address.
            temp = temp->next;
        }

        //now traversing for random pointers.
        temp = head;
        tail = newHead;
        while(temp != NULL){
             tail->random = ump[temp->random];

          tail = tail->next;
          temp = temp->next;
        }

        return newHead; 
    }



//Approach 3: First create linked list without random pointer then with random pointer. TC-O(N*M) SC-O(1)
Node *copyList(Node *head)
    {
        Node *head1=new Node (-1);
        Node *ptr=head1;
        Node *curr=head;
         //step 1: Create a clone list except random pointers.
        while(curr != NULL){
            Node *temp=new Node(curr->data);
            ptr->next=temp;
            ptr=temp;
            curr=curr->next;
        }
        ptr->next=NULL; //pointing last node to null.
        
        curr=head; //pointing curr to head.
        head1=head1->next; //shifting head1 from dummy node to its. next.
        ptr=head1; //and again poiting ptr to new head1.
        
    //step 2: Connect random pointers. Tcfor this loop is N*M.
        while(curr != NULL){ //looping for arbitary pointer (random pointer)
            if(curr->arb == NULL){ 
                ptr->arb=NULL;
            }
            else{
                Node *temp1=head;
                Node *temp2=head1; //pointing both temp nodes to its head respectively.
                while(curr->arb != temp1){ //looping till curr's random pointer not equal to temp node.
                    temp1=temp1->next;
                    temp2=temp2->next; //shifitng both temp, not one temp.
                }
                ptr->arb=temp2; //once loop out that means curren temp2 node is a node which should pointed random pointer of ptr.
            }
            curr=curr->next;
            ptr=ptr->next; //shifting both curr and ptr.
        }

    //Step 3: finally return head.  
        return head1;
    }