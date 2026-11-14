//Leetcode. 
//Approach 1: Counting frequency approach. simple one. TC-O(N*M) SC-O(N+M)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(),  m=grid[0].size();
        vector<int>rowCnt(n);
        vector<int>colCnt(m);

        int totalCnt = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1) {
                    rowCnt[row]++; //count how many 1's in current row
                    colCnt[col]++;//same for column.
                }
            }
        }

       
        for(int row=0; row<n; row++){  //now loop over matrix.  
            for(int col=0; col<m; col++){    
                if(grid[row][col]==1){
                    if(rowCnt[row]>1 or colCnt[col]>1) totalCnt++; //if for current row and column.
                    //if one's cnt is greater than 1, then take this 1's into totalCnt.
                }
             
            }
        }

        return totalCnt;
    }
};

//Approach 2: Graph Approach. TC-O(N*M) SC-O(N+M+S) sc(Adjacency list: O(N + M + S))
//TC-Adjacency list: O(N + M + S)
// Visited array: O(N + M)
// DFS recursion stack: O(N + M)
// Idea is Servers can communicate if they share a row or column, so group connected servers using 
// DFS and count the groups containing more than one server.

class Solution {
public:
    void solve(int node, vector<vector<int>>&adj, int &edgeCnt, vector<int>&visited){
        visited[node]=1;

        
        edgeCnt+=adj[node].size();
        
        for(auto nbr:adj[indnode]){

            if(!visited[nbr]){
                solve(nbr,adj,edgeCnt,visited);
            }
        }
    }


    int countServers(vector<vector<int>>& grid) {

        int s = grid.size()+grid[0].size();
        vector<vector<int>>adj(s);

        int n = grid.size(), m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 1){
                    adj[i].push_back(n+j);
                    adj[n+j].push_back(i);
                }
            }
        }

        
        int cnt = 0;
        vector<int>visited(n+m,0);
        for(int i=0; i<n+m; i++){

            if(!visited[i]){
                int edgeCnt = 0;
                solve(i,adj,edgeCnt,visited,-1);
                
                if(edgeCnt/2 > 1) cnt+=(edgeCnt/2);
            }
        }

        return cnt;
    }
};