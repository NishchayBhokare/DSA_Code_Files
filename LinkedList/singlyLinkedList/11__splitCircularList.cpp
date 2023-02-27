//Split a Circular Linked List into two halves
//GFG
#include<unordered_map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Most optimised approach. Using map. TC-(N) SC-O(N)
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *first=head; //initially pointing first to head and second to head's next so that in both odd and even cases, first pointer will point to last node of first half of linked list.
    Node *second=head->next;

    while(second !=head and second ->next != head){ //looping till second not equal to head and second's next not equal to head.
        first=first->next;
        second=second->next->next; //shifting first one time and second two time.
    }
    
    *head1_ref=head; //pointing given head1 to head.
    *head2_ref=first->next; //and head2 to first's next, because first's next node will be the starting node for seocn linked list.

    first->next=head; //Pointing first linked list's last node to head.
    
    Node *ptr= *head2_ref; //pointing ptr to starting node of second linked list.
    while(ptr->next != head){ //looping till ptr's next not equal to head.
        ptr=ptr->next; 
    }
    ptr->next = *head2_ref; //once we reached to last node, then connect ptr's next to start of second linked list. ie. head2.
}

//Input
//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.