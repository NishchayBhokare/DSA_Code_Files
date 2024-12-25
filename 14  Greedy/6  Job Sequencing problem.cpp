//GFG.

//We can optimise this solution using priority queue and also Disjoint set.

//TC-O(N*LogN + N*maxDeadLine) SC-O(maxDeadLine).
//logic is create mapping between profit and deadline.
//sort it according to profit.
//also get maximum number of deadline.
//create hash array of it. to check..a day is filled with process or not.
//not iterate over mapping. now check for current deadline in job array. can we filled it or not.
//if yes then filled it else move back to other days till 1. 

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                            vector<int> &profit) {
    
    vector<pair<int,int>>mapping;
    
    int n=id.size(), maxDL=0;
    for(int i=0; i<n; i++){
        maxDL = max(maxDL, deadline[i]);
        
        mapping.push_back({profit[i], deadline[i]});
    }
    
    sort(mapping.begin(), mapping.end(), greater<pair<int,int>>()); //sort descending order.
    
    vector<bool>jobArr(maxDL+1, false);
    
    int Tprofit = 0, proCnt=0;
    for(auto mp:mapping){
        
        int profit = mp.first;
        int DL = mp.second;

        while(DL >= 1){
            
            if(!jobArr[DL]){ //if current day is empty..then we can filled with current processs.
                
                jobArr[DL]=true;
                Tprofit += profit;
                proCnt++;
                
                break;
            }
            DL--;
        }

    }
    
    return {proCnt, Tprofit};
}