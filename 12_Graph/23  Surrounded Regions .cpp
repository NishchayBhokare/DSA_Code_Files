//GFG  -> Replace O's With X surrounded by X.

//Approach 1: Very creative approach...we have to replace all O's  which are surrounded by x.
//but instead instead of this we can do different thinking..we will check..
//the O's which are not sourrouded by X. that means..somewhere it starts from boundary of matrix.
//so store all O's which are not surrounded by x..and do bfs..to mark all O's as visited which are not
//surrounded by X. 
//and then traverse over loop and except this visited O's convert remaining O's into the X.

//Approach 1: TC-O(N*M) SC-O(N*M)
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;

        //for top and bottom row.
        for(int row = 0,col=0; col<m; col++){
            //add top array row if O
            if(mat[row][col] == 'O'){
                    q.push({row,col});
                    visited[row][col] = true;
            }

            int nRow = n-1;
            if(mat[nRow][col] == 'O'){
                    q.push({nRow,col});
                    visited[nRow][col] = true;
            }
        }

        //for left and right column.
        for(int row = 0,col=0; row<n; row++){
            if(mat[row][col] =='O') {
                    q.push({row,col});
                    visited[row][col] = true;
            } 

            int nCol = m-1;
            if(mat[row][nCol] =='O') {
                    q.push({row,nCol});
                    visited[row][nCol] = true;
            } 
        }  

        vector<int> rowArr = {-1,1,0,0};
        vector<int> colArr = {0,0,1,-1};

        while(!q.empty()){
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();

            for(int i = 0; i<4; i++){
                
                int nRow = row + rowArr[i];
                int nCol = col + colArr[i];

                if(nRow >= 0 && nRow<n && nCol >=0 && nCol<m && !visited[nRow][nCol] && mat[nRow][nCol] == 'O'){
                
                q.push({nRow,nCol});
                visited[nRow][nCol] = true;
            }  
        }
    } 
     
    //aprt from visited 'O's ...mark remianing O's as X..because those O's are
    //surrounded by X.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 'O' && !visited[i][j]){
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}


//Appraoch 2: same using above..just eleminate multiple loops to iterate over boundary of given matrix.
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
        
        addInQueue(row,col,q,grid,visited); //calling function
        
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
 

//similar like above..but just using foour loops to traverse over the boundary of matrix.
Approach 3:
 vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
  {
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    queue<pair<int,int>>q;

    int row = 0;
    int col = 0;
    for(; col<m; col++){
        //add top array row if O
        if(mat[row][col] == 'O'){
             q.push({row,col});
             visited[row][col] = true;
        }
    }
    //add bottom array row if O
    row = n-1;
    col = 0;
    for(; col<m; col++){
        if(mat[row][col] == 'O'){
             q.push({row,col});
             visited[row][col] = true;
        }
    }

    //add left column
    row = 0;
    col = 0;
    for(; row<n; row++){
        if(mat[row][col] =='O') {
             q.push({row,col});
             visited[row][col] = true;
        } 
    }  

    //add right column
    row = 0;
    col = m-1;
    for(; row<n; row++){
        if(mat[row][col] =='O') {
             q.push({row,col});
             visited[row][col] = true;
        } 
    }  

    vector<int> rowArr = {-1,1,0,0};
    vector<int> colArr = {0,0,1,-1};
    while(!q.empty()){
        auto node = q.front();
        int row = node.first;
        int col = node.second;    
        q.pop();

        for(int i = 0; i<4; i++){
           int nRow = row + rowArr[i];
           int nCol = col + colArr[i];

           if(nRow >= 0 && nRow<n && nCol >=0 && nCol<m && !visited[nRow][nCol] && mat[nRow][nCol] == 'O'){
            q.push({nRow,nCol});
            visited[nRow][nCol] = true;
           }  
        }
    } 

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 'O' && !visited[i][j]){
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
  }

   

  