//GFG 
//Amazing approach. doing bfs..for every node..then pushing connecting 1 nodes in queue with it's row and col.
//but when we are poping out from queue then before storing in temp vector..we are doing substraction with base values of row and col.
//base node is nothing but..first node of this..connected links.
//logic is..if islands are same then their row and col value will be equal after doing substraction with base node.
//so applying this logic..and if its same..then set will remove it..duplicate values..

//TC-O(N*M Log(N*M)) SC-O(N*M)
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>>q;                                                               //two distinct islands.
    set<vector< pair<int,int> >>st; //set will store group of distinct islands like[[{0,0},{0,1},{1,0}] , [{2,1}{2,2}]]
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    
    vector<int>rowArr = {-1,1,0,0};
    vector<int>colArr = {0,0,1,-1};
    
    for(int i = 0; i<n; i++){ 
        for(int j = 0; j<m; j++){ //iterating over all the elements.
            
            if(grid[i][j]==1 && !visited[i][j]){ //as we deal with finding connections of 1..so grid should have 1 and not visited.
                
                pair<int,int>base = {i,j}; //this will be the values of base node's row and col. this is starting node this connected links.
                q.push({i,j}); //now push their ith and jth values.
                visited[i][j] = true;

                vector<pair<int,int>>temp; //create temp of pair of int..this temp will going to insert in set.
                
                while(!q.empty()){
                    
                    auto node = q.front();
                    q.pop();
                    
                    int row = node.first , col = node.second; //getting current row and col values.
                    int row0 = base.first, col0 = base.second; //getting base node's row and col values.
                    temp.push_back( {row-row0, col-col0} ); //substracting current node row's,col's values from base values.
            
                    for(int i = 0; i<4; i++){ //looping to insert adjacent in all four directions.
                        int nRow = row + rowArr[i];
                        int nCol = col + colArr[i];
                        
                        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && !visited[nRow][nCol]){
                            //if satisfied above conditions..then push into the queue.
                            q.push({nRow,nCol});
                            visited[nRow][nCol]  = true;
                        }
                    }
                }

                st.insert(temp); //once stack get's empty..that means..current sequences of 1 list is compeleted..so 
                //push whatever nodes present so far in temp to stack.
            }
        }
    }

    return st.size(); //at the end..return size..as stack will remove duplicates.
}

    