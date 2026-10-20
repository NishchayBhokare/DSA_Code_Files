
//TC - O(n2 × log(n)) SC - O(N2)
class Solution {
  public:
  //similar to prims algo.
    int minCost(vector<vector<int>>& houses) {
        // code here
        
        int n = houses.size();
        vector<int>visited(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        pq.push({0,0}); //[dist,nodeInd]
        
        int cost = 0;
        while(!pq.empty()){
            
            int dist = pq.top().first;
            int nodeInd = pq.top().second;
            
            pq.pop();
            
            if(!visited[nodeInd]){
                cost += dist;
                visited[nodeInd]=1;
                
                for(int i=0; i<n; i++){
                    
                    if(i!=nodeInd and !visited[i]){
                        
                        int currCost = abs(houses[nodeInd][0] - houses[i][0]) 
                        + abs(houses[nodeInd][1] - houses[i][1]);
                        
                        pq.push({currCost,i});
                    }
                }
            }
        }
        
        return cost;
    }
};