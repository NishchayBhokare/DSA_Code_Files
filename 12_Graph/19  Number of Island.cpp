//GFG -> Find Numebr of islands. (i.e total number of connected components)

//Approach 1: using DFS.
//Logic like question 18th...we have to calculate number of islands that means..connected components count
//from given matrix grid.
void solve(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&visited, 
    int &n, int &m){
    
    visited[row][col] = 1; 
    
    for(int newRow = -1; newRow<=1; newRow++){
        for(int newCol = -1; newCol<=1; newCol++){
            int nRow = newRow + row;
            int nCol = newCol + col;
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == '1' && !visited[nRow][nCol]){
                solve(nRow,nCol,grid,visited,n,m);
            }
        }
    } 
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int land = 0;
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                land++; //incrementing land for every start node.
                solve(i,j,grid,visited,n,m);
            }
        }
    }
    
    return land;
}

//Approach 2: using bfs..optimised approarch.
//we are storing data in queue by row and col index..so that further we can check for remaining 8 directions..i.e neighbors.
void checkForPush(int row, int col, vector<vector<char>>& grid, queue<pair<int,int>>&q,
    vector<vector<int>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    
    if(row>=0 && row<n && col>=0 && col<m && grid[row][col] == '1' && !visited[row][col]){
        q.push({row,col});
        visited[row][col] = 1;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int land = 0;
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            
            if(grid[i][j] == '1' && !visited[i][j]){ //if value at ith and jth is one and not visited.
                land++; //increment land.
                q.push({i,j}); //push this pair of i and j in queue.
                visited[i][j]=1; //make as visited.
                
                while(!q.empty()){
                    auto nodePr = q.front();
                    q.pop();
                    
                    int row = nodePr.first;
                    int col = nodePr.second;
                    
                    for(int newRow = -1; newRow<=1; newRow++){ //traversing from -1 to 1. for row.
                        for(int newCol = -1; newCol<=1; newCol++){ //same for -1 to 1..for col.
                            int nRow = newRow + row;
                            int nCol = newCol + col;
                            
                            checkForPush(nRow,nCol,grid,q,visited); //calling checkforPush function with update rows and calls.
                        }
                    }
                    
                }
            }
        }
    }
    
    return land;
}


//Approach 1: using bfs..here optimization can be..we can integrate 8 function calls into the one..
//by using two for loops..check Approach 1.
void checkForPush(int row, int col, vector<vector<char>>& grid, queue<pair<int,int>>&q,
    vector<vector<int>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    
    if(row>=0 && row<n && col>=0 && col<m && grid[row][col] == '1' && !visited[row][col]){
        q.push({row,col});
        visited[row][col] = 1;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int land = 0;
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                land++;
                q.push({i,j});
                visited[i][j]=1;
                
                while(!q.empty()){
                    auto nodePr = q.front();
                    q.pop();
                    
                    int row = nodePr.first;
                    int col = nodePr.second;
                    
                    //can we go up.
                    checkForPush(row+1,col,grid,q,visited);
                    
                    //can we go down
                    checkForPush(row-1,col,grid,q,visited);
                    
                    //can we go left
                    checkForPush(row,col-1,grid,q,visited);
                    
                    //can we go right
                    checkForPush(row,col+1,grid,q,visited);
                    
                    //can we go upper left diagonal
                    checkForPush(row-1,col-1,grid,q,visited);
                    
                    //can we go bottom left diagonal
                    checkForPush(row+1,col-1,grid,q,visited);
                    
                    //can we go upper right diagonal
                    checkForPush(row-1,col+1,grid,q,visited);
                    
                    //can we go lower right diagonal
                    checkForPush(row+1,col+1,grid,q,visited);
                }
            }
        }
    }
    
    return land;
}

