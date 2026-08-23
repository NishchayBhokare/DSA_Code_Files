 //GFG.
 //TC-O(ELogV) SC-O(V+E)
 //Approach 1: using priority queue, distance array and ways array.
 //The logic is..as we have to calculate number of ways to reach destination..
 //so we're using distance array to track shortest distance for any node..and taking ways array..which derscribes..
 //ways of or count of shortest distance on which we can reach that path..example..for node x with shortest distance 7 there can be 4 paths..so answer will be..
 //and that 4 will is stored in ways array for node x.
 int countPaths(int n, vector<vector<int>>& roads) 
    {    vector<vector<pair<long long,long long>> > adj(n);
        
        for(auto i:roads){
            long long u = i[0];
            long long v = i[1];
            long long t = i[2];
            
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        long long mod = (1e9 + 7) ;
        vector<long long>distance(n, 1e10); //1e10 because..distance value can be 1e9 so.
        vector<long long>ways(n,0);
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, 
            greater<pair<long long,long long>> > pq;
        
        pq.push({0,0}); //{time,node}.
        ways[0]=1;
        distance[0]=0;
        while(!pq.empty()){
           
          long long nodeTime = pq.top().first;
          long long nodeVal = pq.top().second;
          pq.pop();
           
           
          for(auto nbr:adj[nodeVal]){
              long long nbrNode = nbr.first;
              long long nbrTime = nbr.second;
               
              long long totalNbrTime = nodeTime + nbrTime;
               
            
                //when we are raching first time to the nebour node..then push this new distance in queue
                //and assing ways to reach to nbrNode equals to nodeVal because first time we're reaching so put value as it is.
              if(totalNbrTime < distance[nbrNode]){
                  distance[nbrNode] = totalNbrTime;
                  pq.push({totalNbrTime, nbrNode});
                  ways[nbrNode] = ways[nodeVal];

              }
              
              //second time raching for same node with same distance..then update the number of ways..to reach nbr node i.e current nebour node ways + parent node ways.
              else if(totalNbrTime == distance[nbrNode]){
                  ways[nbrNode] = (ways[nbrNode] + ways[nodeVal])%mod;
              }
          }
        }
        return (ways[n-1]%mod);
    }


    //Second Approach using unordered map, simple one.
    class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto m:edges){
            int u=m[0], v=m[1], w=m[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int>distance(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,0}); //{dist,node};
        distance[0]=0;
        
        int minDist = INT_MAX, cnt = 1;
        unordered_map<int,int>ump;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int dist = pq.top().first;
            
            pq.pop();
            
            if(node == V-1){
               minDist = min(minDist,dist);
               ump[dist]++;
            }
            
            for(auto nbr:adj[node]){
                
                int nbrNode = nbr.first;
                int nbrDist = nbr.second + dist;
                
                if(nbrDist <= distance[nbrNode]){
                    pq.push({nbrDist,nbrNode});
                    
                    distance[nbrNode] = nbrDist;
                }


                // if(nbrNode == V-1){ //here also we can add this condition.
                //    minDist = min(minDist,nbrDist);
                //    ump[nbrDist]++;
                // }
            }
        }
        
        return ump[minDist];
    }
};

























