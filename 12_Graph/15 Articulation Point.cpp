//gfg
//Articualtion point is the point..by which..if we remove this node...then graph will divide in sub components.
//Same like bridges in graph..only changes in if conditions.

void solve(int node,int parent, vector<int>adj[], vector<int>&low, vector<int>&disco,
    unordered_map<int,bool>&visited, vector<int>&ap, int &timer){
        
        
    visited[node] = true;
    
    low[node] = disco[node] = timer++;
    
    int child = 0;
    
    for(auto nbr:adj[node]){
        
        if(nbr == parent) continue;
        
        if(!visited[nbr]){
            
            solve(nbr,node,adj,low,disco,visited,ap,timer);
            
            low[node] = min(low[node], low[nbr]); //same like bridges.
            
            //here low's nbr should not be even equal to disco of node..because we're going to delete this node..so current neighbor should
            //reachable to above node. if it's not then low's nbr will greater than 1.
            if(low[nbr] >= disco[node] && parent != -1){ //we are not taking parent condition here..because..for neighbor node..to reach above parent node
            //node 0..there are no nodes..so to handle this case..we're skipping parent.
                ap[node] = 1;
            }
            
            child++;
        
        }
        else{
            low[node] = min(low[node],disco[nbr]); 
            //if already visited..then take minimum of it's disco's nbr...

        }
    }
    
    if(child > 1 && parent == -1)  //if child is greater than 1 that means..if we delete this 0 node..graph will subdivided..
    //because..even if there are two child links for this node..but if that two child links also connected with each other..
    //then that time..count for this parent node will be 1..beause of visited array..as already..we visited second child of current node.
    
    //so in that case..child is not ap..but if child is greter than 1 and not connected child links each other
    //that time..count of child will be 2. because..we are not able to visit second part of node..so for that we have to traverse
    //from current node..so child will again increased by 1.
        ap[node] = 1;
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    
    vector<int>low(V,-1);
    vector<int>disco(V,-1);
    vector<int>ap(V,0);
    unordered_map<int,bool>visited;
    
    int node = 0, timer = 0;;
    solve(node,-1,adj,low,disco,visited,ap,timer);
    
    vector<int>ans;
    
    for(int i = 0; i<ap.size(); i++){
        if(ap[i])
            ans.push_back(i);
    }
    
    if(ans.size() == 0) return {-1};
    
    return ans;
}