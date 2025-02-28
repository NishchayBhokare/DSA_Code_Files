//GFG

//Approach 2: we can solve this question by just checking whther cycle is present or not..if yes..then return false
//else true
bool solve(int node, vector<vector<int>>&adj, vector<bool>&dfs, vector<bool>&visited){
    
    visited[node] = true;
    dfs[node] = true;
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            bool ans = solve(nbr,adj,dfs,visited);
            
            if(ans == false)
            return false; 
        }
        else{
            
            if(dfs[nbr]) //if visited and also dfs visited then return false..that is not possible because cycle is presnet.
                return false;
        }
    }
    
    dfs[node] = false;
    return true; //return true..as far now..it's possible.
}

bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
    
    vector<vector<int>>adj(N);
    vector<bool>visited(N,false);
    vector<bool>dfs(N,false);
    
    for(auto i:pre){
        adj[i.first].push_back(i.second);
    }
    
    
    for(int i = 0; i<N; i++){
        
        if(!visited[i]){
            bool ans = solve(i,adj,dfs,visited);
            
            if(ans == false) //if answer is false..that means cycle is prsent so return false;
            return false;
        }
    }
    
    return true; //else true.
}

//Question is very simple..we have to check..all task can complete or not..you can go through gfg for better understanding of que.
//we can solve this question by simply chcecking if there any cycle prsent or not..if yes..then task cannot be gets' complete.
//another way..i solved it by myself.

//Approach 1: my solution - using DFS
//logic is..if for any node..next neighbouring nodes are finished..then task for that node is completed.
//so before returning for this node..mark sure mark task for node is true and return true.
//while traversing over adjacent nodes..if at any point neighbour is alread visited and 
//also their task is not completed..that means...we cannot complete task..
bool solve(int node, vector<vector<int>>&adj, vector<bool>&task, vector<bool>&visited){
    
    visited[node] = true;
    
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            bool ans = solve(nbr,adj,task,visited);
            
            if(ans == false)
            return false; 
        }
        else{
            
            if(task[nbr] == false) //if neihgbour is already visited and also task not completed then return false.
                return false;
        }
    }
    
    task[node] = true; //before returing maek sure to mark it as true.
    return true;
}

bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
    
    vector<vector<int>>adj(N);
    vector<bool>visited(N,false);
    vector<bool>task(N,false);
    
    for(auto i:pre){
        adj[i.first].push_back(i.second);
    }
    
    
    for(int i = 0; i<N; i++){
        
        if(!visited[i]){
            bool ans = solve(i,adj,task,visited);
            
            if(ans == false)
            return false;
        }
    }
    
    return true;
}



//Approach 3: Using BFS..topological sort.
bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
    
    vector<vector<int>>adj(N);
    vector<bool>visited(N,false);
    vector<bool>task(N,false);
    
    for(auto i:pre){
        adj[i.first].push_back(i.second);
    }
    
    
    vector<int>indegree(N);
    queue<int>q;
    
    //creation of indegree.
    for(int i = 0; i<adj.size(); i++){
        for(auto j:adj[i]){
            indegree[j]++;
        }
    }
    
    
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
        if(count != N) //if count not equal to total nodes..then return true..i.e cyclic graph that means..task cannot get's complete
        return false;

    return true;
}