// Example for remove loop is present in linked list.
//GFG
#include<map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};

//Approach 1: Most optimised approach. Using slow and fast pointer. TC-(n) SC-O(1)

//Analogy:
//Incrementing  slow by one and fast by two, if slow and fast gets equals then loop is exist.
//When linked list is exact circular that means, if last node is connected with head then slow and fast pointer will also points to head (head means start of circular linked list.) when we detect loop.
//but if last node connected somewhere between linked list instead connecting with head node, then slow and fast pointer will both point somewhere in linked list instead pointing head node.
//But, the distance between head node to the start of loop node equals to distance between slow node to start of loop node. 
//So, if loop is present, then one by one shift temp node (which is intitally pointing to head) and slow node. Once temp node and slow node points on same node i.e that particular node is starting node of loop present in linked list.
void removeLoop(Node *head)
{
    int loop = 0;
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    Node *prev;
    while (fast && fast->next)
    { // Checking whether loop is terminate with null or not.

        prev = slow;             // pointing previous to the slow before moving slow at next position.
        fast = fast->next->next; // moving fast pointer two step at every iteration. if there is loop is present
        slow = slow->next;       // moving slow pointer one step at every iteration.
        if (fast == slow)
        { // if slow and fast is pointing on same position then there is loop.
            loop = 1;
            break; // Breaking from the loop.
        }
    }

    if (loop)
    { // if value of loop is 1 then it will enter in if block
        while (temp != slow)
        {                      // when temp==slow then this is start position of loop.
            prev = slow;       // pointing previous to the slow before moving slow at next position.
            slow = slow->next; // moving slow pointer one step for every iteration.
            temp = temp->next; // moving temp pointer one step for every iteration.
        }

        prev->next = nullptr; // when there will be condition of temp==slow then that time we have to connect previous node of slow to the nullptr. so for this we have prev node which is pointing to the previous of slow. and finally we point prev->next=nullptr to remove the loop.
    }
}


//Approach 2: Using Map TC-O(N) SC-O(N)
void removeLoop(Node* head) //This is also one apporach but giving TLE On gfg.
{
    map<Node*,bool>visited;
    
    Node *ptr=head;
    Node *previous=ptr;
    while(ptr != NULL){ //looping till ptr not equal to null.
        if(visited[ptr] == true) {previous->next=NULL; break;} //before marking as true, checking whether it is already true or not. if yes then loop is present so point last node's next to null., if not,then marked as true in next statement.
        visited[ptr] = true; //marking as true.
        previous=ptr; //point previous to ptr.
        ptr=ptr->next; //shifting ptr to its next.
    }
}



// //approach 3: by modfiying linked list structure. i.e change data of node to -1
// void removeLoop(Node* head) //This is one simple approach but we need to change data of nodes to -1.
// {
//   Node *ptr=head;
// while(ptr->next!= NULL and ptr->next->data != -1 ){
//     ptr->data=-1;
//     ptr=ptr->next;
// }
// // if(ptr->next == NULL) return;
// ptr->next=NULL;
// }



