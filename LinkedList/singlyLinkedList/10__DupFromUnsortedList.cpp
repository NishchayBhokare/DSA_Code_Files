// Example for remove duplicate element from Unsorted linked list.
//GFG
#include<unordered_map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Most optimised approach. Using map. TC-(N) SC-O(N)
 Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head == NULL or head->next == NULL) return head;

    Node *ptr=head;
    Node *prev;
    unordered_map<int,bool> visited; //creating unordered map of type int and bool which hold data of linked list and true or false. Unordered map is used because it searches element in ordered of 1. and normal map searches in logn.

    while(ptr != NULL){
        if(visited[ptr->data] == true){ //before marking as true, checking whether it is already true or not. if yes then current element is duplicate element, if not,then marked as true in else statement.
            prev->next=ptr->next; //pointing prev's next to ptr's next.
            delete ptr; //deleting ptr.
            ptr=prev->next; //little optimised. i.e then poiting ptr to prev's next node.
        }
        else{ //if element is not marked as true, then marked it as true.
            visited[ptr->data] = true;  //marking true.
            prev=ptr; //pointing prev to ptr.
            ptr=ptr->next; //and shifting ptr to it's next for further execution.
        }
    }
    return head;
}


//Approach 2: Brute force solution. Using map. TC-(n2) SC-O(1)
//Analogy: taking two loops checking for every element and if element is found as duplicate then connect previous node to duplicate's next node.
Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL or head->next == NULL) return head;

    Node *ptr=head;
    while(ptr!=NULL and ptr->next!=NULL){

        Node *temp=ptr->next;
        Node *prev=ptr; //creating prev pointer which will point to previous node of duplicate element so that we can connect it to next of duplicate node.
        while(temp != NULL){
            if(ptr->data == temp->data){ //if duplicate then delete that node.
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
            } 
            else{
                prev=temp;  //if not duplicate then point prev to temp and shift temp to next iteration.
                temp=temp->next;
            }
        }
        ptr=ptr->next;
    }
    return head;
}