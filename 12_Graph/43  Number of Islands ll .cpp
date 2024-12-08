//GFG. Number of islands ||


//Approach : using Disjoint set.
//As we have dynamically adding answer of number islands..then there is scop of using disjoint set.
//we're storing parent node for row,col is row * m + col. this will give one value..which will consider as node for this row,col.
//0 1 2 3
//4 5 6 7
//8 9 10 11. in this way..we are visualising for connecting nodes.
class DisjointSet{
    public:
        vector<int>parent;
        vector<int>size;
        
        DisjointSet(int n){
            size.resize(n,0);
            
            parent.resize(n);
            
            for(int i = 0; i<n; i++)
                parent[i]=i;
        }
        
        
        int findParent(int node){
            
            if(parent[node] == node)
                return node;
            
            return parent[node] = findParent(parent[node]);
        }        
        
        void makeUnion(int u, int v){
            int uP = findParent(u);
            int vP = findParent(v);
            
            if(uP == vP)
                return;
            
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

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        //initilise ds with n*m size.
        DisjointSet ds(n*m);

        //creation of matrix. n*m.
        vector<vector<int>>mat(n,vector<int>(m,0));
        
        int count = 0;
        vector<int> ans;
        
        //as we have to go into the four directions..then create arrray for it.
        vector<int>rowArr = {-1,1,0,0};
        vector<int>colArr = {0,0,1,-1};
        
        //looping over given operators vector of vector
        for(auto vec:operators){
            
            int row = vec[0];
            int col = vec[1];
             
            if(mat[row][col] == 1){ //if already island is there..that means..we already visited. so add current cnt in answer and return.
                ans.push_back(count);
                continue; //skip this iteration move to next.
            }
            
            mat[row][col] = 1; //if island is not there..then make current row,col as island.
            
            count++; //increment count.
            
            for(int i = 0; i<4; i++){ //now check in all four directions that..can we connect to any group of island or not.
                
                int r = row + rowArr[i];
                int c = col + colArr[i];
                
                if(r>=0 && c>=0 && r<n && c<m && mat[r][c] == 1){ //if there is island on any of the left,right,top,bottom position.
                    //then connect with it.
                    int u = row * m + col; //this is where..we're creating one node value..so that.we can conect both of it.
                    int v = r * m + c;
                    
                    
                    if(ds.findParent(u) != ds.findParent(v)){ //if there two nodes parent are not same..then connect it.
                        
                        ds.makeUnion(u,v); //connect this nodes
                        count--; //as we connecting..then count should decrese by 1.
                    }
                }   
            } 
            
            ans.push_back(count); //for ever iteration store count in answer array
        }
        
        
        return ans; //return final answer.
    }
};
