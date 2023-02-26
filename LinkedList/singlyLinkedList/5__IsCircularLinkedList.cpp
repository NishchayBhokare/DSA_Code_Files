// Example to check whether given linked list is circular or not.
//Coding ninja and GFG.
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    /* data */
};

//Simple version example from gfg. Just check circular or not. i.e last node connected with first or not.
//TC-O(N) SC-O(1)
bool isCircular(node *head)
{
   if(head == NULL) return true; //if head is null then return true.
   node *ptr=head; //pointing ptr to head.
   do{
       ptr=ptr->next; //shifting ptr to its next.
   }while(ptr != NULL and ptr!=head); //looping till ptr not equal to null and also it not equal to head.
   
   if(ptr == head) return true; //if ptr equals ot head that means loop is present
   return false; //else return false.
}



//Approach: slow and fast pointer. TC-O(N) SC-O(1)
bool isCircular(node* head){

    if(head == NULL) return true; //if head is null then linked list is circular.
    if(head->next == NULL) return false; //if head's next equals to null then linked list is not circular.

    node *fast=head; //initialising fast and slow to head.
    node *slow=head;
    do {
      slow = slow->next; //shifting slow pointer by one.
      fast = fast->next->next; //fast by two 
      if (fast == NULL or fast->next == NULL) //if fast or fast's next equals to NULL then simply return false. i.e not circular.
        return false;
    } while (fast != slow); //looping till fast is not equal to slow.

    if (fast == head) //if fast equals slow and also it equals to head that means it is complete circular.
      return true;

    return false; //when fast equals to slow but not equals to head. i.e loop is present in between somewhere in linked list.
}

