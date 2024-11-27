//GFG question.


//Logic is for dfs..we goes deeper...using recursion...pick one node..then pick next node..then pick
//next or next node like that.
//TC-O(2 * Edges) SC-O(V)
void solve(int node, vector<vector<int>>& adj, 
    unordered_map<int,bool>&visited, vector<int>&ans){
                    
    ans.push_back(node); //push current node.
    visited[node] = true; //mark as visited.

    for(auto i: adj[node]){ //loop over adjaceny list for (current) node index element.
        if(!visited[i]){ 
            solve(i,adj,visited,ans); //solve for i node.
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<int>ans;
    unordered_map<int,bool>visited;
    
    int node = 0;
    solve(node,adj,visited,ans);
    
    return ans;
}