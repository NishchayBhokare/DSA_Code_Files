//GFG.
//We have to find minimum absolute difference possible to reach destination.
//there can be multiple path..among all path..we have to find minimum absolute difference between every node which are in that path.

//Approach 1: Using Dijkstra's Algo Approach. 
//Basically we are using prirority queue..and distance array.
//on every node..we are storing absolute differnce in distance array...but there is catch..we are not storing
//absolute diff as it is..we are getting maximum absolute diff among (parent node absolute diff and current node absolute diff)
//and then storing maximum absolute difference in distance array if it is lesser than previous for current node. 
// we're doing this because, for particular path..we have to check..what will be the maximum
//absolute difference between the two nodes..so maximum absolute diff we're passing to next node till destination node.

int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
    
    int n = rows, m = columns;
    
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX)); 
    vector<int>rowArr = {1,0,-1,0}; //there can be 4 directions to go..so creating array for it.
    vector<int>colArr = {0,1,0,-1};
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    //we are using priority queue because we will get minimum difference on top..so that we can get path with minimum efforts. 
    
    pq.push({0,0,0}); //pushing in this way (diff, row, col)
    distance[0][0] = 0; //source node's absolute difference will be 0.
    
    while(!pq.empty()){
        
        auto node = pq.top();
        pq.pop();
        
        int nodeDiff = node[0];
        int row = node[1];
        int col = node[2];
        
        if(row == n-1 && col == m-1){ //if we get top node as destionation..then return it's effort. i.e minimum absolute differnec between all paths..and maximum absolute diffence of all nodes in current path.
            return nodeDiff;
        }
        
        for(int i = 0; i<4; i++){
            
            int r = row + rowArr[i];
            int c = col + colArr[i];
            
            if(r>=0 && r<n && c>=0 && c<m){
                
                int nbrDiff = abs(heights[row][col] - heights[r][c]); //calculating absolute diff for current node..by doing substracton of parent node value.
                int maxDiff = max(nodeDiff,nbrDiff); //then taking maximum absolute diff among both...
                
                if(maxDiff < distance[r][c]){ //and checking is that maximum absolute diff is less than previously inserted effort in distance array or not.
                    distance[r][c] = maxDiff; //if it's less then update effort in distance array.
                    pq.push({maxDiff,r,c}); //and create node with this effort, new row and new col and push into the priority queue.
                }
            }
        }
    }
}