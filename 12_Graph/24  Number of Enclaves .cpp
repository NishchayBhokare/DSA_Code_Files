//GFG 

//Approach 1: using BFS..similar like approach used in last question of surrounded Regions.

//do boundary traversal..then check..numebr of 1's which are not enclaves...and mark remaining as enclaves.
int numberOfEnclaves(vector<vector<int>> &grid) {
    
    int n=grid.size(), m = grid[0].size(), count = 0;
    
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    queue<pair<int,int>>q;
    
    //boundary traersal for top and bottom..
    for(int row=0, col=0; col<m; col++){
        
        if(grid[row][col] == 1){
            q.push({row,col});
            visited[row][col] = true;
        }
        
        int nRow = n-1;
        if(grid[nRow][col] == 1){
            q.push({nRow,col});
            visited[nRow][col] = true;
        }
    }
    
    
    //boundary traversal for left and right.
    for(int row = 0, col = 0; row<n; row++){
        
        if(grid[row][col] == 1){
            q.push({row,col});
            visited[row][col] = true;
        }
        
        int nCol = m-1;
        if(grid[row][nCol] == 1){
            q.push({row,nCol});
            visited[row][nCol] = true;
        }
    }
    
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1};
    while(!q.empty()){
        
        auto node = q.front();
        q.pop();
        
        int row = node.first;
        int col = node.second;
        
        
        //check for all four directions..is there any 1's are present or not. if yes..then 
        //mark it as visited.
        for(int i = 0; i<4; i++){
            int nRow = row + rowArr[i];
            int nCol = col + colArr[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] 
                && grid[nRow][nCol]==1){
                
                q.push({nRow,nCol});
                visited[nRow][nCol]  = true;
            }
        }
    }
    
    //now count 1's which are prsent and not visited i.e those are enclaves.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                count++;
            }
        }
    }
    
return count;
}


//Similar approach like above..just some changes..added one function instead of writing same condition
//for boundary trversal.
 void addInQueue(int row, int col, queue<pair<int,int>> &q, vector<vector<int>>&grid, 
    vector<vector<bool>>&visited){
        
        if(grid[row][col] == 1){
            q.push({row,col});
            visited[row][col] = true;
        }   
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    
    int n=grid.size(), m = grid[0].size(), count = 0;
    
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    queue<pair<int,int>>q;
    
    //boundary traersal for top and bottom..
    for(int row=0, col=0; col<m; col++){
        
        addInQueue(row,col,q,grid,visited); //calling function to insert in queue.
        
        int nRow = n-1;
        addInQueue(nRow,col,q,grid,visited);
    }
    
    
    //boundary traversal for left and right.
    for(int row = 0, col = 0; row<n; row++){
        
        addInQueue(row,col,q,grid,visited);
        
        int nCol = m-1;
        addInQueue(row,nCol,q,grid,visited);
    }
    
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1};
    while(!q.empty()){
        
        auto node = q.front();
        q.pop();
        
        int row = node.first;
        int col = node.second;
        
        
        //check for all four directions..is there any 1's are present or not. if yes..then 
        //mark it as visited.
        for(int i = 0; i<4; i++){
            int nRow = row + rowArr[i];
            int nCol = col + colArr[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] 
                && grid[nRow][nCol]==1){
                
                q.push({nRow,nCol});
                visited[nRow][nCol]  = true;
            }
        }
    }
    
    //now count 1's which are prsent and not visited.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                count++;
            }
        }
    }
    
return count;
}

//check below solution. instead of looping for count seperately, we can count the 1 on the fly
//and will decrement it when we are popping. so basically total 1cnt - visited 1cnt = unreacable 1cnt.
class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==1)cnt++;
                
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        
        
        int rowArr[]={-1,1,0,0};
        int colArr[]={0,0,-1,1};
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            cnt--;
            
            q.pop();
            
            for(int i=0; i<4; i++){
                int newR = row+rowArr[i];
                int newC = col+colArr[i];
                
                if(newR>=0 and newR<n and newC>=0 and newC<m and !visited[newR][newC]
                    and grid[newR][newC]==1){
                    
                    q.push({newR,newC});
                    visited[newR][newC]=1;
                    
                }
            }
        }
        
        
        return cnt;
    }
};