 //GFG.
 //TC-O(N)
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
               
              long long totalTime = nodeTime + nbrTime;
               
            
                //when we are raching first time to the nebour node..then push this new distance in queue
                //and assing ways to reach to nbrNode equals to nodeVal because first time we're reaching so put value as it is.
              if(totalTime < distance[nbrNode]){
                  distance[nbrNode] = totalTime;
                  pq.push({totalTime, nbrNode});
                  ways[nbrNode] = ways[nodeVal];

              }
              
              //second time raching for same node with same distance..then update the number of ways..to reach nbr node i.e current nebour node ways + parent node ways.
              else if(totalTime == distance[nbrNode]){
                  ways[nbrNode] = (ways[nbrNode] + ways[nodeVal])%mod;
              }
          }
        }
        return (ways[n-1]%mod);
    }