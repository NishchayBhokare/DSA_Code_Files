//Approach 1: logic is centered element of tree based graph will be the node who has minimum height among all other nodes.
//So, concept of topological sort, degree is used.

//TC-O(V) SC-O(V)
class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>deg(V,0);
        
        for(auto m:edges){
            
            int u = m[0];
            int v = m[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            deg[u]++;
            deg[v]++;
        }
        
        vector<int>ans; //answer length could be 1 or 2 max. 
 
        queue<int>q;
        
        for(int i=0; i<V; i++){
            
            if(deg[i] <= 1) //lesser than equal to 1 because if there is single 
            //node and zero edges. so degree of node will be 0.
                q.push(i);
        }
        
        while(!q.empty()){
            
            int n = q.size();
            
            vector<int>temp;
            
            for(int i=0; i<n; i++){
                int node = q.front();
                temp.push_back(node);
                
                q.pop();
                
                for(auto nbr:adj[node]){
                    
                    deg[nbr]--;
                    
                    if(deg[nbr] == 1)
                        q.push(nbr);
                }
                
            }
            
            ans = temp;
        }
        
        return ans;
    }
};


//Approach 2: Find out height for every node and then store minimum height node. 
//but gives TLE as TC is O(V2) and SC-O(V)
class Solution {
  public:
    int solve(int node, vector<int>&visited, vector<vector<int>>&adj){
        
        visited[node]=1;
        
        int maxi = 0;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr]){
                int curr = 1 + solve(nbr,visited,adj);
                maxi = max(maxi,curr);
            }
        }
        
        return maxi;
    }
  
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        
        for(auto m:edges){
            
            int u = m[0];
            int v = m[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int mini = INT_MAX;
        vector<int>ans;
   
        
        for(int i=0; i<V; i++){

           vector<int>visited(V,0);
           int currAns = solve(i,visited,adj);

           if(currAns < mini){
               ans.clear();
               ans.push_back(i);
               mini = currAns;
           }
           else if(currAns == mini){
               ans.push_back(i);
           }
       }
        
        return ans;
    }
};














