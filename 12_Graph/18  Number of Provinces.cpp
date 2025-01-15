//GFG
//Number of provinces is nothing but number of components we have to return.

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


//Approach 3: using disjoint set.
//As we find to number of components...so from disjoint set we can understand that..the numebr of ultimate parent
//is nothing but number of components..so by this logic we can solve this question
class DisjointSet{
    public:
    vector<int>rank;
    vector<int>parent;
    
    DisjointSet(int v){
        
        rank.resize(v,0);
        parent.resize(v);
        
        for(int i = 0; i<v; i++){
            parent[i]=i;
        }
    }
    
    
    int findParent(int node){
        if(node == parent[node])
            return node;
            
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnionByRank(int uP, int vP){
        
        if(rank[uP] == rank[vP]){
            parent[vP] = uP;
            rank[uP]++;
        }
        else if(rank[uP] > rank[vP]){
            parent[vP] = uP;
        }
        else
            parent[uP] = vP;
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisjointSet ds(V);
        
        for(int u = 0; u<V; u++){
            
            for(int v = 0; v<adj[u].size(); v++){
                if(adj[u][v] == 1){
                    
                    int uP = ds.findParent(u);
                    int vP = ds.findParent(v);
                    
                    if(uP != vP){
                        ds.makeUnionByRank(uP,vP);
                    }
                    
                }
            }
        }
        

        int count = 0;
        for(int i = 0; i<ds.parent.size(); i++){ //at the end logic is..if node is ultimate parent..then 
        //it will be parent of itself..so count those ultimate parent.
            if(ds.parent[i] == i) //this is conditon.
                count++;
        }
        
        return count; //return count.
    }
    


    //Also we can solve like this too..without traversing over parent. first we will do count equal to numebr of nodes.
    //as we know..we will do union only if there is edge from u to v and its ultimate parent is not equals.
    //so whenever we're calling union function..that time..we will decrement count by 1.
    //because.. there is edge between u to v so, only one will be ultimate parent..so decrement count.
    
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisjointSet ds(V);
        int count = V;
        
        for(int u = 0; u<V; u++){
            
            for(int v = 0; v<adj[u].size(); v++){
                if(adj[u][v] == 1){
                    
                    int uP = ds.findParent(u);
                    int vP = ds.findParent(v);
                    
                    if(uP != vP){ 
                        count--;
                        ds.makeUnionByRank(uP,vP);
                    }
                    
                }
            }
        }        
        return count;
    }
};