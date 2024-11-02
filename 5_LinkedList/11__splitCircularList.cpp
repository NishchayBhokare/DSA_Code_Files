//Split a Circular Linked List into two halves
//GFG
#include<unordered_map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};

//Apporach 1: using slow fast apporach
pair<Node *, Node *> splitList(struct Node *head) {
        
        
        struct Node *slow = head, *fast = head;
        while(fast->next != head and fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        } //we pointed slow to middle element of list.
        
        Node *secondHead = slow->next; //from slow's next..second heaad started
        slow->next = head; //now slow's next should be it's head.
        
        Node *ptr = secondHead; //creating ptr pointer which points to secondhalf.
        while(ptr->next != head){
            ptr = ptr->next; //move to next. 
        }
         ptr->next = secondHead; //now last point next equals to start of second half.
         
        return {head,secondHead}; //return ans;
    }

//Approach 2: question is updated: first calculate length.
//then point tell of first half to head and traverse for second half and point second half tail to second half head.
 pair<Node *, Node *> splitList(struct Node *head) {
        pair <Node *,Node *> ans;
        
        int len = 0;
        struct Node *temp = head;
        do{ //calculating length of linked list.
            len++;
            temp = temp->next;
        }while(temp != head);
        
        
        int mid;
        if(len%2 == 0) mid = (len/2) - 1; //doing -1 because while traversing...mid need to reduce by 1.
        else mid = (len/2);
        
        temp = head;
        while(mid--){ //moving for first half.
            temp = temp->next;
        }
        
        struct Node *headSecondHalf = temp->next; //point second half head to first half tail's next.
        temp->next = head; //now point first half tail to head.
         
        struct Node *ptr = headSecondHalf; //traverse for second half.
        while(ptr->next != head){
            ptr=ptr->next;
        }
        ptr->next = headSecondHalf; //point second half tail to second half head.

        //   pair <Node *,Node *> ans =  make_pair(head,headSecondHalf);
        ans.first = head; 
        ans.second = headSecondHalf;
        
        return ans; //return ans;
    }

//Approach 1: Most optimised approach. TC-(N) SC-O(1)
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