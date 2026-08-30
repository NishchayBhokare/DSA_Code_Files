//GFG -> better dp solution is there. refer 10th question in dp. 
//Approach 1: Graph Solution. Dijktra algorithm. TC-O(N2logN2) i.e TC-O(N2logN) SC-O(N2).
//Mathematics is. logn2 = 2logn. and 2 is constant. so. it will be logN
class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({grid[0][0], 0, 0});
        distance[0][0] = grid[0][0];
        
        int rowArr[]={-1,1,0,0};
        int colArr[]={0,0,-1,1};
        
        while(!pq.empty()){
            
            vector<int>currNode = pq.top();
            pq.pop();
            
            int dist = currNode[0];
            int row = currNode[1];
            int col = currNode[2];

            if(row == n-1 && col == n-1)
                return dist;
            
            for(int i=0; i<4; i++){
                
                int newR = rowArr[i] + row;
                int newC = colArr[i] + col;
                
                if(newR>=0 and newR<n and newC>=0 and newC<n){
                    
                    int newDist = dist + grid[newR][newC];
                    
                    if(newDist < distance[newR][newC]){
                        
                        distance[newR][newC] = newDist;
                        pq.push({newDist,newR,newC});
                    }
                }
            }
        }
        
        return -1;
    }
};
