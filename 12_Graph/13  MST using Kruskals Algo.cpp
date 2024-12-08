//GFG

//Disjoint set used in dynamic graphs..which keeps on changing.

//we can solve this problem using prims algo too..but this krukal's algo is optmised algo.
//here u are using disjoint set technique
//Disjoint set are the set..in which we can get ulitmate parent and makeunion by rank..
//basically this disjoint set can be used to  find MST. 

//TC- O(E * (4 * alpha)) i.e constant.
class disJointSet{
	public:
	vector<int>parent;
	vector<int>rank;

	disJointSet(int n){
		parent.resize(n);
		for(int i = 0; i<n; i++)
			parent[i] = i;

		rank.resize(n,0);
	}

	int findParent(int node){
		if(parent[node] == node)
			return node;
			
		parent[node] = findParent(parent[node]);
		
		return parent[node];
	}

	void makeUnionByRank(int u, int v){
		int uP = findParent(u);
		int vP = findParent(v);
		
		if(rank[uP] == rank[vP]){
			parent[vP]  = uP;
			
			rank[uP]++;
		}
		else if(rank[uP] > rank[vP])
			parent[vP] = uP;
			
		else
			parent[uP] = vP;
	}

};

int spanningTree(int V, vector<vector<int>> adj[]) 
{ //adj is V size array of vector..check drivers code.


	disJointSet ds(V); //creating instance of disjoint set.
	
	vector<pair<int, pair<int,int> > > adjList;
	
	for(int i = 0; i<V; i++){
		for(auto j:adj[i]){
			int u = i;
			int v = j[0];
			int w = j[1];
			
			adjList.push_back({w,{u,v}});
		}
	}
	
	sort(adjList.begin(),adjList.end());
	
	int sum = 0;
	
	for(auto i:adjList){
		int w = i.first;
		int u = i.second.first;
		int v = i.second.second;
		
		int uP = ds.findParent(u);
		int vP = ds.findParent(v);
		
		if(uP != vP){
			sum+= w;
			ds.makeUnionByRank(u,v);
		}
	}
	
	return sum;
}




  //coding ninja solution without using class disjoint set..just creation of functions.
void makeSet(vector<int>&parent, int n){
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }
}

int findParent(vector<int>&parent, int node){
    if(parent[node] == node)
        return node;
    
    parent[node] = findParent(parent, parent[node]);

    return parent[node];
}

void unionByRank(int u, int v, vector<int>&parent, vector<int>&rank){
    int uP = findParent(parent,u); //finding ultimate parent.
    int vP = findParent(parent,v);

    if(rank[uP] == rank[vP]){
        parent[vP] = uP;
        rank[uP]++;
    }
    else if(rank[uP] > rank[vP]){
        parent[vP] = uP;
    }
    else{
        parent[uP] = vP;
    }
}

bool cmp(vector<int>&a, vector<int>&b){
    return a[2] < b[2];
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{   
    sort(edges.begin(),edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n,0);

    makeSet(parent,n);

    // vector<pair<int,int>>mst; 

    int tw = 0;
    for(int i = 0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];

        int uP = findParent(parent,u); //finding ultimate parent.
        int vP = findParent(parent,v);
        int w = edges[i][2];

        if(uP != vP){

            tw += w;
            // mst.push_back({edges[i][0], edges[i][1]}); if question asked to return mst nodes..we can calculate 
            //mst like this.

            unionByRank(uP,vP,parent,rank); 
        }
    }

    // for(auto i:mst){
    //     cout<<i.first<<" "<<i.second<<endl;  
    // }

    return tw;
}
