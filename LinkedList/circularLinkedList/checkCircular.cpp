#include <iostream>
using namespace std;
//Circular linked list
class Node
{
public:
    int data;
    Node *next;
};

void Traversing(Node *head)
{
    // int count=0;
    Node *ptr=head;
    do {
        cout << ptr->data << " ";
        // count++;
        ptr = ptr->next;
    }
    while (ptr!=head);
   
    // cout<<count;
}


 void isCircular(Node *head)
{
     Node *ptr=head;
    do{
        if(ptr==nullptr || ptr->next==head){
            // return 1;
            cout<<"yes! it is circular linked list";  
        }
        else if(ptr->next==nullptr){
            // return 0;
            cout<<"No! it is not circular linked list";  

        }
        ptr=ptr->next;
}while(ptr!=head);
}

int main()
{

    Node *first = nullptr ;
    Node *second =nullptr ;
    Node *third = nullptr;
    Node *fourth =nullptr;
    Node *fifth = nullptr;

    first = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;

    first->next = second;
    first->data = 2;

    second->next = third;
    second->data = 2;

    third->next = fourth;
    third->data = 3;

    fourth->next = fifth;
    fourth->data = 5;

    fifth->next =first;
    fifth->data = 7;

    Traversing(first);
    cout<<endl;
    isCircular(first);
    return 0;
}