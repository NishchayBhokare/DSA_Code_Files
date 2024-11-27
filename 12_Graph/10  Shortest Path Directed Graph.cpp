// code studio..unable to add code studio question..so added gfg question.

//question is find..shortest path between soruce node to all nodes for directed wighted graph.

//Approach 1: using Dijkstras algorithm for directed graph.
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int,list<pair<int,int>> >adj;
    
    for(int i = 0; i<edges.size(); i++){ //creation of adjacency list.
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        adj[u].push_back(make_pair(v,w));
    }

    vector<int> distance(n,-1); //initialising distance vector with -ve value.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    //creating min  heap.

    //creating pair of distance and node.
    int source = 0;
    pq.push({0,source});
    distance[source]=0;

    while(!pq.empty()){
        auto node = pq.top();

        int nodeDistance = node.first;
        int topNode = node.second;
        
        pq.pop();

        for(auto neighbor:adj[topNode]){
            
            int neighborNode = neighbor.first;
            int neighborDist = neighbor.second;

            int totalNeighborDist = nodeDistance + neighborDist;

            if(distance[neighborNode] == -1 || totalNeighborDist < distance[neighborNode]){
                //added condition is only this..if distnce is -ve..then don't compare..just udpate distnace.
                
                //update distance
                distance[neighborNode] = totalNeighborDist;
                
                //now push in stack.
                pq.push({totalNeighborDist,neighborNode});
            }
        }
    }
    return distance;
}

//Approach 2: Optimised Approach using toplogical sort. using dfs
void solve(int node, unordered_map<int,list<pair<int,int>> >&adj, //just normal toplogical sort.
    stack<int>&st, unordered_map<int,bool>&visited){
    
    visited[node] = true;

    for(auto neighbor:adj[node]){
        if(!visited[neighbor.first]){ //checking neighbor of first is visited or not..first is node value and second is distance so.
            solve(neighbor.first,adj,st,visited); //calling solve for neighbor.
        }
    }
    
    st.push(node);  //before going back..add node into the toplogical sort.
}
  
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{  unordered_map<int,list<pair<int,int>> >adj;
    for(int i = 0; i<m; i++){ //creation of adjacency list.
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        pair<int,int> pr = make_pair(v,w);
        adj[u].push_back(pr);
    }

    vector<int>distance(V,-1); //initialising distance array with -1.
    unordered_map<int,bool>visited;
    stack<int>st;
    
    for(int node = 0; node<V; node++){ //call solve function for every vertex to get toplogical sort.
        if(!visited[node])
            solve(node,adj,st,visited);
    }
    
    
    //now toplogical list is prepared and stored in stack.
    distance[0]=0; //source node of distacne is 0.
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(distance[node] != -1){ //if distance of node is -1..that means..
        //this node disconnected component of graph or indegree of this node is 0.
        //in short..we cannot rech till this node so skip this node from checking.
            for(neighbor:adj[node]){ //checking neighbor of node.
                int weight = distance[node] + neighbor.second; //addning weight for current neighbor.
                int index = neighbor.first; //first shows node value.
                
                if(distance[index] != -1){ //if distacne for that node is not -1. then take min distance 
                    distance[index] = min(weight, distance[index]);
                }
                else
                    distance[index] = weight; //else if first time updating distance..then add it directly.
            }
        }
        
    }
    
    return distance;
}





    //Approach 3: using BFS. But it is giving TLE on gfg..as not that much optimised.
//by bfs..we are traversing all possible path to rech every node.
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int,list<pair<int,int>> >adj; //data structure to create grapht with node to it's weight.

    for(int i = 0; i<E; i++){ //creation of adjacency list.
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        pair<int,int> pr = make_pair(v,w);
        adj[u].push_back(pr);
    }

    vector<int>ans(V,-1);
    queue<pair<int,int>>q;
    q.push({0,0}); //for zero node distance is also zero.

    while(!q.empty()){ //while queue not empty.
        pair<int,int>node = q.front();
        q.pop();

        int index = node.first; //take index.
        int weight = node.second; //take weight of current node.

        if(ans[index] == -1) //if index is -1
            ans[index] = weight; //then add weight as it is.
        else
            ans[index] = min(ans[index], weight); //else check..min weight and add it.

        for(auto neighbor:adj[node.first]){ //now check for further neighbor nodes for current node
        //and add it in queue..here we're not tracking visited or not..because..we want to visit node in all possbile ways.
            neighbor.second += node.second;
            q.push(neighbor);
        }
    }
    
    return ans;
}