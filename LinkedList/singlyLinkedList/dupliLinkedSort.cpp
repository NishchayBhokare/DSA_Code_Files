#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void Traversing(Node *head)
{
    // int count=0;
    while (head != NULL)
    {
        cout << head->data << " ";
        // count++;
        head = head->next;
    }
    // cout<<count;
}

Node* remDuplicate(Node *head)
{
    Node *ptr = head;
     while (ptr->next != nullptr)
    {
        if (ptr->data == ptr->next->data)
        {
            Node *q=ptr->next;
            ptr->next = ptr->next->next;
            delete q;
            
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
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

    fifth->next = NULL;
    fifth->data = 7;

    Traversing(first);
    // cout<<first->next->next->next->next->next->data;
    Node *head = remDuplicate(first);
    cout << "\nafter removing duplicate elements\n";
    Traversing(head);
    return 0;
}