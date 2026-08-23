//GFG.

//TC-O(N*M) SC-O(N*M).
//Approach is simple..we are doing normal bfs..similar to dijkstra algo..and pushing elements in queue
//we have used here queue..because no need to use priority queue..as distance is getting increased by 1 for all directions.

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> des) {
    
    int n = grid.size(), m = grid[0].size(); //first store n and m size.
    
    if(grid[des.first][des.second] == 0) //if destination row and col has value 0. that means we cannot reach there so return -1.
        return -1;
        
    if(source.first == des.first && source.second == des.second) //if source row's col's and destination row's and col's is same..
    // that means..we need to return 0.
        return 0;
    
    int rowArr[]={-1,1,0,0}; //as we have 4 directions mentined in question so storing directions in arrays.
    int colArr[]={0,0,1,-1};
    
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    
    queue<vector<int>> q;
    q.push({source.first, source.second,0}); //push source node with weight..distance in queue.
    distance[source.first][source.second] = 0; //make distance for source node is 0.
    
    while(!q.empty()){
        auto node = q.front(); //take front node.
        q.pop();
        
        int row = node[0];
        int col = node[1]; 
        int wt = node[2];
        
        
        for(int i = 0; i<4 ; i++){ //traverse in all 4 directions.
            int r = row + rowArr[i];
            int c = col + colArr[i];
            
            int totalWt = wt+1; //increment totalWt by parent weight + 1.
            
            if(r == des.first && c == des.second) //if any point we reached to the destionation address.
                return totalWt; //then return total weight.
            
            if(r >= 0 && r<n && c>=0 && c<m && grid[r][c] == 1 && totalWt < distance[r][c]){
                //before push into the queue..check for above all conditions. 
                q.push({r, c, wt+1}); //push this r,c and newly distnace or weight in queue.
                distance[r][c] = totalWt; //update distance with totalWt as this distacne or wieght is smaller that previous one.
            }
        }
    }
    
    
    return -1; //if we reached till here then return -1.
}



//We can use visited array to instead of distnace array. 
int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        
        int sr = src[0], sc = src[1];
        int dr = dest[0], dc = dest[1];
        
        if(mat[sr][sc] == 0 or mat[dr][dc]==0)  
            return -1;
    
        int rowArr[]={-1,1,0,0};
        int colArr[]={0,0,-1,1};
        
        vector<vector<int>>visited(mat.size(), vector<int>(mat[0].size(),0));
        queue<vector<int>>q;
        q.push({sr,sc,0});
        visited[sr][sc]=1;
        
        while(!q.empty()){
            
            int nr = q.front()[0];
            int nc = q.front()[1];
            int dist = q.front()[2];
            
            q.pop();
            
            if(nr==dr and nc==dc){ //checking here.
                return dist;
            }
            
            for(int i=0; i<4; i++){
                int newR = nr+rowArr[i];
                int newC = nc+colArr[i];
                
                if(newR>=0 and newR<mat.size() and newC>=0 and newC<mat[0].size()
                    and mat[newR][newC]==1 and !visited[newR][newC]){
                        
                       visited[newR][newC]=1;
                       q.push({newR,newC, dist+1});
                }
            }
        }
        
        return -1;
    }