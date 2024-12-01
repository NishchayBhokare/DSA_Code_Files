//Coding ninja.
//Dijkstra's algorithm on undirected weighted graph.

//Dijkstra's algorithm will work in only with positive values on both directed and undirected graph.
//if it has negative weight..then we will fall in infinite loop..because every time from u to v distance will get reduce..
//and we will keep traversing from u to v.  

//actually approach 2 is very optimised..because we have used set..and we can erase pair..which has 
//maximum distance...but in prioritye queue we cannot do this.

//Approach 1: using min heap. TC-o(ElogV) SC-O(E+V)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>> >adj;
    // 0u -> [1v,2w], [3v,4w]; //these is sturcure.
    
    for(int i = 0; i<edges; i++){ //creation of adjacency list.
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> distance(vertices,INT_MAX); //initialising distance vector with int max.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    //creating min  heap.

    //creating pair of distance and node.
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

            if(totalNeighborDist < distance[neighborNode]){
                
                //update distance
                distance[neighborNode] = totalNeighborDist;
                
                //now push in stack.
                pq.push({totalNeighborDist,neighborNode});
            }
        }
    }


    return distance;
}




Approach 2: Using set//logic is..first do bfs and pop out node from set..then check adjacent of these nodes...if adjacent node's 
// distance + node distance is less than current distance present in distance vector for that node..then delete more distance pair 
//from set. and update distance in distance vector..and push this new distance in set.

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>> >adj;
    
    for(int i = 0; i<edges; i++){ //creation of adjacency list.
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> distance(vertices,INT_MAX); //initialising distance vector with int max.
    set<pair<int,int> > st;

    //creating pair of distance and node.
    st.insert({0, source});
    distance[source]=0;

    while(!st.empty()){
        auto node = *(st.begin()); //st.begin will give iterator pointing to that address..by dereferencing
        //it..we will get value at that address..i.e pair.

        int nodeDistance = node.first;
        int topNode = node.second;
        
        st.erase(st.begin());

        for(auto neighbor:adj[topNode]){
            
            int neighborNode = neighbor.first;
            int neighborDist = neighbor.second;

            int totalNeighborDist = nodeDistance + neighborDist;

            if(totalNeighborDist < distance[neighborNode]){

                if(distance[neighborNode] != INT_MAX){ //if this node is already visited..then delete their instance or pair from set..because no need to keep it.
                //as we found minimum distnace pair.
                    st.erase({distance[neighborNode],neighborNode}); //deleting that maximum distance pair.
                }
                
                //update distance
                distance[neighborNode] = totalNeighborDist;
                
                //now push in stack.
                st.insert({totalNeighborDist,neighborNode});
            }
        }
    }


    return distance;
}


//Approach 3: normal approach using queue.. GFG.
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<vector<int> >adj(N);
    
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    vector<int>distArr(N,-1);
    queue<int>q;
    q.push(src);
    distArr[src] = 0;
    
    while(!q.empty()){
        
        auto node = q.front();
        q.pop();
        
        int wt = distArr[node];
        
        for(auto nbr:adj[node]){
            
            int nbrWt = wt + 1;
            
            if(distArr[nbr] == -1 || nbrWt < distArr[nbr]){
                distArr[nbr] = nbrWt;
                
                q.push(nbr);
            }
        }
    }
    
    
    return distArr;
}