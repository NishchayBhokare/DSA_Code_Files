//Example for merge sort using linked list.
//GFG

//Approach 1: Optimised approach TC-O(Nlogn) SC-O(logn)
Node * findMid(Node *head){ //finding mid of linked list.
        Node *slow=head;
        Node *fast=head->next;
        while(fast != NULL and fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node *left, Node *right){ //similar approach like we solve in merging two sortedl linked list.
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        Node *ans=new Node(-1); //creating dummy node
        Node *tail=ans;
        
        while(left != NULL and right != NULL){  //looping till both not equal to null.
            if(left->data <= right->data){ //if lest's data less than right data
                tail->next=left; //connecting left node to tail's next.
                tail=tail->next;
                left=left->next;
            }
            else{
                tail->next=right; //similarly for connecting right node to tails next.
                tail=tail->next;
                right=right->next;
            }
        }
        
        while(left != NULL){ 
            tail->next=left;
            tail=tail->next;
            left=left->next;
        }
        while(right != NULL){
            tail->next=right;
            tail=tail->next;
            right=right->next; 
        }
        
        ans=ans->next; //shiting ans to its next. because ans pointing to dummy node.
        return ans; //return ans which is pointing to head of merged linked list.
    }


Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) return head; //if head is null or head's next is null then return head.
    
    Node* mid=findMid(head); //finding middle node of linked list.
    
    Node *left=head; //pointing left to head.
    Node *right=mid->next; //mid's next.
    mid->next=NULL; //mid's next equals to null that is pointing last node to mid's next.
    
    left=mergeSort(left); //dividing left part of linked list.
    right=mergeSort(right); //dividing right part of linked list.
    
    Node *ans=merge(left,right); //merging both linked list.
    return ans; //merged linked list.
}