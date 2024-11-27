//GFG
//Kosaraju Algo.
//We have to find strongly connected components..that means...these components can be cycle or single node.
//specifically the components in which from any node to any node..we can visit..those components are
//strongly connected component..here exception is there..if single node also the strongly connected component.

//so to find these..logic is first do topological sort..because we want to get nodes like in that way and store nodes in stack.
//then change the links..if u to v is link...make v to u.
//it is just because.. we have done topological sort.
//then again do dfs..just incremnet count..when we are calling dfs function..


void getTopoLogicalSort(int node, vector<vector<int>>& adj, stack<int>&topo,
    unordered_map<int,bool> &visited){
        
    visited[node]  = true;
    
    for(auto nbr:adj[node]){
        if(!visited[nbr])
            getTopoLogicalSort(nbr,adj,topo,visited);
    }
    
    topo.push(node);
}

void getCountOfStronglyConnectedComp(int node, unordered_map<int,list<int>>&transpose, 
    unordered_map<int,bool> &visited){
    
    visited[node] = true;
    
    for(auto nbr:transpose[node]){
        if(!visited[nbr])
            getCountOfStronglyConnectedComp(nbr,transpose,visited);
        
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    stack<int>topo;
    unordered_map<int,bool> visited;
    
    unordered_map<int,list<int>>transpose;
    
    //first get toplogical Sort
    for(int i = 0; i<V; i++){
        if(!visited[i])
                getTopoLogicalSort(i,adj,topo,visited);
    }
    
    
    
    // transpose adjacency list.
    for(int i = 0; i<V; i++){
        visited[i] = false; //updating visited map to false for all nodes.
        
        for(auto j:adj[i]){
            transpose[j].push_back(i);    
        }
    }
    
    //get count of strongly connectd components.
    int count = 0;
    
    while(!topo.empty()){
        int node = topo.top();
        topo.pop();
        
        if(!visited[node]){
            count++; //increment count for thes new node..which will going to be stronly connected
            //component.
            
            getCountOfStronglyConnectedComp(node,transpose,visited);
        }    
    }
    
    
    return count;
}