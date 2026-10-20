//Approach 1: USING BFS: TC-O(N*M*4) SC-O(N*M)
class Solution {
  public:
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        
        //first find out position of start and end node.
        
        int n = mat.size();
        
        int sr,sc;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(mat[i][j] == 1){
                    sr=i;
                    sc=j;
                }
            }
        }
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
        visited[sr][sc]=1;
        
        
        int rowArr[]={-1,1,0,0};
        int colArr[]={0,0,-1,1};
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            int row=node.first;
            int col=node.second;
            
            if(mat[row][col]==2)
                return true;
            
            for(int i=0; i<4; i++){
                
                int newR=row+rowArr[i];
                int newC=col+colArr[i];
                
                if(newR>=0 and newR<n and newC>=0 and newC<n and mat[newR][newC]!=0 and !visited[newR][newC]){
                    
                    q.push({newR,newC});
                    visited[newR][newC]=1;
                }
            }
        }
        
        return false;
    }
};



//Approach 2: Using DFS: TC-O(N*M*4) SC-O(N*M)
bool solve(int row, int col,vector<vector<int>>& mat,vector<vector<int>>&visited){
    
    int n = mat.size();
    
    if(mat[row][col] == 2)
        return true;
    
    visited[row][col]=1;
    
    int rowArr[]={-1,1,0,0};
    int colArr[]={0,0,-1,1};
    
    for(int i=0; i<4; i++){
        
        int newR=row+rowArr[i];
        int newC=col+colArr[i];

        if(newR>=0 and newR<n and newC>=0 and newC<n and mat[newR][newC]!=0 and !visited[newR][newC]){

            bool ans = solve(newR,newC,mat,visited);
            if(ans)
                return ans;
        }
    }
    
    return false;
}


class Solution {
  public:
    bool isPathPossible(vector<vector<int>>& mat) {
         //first find out position of start and end node.
        
        int n = mat.size();
        
        int sr,sc,dr,dc;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(mat[i][j] == 1){
                    sr=i;
                    sc=j;
                }
            }
        }
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        return solve(sr,sc,mat,visited);
    }
};





























