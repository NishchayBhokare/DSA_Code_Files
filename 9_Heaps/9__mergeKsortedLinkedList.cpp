//Merge k Sorted linked list
//GFG

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Using min heap. TC-O(NKlogk) SC-O(K)
 class comapre{ //compare class
      public:
      bool operator() (Node *a, Node *b){
          return a->data > b->data;
      }  
    };

    
Node * mergeKLists(Node *arr[], int k)
{ 
    priority_queue<Node *, vector<Node*>, comapre> pq;
    
    for(int i=0; i<k; i++){
        pq.push(arr[i]); //first pushing k nodes in priority queue.
    }
    
    Node *head = NULL;
    Node *tail = NULL;
    while(pq.size() != 0){ //looping over priority queue
        Node *temp = pq.top();
        pq.pop(); //getting top minimum node and popping out that node

        if(temp->next) pq.push(temp->next); //once pop out, checking next node is present or not
        
        if(head == NULL){ //At initial  if head is null then point head and tail to current top node
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp; //else, point tail's next to current top node
            tail = tail->next; //and shift tail to its next.
        }
    }
    return head; //return head of answer linked list.
}

//using dummy node.
Node* mergeKLists(vector<Node*>& arr) {
    priority_queue<Node*, vector<Node*>, comapre > pq;

    for(int i = 0; i<arr.size(); i++){
        pq.push(arr[i]);
    }
    
    Node *head = new Node(-1); //using dummy node technique.
    Node *tail = head;
    
    while(!pq.empty()){
        tail->next = pq.top();
        tail = tail->next;
        pq.pop();
        
        if(tail->next)
            pq.push(tail->next);
    } 
    return head->next;
}



//Approach 2: By sorting ans vector. TC-O(nk.lognk) SC-O(n*k).
Node * mergeKLists(Node *arr[], int k)
{
    vector<int> ans;
    for(int i=0; i<k; i++){
        while(arr[i] != NULL){
            ans.push_back(arr[i]->data);
            arr[i] = arr[i]->next;
        }
    }
    
    sort(ans.begin(),ans.end());
    
    Node *head = new Node (ans[0]);
    Node *tail = head;
    for(int i=1; i<ans.size(); i++){
        tail->next = new Node(ans[i]);
        tail = tail->next;
    }
    
    return head;
}