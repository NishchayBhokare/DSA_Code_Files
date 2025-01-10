//GFG.

//Approach: Using doubly linked list and map. TC-O(1) for get & put.
class Node{ //create doubly linkedlist.
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int k, int v){
            this->key = k;
            this->value = v;
            this->next=NULL;
            this->prev=NULL;
        }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*>mp;
    Node *head; 
    Node *tail;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1); //creation of dummy head and tail.
        tail = new Node(-1,-1);

        head->next = tail; //connect this head and tail.
        tail->prev = head;
    }

    void removeNode(Node *curr){ //remove node from their current position.
        Node *prevNode=curr->prev; //get previous node.
        Node *nextNode=curr->next; //get next node.

        prevNode->next = nextNode; //and then connect this prev and next node.
        nextNode->prev = prevNode;
    }

    void insertAtHead(Node *curr){ //inserting at head. as we used this cache.
        Node *nextNode = head->next; //first store head's next in nextnode.

        head->next = curr; //now point head to curetn used cache.
        curr->prev = head; //then connect curr with head.
        curr->next = nextNode;
        nextNode->prev = curr; //also connect stored nextNode to curr.
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end()) //if key doesn't found then return -1.
            return -1;
        
        Node *curr = mp[key]; //if key found then store it's address.
        int val = curr->value; //gets value of this node.
        
        //before returning value. add this cache to head. as we used this.
        removeNode(curr); //first remove it from its position.
        insertAtHead(curr); //and then insert at head.

        return val; //return value.
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){ //if key is already present.
            Node *curr = mp[key];
            curr->value = value; //update value.
            removeNode(curr); //and as we updated just. so add this cache as recently used cache.
            insertAtHead(curr);
            return; //and then return.
        }
       
        
       if(mp.size() == capacity){ //if size equals to capcity then before pushing. remove least recently used caceh.
            Node *leastUsed = tail->prev; //least recently used cache will be connected to tail.
            removeNode(leastUsed); //so get it. and remove it.
            
            //delete from map and doubly linked list.
            mp.erase(leastUsed->key);
            delete leastUsed;
       }

        //now insert new node. 
        Node *newCache = new Node(key,value);
        insertAtHead(newCache);
        mp.insert({key,newCache});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */