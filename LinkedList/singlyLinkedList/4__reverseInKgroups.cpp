// Example for Reverse a singly linked list in k groups.
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    /* data */
};

//Approach 1: Recursive approach. Tc-O(N) SC-O(N)
struct node *reverse (struct node *head, int k)
    { 
        if(head == nullptr or head->next == nullptr ) return head; //if head or its' next is null then simply return head becuase no need to reverse.

        //step 1: reverse first k nodes
        node *prev=nullptr;
        node *curr=head;
        node *forward;
        int i=1;
        while(i<=k and curr !=nullptr){ //looping till i less than or equal to k and also current should not be equal to null.
            forward=curr->next;
            curr->next=prev;
            prev = curr;
            curr=forward;
            i++;
        }
    
        //step 2: calling recursion for further nodes.
        head->next=reverse(forward,k); //forward and current both points to same nodes so pass either curr or forward. //prev node which will returned by recursion call will connected to head's next.
        
        //step 3: return head of reversed list.
        return prev; //and return prev which nothing but head of reversed linked list.
    }


//Approach 2: Iterative approach using stack. Tc-O(N) SC-O(k)
 struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
    stack<node *> st;
    node *headNode;
    node *ptr;
    int sign=1;
    while(head != nullptr){ //Looping till head not reaches to end of node.
        int i=1;
        while(i<=k and head!= nullptr){ //looping till i less than or equal to k and also head should not be equal to null.
           st.push(head);
           head=head->next;
           i++; 
        }
        
       if(sign){ //Enter in if block just one time at the starting.
        ptr=st.top(); //pointing ptr pointer to the node present at top of stack
        headNode=ptr; //also pointing final head node to ptr.
        st.pop(); //popping out top most element.
        }

        while(!st.empty()){ //Looping till stack is not empty
            ptr->next=st.top(); //connecting ptr's next to top of stack node element.
            ptr=ptr->next; //shiftin ptr to its next.
            st.pop(); //popping out element from stack once connected with ptr.
        }
        sign=0; //now sign will be 0 so that control will not enter in if block anymore.
    }
    ptr->next=nullptr; //ptr pointing to last element so connect last element with null.
    return headNode; //and return headNode which points to first element after reversing linked list.
    }