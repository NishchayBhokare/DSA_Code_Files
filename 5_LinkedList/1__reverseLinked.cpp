// Example for Reverse a single linked list.
//GFG
// link-
    // https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    /* data */
};

//Total 5 approaches.    
//Approach 1: Most optimised approach Iterative way. Tc-O(N) SC-O(1)
struct Node* reverseList(struct Node *head)
{
    //Here we are creating three pointers to point the nodes.
    struct Node *current=head;  //Initially current pointer pointing to the head.
    struct Node *prev=nullptr;  //Previous pointer pointing to the nullptr.
    struct Node *next; 
    while(current!=nullptr){
        next=current->next; //next pointer Pointing to the next node of current so that we can get access when current pointer points to different node.
        current->next=prev; // now current pointing to the previous node so that link will get reversed.
        prev=current; // now prev = current so that current can move further.
        current=next; // current is equal to the next node.
    }
    return prev; //returning prev which is pointing to the first node of linked list after get reversed.
}


//Approach 2: Recursive way TC-O(N) SC-O(n).
 Node * solve(Node *curr,Node *prev,Node *forward){
    if(curr == nullptr) return prev;
    
    forward=curr->next; //exactly performing same opration as iterative way.
    curr->next=prev;
    prev=curr;
    curr=forward;
    return solve(curr,prev,forward); //calling for next recursive call.
}

 struct Node* reverseList(struct Node *head)
{
    if(head == nullptr or head->next==nullptr) return head;
    Node *curr=head;
    Node *prev=nullptr;
    Node *forward;
    return solve(curr,prev,forward);
}



//Approach 3: More efficient another approach as apporach shown in 2. TC-O(N) SC-O(n).
//Looping till last node and then connecting curr to prev node one by one.
 void solve1 (Node *&head , Node *prev, Node *curr){ //passing head as pass by reference.
    if(curr== nullptr){
        head=prev; //pointing head to prev and head is passed by reference.
        return;
    }
    solve1(head,curr,curr->next); //looping till last node by shifting prev and current node.
    curr->next=prev; //once reaches to last node then connect that current node to previous node. ans so on.
}
 struct Node* reverseList(struct Node *head)
{
    if(head == nullptr or head->next==nullptr) return head;
    Node *prev=nullptr;
    Node *curr=head;
    solve1 (head,prev,curr);
    return head;
}



//Approach 4: Using only head. TC-O(N) SC-O(n).
//Looping till last node and connecting nodes links between head and chotaHead.
Node *solve2(Node *head){
    if(head == nullptr or head->next==nullptr) return head;
    
    Node *chotaHead=solve2(head->next); //looping till last and returning last node and chotaHead.
    head->next->next=head; //pointing current head's next's next to head. i.e pointing next node of head to the head i.e head is act as previous node.
    head->next=nullptr; //and head's next to NULL.
    
    return chotaHead; 
}
struct Node* reverseList(struct Node *head)
{
    if(head == nullptr or head->next==nullptr) return head;
    return solve2(head);
}


//Approach 5: Iterative approach using stack i.e extra space TC-O(N) SC-O(n)
struct Node* reverseList(struct Node *head)
{
    if(head == nullptr or head->next==nullptr) return head;

    stack <Node*> st; //creating stack of Node * type.
    while(head->next !=nullptr){ //looping till we not reached last node
        st.push(head); //one by one pushing nodes in stack.
        head=head->next; //shifting head's next.
    }

    Node *ptr=head; //now head and ptr both pointing to last node in linked list.
    while(!st.empty()){ //looping till stack is not empty.
        ptr->next=st.top(); //connecting ptr's next to top element of stack.
        ptr=ptr->next; //shifting ptr to its next.
        st.pop(); //popping out stack element for next iteration.
    }
    ptr->next=nullptr;
    return head;
};