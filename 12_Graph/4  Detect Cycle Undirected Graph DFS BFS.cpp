//GFG

//Approach 1:using DFS traversal..but without using parent data structure..only using parent varaible.
 bool solve(int node, int parent, vector<vector<int>>& adj,
    unordered_map<int,bool>&visited){
    
    visited[node] = true; //visiting current node.
    
    for(auto neighbor:adj[node]){
        if(visited[neighbor] && neighbor != parent){ //checking cycle destection condition.
            return true;
        }
        else if(!visited[neighbor]){
            
            bool ans = solve(neighbor,node,adj,visited); //now passing child as neighbour and current node as parent of neigbor child.
            
            if(ans) return ans;
        }
    }

    //or
    // for(auto nbr:adj[node]){ //we can write for loop like this too.
        
    //     if(nbr == parent) continue;
        
    //     if(visited[nbr]) return true;
        
    //     bool ans = solve(nbr,node,adj,visited);
    //     if(ans) return true;
    // }
    
    return false;
}    

bool isCycle(vector<vector<int>>& adj) {
    bool ans = false;
    unordered_map<int,bool>visited;
    
    for(int node=0; node<adj.size(); node++){  //we're looping over all nodes..because there can be multiple components.
        if(!visited[node]){  
            int parent = -1;
            if(solve(node, parent, adj, visited)) //if return value is true..then no need to check further..return true as it is
                return true;
        }
    }
        
    return false;
}


//Approach 2: using DFS traversal.
//same dfs traversal...just addition of this parent condition and parent data strucutre.
//we can neglect parent data sturcture..by passing parent from arguement..because we're going deeper
//by taking one node..so we can pass parent. refer approach 1.
 bool solve(int node, vector<vector<int>>& adj, unordered_map<int,int>&parent,
    unordered_map<int,bool>&visited){
    
    visited[node] = true;
    
    for(auto neighbor:adj[node]){
        if(visited[neighbor] && neighbor != parent[node]){ //this is new condition.
            return true;
        }
        else if(!visited[neighbor]){
            parent[neighbor] = node;
            bool ans = solve(neighbor,adj,parent,visited);
            
            if(ans) return ans;
        }
    }
    
    return false;
}    

bool isCycle(vector<vector<int>>& adj) {
    bool ans = false;
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    
    for(auto i:adj){
        for(auto j:i){
            if(!visited[j])
            {
                parent[j]=-1; //initially parent is -1. if we not write this..still it will work. because starting point is parent.
                ans = solve(j,adj,parent,visited);
                
                if(ans) return ans; //if cycle is presnet then return immediately.
            }
        }
    }
    
    return ans;
}

//Approach 3: detecting cycle using undirected graph by BFS Traversal.
//logic is just addition of parent map..which tracks parent of current node.
//if neighbour node is already visited..and that is not parent for current node..then there cycle 
//is present.
 bool solve(int j, vector<vector<int>>& adj, unordered_map<int,int>&parent,
    unordered_map<int,bool>&visited){
    
    queue<int>q;
    q.push(j);
    // parent[j]=-1; //for first node..there is not parent..so insert -1.
    //now -1 condition handles already while initialising array with all -1.
    visited[j]=true;

    
    while(!q.empty()){
        int node = q.front();
        
        q.pop();
        
        for(auto neighbor:adj[node]){
            if(visited[neighbor] && neighbor != parent[node]){ //this is additional condition. if neigbour is already true..and it's not parent..then return true..that cycle is present.
                return true;
            }
            
            if(!visited[neighbor]){ //if neigbour is not visited then push in queue and add his parent as current node and mark as visited.
                q.push(neighbor);
                parent[neighbor]=node;
                visited[neighbor]=true;
                
            }
            
        }
    } 
    
    return false; //if we reach till here then cycle is not parent for this component.
}    
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    bool ans = false;
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent(V,-1);
    
        for(int i = 0; i<V; i++){
            if(!visited[i])
            {
                ans = solve(i,adj,parent,visited);
                
                if(ans) return ans; //if cycle is presnet then return immediately.
            }
        }
    
    return ans; //if we reach till here..then cycle is not present.
}