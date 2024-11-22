//GFG. 
topological sort is the sorting technique..in which we sort node...u to v..such that..
node u comes before node v..in answer vector.

//Approach 1: topological sort using dfs.
//so logic is..we will go deep as per dfs..and while returning from that node..push that node..in stack..
void solve(int node, vector<vector<int>>& adj, unordered_map<int,bool>&visited,
stack<int> &st){
    
    visited[node] = true;
    
    
    for(auto neighbor:adj[node]){
        
        if(!visited[neighbor]){
            solve(neighbor, adj, visited, st);
        }
    }
    
    st.push(node); //push in the stack.
}
    
vector<int> topologicalSort(vector<vector<int>>& adj) {
    
    stack<int> st; 
    vector<int> ans;
    unordered_map<int,bool>visited;

    for(int node = 0; node<adj.size(); node++){
        if(!visited[node]){
                solve(node,adj,visited,st);
        }
    }
    
    while(!st.empty()){ //push values in answer vector.
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}




// Approach 2://we can optimise this code..by directly using answer vector..instead of stack..and we can reverse the ansewr vector.

void solve(int node, vector<vector<int>>& adj, unordered_map<int,bool>&visited,
        vector<int> &ans){
        
        visited[node] = true;
        
        for(auto neighbor:adj[node]){
            
            if(!visited[neighbor]){
                solve(neighbor, adj, visited, ans);
            }
        }

        ans.push_back(node); //directly pusing node in answer.
    }

vector<int> topologicalSort(vector<vector<int>>& adj) {
    
    vector<int> ans;
    unordered_map<int,bool>visited;

    for(int node = 0; node<adj.size(); node++){
        if(!visited[node]){
                solve(node,adj,visited,ans);
        }
    }
    
    reverse(ans.begin(),ans.end()); //reverse answer.
    return ans;
}


