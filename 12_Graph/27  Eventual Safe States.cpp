//GFG 

//I have solved this question by myselef..kudos to u nishu.
//Approach usign DFS: On the fly just add safe node in answer vector. 
class Solution {
  public:
    bool solve(int node, vector<vector<int>>&adj, vector<int>&visited,
        vector<int>&dfsVisited, vector<int>&ans){
        
        
        visited[node]=1;
        dfsVisited[node]=1;
        
        for(auto neighbor:adj[node]){
            
            if(!visited[neighbor]){
                
                if( solve(neighbor, adj, visited, dfsVisited, ans) == false)
                    return false;
            }
            else if(dfsVisited[neighbor])
                return false;
        }
        
        ans.push_back(node);
        dfsVisited[node]=0;
        return true;
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
    
        vector<vector<int>>adj(V);
        
        for(auto m:edges){
            int u=m[0], v=m[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>visited(V);
        
        vector<int>ans;
        
        vector<int>dfsVisited(V);
        
        for(int node=0; node<V; node++){
            
            if(!visited[node]){
                solve(node,adj,visited,dfsVisited,ans);
            }
        }
        
        // sort(ans.begin(), ans.end()); //not required optional.
        //we can return in any order.
     
        
        return ans;
    }
};

//Approach 2: using path array..we can solve it..we're using path array to check if cycle is prsent or not
//if not..then it's safe like that..if cycle is present then it's not safe so return false..but make sure...you are NOT uncehcking or removing path values from true to false.
//because there can be the nodes..attached to this cycle..so that node will also not safe. so to save that itration to check..because we already check..so that's why
//don't change values of path array..when cycle is detected
 bool solve(int node, vector<int> adj[], vector<bool>&safe, vector<bool>&visited, vector<bool>&path){
        
        visited[node] = true;
        path[node] = true;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr]){
                bool ans = solve(nbr,adj,safe,visited,path);
                if(ans == false){
                    return false;
                }
            }
            
            else if(path[nbr]){ //nbr is already visited and it's present in path array that means cycle is present..so return false;.
                return false; //then no need to do further processing return false.
            }
            
        }
        
        path[node] = false; //uncheck ...that is make false;
        safe[node] = true; //if we did all adjacent node travesing..and till we reached here that means..this node is safe.
        return true;
    }

     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<bool>safe(V,false);
        vector<bool>visited(V,false);
        vector<bool>path(V,false);
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                solve(i,adj,safe,visited,path);
            }
        }
        
        vector<int>ans;
    
        for(int i = 0; i<V; i++){
            if(safe[i])
                ans.push_back(i);
        }
        
        return ans;
    }

//Approach 1: Optimised Approach.

//we will do simpley dfs..so when.. anyparticular node is not visited..then call for it.
//if it's visited..then there are two possbile reasons...either that node is safe node..or it's unsafe.
//if it's unsafe..then no need to check further..because..current node...connected to that node..so current node is also unsafe..so return false which indicates not safe.
//if it's safe..then check for next path..if present..then if we traverse over all the adjacents..and still
//we have not return as false..then current node is safe node..so mark it as safe and return true.
bool solve(int node, vector<int> adj[], vector<bool>&safe, vector<bool>&visited){
    
    visited[node] = true;
    
    // if(adj[node].size() == 0){ //we can add condition for terminal node..or can skip it..because..it will not goes into for loop and 
                                 //at last..we will mark this node as safe.
    //     //this is terminal node.
    //     safe[node] = true;
    //     return true;
    // }
    
    for(auto nbr:adj[node]){
        
        if(!visited[nbr]){
            
            bool ans = solve(nbr,adj,safe,visited);
            if(ans == false) //if at any point..node is unsafe then return false..
                return false;
        }
        
        else if(safe[nbr] == false){ //nbr is already visited but it's not safe.
            return false; //then no need to do further processing return false.
        }
        
    }
    
    safe[node] = true; //if we traversed all adjacent nodes..and till we reached here that means..this node is safe.
    return true;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<bool>safe(V,false); //initially marking safe node as false.
    vector<bool>visited(V,false);
    
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            solve(i,adj,safe,visited);
        }
    }
    
    vector<int>ans;
    
    for(int i = 0; i<V; i++){
        if(safe[i])
            ans.push_back(i);
    }
    
    return ans;
}



// //Approach 3: // Approach 3: Using Topological Sort by Reversing the Edges TC-O(V+E) 
// Core idea:
// Reverse all the edges of the graph.
//
// In the original graph:
//     terminal node → has outdegree 0
//
// After reversing the edges:
//     terminal node → has indegree 0
//
// Therefore, terminal nodes can be treated as starting nodes for
// Kahn's Topological Sort.
//
// We put all nodes with indegree 0 into the queue.
// While processing a node:
//     1. Remove its outgoing edges in the reversed graph.
//     2. Decrease the indegree of its neighbors.
//     3. If any neighbor's indegree becomes 0, push it into the queue.
//
// Every node whose indegree eventually becomes 0 is an eventual safe node.
//
// Why?
// If a node can eventually reach a terminal node and cannot reach a cycle,
// then after reversing the edges, all of its incoming edges will eventually
// be removed starting from the terminal nodes. Its indegree will therefore
// become 0.
//
// But if a node can reach a cycle, at least one edge coming from the cycle
// (or another unsafe node) will remain. Therefore, its indegree will never


// become 0, so it will not be added to the answer.
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<vector<int>>adjList(V);
    
    vector<bool>safe(V,false);
    vector<int>indegree(V,0);
    
    for(int i = 0; i<V; i++){
        
        for(auto nbr:adj[i]){
            adjList[nbr].push_back(i); //reversing links..that is make v to u from u to v.
            indegree[i]++; //also increment indegree of i. as linke is from nbr to i.
        }
    }
    
    
    queue<int>q;
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0) //push all nodes with indegree zero.
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        safe[node] = true; //make as true..because current node is now safe node.
        
        for(auto nbr:adjList[node]){
            indegree[nbr]--;
            
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    vector<int> ans;
    
    for(int i = 0; i<safe.size(); i++){
        if(safe[i])
            ans.push_back(i);
    }
    
    return ans;


    // vector<int> ans; //Optimised one..we don't need to mark node as safe..and traverse over safe array..instead..we can do like this..if node is
                        //then there indegree will definitely 0..so traverse over indegree array and whoever have indegree 0..then just push that node in anwer
                        
    // for(int i = 0; i<indegree.size(); i++){
    //     if(indegree[i] == 0)
    //         ans.push_back(i);
    // }
    
    // return ans;
}


//Approach usign DFS: On the fly just add safe node in answer vector. 
class Solution {
  public:
    bool solve(int node, vector<vector<int>>&adj, vector<int>&visited,
        vector<int>&dfsVisited, vector<int>&ans){
        
        
        visited[node]=1;
            dfsVisited[node]=1;
        
        for(auto neighbor:adj[node]){
            
            if(!visited[neighbor]){
                
                if( solve(neighbor, adj, visited, dfsVisited, ans) == false)
                    return false;
            }
            else if(dfsVisited[neighbor])
                return false;
        }
        
        ans.push_back(node);
        dfsVisited[node]=0;
        return true;
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
    
        vector<vector<int>>adj(V);
        
        for(auto m:edges){
            int u=m[0], v=m[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>visited(V);
        
        vector<int>ans;
        
        vector<int>dfsVisited(V);
        
        for(int node=0; node<V; node++){
            
            if(!visited[node]){
                solve(node,adj,visited,dfsVisited,ans);
            }
        }
        
        // sort(ans.begin(), ans.end()); //not required optional.
        //we can return in any order.
     
        
        return ans;
    }
};