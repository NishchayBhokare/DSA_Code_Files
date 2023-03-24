#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev=NULL; //creating prev pointer of type node.
    Node *next=NULL; //creating next pointer of type Node.

    Node(int data){ //creating constructor to initialise data member of Node.
        this->data=data;
    }
};

void traverse(Node *head){

   Node *ptr=head;
    do{ //using do while loop to escape from first iteration because initially ptr pointing to head.
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=head); //looping till we not reach till head again.
   cout<<endl;
}
void traverseFromBack(Node *head){
    Node *ptr=head->prev;
    do{ //Looping till head not reach till the last node.
        cout<< ptr->data<<" ";
        ptr=ptr->prev; //shifting head to its next.
    }while(ptr != head->prev); cout<<endl;
}

void InsertAtTheBegining(Node * &head,int data){
    Node * temp=new Node(data); //creating new node with provided data.
    temp->prev=head->prev;
    head->prev->next=temp; //This is new line need to add i.e pointing last node's next to new node.(in CDL)
    temp->next=head; //pointing new node's next  to head node.
    head->prev=temp; //connecting heads previous to temp.
    head=temp; //and we want head on new node so finally point head on new node.
}

void InsertAfterNode(Node *second,int data){
    Node * temp=new Node(data); //creating new node.
    temp->prev=second; //pointing temps'prev to second.
    temp->next=second->next; //pointing new node's next to given node's next.
    second->next->prev=temp; //pointing second's next's prev to the temp.
    second->next=temp; //and connecting given node to new node.
}

void InsertAtTheEnd(Node *&head, int data){ //taking through reference variable so that automatic changes will happen in original head.
    // Node *ptr=head;
    // while(ptr->next != NULL){ //looping till we not reach to tha last node.
    //     ptr=ptr->next;
    // }

    Node *temp=new Node(data); //Creating a new node.
    // ptr->next=temp; //linking that node to last node in given linked list.
    // temp->prev=ptr; //pointing temp's previous to ptr.

    // temp->next=NULL; //and pointing that new node to null. (No need to do expicitly because while creating node, we initialise next pointer to the null.)

    head->prev->next=temp; //Even without iterating to last node we can perform operation to insert at last node. //here pointing last node'next pointer to temp.
    temp->next=head; //pointing temp's next to head.
    temp->prev=head->prev; //connecting temp's prev to head's prev.
    head->prev=temp; //and finally pointing head's prev to temp.
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
    temp->prev=ptr; //pointing temp's prev to ptr.
    temp->next=ptr->next; //pointing new nodes next to ptr's next.
    ptr->next->prev=temp; // pointing ptr's next nodes prev to the temp.
    ptr->next=temp; //connecting ptr to new node.
}


//Deletion.
void DeleteAtTheBegining(Node *&head){
    Node *ptr=head; //creating new node pointer which pointing to head.
    head->prev->next=head->next; //pointing last node's next to head's next.
    head=head->next; //shifting head to its next as we want to delete first node.
    head->prev=head->prev->prev; //pointing head's prev to head's prev of prev. i.e to last node.
    delete ptr; //deleting ptr. i.e nothing but first node.
    //and remember head is reference variable so all changes are happining in original head.
}

void DeleteAtIndex(Node *&head , int index){
    if(index == 0){ //if index is zero then call delete at the begining function to handle this index 0 case.
        DeleteAtTheBegining(head);
        return;
    }
    Node *first=head; //creating first pointer which at the end points to previous node i.e node which will going to delete.
    Node *second=head->next; //creating second point  er which will points to node that will delete.
    index--; //decrement index.
    while(index > 0){
        first=first->next; //shifting both first and second.
        second=second->next;
        index--;
    }
    first->next=second->next; //finally connecting first's next to second next so that we can delete second.
    second->next->prev=first; //pointing second's next's prev to the first as we are going to delete second.
    delete second; //deleting second.
}

void DeleteAtTheLast(Node *&head){ 
    Node*ptr=head->prev;
    head->prev->prev->next=head; //pointing second last nodes' next to head.
    head->prev=head->prev->prev; //pointing head's prev to second last node.
    delete ptr; //deleting ptr's i.e last node.
}

void DeleteAtValue(Node *&head, int key){
    if(head->data == key){ //handling case when key element is first element in linked list.
       DeleteAtTheBegining(head);
       return;
    }
    Node *first=head;
    Node *second=head->next;
    while(second!=NULL){ //looping till second pointer not reaches to null. 
        if(second->data == key){ //if second's data equals to key then,
            first->next=second->next; //pointing first's next pointer to second's next.
            second->next->prev=first; //then pointing seconds next's previous to the first.
            delete second; //deleting second.
            return; //returning as we dont need to iterate further.
        }
        first=first->next; //shifting first to its next.
        second=second->next; //similary second.
    }
    cout<<"Element is not present in given linked list "<<endl; //if we reach till here then element is not present in linked list.
}

int main(){
    Node *head=new Node(5); //creation of pointer of type Node in STACK(static memory) and allocating memory for linked list nodes in HEAP(dynamic memory).
    Node *second=new Node(9);
    Node *third=new Node(7);
    Node *fourth=new Node(2);

    head->prev=fourth; //Connnecting linked list nodes.
    head->next=second; 
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    fourth->next=head; //pointing last node to NULL so that we can get linked list is end.

    cout<<"Traversing ";
    traverse(head); //Traversing L to R
    cout<<"Traversing from back ";
    traverseFromBack(head); //Traversing R to L.

// Insertion
    // InsertAtTheBegining(head,8); //Inserting node at the beginning or inserting at the head.
    // InsertInBetween(head,2,6); //Inserting at given index.
    // InsertAtTheEnd(head,3); //Inserting at the end of linked list.
    // InsertAfterNode(fourth,1); //Inserting after given node, for example if given node is second node then new node will insert after second node i.e on third node.

    // cout<<endl<<"After insertion in linked list "<<endl;
    // cout<<"Traversing ";
    // traverse(head); //Traversing L to R
    // cout<<"Traversing from back ";
    // traverseFromBack(head); //Traversing R to L.


//Deletion
    // DeleteAtTheBegining(head);
    // DeleteAtIndex(head,0);
    // DeleteAtTheLast(head);
    DeleteAtValue(head,2);

    cout<<endl<<"After deletion in linked list "<<endl;
    cout<<"Traversing ";
    traverse(head); //Traversing L to R
    cout<<"Traversing from back ";
    traverseFromBack(head); //Traversing R to L.    
}