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

        //we can check number of components by updating size in disjoint set and checking if size for any node is greater
        //than 1. that means this is one component. so increment count.
        for(auto i:ds.size){
            
            if(i > 1)
                components++;
        }
        
        for(auto node:st){ //else we can do like this also. we can insert all nodes in stack.
            if(ds.findParent(node) == node) //and check their parents. ultimatix parent..
            //the count unique nodes who is poiting itself as ultimate parent.
                components++;
        }
    
        int deleteComp = n - components; //these are the number of components which we can delete..means
        //n - uniqueu components which we cannot delete so, n - uniqueu components..and remaing component can be delete.
        return (deleteComp); //at the end..we can remove n - components because
    }
};





