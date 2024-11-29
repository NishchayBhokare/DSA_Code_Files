//GFG
//BFS and DFS. approach 3 is dfs.

//Approach 1: using BFS -> Optimised approach. TC-O(V+E) SC-O(V)
//simple logic..just do bfs..and mark current node suppose as 1 and their adjacent node is opposite of it..i.e 0.
//if at any point adjacent node is alreayd visited and it's color as same to the node..
//that means..graph is not bipartite..because..no two adjacent nodes can have same color.

//Another observation is...if graph is linear of with even number of cycle..then it's bipartite graph.
//if graph have odd number of cycle then it's not bipartite.
 bool isBipartite(vector<vector<int>>& adj) {
    
    int n = adj.size();
    
    queue<int>q;
    vector<int>color(n,-1);
    
    q.push(0); //node is zero and color is 1.
    color[0] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto nbr:adj[node]){
            
            if(color[nbr] == color[node]){ //no need to create visited array if nbr is not visited..
            // then that time color will be -1..so that color will not match.
            //but if color is same..that means..nbr is already visited..and color is same..that is the case not bipartite
            
                return false;
            }
            
            if(color[nbr] == -1){ //just check...color for nbr is -1 or not..if yes that means..first time we're visiting.
                q.push(nbr);
                
                color[nbr] = !color[node]; //set opposite color.
            }
            
        }
    }
    
    return true;
}


//Approach 2: using BFS..but using visited array to understand in better way.
bool isBipartite(vector<vector<int>>& adj) {
    
    int n = adj.size();
    
    queue<int>q;
    vector<int>color(n,1);
    
    vector<bool>visited(n,false);
    
    q.push(0); //node is zero and color is 1.
    visited[0] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto nbr:adj[node]){
            
            if(visited[nbr] && color[nbr] == color[node]){ //so if it's visited and have same color..then not bipertite
                return false;
            }
            
            if(!visited[nbr]){
                q.push(nbr);
                
                color[nbr] = !color[node];
                visited[nbr] = true;
            }
        }
    }
    
    return true;
}


//Approach 3: Using DFS algorithm.
bool checkBipartite(int node, vector<vector<int>>& adj, vector<int>&color){       
    for(auto nbr:adj[node]){
            
        if( color[nbr] == color[node]){ //no need to create parent array..visited array...
        //if nbr is parent...then color will not match..and if nbr is not visited..then that time color will be -1..so 
        //that too will not match.
        
            return false;
        }
        
        if(color[nbr] == -1){ //just check...visited or not..if not visited..then color will be -1.
            color[nbr] = !color[node]; //set opposite color..and move to nbr.
            if( !checkBipartite(nbr,adj,color) ) //if it is not bipartite..then don't wait..return immediately false.
                return false;
        }
        
    }
    
    return true; //if at the end..if we found that it's bipartite..then return true.
}

bool isBipartite(vector<vector<int>>& adj) {
    
    int n = adj.size();
    vector<int>color(n,-1);
    
    color[0] = 1;
    
    return checkBipartite(0,adj,color);
}


//little differnt in above..for coloring.
bool checkBipartite(int node, int nodeColor, vector<vector<int>>& adj, vector<int>&color){
        
        for(auto nbr:adj[node]){
            
            color[node] = nodeColor; //marking current node to node color.
                
            if( color[nbr] == color[node]){ //no need to create parent array..visited array...
            //if nbr is parent...then color will not match..and if nbr is not visited..then that time color will be -1..so 
            //that too will not match.
            
                return false;
            }
            
            if(color[nbr] == -1){ //just check...
                int nbrColor = !nodeColor;
                
                if( !checkBipartite(nbr,nbrColor,adj, color) )
                    return false;
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        
       int n = adj.size();
       vector<int>color(n,-1);
        
       color[0] = 1;
       int node = 0;
       int nodeColor = 1;

       return checkBipartite(node,nodeColor,adj,color); //here passing color also..for current node.
    }