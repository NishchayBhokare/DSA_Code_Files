//Both GFG and coding ninja..question's anawer is provided.


//gfg answer. 
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>>adj(V,vector<int>()); //creating adjacency list using vector of vector.
    
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first; //taking u and v and updating in adjacency matrix.
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}


// coding ninja answer
//Same like above..just one addition is ..we want nodes values first..so first for loop is adding vertex value.
//at vertex index.
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    vector<vector<int>>adj(n,vector<int>());
    for(int i = 0; i<n; i++){
        adj[i].push_back(i);
    }

    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    return adj;
}