//Burning Tree problem
//GFG


//Approach : TC-O(N) SC-O(N)
//Analogy: 
    //Step 1: Create node to parent node mapping 
    //step 2: get target node //This step 1 and step 2 are doing in create mapping function
    //step 3: burn tree; //step 3 are gets done in burn tree function

Node * createMapping(Node *root,unordered_map<Node *, Node *> &nodeToParent, int target){
    
    Node *targetNode = NULL; //initially pointing target node to null
    queue<Node *> q; //doing level order traversal for mapping
    q.push(root);
    while(!q.empty()){
        Node *frontNode = q.front();
        q.pop();
        
        if(frontNode->data == target) targetNode = frontNode;  //if we found target element then store that node in target Node.
        
        if(frontNode->left){ //if front node's left exist then,
            nodeToParent[frontNode->left] = frontNode; //connect front node's left with current node. i.e front node's left will be child and front node will be parent
            q.push(frontNode->left); //and also push that left node in queue
        }
        
        if(frontNode->right){ //similarly for right side
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    
    return targetNode; //finally return target node.

}


int burnTree(Node *targetNode, unordered_map<Node *, Node *> nodeToParent){
    unordered_map<Node *, bool> visited; //creating one visited map, which tells us that current node is already visited or not. if yes, then no need to visit it again and no need to push this node in queue
    int Time = 0; //initially time will be 0
    queue<Node *> q; //pushing target node in queue
    q.push(targetNode);
    visited[targetNode] = true; //marking target node as visited
    while(!q.empty()){ //looping till q not gets empty
        int size = q.size(); //getting size of queue
            int flag = 0; 
        for(int i=0; i<size; i++){ //looping over queue size times
            Node *frontNode = q.front(); //getting front node
            q.pop(); //popping from queue
            
            if(frontNode->left and !visited[frontNode->left]){ //check two condition, first one is left node present or not and second is left node is visited or not. if left node is prsent and it is not visited then enter in if block
                flag = 1; //flag equals to 1 that means we're going to update queue
                visited[frontNode->left] = true; //mark left node as visited
                q.push(frontNode->left); //and push into the queue
            }
            
            if(frontNode->right and !visited[frontNode->right]){ //similarly for right node
                flag = 1;
                visited[frontNode->right] = true;
                q.push(frontNode->right);
            }
            
            if(nodeToParent[frontNode] and !visited[nodeToParent[frontNode]]){ //similarly for parent node, first get parent node from mapping and check visited or not
                flag = 1;
                visited[nodeToParent[frontNode]] = true;
                q.push(nodeToParent[frontNode]);
            }   
        }
            if(flag) Time++; //once for loop is over and flag equals to 1 that means we update queue so we requre  1 unit to burn elements present in queue, so incrment time by 1.
        
    } 
    return Time; //once queue gets over return time.
}


//Main function
int minTime(Node* root, int target) 
{   
    unordered_map<Node *, Node *> nodeToParent; //creating map which stores node to parent mapping that we're storing parent of particular node. first->node and second->node's parent
    
    Node * targetNode = createMapping(root,nodeToParent,target); //calling createmapping function for mapping node to parent and also for finding target node.
    
    int Time = burnTree(targetNode,nodeToParent);
    return Time; //Finally return answer.
}