#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next=NULL; //creating pointer of type Node.

    Node(int data){ //creating constructor to initialise data member of Node.
        this->data=data;
    }
};

void traverse(Node *head){
    while(head != NULL){ //Looping till head not reach till the last node.
        cout<< head->data<<" ";
        head=head->next; //shifting head to its next.
    } cout<<endl;
}

void InsertAtTheBegining(Node * &head,int data){
    Node * temp=new Node(data); //creating new node with provided data.
    temp->next=head; //pointing new node's next  to head node.
    head=temp; //and we want head on new node so finally point head on new node.
}

void InsertAfterNode(Node *second,int data){
    Node * temp=new Node(data); //creating new node.
    temp->next=second->next; //pointing new node's next to given node's next.
    second->next=temp; //and connecting given node to new node.
}

void InsertAtTheEnd(Node * &head, int data){ //taking through reference variable so that automatic changes will happen in original head.
    Node *ptr=head;
    while(ptr->next != NULL){ //looping till we not reach to tha last node.
        ptr=ptr->next;
    }

    Node *temp=new Node(data); //Creating a new node.
    ptr->next=temp; //linking that node to last node in given linked list.
    temp->next=NULL; //and pointing that new node to null. (No need to do expicitly because while creating node, we initialise next pointer to the null.)
}

void InsertInBetween(Node *&head,int index,int data){
    if(index == 0) {
        InsertAtTheBegining(head,data); //if index is 0 then we need to insert at first index so call insert at the beginning function.
        return;
    }
    Node *ptr=head; //pointing ptr to head.
    index--; //decrement index by 1 because if index 3 then we need to iterate 2 times to insert node at index 3.(because we want ptr pointer on 2nd node so that we can connect it to new node.)
    while(index > 0){
        ptr=ptr->next; //looping till index is greater than 0.
        index--;
    }
    Node *temp=new Node(data); //creating node.
    temp->next=ptr->next; //pointing new nodes next to ptr's next.
    ptr->next=temp; //connecting ptr to new node.
}


//Deletion.
void DeleteAtTheBegining(Node *&head){
    Node *ptr=head; //creating new node pointer which pointing to head.
    head=head->next; //shifting head to its next as we want to delete first node.
    delete ptr; //deleting ptr. i.e nothing but first node.
    //and remember head is reference variable so all changes are happining in original head.
}

void DeleteAtIndex(Node *&head , int index){
    if(index == 0){ //if index is zero then call delete at the begining function to handle this index 0 case.
        DeleteAtTheBegining(head);
        return;
    }
    Node *first=head; //creating first pointer which at the end points to previous node i.e node which will going to delete.
    Node *second=head->next; //creating second pointer which will points to node that will delete.
    index--; //decrement index.
    while(index > 0){
        first=first->next; //shifting both first and second.
        second=second->next;
        index--;
    }
    first->next=second->next; //finally connecting first's next to second next so that we can delete second.
    delete second; //deleting second.
}

void DeleteAtTheLast(Node *&head){ 
    //we can use first and second like two pointer to delete last node but by taking one pointer also we can perform this execution.
    Node *ptr=head;
    while(ptr->next->next != NULL){ //looping till ptr not points to previous node to the last node.
        ptr=ptr->next;
    }
    delete ptr->next; //deleting ptr's next i.e last node.
    ptr->next=NULL; //pointing ptr's next to null.
}

void DeleteAtValue(Node *&head, int key){
    if(head->data == key){ //handling case when key element is first element in linked list.
       DeleteAtTheBegining(head);
       return;
    }
    Node *first=head;
    Node *second=head->next;
    while(second!=NULL){
        if(second->data == key){
            first->next=second->next;
            delete second;
            return;
        }
        first=first->next;
        second=second->next;
    }
    cout<<"Element is not present in given linked list "<<endl;
}

int main(){
    Node *head=new Node(5); //creation of pointer of type Node in STACK(static memory) and allocating memory for linked list nodes in HEAP(dynamic memory).
    Node *second=new Node(9);
    Node *third=new Node(7);
    Node *fourth=new Node(2);

    head->next=second; //Connnecting linked list nodes.
    second->next=third;
    third->next=fourth;
    fourth->next=NULL; //pointing last node to NULL so that we can get linked list is end.

    traverse(head); //Traversing

// Insertion
    // InsertAtTheBegining(head,8); //Inserting node at the beginning or inserting at the head.
    // InsertInBetween(head,0,6); //Inserting at given index.
    // InsertAtTheEnd(head,3); //Inserting at the end of linked list.
    // InsertAfterNode(second,1); //Inserting after given node, for example if given node is second node then new node will insert after second node i.e on third node.

    // cout<<"After insertion in linked list "<<endl;
    // traverse(head);


//Deletion
    DeleteAtTheBegining(head);
    // DeleteAtIndex(head,2);
    // DeleteAtTheLast(head);
    // DeleteAtValue(head,3);

      traverse(head);


    
}