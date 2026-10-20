//Approach Using Disjoint set. 
// 1. Time Complexity (TC) O(E) all other operations are constant.
//SC-O(V)

class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){

        size.resize(n,1);
        parent.resize(n);

        for(int i=1; i<n; i++){
            parent[i]=i;
        }
    }

    int findParent(int up){

        if(parent[up] == up){
            return up;
        }

        return parent[up] = findParent(parent[up]);
    }

    void makeUnion(int u, int v){

        int up = findParent(u);
        int vp = findParent(v);

        if(size[up] >= size[vp]){
            size[up] += size[vp];
            parent[vp] = up;
        }
        else{
            size[vp] += size[up];
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);

        vector<int>ans(2);
        for(auto edge:edges){

            int u = edge[0];
            int v = edge[1];

            if(ds.findParent(u) != ds.findParent(v)){
                ds.makeUnion(u,v);
            }
            else{
                ans[0]=u;
                ans[1]=v;
            }
        }

        return ans;
    }
};