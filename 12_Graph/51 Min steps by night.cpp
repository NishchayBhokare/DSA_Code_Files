class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        vector<int>rowArr = {-2,-2,2,2,-1,-1,1,1};
        vector<int>colArr = {-1,1,-1,1,-2,2,-2,2};
        
        int dirSize = rowArr.size();
        
        vector< vector<int> >dist(n+1,vector<int>(n+1,INT_MAX));
       
        queue<vector<int>>q;
        int sr=knightPos[0]-1, sc=knightPos[1]-1;
        int dr=targetPos[0]-1, dc=targetPos[1]-1;
  
        q.push({0,sr,sc});
        dist[sr][sc] = 0;
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            int nodeDist = node[0];
            int row = node[1];
            int col = node[2];
            
            if(row == dr and col == dc)
                return nodeDist;
            
            for(int i=0; i<dirSize; i++){
                
                int nbrDist = nodeDist + 1;
                int nbrRow = row + rowArr[i];
                int nbrCol = col + colArr[i];
                
                if(nbrRow>=0 and nbrRow<n and nbrCol>=0 and nbrCol<n and nbrDist < dist[nbrRow][nbrCol]){
                    
                    q.push({nbrDist,nbrRow,nbrCol});
                    dist[nbrRow][nbrCol] = nbrDist;
                }
            }
        }
        
        return -1;
    }
};
























