// Example for merge two linked list.
// link-
// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// this is efficient soln which is (in-place) i.e SC- O(1) TC-O(n+m).
Node *sortedMerge(Node *head1, Node *head2)
{
    // In this example we are using tail pointer which will merge head1 and head2.
    Node *ans, *tail; // creating two pointers of node.
    if (head1->data < head2->data)
    { // if head1's data < head2's data then simply we will assing ans and tail to head1.
        ans = head1;
        tail = head1;
        head1 = head1->next; // moving to head's next.
    }
    else
    { // similarly if head2 is small.
        ans = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL and head2 != NULL)
    { // looping head1 and head2 not equal to NULL.
        if (head1->data < head2->data)
        {                        // if head1's data < head2's data then enter in if block
            tail->next = head1;  // pointing tail's next to head1.
            tail = head1;        // now updating tail to head.
            head1 = head1->next; // moving head1 to next node.
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    { // when head1 contains elment but head2 not.
        tail->next = head1;
    }
    else
    { // similary if head2 contains but head1 is null.
        tail->next = head2;
    }
    return ans;
}



// this is one kind of soln which is not (in-place) cause this used space i.e SC- O(n+m) TC-O(n+m).
 Node* sortedMerge(Node* head1, Node* head2)
 {
   Node *dummy=new Node(0); //creating dummy named pointer object of node class and initialzing it with one node which contain data 0.
   Node *ans=dummy; //creating node pointer which points to head of dummy so that we can return it.
   while(head1 !=NULL and head2 !=NULL){ //looping till both are not NULL.
   if(head1->data < head2->data){ //if head1's data is less than head2's data then we will enter.
       dummy->next=head1; //pointing dummy's next to head1.
       dummy=head1; //updating pos. of dummy to head1.
       head1=head1->next; //moving head1 to its next so that we can compare.
   }
   else{ //similar process when head2 is small than head1.
       dummy->next=head2;
       dummy=head2;
       head2=head2->next;
      }
   }

  if(head1 != NULL and head2 == NULL) { //when head1 contains elment but head2 not.
      dummy->next = head1; //in this time simply attach head1 to dummy's next.
  }
  else{ //similary if head2 contains but head1 is null.
      dummy->next = head2;
  }

  return ans->next; //returning ans which points to dummy so we will return ans->next.
  //to escape from 0 data node.
}
