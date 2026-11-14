//GFG.

//Approach 1: Two stack approach. Optimised Approach. TC-O(N+M) SC-O(H1+H2).
// Idea is, Inorder traversal of a BST generates elements in sorted order. Instead of storing the complete 
// inorder arrays, use two stacks to lazily generate the next smallest element from each BST and apply the 
// two-pointer technique to find common elements.

class Solution {
public:

    // Push all left-side nodes into the stack.
    // The top will always contain the next smallest element.
    void pushLeft(Node *root, stack<Node*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    // Move the iterator to the next inorder element.
    // Pop the current node and explore the leftmost path
    // of its right subtree.
    void getNext(stack<Node*>& st) {

        Node *top = st.top();
        st.pop();

        pushLeft(top->right, st);
    }

    vector<int> findCommon(Node* r1, Node* r2) {

        stack<Node*> st1, st2;

        // Initialize both BST iterators with their
        // respective leftmost paths.
        pushLeft(r1, st1);
        pushLeft(r2, st2);

        vector<int> ans;

        // Both stacks provide elements in sorted order,
        // just like two pointers on sorted arrays.
        while (!st1.empty() && !st2.empty()) {

            int val1 = st1.top()->data;
            int val2 = st2.top()->data;

            if (val1 == val2) {

                // Common element found.
                ans.push_back(val1);

                // move to the next inorder element for both BST iterators.
                getNext(st1);
                getNext(st2);
            }
            else if (val1 < val2) {

                // First BST has a smaller element.
                // move to the next inorder element to find a possible match.
                getNext(st1);
            }
            else {

                // Second BST has a smaller element.
                // move to the next inorder element to find a possible match.
                getNext(st2);
            }
        }

        return ans;
    }
};



//Approach 2: get inorder and check. TC-O(N+M) SC-O(N+M).
class Solution {
  public:
    void getInOrder(Node *r, vector<int>&inorder){
        
        if(!r) return;
        
        getInOrder(r->left,inorder);
        inorder.push_back(r->data);
        getInOrder(r->right,inorder);
    }
    
    vector<int> findCommon(Node* r1, Node* r2) {
  
        vector<int>inorder1, inorder2;
        
        getInOrder(r1,inorder1);
        getInOrder(r2,inorder2);
        
        vector<int>ans;
        
        int i=0, j=0;
        while(i<inorder1.size() and j<inorder2.size()){
            
            if(inorder1[i]==inorder2[j]) {
                ans.push_back(inorder1[i]);
                i++; j++;
            }
            else if(inorder1[i] < inorder2[j]) i++;
            else j++;
        }
        
        return ans;
    }


//Appraoch 3: Another approach using set. TC-O(N+M) SC-O(N+M)
class Solution {
  public:
    void getNodes(Node *r, unordered_set<int>&common){
        
        if(!r) return;
        
        common.insert(r->data);
        
        getNodes(r->left,common);
        getNodes(r->right,common);
    }
    
    
    void getCommonNodes(Node *r, unordered_set<int>&common, vector<int>&ans){
        if(!r) return;
        
        if(common.find(r->data) != common.end())
            ans.push_back(r->data);
        
        getCommonNodes(r->left,common,ans);
        getCommonNodes(r->right,common,ans);
    }
    
    vector<int> findCommon(Node* r1, Node* r2) {
  
        unordered_set<int>common;
        
        getNodes(r1,common);
        
        vector<int>ans;
        getCommonNodes(r2,common,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
