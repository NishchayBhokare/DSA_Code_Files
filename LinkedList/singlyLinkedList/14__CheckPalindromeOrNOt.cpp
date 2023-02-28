// Example to check given linked list is palindrome or not.
// GFG

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
 

//Approach 1: Most Optimised approach. TC-O(N) SC-O(1).
//reversing next half of linked list and simply check.
 Node* reverseLinkedList(Node *head){
        Node *curr=head;
        Node *prev=NULL;
        Node *forward;
        while(curr != NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        if(head == NULL or head->next==NULL) return 1;
        
        Node *slow=head;
        Node *fast=head->next; //using slow and fast pointer we will find mid element of linked list.
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        } //slow will point to end of first half node.
        
        
        Node *secondHead=slow->next; //now secondHead will point to start of second half.
        slow->next=reverseLinkedList(secondHead); //reversing second half and connecting with slow's next.
        secondHead=slow->next; //now after reversing again poiting secondHead to slow's next.
        
        Node *head1=head; //head1 is on first head i.e starting of linked list.
        Node *head2=secondHead; //head2 is on starting of second half after reversing.
        while(head2 !=NULL){ //looping till head2 not equal to null.
            if(head1->data != head2->data) break; //if data of head1 and head2 not equal then exit from loop.
            head1=head1->next; 
            head2=head2->next; //shfting both heads.
        }
        
        slow->next=reverseLinkedList(secondHead); //Now, again reversing second half because we want to return linked list the way it inputed. (This is optional step)

        if(head2 == NULL) return 1; //check eiter head2 not equal to null if yes then we reach to last node so linked list is palindrome
        return 0; //if we exit from the loop because of break statement then linked list is not palindrome.
    }


//Approach 2: Optimised approach. TC-O(N) SC-O(1).
//We are using long int variable to store data of linked list.
     bool isPalindrome(Node *head)
    {
        long int num=0; //creating 
        Node *ptr=head;
        while(ptr != NULL){
            num=num*10 + ptr->data; //storing linked list data in the num variable in sequential manner.
            //if linked list is 1->2->3->4 then num will be num=1234.
            ptr=ptr->next;
        }

        ptr=head; //pointing ptr again on head.
        
        while(ptr != NULL){ //looping till ptr not reaches to null.
            long int digit = num % 10; //one by one getting digit and comparing with linked list data
            if(digit != ptr->data) return 0; //for eg. if linked list is 1->2->3->4 and num=1234 then in first iteration will compare first node of data i.e 1 equals to last node of data or not. i.e digit = 4
            num=num/10; //removing one by one digit in num variable.
            ptr=ptr->next; //similaryly shifting ptr.
        }
        return 1; //if we reach till here then simply return 1. 
    }



//Approach 3: Using extra space i.e Array TC-O(N) SC-O(N).
bool isPalindrome(Node *head)
{
    vector<int>vec;
    Node *ptr=head;
    while(ptr != NULL){ //pushing all data of linked list node into the array
        vec.push_back(ptr->data);
        ptr=ptr->next;
    }
    
    int i=0;
    int j=vec.size()-1; //now pointing i on starting of array and j on ending of array, and one by one comparing.
    while(i<j){
        if(vec[i] != vec[j]) return 0; //if ith element is not equal to jth element then simply return 0.
        i++;
        j--;
    }
    return 1; //else given linked list is palindrome
}



//Approach 4:Using Recursion TC-O(N) SC-O(N).
 int solve(Node *&start, Node *end){
        if(end == NULL ) return -1; //if end gets equal to null then return end to its previous call
    
        int result=solve(start,end->next); //calling function till end not reaches to last node and then for every node will compare start and end.
        if(start>=end and result==1) return 1; //by comparing if we reach to the mid of linked list then return 1.
        if(result == 0) return 0; //if result equals to 0 then simply return 0.
        if(start->data != end->data) return 0; //if start node data not equals with end node data then return 0.
        start=start->next; //if we reach to here then start node data equals to end node data so shift start to its next.
        return 1; //and return 1.
    }
    
    bool isPalindrome(Node *head)
    {   
        Node *start=head; 
        Node *end=head; //pointing both start and end on head.
        return solve(start,end);
    }




