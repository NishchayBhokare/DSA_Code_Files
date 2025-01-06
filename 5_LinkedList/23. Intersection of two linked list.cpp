//Leetcode.
//we have to find intersection of two linked list (same reference not value).

//Approach 1: TC-O(N+M) SC-O(1). Optimised approach. if we reduced extra nodes from any bigger linked list.
//then at the end we will just shift ony by one. and will return answer once meet at one point.
int getLen(ListNode *head){
    int len = 0;
    while(head){
        head=head->next;
        len++;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int len1 = getLen(headA);
    int len2 = getLen(headB);

    ListNode *bigger = headA, *smaller = headB; //initially assuming bigger is first linked list and second is smaller.

    int extraNodes=len1-len2; //considering first linked list is greater.

    if(len2 > len1){ //if second is greater in length. then intercahnge values.
        bigger = headB;
        smaller=headA;  
        extraNodes=len2-len1;
    }

    while(extraNodes--){ //skip starting extra nodes from bigger size linked list.
        bigger=bigger->next;
    }

    //now shift one by one.
    while(smaller && bigger){

        if(smaller == bigger) //once meet at one point of reference then retur smaller. or bigger
            return smaller;
        
        smaller = smaller->next;
        bigger = bigger->next;
    }

    return NULL; //if not meet then return null. NO intersection point.
}