//GFG.
//wasn't able to solve using dp. memorization.
//Just used normal dijkstra.
int minimumCostPath(vector<vector<int>>& grid) 
    {   
        int n=grid.size(), m=grid.size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        vector<int>rowArr={-1,1,0,0};
        vector<int>colArr={0,0,1,-1};
    
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >pq;
        
        pq.push({grid[0][0],0,0}); //{cost,row,col};
        
        while(!pq.empty()){
            
            auto node = pq.top();
            pq.pop();
            
            int nodeDist = node[0];
            int nodeRow = node[1];
            int nodeCol = node[2];
            
            if(nodeRow==n-1 && nodeCol==m-1) return nodeDist;
            
            for(int i = 0; i<4; i++){
                int newRow = nodeRow + rowArr[i];
                int newCol = nodeCol + colArr[i];
                
                if(newRow>=0 && newCol>=0 && newRow<n && newCol<m){
                    int newDist = nodeDist + grid[newRow][newCol];
                
                    if(newDist < dist[newRow][newCol]){
                        
                        pq.push({newDist,newRow,newCol});
                        dist[newRow][newCol]=newDist;
                    }
                }
                
            }
        }
    }