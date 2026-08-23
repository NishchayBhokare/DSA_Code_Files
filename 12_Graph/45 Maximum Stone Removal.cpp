//GFG. 
//here logic is we will consider every row as one node and column as one node..then make union of it.
//at the end answer will be number of components - 1.
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
                size[vP]= 0; //updating size to 0 as now vp is connected to up so size of vp is no longer needed.
            }
            else{
                
                parent[uP] = vP;
                size[vP] += size[uP]; 
                size[uP] = 0; //similarly for size up.
            }
        }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int rowSize=0, colSize=0;
        
        for(auto arr:stones){
            rowSize = max(rowSize, arr[0]);
            colSize = max(colSize, arr[1]);
        }
        
        rowSize++;
        colSize++;
        
        DisjointSet ds(rowSize+colSize);
        
        set<int>st;
        
        for(auto arr:stones){
            
            int nodeRow = arr[0];
            int nodeCol = arr[1] + rowSize;
            
            ds.makeUnion(nodeRow,nodeCol);
            
            st.insert(nodeRow);
            st.insert(nodeCol);
        }
        
        int components = 0;
        
        for(auto node:st){//we can insert all nodes in stack.
            if(ds.findParent(node) == node) //and check their parents. ultimatix parent..
            //the count unique nodes who is poiting itself as ultimate parent.
                components++;
        }
        
        //from every components, we can delete compSize - 1 stones. so deleting count of components
        // from n means subtracting that 1 stones as we cant delete it.
        int deleteComp = n - components; // N means total stones.
        return (deleteComp); 
    }
};





