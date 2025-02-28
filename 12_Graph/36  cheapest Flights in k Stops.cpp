//GFG.


//Question want to reach destination within k stops.
//so here we cannot apply regular dijkstra using priority queue.. only distance is not on priority..now number of stops are also on priority.
//so we will use simple queue..and distance array.
//the logic behind is..there might be the cases..where distance to particular node is smaller but number of stops is greater than k
//then that time..dijkstra with priority queue will fail..because it will neglect distance which are greater but stops are less.

//so for that we are using queue..with dijkstra which will work as bfs..we will reach to destination with shortest k stops with smaller distance.
 int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    vector<vector<pair<int,int> >>adj(n);
    
    for(auto i:flights){
        int u = i[0];
        int v = i[1];
        int w = i[2];
        
        adj[u].push_back({v,w}); //creation of adjacency list.
    }

    vector<int>priceArr(n,INT_MAX); //price array is nothing but distance array.
    queue<vector<int>>pq;
    
    pq.push({0,src,0}); //{stopNo,nodeVal,price}.
    priceArr[src] = 0;
    while(!pq.empty()){
        
        auto node = pq.front();
        pq.pop();
        
        int nodeStop = node[0];
        int nodeVal = node[1];
        int nodePrice = node[2];

        //we are not adding condition as we reached to destination or not..because there might be other shorter ways also..within k stops.
        //to reach destination..so not adding any condtion.
        
        for(auto nbr:adj[nodeVal]){
            int nbrNode = nbr.first;
            int nbrPrice = nbr.second;
            int nbrStop = nodeStop + 1;
            
            int totalPrice = nodePrice + nbrPrice;

            if((nbrStop-1) <= K && totalPrice < priceArr[nbrNode]){ 
                //as we added source node also..so source node to first dest will be consider as 0 stops.
                //becasue we reached..so that's why checking condition like..nbrStop-1 is lesser than k then push.
                //and if stop is lesser and price too..then only update price array and push in queue.
                
                pq.push({nbrStop, nbrNode, totalPrice});
                priceArr[nbrNode] = totalPrice;
            }
        }
    }
    
    if(priceArr[dst] != INT_MAX) //at last..if we reached till the destination..then definitely destination price will not be infinite..
        return priceArr[dst];  //if not..then return answer. which nothing but value or price stored at dst index.
        
    return -1; //if dst have int_max that means we're not able to reach destination so return -1.
}