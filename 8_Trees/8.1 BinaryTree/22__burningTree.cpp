//Burning Tree problem
//GFG


//Approach : TC-O(N) SC-O(N) -> Creation of node to parent mapping.
//Analogy: 
    //Step 1: Create node to parent node mapping 
    //step 2: get target node //This step 1 and step 2 are doing in create mapping function
    //step 3: burn tree; //step 3 are gets done in burn tree function

// Node * createMapping(Node *root,unordered_map<Node *, Node *> &nodeToParent, int target){
    
//     Node *targetNode = NULL; //initially pointing target node to null
//     queue<Node *> q; //doing level order traversal for mapping
//     q.push(root);
//     while(!q.empty()){
//         Node *frontNode = q.front();
//         q.pop();
        
//         if(frontNode->data == target) targetNode = frontNode;  //if we found target element then store that node in target Node.
        
//         if(frontNode->left){ //if front node's left exist then,
//             nodeToParent[frontNode->left] = frontNode; //connect front node's left with current node. i.e front node's left will be child and front node will be parent
//             q.push(frontNode->left); //and also push that left node in queue
//         }
        
//         if(frontNode->right){ //similarly for right side
//             nodeToParent[frontNode->right] = frontNode;
//             q.push(frontNode->right);
//         }
//     }
    
//     return targetNode; //finally return target node.

// }
void createMapping(Node *root,int target, Node *&targetNode, unordered_map<Node*,Node*> &nodeToParent){
    if(root == NULL) return;

    if(root->data == target) targetNode = root;

    if(root->left){
        nodeToParent[root->left] = root; //creating parent child mapping.
        createMapping(root->left,target,targetNode,nodeToParent);
    }

    if(root->right){
        nodeToParent[root->right] = root;
        createMapping(root->right,target,targetNode,nodeToParent);
    }
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
        for(int i=0; i<size; i++){ //looping over queue for current queue size. as these new added nodes.
        //we're doing like this..because we have to keep track of timer so.
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


                                     //or we can do like this too..
    queue<Node*>q;
        unordered_map<Node*,bool>visited;
        
        q.push(targetNode);
        visited[targetNode]=true;
        q.push(NULL);
        
        while(q.size()>1){
            
            Node* frontNode = q.front();
            q.pop();
            
            if(frontNode == NULL){
                timer++;
                q.push(NULL);
                continue;
            }
            
            if(!visited[frontNode->left] && frontNode->left){
                visited[frontNode->left]=true;
                q.push(frontNode->left);
            }
            
            if(!visited[frontNode->right] && frontNode->right){
                visited[frontNode->right]=true;
                q.push(frontNode->right);
            }
                
            if(!visited[mp[frontNode]] && mp[frontNode]){
                visited[mp[frontNode]]=true;
                q.push(mp[frontNode]);
            }
        }
    return Time; //once queue gets over return time.
}


//Main function
int minTime(Node* root, int target) 
{   
    unordered_map<Node *, Node *> nodeToParent; //creating map which stores node to parent mapping that we're storing parent of particular node. first->node and second->node's parent
    
    // Node * targetNode = createMapping(root,nodeToParent,target); //calling createmapping function for mapping node to parent and also for finding target node.
    Node * targetNode = NULL;
    createMapping(root,nodeToParent,target, targetNode); //calling createmapping function for mapping node to parent and also for finding target node.
    
    int Time = burnTree(targetNode,nodeToParent);
    return Time; //Finally return answer.
}


//Approach 2: similar like above..but used recrusion for cresation of mapping.
void createMapping(Node *root,int target, Node *&targetNode, unordered_map<Node*,Node*> &mapping){
    if(root == NULL) return;

    if(root->data == target) targetNode = root;

    if(root->left){
        mapping[root->left] = root; //creating parent child mapping.
        createMapping(root->left,target,targetNode,mapping);
    }

    if(root->right){
        mapping[root->right] = root;
        createMapping(root->right,target,targetNode,mapping);
    }
}

int minTime(Node* root, int target) 
{   
    int time = 0;
    if(root->left == NULL && root->right == NULL) return time;
    Node *targetNode = NULL;
    unordered_map<Node*,Node*> mapping;
    unordered_map<Node*,bool>visited;

    createMapping(root,target,targetNode,mapping);

    queue<Node*>q;
    q.push(targetNode);
    visited[targetNode] = true;

    bool firstIteration = true;
    while(!q.empty()){ //these things are same like Approach 1.
        int size = q.size();
        for(int i =0; i<size; i++){
            Node *frontNode = q.front();
            q.pop();

            if(frontNode->left && !visited[frontNode->left]){
                q.push(frontNode->left);
                visited[frontNode->left] = true;
            }

            if(frontNode->right && !visited[frontNode->right]){
                q.push(frontNode->right);
                visited[frontNode->right] = true;
            }

            if(mapping[frontNode] && !visited[mapping[frontNode]]){
                q.push(mapping[frontNode]);
                visited[mapping[frontNode]] = true;
            }
        }
     
        if(!firstIteration) //condition because we don't want to increment time for given target node.
            time++; //in first approach we have used flag...so this is alternative for that.
        
        else firstIteration = false;
    }

    return time;
}







                                            //Approach 3:
//using little extra space..but i have solved the problem 
void createMapping(Node *root, unordered_map<int,vector<int> > &mapping){
    if(root == NULL) return;

    if(root->left){
        //mapping current node as parent for left child node.
        mapping[root->left->data].push_back(root->data);

        //mapping child node to current node.
        mapping[root->data].push_back(root->left->data);
    }

    if(root->right){
        //same first map parent.
        mapping[root->right->data].push_back(root->data);

        //mapping child.
        mapping[root->data].push_back(root->right->data);
    }

    createMapping(root->left,mapping);
    createMapping(root->right,mapping);
}



int minTime(Node* root, int target) 
{
    int time = 0;
    if(root->left == NULL && root->right == NULL) return time;

    // Your code goes here
    unordered_map<int,vector<int> > mapping;
    unordered_map<int,bool> visited;

    createMapping(root,mapping);

    //mark target node as visited.
    visited[target] = true;


    queue<int> q;
    for(auto i: mapping[target]){
        if(!visited[i]){
            q.push(i);
            visited[i]=true;
        }
    }

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size;i++){
            int node = q.front();
            q.pop();

            for(auto i:mapping[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        time++;
    }

//or we can do like this too.
    queue<int>q;
    unordered_map<int,bool>visited;
    q.push(target);
    visited[target]=true;
    q.push(-1);
    
    while(q.size()>1){
        
        int frontNode = q.front();
        q.pop();
        
        if(frontNode == -1){
            timer++;
            q.push(-1);
            continue;
        }
        
        for(auto node: mp[frontNode]){
            
            if(!visited[node]){
                q.push(node);
                visited[node]=true;
            }
        }
    }
    return time;
}