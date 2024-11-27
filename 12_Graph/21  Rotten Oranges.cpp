//GFG -> Rotten Oranges.

//Approach 1: optimised approach using elminate for loop to return -1 and also..elminating pushing
// -1 delimeter in queue...as we're doing in approach 2.
//TC-O(N*M) SC-O(N*M).
int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    
    queue< vector<int> >q; //creating queue of vector..to store three fields. {row,col,time}.
    
    int freshCnt = 0; //this variable we're using for eliminating uses of for loop to return -1.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 2) //if index have value 2..then push row,col and time with zero in queue.
                q.push({i,j,0});
            
            if(mat[i][j] == 1) //counting count for 1.
                freshCnt++;
        }
    }
    
    int totalTime = 0;
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1}; //creation of rowArr and colArr to move in all four directions.
    
    while(!q.empty()){ //looping till q not empty
        auto node = q.front();
        q.pop();
        
        int row = node[0];
        int col = node[1];
        int t   = node[2];
        
        totalTime = max(totalTime,t); //updating time..if current time is greater than totalTime.
        
        for(int i = 0; i<4; i++){
            int nRow = row + rowArr[i]; 
            int nCol = col + colArr[i]; //updating row and column to check for neighbours.
            
            //if..this new row and col satisfied all below conditions..then mark these index value in mat as 2 i.e rotted
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol] == 1 && !visited[nRow][nCol]){
                
                mat[nRow][nCol] = 2;
                visited[nRow][nCol] = true; //also..mark visited as true.
                q.push({nRow,nCol,t+1}); //and push all these new values..by incrementing time in queue.
                
                freshCnt--; //decrementing freshCount of fresh oranges.
            }
        }
    }
    
    
    if(freshCnt != 0) //at the end..if fresh count is not equal to zero..that means..there are fresh oranges are there..which
    //are not rotted..because they are not reachable.
        return -1; //so return -1.
    
    return totalTime; //else return totalTime.
}



//Approach 2: using adding delimeter..so that..we can increment count..after getting -1 as delimeter.
 int orangesRotting(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    
    queue<pair<int,int>>q; //creatiing q of pair..as we're not inserting time in q. 
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 2)
                q.push({i,j});
        }
    }
    
    int time = 0;
    q.push({-1,-1});  //pushing -1,-1 pair as delimeter.
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1};
    
    while(q.size() > 1){
        auto nodePr = q.front();
        q.pop();
        
        int row = nodePr.first;
        int col = nodePr.second;

        if(row == -1){ //if we found -1.
            time++; //increment count..that...current iteration is over.
            q.push({-1,-1}); //then push pair of -1,-1 which will be delimeter for next elements.
            continue; //and move to next iteration.
        }
        
        for(int i = 0; i<4; i++){ //else..check in all four directions.
            int nRow = row + rowArr[i];
            int nCol = col + colArr[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol] == 1 && !visited[nRow][nCol]){
                
                mat[nRow][nCol] = 2;
                visited[nRow][nCol] = true;
                q.push({nRow,nCol}); 
            }
        }
    }
    
    
    for(int i = 0; i<n; i++){ //at last..check..any of the index..contains value as 1..if it is..then return -1.
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 1)
                return -1;
        }
    }
    
    return time; //else return time.
}