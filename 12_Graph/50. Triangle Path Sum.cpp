//GFG -> better dp solution is there. refer 11th question in dp. 
//Approach 1: Graph Solution. Dijktra algorithm. TC-O(N2logN2) i.e TC-O(N2logN) SC-O(N2).
//Mathematics is. logn2 = 2logn. and 2 is constant. so. it will be logN

int minPathSum(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        pq.push({triangle[0][0],0,0});
        distance[0][0] = triangle[0][0];
        
        
        while(!pq.empty()){
            
            auto node = pq.top();
            pq.pop();
            
            int dist = node[0];
            int row = node[1];
            int col = node[2];
            
            if(dist > distance[row][col])//we cam add this additional question in every 
            // graph problem to overcome extra checks for neighbors.
                continue;
            
            if(row==n-1)
                return dist;
            
            for(int c=0; c<=1; c++){
                
                int newR = row+1;
                int newC = col+c;
                int newDist = dist + triangle[newR][newC];
                
                if(newDist < distance[newR][newC]){
                    distance[newR][newC] = newDist;
                    pq.push({newDist,newR,newC});
                }
            }
        }
        
        
        return -1;
    }