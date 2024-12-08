//Code studio question
//Tarajan's algorithm.

//Bridges in graph is the edge between u to v..so if we remove that edge...then graph will divide
//into the two parts.

//Here we have to find all the bridges prsent in graph.
//Logic is creation two arrays low and discovery array..and timer.

//on every dfs call timer will incresase by one to go from one node to next node.

//Low array stores..minimum time of insertion of all adjacent nodes apart from parent because..we are going to break this edge link..
//so we want that..this node should reachable from other nodes..except parent.

//Discovery array stores initial timer value..when we reached that node first time.

void solve(int node,int parent, unordered_map<int,list<int>> &adj, vector<int>&low, vector<int>&disco, 
    unordered_map<int,bool> &visited, vector<vector<int>> &result, int &timer){

    visited[node] = true;
    disco[node] = low[node] = timer++;

    for(auto nbr:adj[node]){
        if(nbr == parent) continue;
        
        if(!visited[nbr]){
            solve(nbr,node,adj,low,disco,visited,result,timer);

  
            low[node] = min(low[node], low[nbr]); 
            //current node taking lowest insrtion time from theri adjacent nodes..


            //if lowerst insertion time from adjacent node...is greater than discovery of current node..that means..this neighbor is 
            //not reacheable if we delete the link betwee them.
            if(low[nbr] > disco[node]){
                //if this condition is satisfied..then this edge is bridge..so add it in answer.
                result.push_back({node,nbr});
            }

        }
        else{
            //this is back edge condition..that means there is another path to reach this node.
            //if we already visited this neihbor..then take discovery time of it.
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


//GFG question need to check..bridge is present between given two nodes or not.
//if we break connection between them and point c to c and d to d. then after when we do dfs from 
//node c..we should able to reach node d..if node d is not visited that means..bridge is present.
 bool solve(int &first, int &second, vector<int> adj[], unordered_map<int,bool> &visited){
        
        visited[first] = true;
        
        if(visited[second]) //if it's reacheable then just return false.
            return false;
        
        for(auto nbr:adj[first]){
        
          if(!visited[nbr]){
             bool ans = solve(nbr, second, adj, visited);
             
             if(ans == false) //if at any point answer is false..then return false.
                return false;
          }
            
        }
        
        
        return true;
    }
  
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        //here remvoing links.
        for(int i = 0; i<adj[d].size(); i++){
            if(adj[d][i] == c)
                adj[d][i] = d; //pointing thier links to itself.
        }
        
        for(int i = 0; i<adj[c].size(); i++){
            if(adj[c][i] == d)
                adj[c][i] = c; //pointing to itself.
        }
        
        
        unordered_map<int,bool> visited;
        
        //now check..d node is reachable or not.
       return solve(c,d,adj,visited);
 
    }


//without doing changes in links..we can solve this problem ..by simpley skipping iteration
//when c is parent and d is neihbor.
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