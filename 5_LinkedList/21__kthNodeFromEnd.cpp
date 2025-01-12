//find kth node from end in linked list
// link-
    // https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

struct Node
    {
        Node *next;
        int data;
    };

//Approach 1: Optimised approach Using single traversal. TC-O(N) SC-O(1)
int getNthFromLast(Node *head, int n)
{
       // Your code here
      Node *curr=head;
      
      while(n--){ //looping till n not gets 0.
          if(curr == NULL) return -1; //if curr reaches till null that means value of n is greater than length of node
          curr=curr->next;
      } //at the end of loop curr will point to n+1 th node.
      
      Node *nthNode=head; //Initially pointing both pointer to head node.
      while(curr != NULL){ //looping till curr not gets null.
          curr=curr->next;
          nthNode=nthNode->next; //now shifting both pointers, nth node pointing to head and curr pointing to n+1th node initially
          //we have got the nth node from end in second pointer since the first 
          //pointer had already traversed n nodes and thus had difference of n 
          //nodes with second pointer. i.e first we traverse for curr n times, so our curr pointer will be n times ahead from nthNode pointer so when we reach to curr equals to null condition, then our nthNode pointer will point node curr-nth node 
          //i.e len-n+1th node
      }
      
      return nthNode->data;
}

//Approach 2: TC-O(N) SC-O(1)
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