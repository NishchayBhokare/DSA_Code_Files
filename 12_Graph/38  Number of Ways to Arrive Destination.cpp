 
 //TC-O(N)
 
 int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long,vector<pair<long long,long long>> > adj;
    
    for(auto i:roads){
        long long u = i[0];
        long long v = i[1];
        long long t = i[2];
        
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    long long mod = (1e9 + 7) ;
    vector<long long>distance(n, 1e10);
    vector<long long>ways(n,0);
    
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> > pq;
    
    pq.push({0,0}); //{time,node}.
    ways[0]=1;
    distance[0]=0;
    long long count = 0;
    while(!pq.empty()){
        
        long long nodeTime = pq.top().first;
        long long nodeVal = pq.top().second;
        pq.pop();
        
        
        for(auto nbr:adj[nodeVal]){
            long long nbrNode = nbr.first;
            long long nbrTime = nbr.second;
            
            long long totalTime = nodeTime + nbrTime;
            
                
            if(totalTime < distance[nbrNode]){
                distance[nbrNode] = totalTime;
                pq.push({totalTime, nbrNode});
                
                ways[nbrNode] = ways[nodeVal];
                if(nbrNode == n-1){
                count++;
                }
            }
            
            else if(totalTime == distance[nbrNode]){
                if(nbrNode == n-1){
                    count++;
            }
                ways[nbrNode] = (ways[nbrNode] + ways[nodeVal])%mod;
            }
        }
    }
    cout<<count<<endl;
    return (ways[n-1]%mod);
}