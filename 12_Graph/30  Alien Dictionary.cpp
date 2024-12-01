 //GFG 
 
//As we know..question is asking to ordering characters..that means...something before something case.
//so in this case we can use topological sort.


//Approach 1: using BFS toplogical sort. 
 string findOrder(vector<string> dict, int k) {
    vector<vector<int>>adj(k);

    for(int i = 0; i<dict.size()-1; i++){ //looping over dictionary array and taking two strings.
        string first = dict[i];
        string second = dict[i+1];
        
        int len = min(first.size(), second.size()); //looping till minimum length of string.
        
        for(int i = 0; i<len; i++){
            if(first[i] != second[i]){
                
                int node = first[i] - 'a'; //getting integer value from character so that we can store it in adjacency list.
                int nbr = second[i] - 'a';
                
                adj[node].push_back(nbr); //create link from node to nbr. as node came before nbr.
                break;
            }
        }
    }
    
    
    //Now, just find toplogical order from this created adjacency list.
    vector<int>indegree(k,0);
    queue<int>q;
    
    //find indegree
    for(int i = 0; i<adj.size(); i++){
        for(auto nbr:adj[i]){
            indegree[nbr]++;
        }
    }
    
    
    //push element in queue which has indegree as 0.
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    
    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        //converting integer to character and stored into the answer string.
        char ch = char(node + 'a'); 
        ans.push_back(ch);
        
        for(auto nbr:adj[node]){
            indegree[nbr]--;
            
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    return ans;
}


//Approach 2: simple way..using DFS toplogical sort. 
void solve(int node, vector<vector<int>>&adj, vector<bool>&visited, string &ans){
    
    visited[node] = true;
    
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            solve(nbr,adj,visited,ans);
        }
    }
    
    //just before returning make sure
    char ch = node + 'a';
    ans.push_back(ch);
}

    string findOrder(vector<string> dict, int k) {
    
    vector<vector<int>>adj(k);
    
    for(int i = 0; i<dict.size()-1; i++){
        string first = dict[i];
        string second = dict[i+1];
        
        int len = min(first.size(), second.size());
        
        for(int i = 0; i<len; i++){
            if(first[i] != second[i]){
                
                int node = first[i] - 'a';
                int nbr = second[i] - 'a';
                
                adj[node].push_back(nbr);
                break;
            }
        }
    }
    
    string ans = "";
    vector<bool>visited(k,false);
    for(int i = 0; i<k; i++){
        if(!visited[i]){
            solve(i,adj,visited,ans);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}