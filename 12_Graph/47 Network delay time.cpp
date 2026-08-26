class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
   
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto m:edges){
            
            int u = m[0];
            int v = m[1];
            int w = m[2];
            adj[u].push_back({v,w});
         
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
 
        vector<int>distance(V, INT_MAX);
        
        pq.push({0,src});
        distance[src]=0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int dist = pq.top().first;
            
            pq.pop();
            
            for(auto nbr:adj[node]){
                
                int nbrNode = nbr.first;
                int nbrDist = nbr.second + dist;
         
                if(nbrDist < distance[nbrNode]){
                    
                    pq.push({nbrDist,nbrNode});
                    
                    distance[nbrNode] = nbrDist;
                }
            }
            
        }
        
        int ans = 0;
        for(auto i:distance){
            
            if(i == INT_MAX) 
                return -1;
                
            ans = max(ans,i);
        }
        
        return ans;
    }
    
};













