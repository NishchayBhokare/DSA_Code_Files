//GFG. 
//This problem is combination of both..graph and recursion.

// M coloring problem state that.. check whether all nodes can be colored using m colors or not. 
// and adjacent nodes shouldn't have same color.

//Approach: Recursive Approach TC-O(M^N) for every node we have m choices. for N=1 and choices is M.
//then TC will be O(3^1 i.e 3). three times we're iterating over loop.
//SC-O(N + N)
bool isSafeToColor(int node, int color, vector<vector<int>>&adjList, 
    unordered_map<int,int>&nodeColor){
    
    for(auto adjNode:adjList[node]){ //check if adjacent nodes has this color or not. 
        
        if(nodeColor[adjNode] == color) //if yes then return false. not safe.
            return false; 
    } 
    
    return true; //else return true. after processing all the possibles color.
}

bool solve(int node, vector<vector<int>>&adjList, unordered_map<int,int>&nodeColor, 
    int &v, int &m){

    if(node == v) return true; //if node value equals to v that means we processed all nodes.
    //and if we reach till here that means we're able to color all nodes so return true. 
    
    for(int color = 1; color<=m; color++){ //loop over all choices of color.
        
        if(isSafeToColor(node, color, adjList, nodeColor)){ //check for current node..can we color it.
            
            nodeColor[node] = color; //if yes then color it with color.
            
            bool ans = solve(node+1, adjList, nodeColor, v, m); //and call function for next node.
            
            if(ans) return true; //if answer if true..that menas solution is possible so return true.
            
            nodeColor[node] = 0; //else backtrack..to check next combination of colors.
        }
        
    }
    
    return false; //if we cannot color node with any color. then we reach till here so return false.
}


bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    
    vector<vector<int>>adjList(v);
    
    for(auto i:edges){ //create adjacency list.
        
        int u=i.first, v=i.second;
            
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    
    unordered_map<int,int>nodeColor; 
    int node=0;
    return solve(node, adjList, nodeColor, v, m);
}