// Example for Reverse a single linked list.
// link-
    // https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

struct Node
    {
        Node *next;
        int data;
    };

int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *current=head; //pointing current node to the head node.
       int count=0; 
       while(current!=nullptr){ //looping whole linked list.
           current=current->next;
           count++; //used count for getting size of linked list at the end of while loop.
       }
       if(n>count){ //if kth index(n) is greater than size then this is not valid.
           return -1; //return -1.
       }

       current=head; //now again current pointing to the head node.
       for(int i=0;i<count-n;i++){ //looping from start of linked list to the count-n. for eg. if n=2 and count=6 then loop will execute from 0 to 3 to get 4th element from start and 2nd element from end. 
           current=current->next;
       }
       return current->data; //returning data or kth element.
      
}