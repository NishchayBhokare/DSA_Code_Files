// Example to return start node of loop in linked list.
//gfg

#include<map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Most optimised approach. Using slow and fast pointer. TC-(n) SC-O(1)
int findFirstNode(Node* head)
{
    int loop = 0;
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    while (fast && fast->next)
    { // Checking whether loop is terminate with null or not.
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
            slow = slow->next; // moving slow pointer one step for every iteration.
            temp = temp->next; // moving temp pointer one step for every iteration.
        }
        return slow->data; //once temp meet to slow then return either temp or slow's data and that node will be start node of loop in linked list.
    }
    else return -1; //if loop is not present then return -1.
}


//Approach 2: Using Map TC-O(N) SC-O(N)
 int findFirstNode(Node* head)
    {
        // your code here
        map<Node*,bool>visited;
        Node *ptr=head;
        while(ptr != NULL){ //looping till ptr not equal to null.
            if(visited[ptr] == true) return ptr->data; //before marking as true, checking whether it is already true or not. if yes then loop is present and return that nodes data i.e start node's data and, if not marked as true, then marked as true in next statement.
            visited[ptr] = true; //marking as true.
            ptr=ptr->next; //shifting ptr to its next.
        }
        return -1;
    }