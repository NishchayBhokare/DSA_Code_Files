//leetcode
//Approach 1: Using only single traversal. TC-O(N) SC(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *prev=NULL, *slow=head, *fast=head;

    for(int i=1; i<=n; i++){
        fast=fast->next;
    }

    while(fast){ //looping till fast not became null.
        prev=slow;
        slow = slow->next;
        fast = fast->next;
    }

    if(prev == NULL) //if this is true that means we're trying to delete first node. prev becomes true only if we were not able to enter in while loop.
        return head->next; //then just return head's next.

    else{ //deleting nodes in between.
        prev->next = slow->next;
        delete slow;
        return head; //then return head.
    }

}


//Approach 2: using double traversal TC-O(N) SC-O(1)
   int getLen(ListNode *head){

        int len = 0;
        while(head){
            head = head->next;
            len++;
        }

        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = getLen(head); //first calcualte length.
      
        int k=len-n; 
        if(k==0) return head->next; //if k is zero that means we're talking about deleting first node.
        
        ListNode *temp = head, *prev=head;

        while(k--){ //loop till k greater than zero.
            prev=temp;
            temp=temp->next; 
        }

        prev->next = temp->next; //at the end. temp will points to node to be delete. and prev will points to previous node.

        delete temp; then delete temp.

        return head; //and return head.
    }