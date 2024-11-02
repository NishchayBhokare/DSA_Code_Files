// Example for remove duplicate element from sorted linked list.
//GFG
#include<map>
using namespace std;
struct Node
{
    Node *next;
    int data;
};


//Approach 1: Most optimised approach. Using slow and fast pointer. TC-(n) SC-O(1)
Node *removeDuplicates(Node *head)
{
  if(head == NULL or head->next==NULL) return head; //IF list is empty or have single element then simply return head. no need to check for duplicate element.

    Node *ptr=head; //pointing ptr to head.
    while(ptr->next != NULL){ //looping till ptr's next not equal to head.
        if(ptr->data == ptr->next->data){ //checking ptr's data equals to its next's data or not.
            Node *temp=ptr->next; //if equals then store ptr's next node to temp node.
            ptr->next=ptr->next->next; //point ptr's next to ptr's next next.
            delete temp; //and delete that duplicate element.
        }
        else ptr=ptr->next; //if not equals then simply shift ptr to its next.
    }
return head; //returning head.
}

//Approach 2: copy pasted from unordered list approach
  Node* removeDuplicates(Node* head) {
    // return head;
    unordered_set<int> st;
    
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL){
        if(st.find(curr->data) != st.end()){
            //duplicate is present.
            Node *temp = curr;
            curr=curr->next;
            delete temp;
            
            prev->next = curr;
        }
        else {
            //else just move to next element.
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;    
        }
    }
    
    return head;
    
}


//Approach 3:using set
Node* removeDuplicates(Node* head) {
        // return head;
        unordered_set<int>st;
    
        // Initialize pointers for traversing the original list
        // and building the new list without duplicates
        Node *new_head = nullptr;
        Node *tail = nullptr;
    
        // Traverse the original list
        Node *curr = head;
        while (curr != nullptr) {
          
            // Check if the current node's data is not in the map
            if (st.find(curr->data) == st.end()) {
              
                // Create a new node for the unique data
                Node *new_node = new Node(curr->data);
    
                // If new_head is null, this is the
                // first unique node
                if (new_head == nullptr) {
                    new_head = new_node;
                    tail = new_head;
                }
                else {
                    // Append the new node to the end
                    // of the new list
                    tail->next = new_node;
                    tail = new_node;
                }
    
                // Mark this data as encountered
                st.insert(curr->data);
            }
          
            // Move to the next node in the original list
            curr = curr->next;
        }
      
        // Return the head of the new list with
        // duplicates removed
        return new_head;
        
    }