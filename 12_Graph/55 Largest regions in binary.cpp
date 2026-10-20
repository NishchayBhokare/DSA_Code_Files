class Solution {
  public:
    int dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&visited){
        
        int n = grid.size(), m=grid[0].size();
        
        visited[row][col]=1;
        
        int cnt = 1;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                
                int newR = row+i, newC = col+j;
                
                if(newR>=0 and newR<n and newC>=0 and newC<m and grid[newR][newC]==1 and !visited[newR][newC]){
                    cnt += dfs(newR,newC,grid,visited);
                }
            }
        }
        
        return cnt;
    }
  
    int largestRegion(vector<vector<int>>& grid) {
 
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int maxCnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 1 and !visited[i][j]){
                    int cnt = dfs(i,j,grid,visited);
                    maxCnt = max(cnt,maxCnt);
                }
            }
        }
        
        return maxCnt;
    }
};