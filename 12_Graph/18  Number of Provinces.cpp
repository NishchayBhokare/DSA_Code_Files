//GFG
//Number of provinces is nothing but number components we have to return.

//Approach 1: using dfs.
//Logic is..when we call dfs function for main..then increment count..because..that will be start node
//of dfs call..so if..there are two components..then two times..solve function will call from main.
//TC-O(V + (V+E) = V) i.e V and SC-O(V)
void solve(int node, vector<vector<int>> &adj, unordered_map<int,bool>&visited){
    
    visited[node] = true;
    
    for(int j = 0; j<adj[node].size(); j++){ //given adjacency matrix..so handling this for loop function accroding to input.
    //looping for adj[node] sub array.
        if(adj[node][j] == 1 && !visited[j]){ //if value at adj[node][j] is 1..that means..there is edge to reach to node j..and also check..
        //if j is visited or not..if not..then call this function.
            solve(j,adj,visited); //next element which are attached to current node.
        }
    }
    
}

int numProvinces(vector<vector<int>> adj, int V) {
    
    int count = 0;
    
    unordered_map<int,bool>visited;
    
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            count++; //incrementing count.
            solve(i,adj,visited);
        }
    }
    
    return count;
}

//we can solve this function using disjoint..so look into that too.

//Approach 2: using dfs.
int numProvinces(vector<vector<int>> adj, int V) {
    int count = 0;
    unordered_map<int,bool>visited;
    queue<int>q;
    
    for(int i = 0; i<V; i++){  //looping for 0 to less than V.
        if(!visited[i]){
            q.push(i); //pushing first vertex..node 0.
            visited[i]=true; //mark as visited.
            count++; //this is the situation where we have to incrmeent count..because..this is starting node of new comp.
        }
    
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int j = 0; j<adj[node].size(); j++){ 
                if(adj[node][j] == 1 && !visited[j]){
                    q.push(j);
                
                    visited[j] = true; 
                }
            }
        }
    }
    
    return count;
}