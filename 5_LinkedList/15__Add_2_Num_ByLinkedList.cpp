// Add two numbers represented by linked lists 
// GFG

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};


//Approach 1: After optimising Approach 2. TC-O(N+M) SC-O(Max(N+M)).
//Analogy: first reverse first and second array. Then add data of one by one node while maintaing carry and create new node with total value i.e addition of first node data, second node data and carry.
 void reverseLinkedList(struct Node *&head){ //here we are reversing linked list.
        Node *curr=head;
        Node *prev=NULL;
        Node *forward;
        while(curr != NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        reverseLinkedList(first);
        reverseLinkedList(second); 
        
        Node *head1=first, *head2=second;
        Node *head=NULL; 
        int carry=0;
        
        while(carry || head1!= NULL || head2!=NULL){ //looping till any of the given condition is true.
            
            int value=carry; //first assigning carry in value.
            if(head1) value+=head1->data;//if head1 is not null then insert head1 data in value
            if(head2) value+=head2->data;//similarly for head2.
            
            carry=value/10; //now, calculating carry by dividing value by 10
            int digit=value%10; //by taking modulus then we will eliminate carry from value.
            
            if(value > 0){ //condition because of leading zero.
                Node *temp=new Node(digit); //creting new node with value data.
                temp->next=head; //then, connecting temp's next to head.
                head=temp; //and then poiting head to temp.
            }

            if(head1) head1=head1->next; //if head1 not null, then head1 will shift to its next
            if(head2) head2=head2->next; //similarly for head2.
        }

        return head; //return head of new linked list.
    }



//Approach 2: By reversing first and second array then calculating sum. TC-O(N+M) SC-O(Max(N+M)).
 void reverseLinkedList(struct Node *&head){
        Node *curr=head;
        Node *prev=NULL;
        Node *forward;
        while(curr != NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        reverseLinkedList(first);
        reverseLinkedList(second); 
        
        Node *head1=first, *head2=second;
        Node *head=new Node(-1);  //creating dummy node.
        Node *ptr=head;
        int carry=0;
        
        while(head1!= NULL and head2!=NULL){ //looping till any of the linked list is not null.
            
            int value = head1->data + head2->data + carry;
            
            carry=value/10;
            value=value%10;
            
            Node *temp=new Node(value);
            ptr->next=temp;
            ptr=ptr->next;
            
            head1=head1->next;
            head2=head2->next;
        }
        
        while(head1 != NULL){ //looping if head1 is not null.
            int value = head1->data + carry;
            
            carry=value/10;
            value=value%10;
            
            Node *temp=new Node(value);
            ptr->next=temp;
            ptr=ptr->next;
            head1=head1->next;
        }
    
          while(head2 != NULL){ //looping if head2 is not null.
            int value = head2->data + carry;
            
            carry=value/10;
            value=value%10;
            
            Node *temp=new Node(value);
            ptr->next=temp;
            ptr=ptr->next;
            head2=head2->next;
        }
        
        if(carry > 0){ //and finally looping for carry, if carry is greater than 0.
            Node *temp=new Node(carry);
            ptr->next=temp;
            ptr=ptr->next;
        }
        
        ptr->next=NULL; //connecting tail of head's to null.
        head=head->next; //shifting head to its next because head is pointing to dummy node.
        
        reverseLinkedList(head); //reversing final linked list.
        
        return head; //returning head.
    }


//Approach 3: using vector arrya TC-O(N+M) SC-O(N+M) additional space of vector.
Node* addTwoLists(Node* num1, Node* num2) {
     Node *head = NULL;
        vector<int> vec1;
        vector<int> vec2;
        
        Node *temp = num1;
        while(temp){
            vec1.push_back(temp->data);
            temp = temp->next;
        }
        
        temp = num2;
        while(temp){
            vec2.push_back(temp->data);
            temp = temp->next;
        }
        
        int i = vec1.size()-1, j = vec2.size()-1, carry = 0, digit=0;
        
        while(carry || i >=0 || j>=0){
            
            int val = carry;
            if(i>=0) val += vec1[i];
            if(j>=0) val += vec2[j];
            
            carry = val/10;
            digit = val%10;
            
            if(val > 0){
                temp = new Node(digit);
                temp->next = head;
                head = temp;
            }
            
            if(i>=0) i--;
            if(j>=0) j--;
        }
        
        return head;
    }
    