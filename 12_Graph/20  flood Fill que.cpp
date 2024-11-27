//GFG


//Updated BFS. TC-O(N2) SC-O(N2)
// we have to find..number adjacent nodes of given src and dest which can be colored with given color.
//so basically we are pushing current source row and source columns in queue and doing BFS.
//checking..is there any adjacent who satisfied all the conditions and can be colored to given color..
//if yes..then color that row and column index and push that row and col in queue to get theri neigbouring nodes.
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {                            
    int n = image.size();
    int m = image[0].size();
    
    queue<pair<int,int>>q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    
    q.push({sr,sc});
    visited[sr][sc] = true;
    int currColor = image[sr][sc];
    image[sr][sc] = newColor;
    
    vector<int>rowArr = {-1,1,0,0}; //these are the possible directions.
    vector<int>colArr = {0,0,1,-1}; //it's bettter to store possible directions..rather than doing muliple function calls.
    //like in second approach.
    
    while(!q.empty()){
        
        auto nodePr = q.front();
        q.pop();
        
        int row = nodePr.first;
        int col = nodePr.second;
        
        //can we go up and down..
        for(int i = 0; i<4; i++){
            int nRow = row+rowArr[i]; //updating new row.
            int nCol = col+colArr[i]; //updatin col.
            
            if(nRow >=0 && nRow <n && nCol >=0 && nCol<m && image[nRow][nCol] == currColor 
            && !visited[nRow][nCol]){ //these are the conditions we're checking.
                
                q.push({nRow,nCol}); //if satisfied.then push into the queue.
            
                image[nRow][nCol] = newColor; //color current nRow and nCol with new colour.
                visited[nRow][nCol] = true; //and mark as visited.
            }
        }
    }
           
    return image; 
}



//Approach 2 using bfs..without creation of directions array for row and columns.
void checkForPush(int row, int col, int currColor, int newColor, 
        queue<pair<int,int>>&q, vector<vector<int>>& image, vector<vector<bool>>&visited){
                                           
          int n = image.size();
          int m = image[0].size();
            
          if(row >=0 && row <n && col >=0 && col<m && image[row][col] == currColor 
                && !visited[row][col]){
                   
              q.push({row,col});
               
              image[row][col] = newColor;
              visited[row][col] = true;
          }   
    }
  
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
                                      
      int n = image.size();
      int m = image[0].size();
       
      queue<pair<int,int>>q;
      vector<vector<bool>> visited(n,vector<bool>(m,false));
       
      q.push({sr,sc});
      visited[sr][sc] = true;
      int currColor = image[sr][sc];
      image[sr][sc] = newColor;
       
      while(!q.empty()){
           
          auto nodePr = q.front();
          q.pop();
           
          int row = nodePr.first;
          int col = nodePr.second;
           
          //can we go up and down..
          for(int newRow = -1; newRow<=1; newRow++){
              int nRow = row+newRow;
              checkForPush(nRow,col,currColor,newColor,q,image,visited);
          }
           
          //can we go up and down..
          for(int newCol = -1; newCol<=1; newCol++){
              int ncol = col+newCol;
              checkForPush(row,ncol,currColor,newColor,q,image,visited);
          }
      }
       
       
        return image; 
    }




// Approach 3: using DFS. Optimised Approach, by creation of two arrays for directions.
void solve(int row,int col,vector<vector<int>>& image, vector<vector<bool>>&visited, 
    int currColor, int newColor, vector<int>&rowArr, vector<int>&colArr, int n, int m){
        
    visited[row][col] = true;
    image[row][col] = newColor;
    
    //can we go up and down..
    for(int i = 0; i<4; i++){
        int nRow = row+rowArr[i];
        int nCol = col+colArr[i];
            
        if(nRow >=0 && nRow <n && nCol >=0 && nCol<m && image[nRow][nCol] == currColor 
            && !visited[nRow][nCol]){
                
                solve(nRow,nCol,image,visited,currColor,newColor,rowArr,colArr,n,m);
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
                                    
    int n = image.size();
    int m = image[0].size();
    
    queue<pair<int,int>>q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    
    q.push({sr,sc});
    visited[sr][sc] = true;
    int currColor = image[sr][sc];
    image[sr][sc] = newColor;
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1};
    
    solve(sr,sc,image,visited,currColor,newColor,rowArr,colArr,n,m);
    
    return image; 
}
