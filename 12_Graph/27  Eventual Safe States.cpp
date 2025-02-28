//GFG 

//I have solved this question by myselef..kudos to u nishu.

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



// //Approach 3: Using Topological Sort by reversing node links.
//In short logic is reveres links..so terminal node will have indegree 0 and we can start checking from terminal node. if any node..connected to terminal node and not to any cycle
//then there indegree will be 0..but if it's connected to any cycle..then indegree will be greater than 0 after decrementing indegree..
//so just take..nodes which has indegree as 0 and push in the queue..and while popping out..just add in answer or mark as true.

Why we need to reverse links. -> reason is below.
// We wish to find a set of eventual safe nodes in the original graph G. Let T be the set of terminal nodes of G. A node 'p' in G is eventual safe if it's neither part of a cycle nor it can 'reach' any cycle. 
// In other words, all the 'outgoing' paths from 'p' can only reach one of the terminal nodes T. Conversely, if 'q' is an unsafe node, then there exists at least one 'outgoing' path which leads to a cycle (or unsafe nodes). 
// Now when we reverse G, in the reversed graph, all the outgoing paths become incoming paths and vice-versa. Let's call the reversed graph H. Note that the 'terminal' nodes T of G becomes the start nodes for the topological sort on H.

// In the reversed graph H, all the 'incoming' paths to 'p' must start from some terminal node in T (and must contain no cycles). 
// On the other hand, there exists at least one 'incoming' path to 'q' which originates from some unsafe node (connected to a cycle). 
// Now when we perform Kahn's topological sort starting from the terminal nodes T, and repeatedly remove edges from terminal node set to its neighbors, 
// at some point, all 'incoming' edges to 'p' will be removed and its indegree will become 0, and hence 'p' will be collected as a safe node. 
// On the other hand, 'q' will be left with at least one edge (involving unsafe nodes connected to a cycle), 
// and hence its indegree would never become zero, and hence it will not be collected as a safe node.

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