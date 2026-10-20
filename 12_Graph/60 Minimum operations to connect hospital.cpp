
//Using disjoint set. Number of connected component approach. 
//TC-O(V+E) SC-O(V)
class DisjointSet{
    
    public:
    vector<int>parent;
    vector<int>size;
    
    DisjointSet(int n){
        
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
            
        size.resize(n,1);
    }
    
    int findParent(int up){
        
        if(parent[up] == up)
            return up;
            
        return parent[up] = findParent(parent[up]);
    }
    
    void makeUnion(int u, int v){
        
        int up = findParent(u);
        int vp = findParent(v);
        
        if(size[up] >= size[vp]){
            size[up] += size[vp];
            parent[vp] = up;
        }
        else{
            size[vp] += size[up];
            parent[up] = vp;
        }
    }
};

class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        // int edgeCnt = n;
        DisjointSet ds(V);
        if(V-n > 1) return -1; //to connect V vertices, at least V-1 edges should be there.
        
        for(auto m:edges){
            
            int u = m[0];
            int v = m[1];
            
            int up = ds.findParent(u);
            int vp = ds.findParent(v);
            
            if(up == vp) continue;
            
            ds.makeUnion(u,v);
        }
        
        int cnt = 0;
        for(int i=0; i<V; i++){
            
            if(ds.parent[i] == i)
                cnt++;
        }
        
        return cnt-1;
    }
};

//Approach 2: Using simply DFS.
class Solution {
  public:
    void solve(int node, vector<vector<int>>&adj, vector<int>&visited){
        
        visited[node]=1;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr])
                solve(nbr,adj,visited);
        }
    }
  
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        if(V-n > 1) return -1;
        
        vector<vector<int>>adj(V);
        
        for(auto m:edges){
            int u = m[0];
            int v = m[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cnt = 0;
        vector<int>visited(V,0);
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                cnt++;
                solve(i,adj,visited);
            }
        }
        
        return cnt-1;
    }
};


