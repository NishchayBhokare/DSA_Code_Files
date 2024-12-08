//GFG -> Maximum connnected group.

//Approach: using disjoint set.
class DisjointSet{
    public:
        vector<int>parent;
        vector<int>size;
        
        DisjointSet(int n){
            size.resize(n,1);
            parent.resize(n);
            
            for(int i = 0; i<n; i++){
                parent[i]=i;
            }
        }
        
        int findParent(int node){
            if(parent[node] == node)
                return node;
                
            return parent[node] = findParent(parent[node]);
        }
        
        void makeUnion(int u, int v){
            
            int uP = findParent(u);
            int vP = findParent(v);
            
            if(uP == vP) return;
            
            if(size[uP] >= size[vP]){
                
                parent[vP] = uP;
                size[uP] += size[vP];
            }
            else{
                
                parent[uP] = vP;
                size[vP] += size[uP];
            }
            
        }
    
};


//Logic is first connect all nodes.
//then for every zero value cell..imagine to place 1..and check in all four directions.
//if we found adjacent node as 1. the take it's ulitmate parent and put in set..(why set..to get avoid from adding size of same ultimate parent.)
//and just do this on every zero cell value. and finally return answer.

//but there is catch..what if..all cells has value 1. so in that case..we have to return answer as n*n.
//so for that..use flag varaible..which will be initially true..and if any cell value has 0, then it will be false.
//so at the end..if flag is true..then return n*n. because that will be the total maximum size.
//else return our answer.
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DisjointSet ds(n*n);
        
        vector<int>rowDir = {-1,1,0,0};
        vector<int>colDir = {0,0,1,-1};
        
        //Step 1: connecting all nodes which has value 1.
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                
                if(grid[row][col] == 0) continue;
                    
                //go into all four directions to connect with neighbors.
                for(int i = 0; i<4; i++){
                    
                    int r = row + rowDir[i];
                    int c = col + colDir[i];
                    
                    if(r>=0 && c>=0 && r<n && c<n && grid[r][c] == 1){
                        
                        int u = row * n + col;
                        int v = r * n + c;
                            
                        ds.makeUnion(u,v);
                    }
                    
                } 
            }
        }
        
        
        //initialisng largeCnt and flag.
        int largeCnt = 0;
        int flag = 1;
        
        //now check..where we can place 1 in matrix.
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                
                if(grid[row][col] == 1) continue;
                
                //if we enter here..that menas cell has value 0. so make flag as 0. i.e false.
                flag = 0;
                
                int currCnt = 1;
                set<int>st;
                
                //go into all four directions to connect with neighbors.
                for(int i = 0; i<4; i++){
                    
                    int r = row + rowDir[i];
                    int c = col + colDir[i];
                    
                    if(r>=0 && c>=0 && r<n && c<n && grid[r][c] == 1){ //if neighbr has value 1 that means we can connect with it.
                        int adj = r * n + c; //conversion of row,col index to node number.

                        int adjParent = ds.findParent(adj); //get it's ultimate parent.
                        st.insert(adjParent); //and push it into the set.
                    }  
                }
                
                for(auto node:st){ //before moving ahead for next cell..add size of every parent in current count.
                    currCnt += ds.size[node];
                }
                
                largeCnt = max( currCnt, largeCnt);  //check for maximum size. 
            }
        }
        
        if(flag) return n*n; //if all cell already has value 1 then return n*n.
        
        return largeCnt; //else large count.
    }
};
