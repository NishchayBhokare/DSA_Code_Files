// GFG

//Approach 1: TC-O(ElogE) SC-O(E)
//using (PRIM's algorithm) priority queue min heap we can solve this problem.
//logic is we are taking minmum node distance edge to create spanning tree.
//in short..first insert soruce node in queue...then..mark it as visited and 
//and insert their adjacent nodes...then take..minimum distance node from queue..add their
//weight in sum and marked as true..and same ..push their adjacents if adjacents are not 
//visited earlier.. 
int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue< pair<int,int>, vector<pair<int,int>>, 
            greater<pair<int,int>> > pq;
        
        int sum  = 0;
        
        vector<bool>visited(V,false);
        
    //storing {weight,node}..currently no need to store parent for this question.
        pq.push( {0,0} );
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int nodeVal = node.second;
            int distance = node.first;
            
            if(visited[nodeVal]) continue; //node is visited..then no need to proceed further
            //jsut go to next iteration..because no need to add it's adjacents..as already this node is processed.
            
            sum += distance; //adding new node distance..as this node with edge wieght dist is added in mst.
            visited[nodeVal] = true; //mark as true.

            for(auto neighbor: adj[nodeVal]){ //check for adjacent nodes.

                int adjNode = neighbor[0];
                int dist = neighbor[1];
                
                if(!visited[adjNode]){ //if adjacent node is not visited already..then push into the queue.
                    pq.push({dist,adjNode});
                }
            }
        }
        
        return sum;
    }


    //If by chance they asked question like..give nodes which forms mst..for that below is solution..
    //just need add parent node also.
        int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>> > pq;
        
        int sum  = 0;
        
        vector<bool>visited(V,false);
        vector<pair<int,int>>mst;
         // {dist,node,parent} //this is positioning.
        pq.push( {0,{0,-1}} ); //here doing pari of pair.
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int nodeVal = node.second.first;
            int dist = node.first;
            int parent = node.second.second;
            
            if(!visited[nodeVal] ){
                sum += dist;
                visited[nodeVal] = true;
                
              if(parent != -1) mst.push_back({parent,nodeVal});
            }
            
            for(auto neighbor: adj[nodeVal]){

                int val = neighbor[0];
                if(!visited[val]){
                    
                    int dist = neighbor[1];
                    int par = nodeVal;
                    pq.push({dist,{val,par}});
                }
            }
        }
        
        for(auto i:mst){
            cout<<i.first<<" "<<i.second<<endl; //but here..in every case we're getting parent as 0..so this is issue
            //in this question but just understand the approach.
        }

        return sum;
    }



//Approach 2: TC-O(V2) because inner loop taking n to get min element.
 int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    
    
    key[0] = 0;
    parent[0] = -1;
    
    for(int i = 0; i<V; i++){
        
        int u;
        int mini = INT_MAX;
        //get min distnace node.
        for(int j = 0; j<V; j++){
            if(!visited[j] && key[j] < mini){ //get minimum distance of node..among all..which are not visited yet.
                mini = key[j];
                u = j;
            }
        }
        
        //mark u as true in visited
        visited[u] = true;
        
        
        //get adjacent nodes and update their distnace...if current distance is lesser.
        for(auto it:adj[u]){
            int v = it[0];
            int w = it[1];
            
            
            if(!visited[v] && w < key[v]){ //if v is not visited and current distacne is lesser than distance 
            //present in key vector..then upddate thier distance i.e weight.
                key[v] = w;
                parent[v] = u; //this parent is optional.
            }
        }
    }
    
    int sum = 0;
    for(auto i:key){ //total sum of spanning tree is sum of key vector values.
        sum+=i;
    }
    return sum;
}