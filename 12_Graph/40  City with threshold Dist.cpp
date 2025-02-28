//GFG. 
 
 //Approach 1: using flyod warshal algo.   
 //In short using floyd warshl algo..we will find..all possible path from i to j. so once 
 //matrix is prepared with paths..then just check..for ith city..how many cities are reachable within threshold value.

 //We have to return city number which has adjacent city count is lesser among all city and their adjancent city
 //distance should be less than threshold.
 //As we have to return city number..first preparre adjacency list in matrix form.
 //then using algo..find all shortest distance.

 //now check..for city x if adjacent city distance less than threshold and also count of adjacent city which
 //satisfied above conditioon is less than among all citiies...then return this city number.
 int findCity(int n, int m, vector<vector<int>>& edges, int threshold) {
    
    vector<vector<int>>adj(n,vector<int>(n,1e9));
    
    for(auto i:edges){
        int u = i[0];
        int v = i[1];
        int w = i[2];
        
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int via = 0; via <n; via++){
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                
                if(row == col || adj[row][via] == 1e9 || adj[via][row] == 1e9){
                    continue;
                }
                
                int viaSum = adj[row][via] + adj[via][col];
                adj[row][col] = min(adj[row][col], viaSum);
            }
        }
    }
    
    
    int minCntCity = n, cityNo = -1;
    for(int row = 0; row<n; row++){ //loop over matrix and check..how many cities are reachable within threshold.
        
        int currCnt = 0;
        
        for(int col = 0; col<n; col++){
            
            if(adj[row][col] <= threshold){ //if less than or equal to threshold then increment adjacnet City count for cityNo.
                currCnt++;
            }
        }
        
        if(currCnt <= minCntCity){ //once adjacent city get's traversed check..of current count of adjacent city is less than minCntCity or not.
            minCntCity = currCnt; //if yes..then update minCntCity
            cityNo = row; //and also update city no.
        }
    }
    
    
    return cityNo;
}


//Approach 2: using Dijkstra Algo.
 int findCity(int n, int m, vector<vector<int>>& edges, int threshold) {
    
    vector<vector<pair<int,int> > > adj(n);
    
    for(auto i:edges){
        int u = i[0];
        int v = i[1];
        int w = i[2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<vector<int>>mat(n,vector<int>(n,1e9));
    int minCntCity = n, cityNo = -1;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    for(int i = 0; i<n; i++){
        
        vector<int>distArr(n,INT_MAX);
        pq.push({0,i});
        distArr[i] = 0;
        
        while(!pq.empty()){
            
            auto node = pq.top();
            pq.pop();
            
            int nodeVal = node.second;
            int dist = node.first;
            
            for(auto nbr:adj[nodeVal]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                int totalDist = dist + nbrDist;
                
                if(totalDist < distArr[nbrNode]){
                    pq.push({totalDist, nbrNode});
                    distArr[nbrNode] = totalDist;
                }
            }
            
        }
        
        int currCnt=0;
        for(int j = 0; j<n; j++){
            if(distArr[j] <= threshold){
                currCnt++;
            }
        }
        
        if(currCnt <= minCntCity){ //once adjacent city get's traversed check..of current count of adjacent city is less than minCntCity or not.
            minCntCity = currCnt; //if yes..then update minCntCity
            cityNo = i; //and also update city no.
        }
    }
    
return cityNo;
}