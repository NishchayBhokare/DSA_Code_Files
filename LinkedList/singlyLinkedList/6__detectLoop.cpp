// Example for detect loop in linked list.
//gfg
// link-
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include<map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};

//Approach 1: Most optimised approach. Using Floyds cycle detection algorithm. slow and fast pointer. TC-O(N) SC-O(1). 
bool detectLoop(Node *head)
{
    // your code here
    Node *slow = head;
    Node *fast = head; // Initially both slow and fast pointing to the head.
    while (fast != nullptr && fast->next != nullptr)
    { // Checking whether loop is terminate with null or not.
        slow = slow->next;       // moving slow pointer one step at every iteration.
        fast = fast->next->next; // moving fast pointer two step at every iteration. if there is loop is present then definitely slow and fast will meet at one point.
        if (fast == slow)
        { // if slow and fast is pointing on same position then there is loop.
            return 1;
        }
    }
    return false; // if fast not equal to slow then there will not loop.
}


//Approach 2: Using Map TC-O(N) SC-O(N)
//Analogy: for every node marked true in map, once you mark all node as true and if loop is present then you will get node which is already marked as true. so if we get such node then loop is present. 
bool detectLoop(Node* head)
{
    map<Node*,bool>visited;
    Node *ptr=head;
    while(ptr != NULL){ //looping till ptr not equal to null.
        if(visited[ptr] == true) return 1; //before marking as true, checking whether it is already true or not. if yes then loop is present, if not then marked as true in next statement.
        visited[ptr] = true; //marking as true.
        ptr=ptr->next; //shifting ptr to its next.
    }
    return 0;
}