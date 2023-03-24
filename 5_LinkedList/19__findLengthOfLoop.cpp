// Example for finding length of loop if present.
// link-
// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

struct Node
{
public:
    Node *next;
    int data;
};

//TC-O(N) SC-O(1)
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *fast = head;
    Node *slow = head;
    int loop = 0;
    int count = 0;
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
        do
        {                       // using do while loop cause intially slow and fast are equal.
            slow = slow->next;  // moving slow one step at a time.
            count++;            // increasing count so that we can get length of loop.
        } while (slow != fast); // after looping over the loop in linked list then slow will equal to fast so we will terminate here.

        return count; // and returning count i.e length of loop.
    }
    return 0; // if loop is not present that time we will return 0.
}