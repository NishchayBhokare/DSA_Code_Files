// Example for detect loop in linked list.
// link-
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

struct Node
{
    Node *next;
    int data;
};

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