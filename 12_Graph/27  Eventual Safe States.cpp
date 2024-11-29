//GFG 

//I have solved this question by myselef..kudos to u nishu.
//Approach 1: Optimised Approach.

//we will do simpley dfs..so when..any particular node is not visited..then call for it.
//if it's visited..then there are two possbile reasons...either that node is safe node..or it's unsafe.
//if it's unsafe..then no need to check further..because..current node...connected to that node..so current node is also unsafe..so return false which indicates not safe.
//if it's safe..then check for next path..if present..then if we traverse over all the adjacents..and still
//we have not return as false..then current node is safe node..so mark it as safe and return true.
bool solve(int node, vector<int> adj[], vector<bool>&safe, vector<bool>&visited){
    
    visited[node] = true;
    
    // if(adj[node].size() == 0){ //we can add condition for terminal node..or can skip it..because..it will not goes into for loop and 
                                 //at last..we will mark this node as safe.
    //     //this is terminal node.
    //     safe[node] = true;
    //     return true;
    // }
    
    for(auto nbr:adj[node]){
        
        if(!visited[nbr]){
            
            bool ans = solve(nbr,adj,safe,visited);
            if(ans == false) //if at any point..node is unsafe then return false..
                return false;
        }
        
        else if(safe[nbr] == false){ //nbr is already visited but it's not safe.
            return false; //then no need to do further processing return false.
        }
        
    }
    
    safe[node] = true; //if we traversed all adjacent nodes..and till we reached here that means..this node is safe.
    return true;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<bool>safe(V,false); //initially marking safe node as false.
    vector<bool>visited(V,false);
    
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            solve(i,adj,safe,visited);
        }
    }
    
    vector<int>ans;
    
    for(int i = 0; i<V; i++){
        if(safe[i])
            ans.push_back(i);
    }
    
    return ans;
}




//Approach 2: using path array..we can solve it..we're using path array to check if cycle is prsent or not
//if not..then it's safe like that..if cycle is present then it's not safe so return false..but make sure...you are NOT uncehcking or removing path values from true to false.
//because there can be the nodes..attached to this cycle..so that node will also not safe. so to save that itration to check..because we already check..so that's why
//don't change values of path array..when cycle is detected
 bool solve(int node, vector<int> adj[], vector<bool>&safe, vector<bool>&visited, vector<bool>&path){
        
        visited[node] = true;
        path[node] = true;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr]){
                bool ans = solve(nbr,adj,safe,visited,path);
                if(ans == false){
                    return false;
                }
            }
            
            else if(path[nbr]){ //nbr is already visited and it's present in path array that means cycle is present..so return false;.
                return false; //then no need to do further processing return false.
            }
            
        }
        
        path[node] = false; //uncheck ...that is make false;
        safe[node] = true; //if we did all adjacent node travesing..and till we reached here that means..this node is safe.
        return true;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool>safe(V,false);
        vector<bool>path(V,false);
        vector<bool>visited(V,false);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                solve(i,adj,safe,visited,path);
            }
        }
        
        vector<int>ans;
        
        for(int i = 0; i<V; i++){ //traverse over the safe nodes and push i into the answer if that node is safe..i.e have value as true
            if(safe[i])
                ans.push_back(i);
        }
        
        return ans;
    }