//GFG
//we can solve this problem using prims algo too..but this krukal's algo is optmised algo.


void makeSet(vector<int>&parent){
	    for(int i = 0; i<parent.size(); i++)
	        parent[i] = i;
	}
	
	int findParent(vector<int>&parent, int node){
	    if(parent[node] == node)
	        return node;
	        
	    parent[node] = findParent(parent,parent[node]);
	    
	    return parent[node];
	}
	
	void makeUnionByRank(vector<int>&parent,vector<int>&rank,int u, int v){
	    int uP = findParent(parent,u);
	    int vP = findParent(parent,v);
	    
	    if(rank[uP] == rank[vP]){
	        parent[vP]  = uP;
	        
	        rank[uP]++;
	    }
	    else if(rank[uP] > rank[vP])
	        parent[vP] = uP;
	       
	    else
	        parent[uP] = vP;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[]) 
    { //adj is V size array of vector..check drivers code.
    
        vector<int>parent(V);
        vector<int>rank(V,0);
        
        makeSet(parent);
        
        vector<pair<int, pair<int,int> > > adjList;
        
        for(int i = 0; i<V; i++){
            for(auto j:adj[i]){
                int u = i;
                int v = j[0];
                int w = j[1];
                
                adjList.push_back({w,{u,v}});
            }
        }
        
        for(int i = 0; i<adjList.size(); i++){
            cout<<adjList[i].first<<" "<<adjList[i].second.first<<" "
            <<adjList[i].second.second<<endl;
            
        }
        
        return 0;
    }