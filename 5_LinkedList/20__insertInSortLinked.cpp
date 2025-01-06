//Insert node in sorted linked list.
//GFG.
// link-
// https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next;
    }
};


//TC-O(N) SC-O(1)
Node *sortedInsert(struct Node *head, int data)
{
    // Code here
    Node *p = head;             // Pointing p node to head.
    Node *q = nullptr;          // creating another node which points to the null.
    Node *tmp = new Node(data); // Creating another pointer object of struct Node.

    if (p->data >= data) //condition to check...if data can be inserted at first position or not.
    {
        tmp->next = p; // new element pointer pointing to the p which is current first element in linked list.
        return tmp;    // returning new head of linked list.
    }

    while (p != nullptr && p->data < data)
    { // looping till data is greater than p's data and p not equal to the null
        // while loop for when, element get inserted at middleware or at the end.
        q = p; // keeping q as a previous pointer which going to point the new inserted node.
        p = p->next;
    }
    q->next = tmp; // when p->data > than data then we will point q->next to the new node.
    tmp->next = p; // connecting link between new node with p.
    return head;   // returning head of linked list.
}