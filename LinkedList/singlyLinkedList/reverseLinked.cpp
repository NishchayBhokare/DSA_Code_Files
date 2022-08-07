// Example for Reverse a single linked list.
// link-
    // https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
    struct Node
    {
        Node *next;
        /* data */
    };
    

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
