//GFG.

//Approach 1: using dfs. simple approach 
void solve(int node, vector<vector<int> >&adjList, vector<bool>&visited){
    
    visited[node] = true;
    
    for(auto nbr:adjList[node]){
        if(!visited[nbr]){
            solve(nbr,adjList,visited);
        }
    }
}

int Solve(int n, vector<vector<int>>& edge) {
    
    if(edge.size() < n-1) //if edges size is less than number of nodes..then return -1 simply..becuase we cannot connect nodes
        return -1;
    
    vector<vector<int> >adjList(n);
    int m = edge.size();
    
    for(auto i:edge){
        int u = i[0];
        int v = i[1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<bool>visited(n,false);
    
    int comp = 0;
    int extraEdg = 0;
    
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            solve(i,adjList,visited);
            comp++; //just count the number of compoentns.
        }
    }
    
    return comp-1; //and return component - 1 i.e required edges
}

//Approach 2: using Disjoint set..
//first count extra edges. then count number of components..then check if number of components.
//now for x number of components..we required x-1 extra edeges..so check this condition..if yes..
//then return count of required edges.

class DisjointSet{
    public:
        vector<int>rank;
        vector<int>parent;
        DisjointSet(int v){
            rank.resize(v,0);
            parent.resize(v);
            
            for(int i = 0; i<v; i++)    
                parent[i]=i;
        }
        
        int findParent(int node){
            if(parent[node] == node)
                return node;
                
            return parent[node] = findParent(parent[node]);
        }
        
        void makeUnion(int uP, int vP){
            if(rank[uP] == rank[vP]){
                parent[vP] = uP;
                rank[uP]++;
            }
            else if(rank[uP] > rank[vP])
                parent[vP] = uP;
            
            else
                parent[uP] = vP;
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
    
       int extraEdge = 0;
       
       DisjointSet ds(n);
       
       for(auto i:edge){ 
        int uP = ds.findParent(i[0]);
        int vP = ds.findParent(i[1]);
        
        if(uP != vP){
            ds.makeUnion(uP,vP);
        }
        else
            extraEdges++; //incrementing count..if both u and v already have connected..i.e have same ultimate parent.
       }
       
       int components = 0;
       for(int i = 0; i<ds.parent.size(); i++){
           if(ds.parent[i]==i){ //increment count if node points to itself.
               components++;
           }
       }
       
       int requiredEdges = components - 1; //required eges will be components -1.f
       
       if(requiredEdges <= extraEdges){ //if required edges less than extra edges then return required edges.
           return requiredEdges;
       }
       
       return -1; //else return -1.
    }
  


  //We can solve like this too. first initilise number of components as n i.e number of vertex.
  //then wehenver we're doing makeunion then decrement component count..because one component count will going to 
  //decrese by 1...as one node will connect another one.

    int Solve(int n, vector<vector<int>>& edge) {
       
      int components = n; 
      int extraEdge = 0;
       
      DisjointSet ds(n);
       
      for(auto i:edge){ 
        int uP = ds.findParent(i[0]);
        int vP = ds.findParent(i[1]);
        
        if(uP != vP){
            ds.makeUnion(uP,vP);
            components--; //decrement coompoent count.
        }
        else
            extraEdge++; //if same increment extra edge count.
      }
       
      int requiredEdges = components-1;
      if(requiredEdges <= extraEdge){
          return requiredEdges;
      }
       
      return -1;
    }


}