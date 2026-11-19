//Leetcode.

//Approach 1: Most optimised approach. TC-O(N) SC-O(1)

class Solution {
public:
    Node* connect(Node* root) {

        // Start traversing the current level from its first node.
        Node *curr = root;

        // Dummy node acts as the starting point of the next level.
        Node *nextLvlHead = new Node();

        // ptr is used to connect nodes of the next level.
        Node *ptr = nextLvlHead;

        // Continue until there are no more levels to process.
        while (curr) {

            // If the current node has a left child,
            // connect it to the next level.
            if (curr->left) {
                ptr->next = curr->left;
                ptr = ptr->next;
            }

            // If the current node has a right child,
            // connect it to the next level.
            if (curr->right) {
                ptr->next = curr->right;
                ptr = ptr->next;
            }

            // Move to the next node in the current level.
            if (curr->next) {
                curr = curr->next;
            }

            else {
                // Current level is completely processed.
                // Start traversing the next level.
                curr = nextLvlHead->next;

                // Reset the dummy node for building the following level.
                nextLvlHead->next = NULL;

                // Reset ptr to the dummy node.
                ptr = nextLvlHead;
            }
        }

        return root;
    }
};


//Approach 2: Level order traversal.
//TC-O(N) SC-O(N)
class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL) return root;
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){

            Node *front = q.front();
            q.pop();

            if(front == NULL) q.push(NULL);
            else{

                front->next = q.front();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }

        return root;
    }
};
