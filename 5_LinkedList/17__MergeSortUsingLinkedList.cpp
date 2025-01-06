//Example for merge sort using linked list.
//GFG

//Approach 1: Approach using finding mid manually. TC-O(logN(N+N/2) i.e NlogN) SC-O(logn(recursive space.))
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
        
        Node *dummy=new Node(-1); //creating dummy node
        Node *tail=dummy;
        
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
        
        if(left) tail->next=left;
        if(right) tail->next=right;
        
        Node *newHead = dummy->next; //creation of new head of sorted linked list.
        return newHead; //return newhead. which is pointing to head of merged linked list.
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


//Appraoch 2: using unorderd map finding mid. so TC-O(NLogN) SC-O(N)
Node * mergeTwoSortedLinkedList(Node *head1, Node *head2){
    
    //merge two sorted linked list.
    Node *dummy = new Node(-1);
    Node *tail = dummy;
    
    while(head1 && head2){
        
        if(head1->data <= head2->data){
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    
    if(head1) tail->next = head1;
    if(head2) tail->next = head2;
    
    
    Node *newHead = dummy->next; 
     
    return newHead; //return newHead which is head of merged sorted list.
}

Node * mergeSortLinkedList(int low, int high, Node *head, unordered_map<int,Node*>&indexToNode){
    
    //base case.
    if(head->next == NULL) return head;
    
    int mid=low+(high-low)/2;
    
    Node *head1 = head;
    Node *tail1 = indexToNode[mid]; //get middle from map.
    tail1->next = NULL;
    
    Node *head2 = indexToNode[mid+1];
    
    //go to left part.
    head1 = mergeSortLinkedList(low,mid,head1,indexToNode);
    
    //go to right part.
    head2 = mergeSortLinkedList(mid+1,high,head2,indexToNode);
    
    
    //merge two sorted linked list.
    return mergeTwoSortedLinkedList(head1,head2);
}

Node* mergeSort(Node* head) {
    // your code here
    unordered_map<int,Node*>indexToNode;
    
    Node *temp = head;
    int i=0;
    while(temp){ //creation of index to node mapping. so that we can get middle node.
        indexToNode[i++] = temp;
        temp=temp->next;
    }
    
    int low=0, high=i-1;
    return mergeSortLinkedList(low,high,head,indexToNode);
}