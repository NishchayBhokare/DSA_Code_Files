//Approach 1: using BFS (Kahn's Algorithm)
//Basically we're calculating 
1) indegree of every node...after that..
2) pushing nodes in queue which has indgree zero.

vector<int> topologicalSort(vector<vector<int>>& adj) {
    
    vector<int>indegree(adj.size()); //don't use map..because..order is matter..
    vector<int> ans;
    queue<int>q;
    
    for(auto i:adj){ //creation of indegree of nodes.
        for(auto j:i){
            indegree[j]++; //incrementing count for j node..as i to j is edge.
        }
    }

    // for(int i = 0; i<v; i++){
    //     for(auto nbr:adj[i]){
    //         indegree[nbr]++; //can do like this also.
    //     }
    // }
    
    
    //pushing nodes..which has indegree equals to 0.
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    
    while(!q.empty()){
        int node = q.front(); //get front node
        q.pop();
        
        ans.push_back(node); //push in answer vector.
        
        for(auto neighbor:adj[node]){ //get neighbor nodes of adj[node]
            indegree[neighbor]--; //as we pop out..node..so we need to decrement indegree of its neighbors.
            
            if(indegree[neighbor] == 0) //now check..if any neighbor's indegree becomes zero..then push in queue
                q.push(neighbor);
        }
        
    }
    
    return ans; //and finally return answer.
}