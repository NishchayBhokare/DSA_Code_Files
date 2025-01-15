 //GFG
 
 //Very simple question.
 Approach: Using bfs. First store cell which having value as 1 in queue...with distance 0.
 //now traverse over queue...and check in all four directions. if current neighbor is having
 //value 0. then we will update distance to reach this nbr by nodeDist+1.
 //and store this updated distance in answer vector of vector for that cell.
 vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){ //store all cells which having 1's .
                    q.push({i,j,0});
                    grid[i][j] = 0;
                    
                    visited[i][j] = true;
                }
            }
        }
        
        vector<int>rowArr = {-1,1,0,0};
        vector<int>colArr = {0,0,1,-1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            int row = node[0];
            int col = node[1];
            int dist = node[2];
            
            for(int i = 0; i<4; i++){ //check in all four directions.
                int nRow = row + rowArr[i];
                int nCol = col + colArr[i];
                
                //if celll having zero..then update it's distance and push this new cell with its distacne in queue.
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol] == 0){
                   q.push({nRow,nCol,dist+1}); 
                   
                   grid[nRow][nCol] = dist+1;
                   visited[nRow][nCol] = true;
                }
            }
        }
       
        return grid;
    }