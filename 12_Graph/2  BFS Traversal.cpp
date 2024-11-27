//gfg solution.


//In BFS -> Breadth First Serach..we picked..one node and then visit there all neighbouring nodes.
//so for that...we used queue. and visisted map..to track..current node is visited or not.

//TC-O(V+E) SC-O(V)
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    vector<int> ans;
    unordered_map<int,bool>visited;
    
    queue<int>q;
    q.push(0); //pushing first vertex..node 0.
    visited[0]=true; //mark as visited.
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        ans.push_back(node);
        
        for(int i = 0; i<adj[node].size(); i++){ //push neighbouring nodes of node.
            int neighborNode = adj[node][i];
            
            if(!visited[neighborNode]){
                q.push(neighborNode); //check..if neighbour is not visited..then push else don't.
          
                visited[neighborNode] = true; //and mark current neighbour as true.
            } 
        }
    }
    
    return ans; //return final answer.
}


//like this way also you can get nbr from adjacent list.
 while(!q.empty()){
    int node = q.front();
    ans.push_back(node);
    q.pop();
    
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            q.push(nbr);
            visited[nbr]=true;
        }
    }
}