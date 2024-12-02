//GFG

//Simple using Dijkstra's algo.
//creating stepsArr which stores minimum step for nodeVal.
//logic is we will push first start node in queue..and will multiply that nodevalue with array's elements.
//and will push those newly generated values in queue by updating their steps.
//we can use visited array also..no need to create steps array.
//TC-O(100000 * N) -> N is for inner loop of traversing over array elements.
int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end)
        return 0;
    
    queue<vector<int>>q;
    q.push({start,0}); //first pushing start value with it's current step count.
    vector<int>stepsArr(100000,INT_MAX); //creation of steps array.
    
    int mod = 100000; //by this mod we're going to modulus.
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        int value = node[0];
        int steps = node[1];
        
        for(auto next:arr){
            
            int nextVal = (value * next)%mod; //multiplying value with next value from array and store it into varaible.
            int nextStep = steps + 1; //update nextStep by 1.
            
            if(nextVal == end)  ///if we found nextVal equals to end..then return nextVal.
                return nextStep;
            
            if(nextStep < stepsArr[nextVal]){ //if nextStep less than nextVal. then then push it into the queue and update steps array.
                q.push({nextVal,nextStep});
                stepsArr[nextVal] = nextStep;
            }
        }
    }
    
    return -1;
}

//Approach 2: with using visited data structure.
int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end)
        return 0;
    
    queue<vector<int>>q;
    unordered_map<int,bool>visited;
    
    q.push({start,0}); 
    visited[start] = true;
    
    int mod = 100000;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        int value = node[0];
        int steps = node[1];
        
        for(auto next:arr){
            
            int nextVal = (next * value)%mod;
            int nextStep = steps + 1;
            
            if(nextVal == end) 
                return nextStep;
            
            if(!visited[nextVal]){ //just check..if not visited then visit it and push into the quque.
                
                q.push({nextVal,nextStep});
                visited[nextVal] = true;
            }
        }
    }
    
    return -1;
}