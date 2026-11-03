

//Approach 1: Optmise approach. Disjoint set. TC-O(nlogn) SC-O(n)
// The idea is to sort edges by weight and use Disjoint Set Union (DSU) to merge connected components. 
// Each merge adds the product of the two component sizes to the total number of valid paths
bool cmp(vector<int>&a, vector<int>&b){
    return a[2] < b[2];
}

class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        
        for(int i=0; i<n; i++) parent[i]=i;
    }
    
    int findParent(int up){
        
        if(parent[up] == up) return up;
        
        return parent[up] = findParent(parent[up]);
    }
    
    int makeUnion(int u, int v){
        
        int up = findParent(u);
        int vp = findParent(v);
        
        if(up == vp) return 0; //if ultimate parent is same then we already taken answer for it.
        //so avoid taking duplicate path.
        
        int paths = size[up] * size[vp]; //if ultimate parent is not same then path cnt will be 
        //product of both component size.
        
        if(size[up] >= size[vp]){ //normal logic of making union.
            size[up] += size[vp];
            parent[vp] = up;
        }
        else{
            size[vp] += size[up];
            parent[up] = vp;
        }
        
        return paths; //return path cnt.
    }
};

class Solution {
  public:

    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        
        //declare ds.      
        DisjointSet ds(n+1);

        //sort the edges accroding to weight in increasing order.
        sort(edges.begin(), edges.end(), cmp);
        
        vector<int>ans(queries.size());
        int totalPath = 0;
        
        //create pair of queries [query to index]
        vector<pair<int,int>>q;
        for(int i=0; i<queries.size(); i++){
            q.push_back({queries[i],i});
        }
        //sort new query pair vector according to query weight.
        sort(q.begin(), q.end());
        
        int j=0;
        for(auto pr:q){ //loop over the each query.
            
            int wt = pr.first;
            int ind = pr.second;
            
            while(j<edges.size() and edges[j][2]<=wt) //loop till, j is in range of edge size and
            //edge weight is less than or equal to query weight.
            {   
                int u=edges[j][0], v=edges[j][1];
                totalPath += ds.makeUnion(u,v); //make union and get totalPath cnt.
                j++; //incrment j for next edge weight.
            }
            ans[ind] = totalPath; //at last once we process all the possible edges for current query weight
            //then store answer at ind in ans.
        }
        
        return ans; //return answer.
    }

};




//Approach 2: Brute force approach. 
// The idea is to start a DFS from every node for each query and count all paths whose maximum edge 
// weight is at most the given value x. 

// TC-O(Q*(n+E) or O(Q*n^2) as no. of nodes and edges are almost equal.
// SC-O(n+E)
class Solution {
  public:
    void solve(int node, vector<vector<pair<int,int>>>&adj, vector<int>&visited, int &nodeCnt, int &maxWt){
        
        visited[node]=1;
        
        for(auto nbr:adj[node]){
            
            int nbrNode = nbr.first;
            int nbrWt = nbr.second;
            
            if(!visited[nbrNode] and nbrWt <= maxWt){
                nodeCnt++;
                solve(nbrNode, adj, visited, nodeCnt, maxWt);
            }
        }
    }
  
  
    
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        // code here
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto m:edges){
            int u=m[0], v=m[1], w=m[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int> ans;
        
        for(int q=0; q<queries.size(); q++){ //find answer for every query.
            
            vector<int>visited(n+1,0);
            int pathCnt=0;
            
            for(int node=1; node<=n; node++){ 
                
                int nodeCnt=1;
                if(!visited[node]){
                    
                    solve(node, adj, visited, nodeCnt, queries[q]);
                }
                
                nodeCnt--;
                pathCnt+= (nodeCnt*(nodeCnt+1)/2);
            }
            
            ans.push_back(pathCnt);
        }
        
        return ans;
    }
};
