// Example for remove duplicate element from sorted linked list.
//GFG
#include<map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Most optimised approach. Using slow and fast pointer. TC-(n) SC-O(1)
Node *removeDuplicates(Node *head)
{
  if(head == NULL or head->next==NULL) return head; //IF list is empty or have single element then simply return head. no need to check for duplicate element.

    Node *ptr=head; //pointing ptr to head.
    while(ptr->next != NULL){ //looping till ptr's next not equal to head.
        if(ptr->data == ptr->next->data){ //checking ptr's data equals to its next's data or not.
            Node *temp=ptr->next; //if equals then store ptr's next node to temp node.
            ptr->next=ptr->next->next; //point ptr's next to ptr's next next.
            delete temp; //and delete that duplicate element.
        }
        else ptr=ptr->next; //if not equals then simply shift ptr to its next.
    }
return head; //returning head.
}
