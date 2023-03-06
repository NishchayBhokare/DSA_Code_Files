// Example to find middle element of linked list.
//GFG
struct Node
{
    Node *next;
    int data;
    Node(int data) 
    {
        this->data = data;
        this->next = nullptr;
    }
};

//Approach 1: Optimised approach. Tc-O(N) SC-O(1)
//Analogy: moving slow pointer one step at a time and moving fast pointer two step at a time.
//once fast pointer reaches to last node or NULL then slow will be in middle of linked list. so return slow's data.
int getMiddle(Node *head)
    {
    Node *slow=head;
    Node *fast=head;
    while(fast != nullptr and fast->next != nullptr ){ //looping till fast not reaches to last node or nullptr.
        slow=slow->next; //shifting one step.
        fast=fast->next->next; //shfiting two step.
    }
    return slow->data; //returing slow's data.
    }


//Approach 2: Brute force solution. Tc-O(N) SC-O(1)
int getMiddle(Node *head)
{
    int count = 0;
    Node *ptr = head;
    while (ptr != nullptr) //counting length of linked list.
    {
        ptr = ptr->next;
        count++;
    }
    int mid = (count / 2); //calculating mid. if mid element is present at 3rd position then here int mid will be 2 because we will shift head two times to reach third node.
    while (mid--) //
    {
        head = head->next; //shifting head's next.
    }
    return head->data; //returning head's data.
}