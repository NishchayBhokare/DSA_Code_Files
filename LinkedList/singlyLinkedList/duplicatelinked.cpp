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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* remDuplicate(Node *head)
{
    Node *ptr = head;
    int i = 0;
    while (ptr!=NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            Node *N = ptr;
            ptr = ptr->next;
            delete N;
        }
        else
        {
            if (i == 0)
            {
                Node *NewHead = ptr;
            }
            i++;
            ptr=ptr->next;
        }
        // if(ptr->next==nullptr){break;}
    }
        // cout<<"ok";
return head;
}

int main()
{

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

    first->next = second;
    first->data = 2;

    second->next = third;
    second->data = 2;

    third->next = fourth;
    third->data = 2;

    fourth->next = fifth;
    fourth->data = 5;

    fifth->next = NULL;
    fifth->data = 6;

    Traversing(first);
    // cout<<first->next->next->next->next->next->data;
    Node *head = remDuplicate(first);
    cout << "\nafter removing duplicate elements\n";
    Traversing(head);
    return 0;
}