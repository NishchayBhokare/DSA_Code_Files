//logic is create original node and new node mapping in map and work accordingly with original node.

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        // code here
        Node *cloneNode = new Node(node->val);
        
        unordered_map<Node*,Node*>ump;
        ump[node] = cloneNode;
        
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty()){
            Node *front = q.front();
            q.pop();
            
            for(auto nbr:front->neighbors){
                
                Node *cloneParent = ump[front];
                
                if(ump.find(nbr) == ump.end()){ //if nbr node is not present then create it, insert it in map and insert original nbr node in queue.
                    
                    Node *cloneNbr = new Node(nbr->val);
                    
                    ump[nbr] = cloneNbr;
                    cloneParent->neighbors.push_back(cloneNbr);
                    q.push(nbr); //why inserting originalnbr in queue, because we have complete original list,
                    // and with the help of original list, we're create cloned list, so that's why we're adding 
                    //original nbr in queue, because cloneNbr don't have it's neighbor nodes as of now, because
                    //it just created now.
                }
                else{
                    
                    Node *cloneNbr = ump[nbr]; //if original nbr is present in map that means, cloneNbr is also there
                    //as we're maintaing originalNode to cloneNode mapping.
                    cloneParent->neighbors.push_back(cloneNbr); //so insert this cloneNbr node in cloneParent node's neighbors array.
                }
                
            }
        }
        
        
        return cloneNode;
    }
};