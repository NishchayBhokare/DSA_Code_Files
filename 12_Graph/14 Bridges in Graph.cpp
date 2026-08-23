//Code studio question
//Tarajan's algorithm.

Bridges in graph is the edge between u to v..so if we remove that edge...then graph will divide
into the two parts.

//Here we have to find all the bridges prsent in graph.
//Logic is creation of two arrays low and discovery array..and timer.

//on every dfs call timer will incresase by one to go from one node to next node.

//Low array stores..minimum time of insertion of all adjacent nodes apart from parent because..we are going to break this edge link..
//so we want that..this node should reachable from other nodes..except parent.

//Discovery array stores initial timer value..when we reached that node first time.

//TC-O(V+2E) SC-O(V+2E) + O(3V) + O(V-1 i.e V) for answer.
void solve(int node,int parent, unordered_map<int,list<int>> &adj, vector<int>&low, vector<int>&disco, 
    unordered_map<int,bool> &visited, vector<vector<int>> &result, int &timer){

    visited[node] = true;
    disco[node] = low[node] = timer++;

    for(auto nbr:adj[node]){
        if(nbr == parent) continue;
        
        if(!visited[nbr]){
            solve(nbr,node,adj,low,disco,visited,result,timer);

  
            low[node] = min(low[node], low[nbr]); 
            //current node taking lowest insrtion time from their adjacent nodes..


            //if lowerst insertion time from adjacent node...is greater than discovery of current node..that means..this neighbor is 
            //not reacheable if we delete the link betwee them.
            if(low[nbr] > disco[node]){
                //if this condition is satisfied..then this edge is bridge..so add it in answer.
                result.push_back({node,nbr});
            }

        }
        else{
            //this is back edge condition..that means there is another path to reach this node.
            //if we already visited this neihbor..then take discovery time/low of it.
            low[node] = min(low[node], low[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    unordered_map<int,list<int>> adj;

    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(v,-1);
    vector<int> disco(v,-1); //initialising with -1.
    unordered_map<int,bool> visited;
    vector<vector<int>> result;
    
    int timer = 0;

    for(int node = 0; node<v; node++){ //if graph is disconnceted..then in this case we need to traverse for all the vertices.
        if(!visited[node]){
            solve(node,-1,adj,low,disco,visited,result,timer);
        }
    }

    return result; //final result.
}



//Approach 2:logic is if there is another path to reach d, that means its not bridge edge.
//note we're passing c to solve function..so that..we will traverse graph from c.

void solve(int &node,int&c, int &d, vector<int> adj[], unordered_map<int,bool> &visited){
    
    visited[node] = true;
    
    for(auto nbr:adj[node]){

        if(node == c && nbr == d)  //if parent is c and neihbor is d..then skip this iteration.
        continue;
        
        if(!visited[nbr]){
        solve(nbr,c,d, adj, visited);
        }
        
    }

}


int isBridge(int V, vector<int> adj[], int c, int d) 
{
    unordered_map<int,bool> visited;
    solve(c,c,d,adj,visited);

    if(visited[d] == true) //if d is visited..then return false.
        return false;
        
    return true; //else true.
}


//Approach 3: first check component count without adding edge in adjacency list.
//then again check by adding edge is adjacency list. if both count doesn't matches then it is bridge.
void dfs(vector<vector<int>>&adj, vector<int>&visited, int node){
        
        visited[node] = 1;
        
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr])
                dfs(adj,visited,nbr);
        }
    }
  
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(auto m:edges){
            int u = m[0];
            int v = m[1];
            
            if(u == c and v == d) continue;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int comp1 = 0;
        
        vector<int>visited(V,0);
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                comp1++;
                dfs(adj,visited,i);
            }
        }
        
        adj[c].push_back(d);
        adj[d].push_back(c);
        
        fill(visited.begin(), visited.end(),0);
        
        int comp2 = 0;
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                comp2++;
                dfs(adj,visited,i);
            }
        }
        
        return comp1 != comp2; //if both comp count is not same that menas there is change in component
        // count. which is nothing but by removing given edge, component count will get increase.
    }

