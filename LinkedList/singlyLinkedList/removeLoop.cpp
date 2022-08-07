// Example for remove loop is present in linked list.
// link-
    // https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

struct Node
{
    Node *next;
    int data;
};

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