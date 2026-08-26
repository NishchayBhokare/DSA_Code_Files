
//TC-O(N2Logn) SC-O(N2)
//Algorithm is slightly different from 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({grid[0][0],0,0}); //[dist,row,col];
        visited[0][0] = 1;

        int rowArr[] = {-1,1,0,0};
        int colArr[] = {0,0,-1,1};

        int reqTime = 0;
        while(!pq.empty()){

            auto node = pq.top();
            pq.pop();

            int dist = node[0];
            int row = node[1];
            int col = node[2];

            reqTime = max(reqTime,dist);

            if(row==n-1 and col==n-1)
                return reqTime;

            for(int i=0; i<4; i++){
                int newR = rowArr[i] + row;
                int newC = colArr[i] + col;

                if(newR>=0 and newR<n and newC>=0 and newC<n and !visited[newR][newC]){
                    
                    int nbrDist = grid[newR][newC];
                    pq.push({nbrDist,newR,newC});
                    visited[newR][newC]=1;
                }
            }
        }


        return reqTime;
    }
};