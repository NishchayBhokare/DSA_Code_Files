// Example for Reverse a single linked list.
//GFG
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    /* data */
};

//Approach 1: Most optimised approach Iterative way. Tc-O(N) SC-O(1)
Node* reverseDLL(Node * head)
{
    Node *curr=head;
    Node *previous=NULL;
    Node *forward;
    while(curr != NULL){
        forward=curr->next;
        curr->next=previous; 
        curr->prev=forward; //This is extra step only need to add in case of doubly linked list.
        previous=curr;
        curr=forward;
    }
    return previous;
}

//Approach 2: Recursive way TC-O(N) SC-O(n).
Node * solve(Node *curr,Node *previous,Node *forward){
    if(curr == nullptr) return previous;
    
    forward=curr->next; //exactly performing same opration as iterative way.
    curr->next=previous;
    curr->prev=forward; // extra step which added.
    previous=curr;
    curr=forward;
    return solve(curr,previous,forward); //calling for next recursive call.
}
Node* reverseDLL(Node * head)
{
    if(head == nullptr or head->next==nullptr) return head;
    Node *curr=head;
    Node *prev=nullptr;
    Node *forward;
    return solve(curr,prev,forward);
}


//Approach 3: More efficient another approach as apporach shown in 2. TC-O(N) SC-O(n).
//Looping till last node and then connecting curr to prev node one by one.
void Solve(Node *&head,Node *curr,Node *previous){
    if(curr == nullptr) {
        head=previous;
        return;
    }
    
    Solve(head,curr->next,curr);
    curr->prev=curr->next; //This is extra step in which we pointing current's prev to current next to reverse.
    curr->next=previous; //and current next to previous node.
}
Node* reverseDLL(Node * head)
{
    if(head == nullptr or head->next==nullptr) return head;
    Node *curr=head;
    Node *previous=nullptr;
    Solve(head,curr,previous);
    return head;
}


//Approach 4: Using only head. TC-O(N) SC-O(n).
//Looping till last node and connecting nodes links between head and chotaHead.
Node * solve2(Node *head){
    if(head->next == NULL ) {
        head->prev=head->next; //once reached to last node then connecting last nodes prev to null. i.e its next.
        return head; // returning head.
    }
    
    Node *headNode = solve2(head->next);
    head->next->next = head; 
    head->prev=head->next; //pointing head's prev to it's next, this is extra step we need to add.
    head->next=NULL;
    return headNode;
}

Node* reverseDLL(Node * head)
{
    if(head == nullptr or head->next==nullptr) return head;
    return solve2(head);
}


//Approach 5: Iterative approach using stack i.e extra space TC-O(N) SC-O(n)
struct Node* reverseList(struct Node *head)
{
       
    stack<Node*>st;
    while(head->next !=NULL){
        st.push(head);
        head=head->next;
    }

    Node *ptr=head;
    while(!st.empty()){
        ptr->prev=ptr->next; //this is extra step in which connecting ptr's previous to it's next.
        ptr->next=st.top();
        ptr=ptr->next;
        st.pop();
    }
    ptr->prev=ptr->next; //lastly also connecting ptr's previous to its next for last node.
    ptr->next=NULL;
    return head;
};