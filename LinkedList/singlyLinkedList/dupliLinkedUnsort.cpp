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

Node *remDuplicate(Node *head)    //time complexity issue
{
    Node *ptr = head;
    Node *p = ptr, *q = ptr->next;
    while ( ptr->next != nullptr)
    {
        
        if (ptr->data == q->data)
        {
            p->next = q->next; //linking with next node 
            // Node *d=q;
            q = q->next;   //moving q to next node
            // delete d;
        }
        else
        {
            p = p->next;  
            q = q->next;
        }

        if (ptr->next!=nullptr) //to solve problem when all elements are same
        {
            if(q==nullptr){  //after reaching q to null we are going to move ptr pointer to next node.
            ptr = ptr->next;
            p = ptr;
            q = ptr->next;
            }
        }
    }

    return head;
}

int main()
{

    Node *first = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;
    Node *fourth = nullptr;
    Node *fifth = nullptr;

    first = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;

    // first->next = second;
    // first->data = 12;

    // second->next = third;
    // second->data = 37;

    // third->next = fourth;
    // third->data = 58;

    // fourth->next = fifth;
    // fourth->data = 37;

    // fifth->next = NULL;
    // fifth->data = 45;

    first->next = second;
    first->data = 2;

    second->next = third;
    second->data = 12;

    third->next = fourth;
    third->data = 2;

    fourth->next = fifth;
    fourth->data = 2;

    fifth->next = NULL;
    fifth->data = 2;

    Traversing(first);
    // cout<<first->next->next->next->next->next->data;
    Node *head = remDuplicate(first);
    cout << "\nafter removing duplicate elements\n";
    Traversing(head);
    // 12,37,58
    return 0;
}

// Another approach
 //  Node *ptr1=head, *del;
    //  Node *ptr2;
    //  while(ptr1!=nullptr){
    //      ptr2=ptr1;
    //      while(ptr2->next!=nullptr){
    //          if(ptr1->data==ptr2->next->data){
    //              del=ptr2->next;
    //              ptr2->next=ptr2->next->next;
    //              delete del;
    //          }
    //          else{
    //              ptr2=ptr2->next;
    //          }  
    //      }
    //      ptr1=ptr1->next;
    //  }
    
    // return head;