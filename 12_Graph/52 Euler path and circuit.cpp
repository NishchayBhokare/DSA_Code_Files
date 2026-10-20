//Path will be eular circuit if,
//Indegree of every node is even and all non-zero indegree node must be connected.

//Path will be eular path if, 
//zero or two node have odd degree and all non-zero indegree node must be connected.

class Solution {
  public:
    void solve(int node, vector<int>&visited, vector<vector<int>>&adj){
        
        visited[node]=1;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr])
                solve(nbr,visited,adj);
        }
    }
  
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        
        
        vector<int>indeg(V,0);
        int oddCnt = 0;
        //calculate indegree for every node and count of nodes who have odd indegree.
        for(int i=0; i<V; i++){
            
            indeg[i] = adj[i].size();
            
            if(indeg[i] % 2 != 0) oddCnt++;
        }
          
        if(oddCnt != 0 and oddCnt != 2) //if oddcnt is other than 0 and 2 then return 0. that, no eularian path or circuit.
            return 0;
        
        
        vector<int>visited(V,0);
        
        for(int i=0; i<V; i++){ //simply do dfs for any node who have indegree greater than zero i.e non-zero indegree node.
            if(indeg[i]){
                solve(i,visited,adj);
                break; //once we done, just break out. we have to chec only once.
            }
        }
        
      
        //checking: if non zero degree nodes still not visited then return 0.
        for(int i=0; i<V; i++){
            
            if(indeg[i] > 0 and !visited[i])
                return 0;
        }
        
        if(oddCnt == 0) //now, if oddcnt is zero then it's eulerian circuit so return 2.
            return 2;
        
        return 1; //if oddCnt is either 0 or 2 then return 1.
    }
};