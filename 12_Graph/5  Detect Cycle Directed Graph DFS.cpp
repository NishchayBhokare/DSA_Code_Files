//GFG.

//Approach 1: using DFS visited..we can track..all the active..parent calls. 
bool solve(int node, vector<vector<int>> &adj, unordered_map<int,bool> &visited, 
unordered_map<int,bool> &dfsVisited){
    
    visited[node]=true;
    dfsVisited[node]=true; //making current node as dfs visited.
    
    for(auto neighbor:adj[node]){ 

        //if neighbor is present in dfs visited as true..that means..to this neighbor..we reached till this
        //current node..and from current node..we can go to neighbor..that means..cycle is present.
        if(dfsVisited[neighbor])  
            return true;
            
        if(!visited[neighbor]){ //if not visited..then call for neighbor for further checking.
            bool ans = solve(neighbor,adj,visited,dfsVisited);
            if(ans) return ans;
        }
    }
    
                                
    dfsVisited[node]=false;  //before going back..make current node as not dfs visited.
    return false;
}


bool isCyclic(int V, vector<vector<int>> adj) {

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited; //creating dfs visited..
    bool ans = false;
    
    for(int node = 0; node<V; node++){
        
        if(!visited[node]){
            ans = solve(node,adj,visited, dfsVisited);
        
            if(ans) return ans;
        }
    }
    
    
    return ans;
}





//Approach 2: using DFS..but tracking current active parent.
//logic is mainting parent vector..which shows active parent.
//if new node is active parent...then cycle is present
 bool solve(int node, vector<vector<int>> &adj, vector<int>&parentVec,
    unordered_map<int,bool> &visited){
    parentVec.push_back(node); //making current node as active parent.
    
    for(auto neighbor:adj[node]){
        
        //checking is current neighbor is active parent..if yes..that means..from that parent we
        //reached to current node..then from current node we can reach to parent and again to current
        //node..so that means cycle is present.
        for(auto parent:parentVec){
            if(neighbor == parent)
                return true;
        }
        
        if(!visited[neighbor]){ //if not visited...then call.
            bool ans = solve(neighbor,adj,parentVec,visited);
        
            if(ans) return ans;
        }
    }
    
    parentVec.pop_back(); //before going back..make remove current node..from active parent.
    return false;
}


bool isCyclic(int V, vector<vector<int>> adj) {
    
    vector<int>parentVec;
    unordered_map<int,bool> visited;
    bool ans = false;
    
    for(int node = 0; node<V; node++){
        if(!visited[node]){
            
            ans = solve(node,adj,parentVec,visited);
            if(ans) return ans;
        }
    }
    
    
    return ans;
}