class Solution {
  public:
    int solve(int n, int node, int parent, vector<vector<int>>&adjList, vector<int>&visited,int &cnt){
        
        visited[node]=1;
        // cout<<cnt<<endl;
        if(cnt==n) return 1;
        for(auto nbr:adjList[node]){
            
            if(!visited[nbr]){
                cnt++;
                int ans = solve(n,nbr,node,adjList,visited,cnt);
                cnt--;

                if(ans==1)
                    return ans;
            }
        }
        
        visited[node]=0;
        
        return 0;
    }
  
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<int>>adjList(n+1);
        
        for(auto m:edges){
            
            int u = m[0];
            int v = m[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
        for(int node=1; node<=n; node++){
         
            vector<int>visited(n+1,0);
            int cnt = 1;
            int ans = solve(n,node,-1,adjList,visited,cnt);
            
            if(ans) return ans;
        }
        
        return false;
    }
};
