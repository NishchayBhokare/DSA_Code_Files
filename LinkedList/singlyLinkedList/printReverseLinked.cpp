// Example for printing linked list in reverse order without reversing linked list.

#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
};

void printReverseLinkedList(Node *head){
    
    if(head==nullptr){  //if list is empty or after recursion when we reach at the last elment then we return call 
     return;
    }
    printReverseLinkedList(head->next); //performing recursion and moving further.
    cout<<head->data;  //after returning one by one we are printing element from last to first.  
}