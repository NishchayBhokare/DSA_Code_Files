//Split a Circular Linked List into two halves
//GFG
#include<unordered_map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Without replacing data.  TC-(N) SC-O(1) 
Node* segregate(Node *head) {
        
        // Add code here
        Node *zeroHead=new Node(-1);
        Node *oneHead=new Node(-1);
        Node *twoHead=new Node(-1); //creating threee dummy node so that we can connect 0,1 and 2 nodes to its next respectively.

        Node *p=zeroHead,*q=oneHead,*r=twoHead; //pointer p,q,r will act as tail of zeroHead,oneHead and twoHead respectively.
        Node*ptr=head; //pointing ptr to head.
        while(ptr != NULL){ //looping till ptr not equal to head.
            if(ptr->data == 0){ //if ptr's data equals to 0.
                p ->next = ptr; //then, connect p's next to ptr i.e tail of zeroHead's next to ptr.
                p=p->next; //and shift p to its next.
            }
            else if(ptr->data == 1){ //similarly for 1.
                q->next=ptr;
                q=q->next;
            }
            else{
                r->next=ptr; //and similarly for 2.
                r=r->next;
            }
            ptr=ptr->next;
        }
        
    //Now, Merging linked list.
    r->next=NULL;  //pointing r's next to null i.e tail of twohead to null.
    if(q->data != -1) { //if one nodes are exist. then simply do normal operation
        p->next=oneHead->next; //i.e connect p's next to oneHead's next.
        q->next=twoHead->next; //q's next to twoHead's next.
    }
    
    else if(q->data == -1){
        p->next=twoHead->next; //if one heads are not exist, then connect p's next to directly twohead's next.
    }
    
    //connecting head to zerohead's next because now zeroHead's next will be the starting node of sorted linked list.
    head=zeroHead->next;
    
    // delete dummy nodes;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head; //returning answer.
    }



//Approach 2: By replacing data. TC-(N) SC-O(1)
//Counting approach.
 Node* segregate(Node *head) {
        
        // Add code here
        int zeros=0;
        int ones=0;
        Node *ptr=head;
        while(ptr != NULL){
            if(ptr->data == 0) zeros++;
            else if(ptr->data == 1) ones++;
            ptr=ptr->next;
        } //looping over linked list and count 0's, 1's and remaining will be 2.

        ptr=head;
        while(ptr !=NULL){
            if(zeros > 0){ //till zeros and greater than 0, change ptr's data to 0.
                ptr->data=0;
                zeros--; //decrementing zeros.
            }
            else if(ones > 0){ //similarly for one.
                ptr->data=1;
                ones--;
            }
            else{ //and for whatever nodes are remaining, for all nodes marked data as 2.
                ptr->data=2;
            }
            ptr=ptr->next; //shift ptr to it's next.
        }
        
     return head; //returning ans.
    }