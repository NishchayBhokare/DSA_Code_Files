//GFG

// we're using toplogical sort kahn's alog BFS technique...we can use topological sort only in
//DAG(Directed Acyclic Graph) so if we use..in ascylic graph..we will get wrong answer...
//so now..we're using it here.

//Approach 1: if graph is cyclic..then count of nodes..will not equal to total nodes...it will
//be less than total nodes.
 bool isCyclic(int V, vector<vector<int>> adj) {
    vector<int>indegree(V);
    queue<int>q;
    
    //creation of indegree.
    for(int i = 0; i<adj.size(); i++){
        for(auto j:adj[i]){
            indegree[j]++;
        }
    }
    
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        count++;
        
        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    
    if(count != V) //if count not equal to total nodes..then return true..i.e cyclic graph.
        return true;
    
    return false;
}

//Approach 2: if graph is cyclic..then at the end in inorder vector...any of the nodes..will have..
//indegree greater than 0 because..with cyclic graph we cannot make indegree of all nodes to 0.
bool isCyclic(int V, vector<vector<int>> adj) {  
    vector<int>indegree(V);
    queue<int>q;
    
    //creation of indegree.
    for(int i = 0; i<adj.size(); i++){
        for(auto j:adj[i]){
            indegree[j]++;
        }
    }
    
    
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    for(auto i:indegree){
        if(i != 0) //if for any node..vertex..if indegree is still greater than 0 i.e not equal to 0 then return true.
            return true;
    }
    return false;
}