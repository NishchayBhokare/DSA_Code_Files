//GFG.

//Approach 1: TC-O(N) sC-O(N)
vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                    vector<int> &newInterval) {
    
    vector<vector<int>>ans;
    int i=0, n=intervals.size();
    //left part which not comes under overlapping.
    while(i<n && intervals[i][1] < newInterval[0]){
        ans.push_back({intervals[i][0], intervals[i][1]});
        i++;
    }
    
    //middle part which might came under overlappin.
    while(i<n && intervals[i][0] <= newInterval[1]){
        //just dry run this condition. suppose current interval is [6,7], new Interval is [7,8] and next interval is [8,10]. then there is overlapping between these three. so
        //we can observe this. 6 7 (current interval)
                            //   7 8 (new interval).
                            //     8 10 (next interval) then, if we take 6 and 10 then all intervals will accomodate in it. so we will insert [6,10].
        
        //so, if starting point of currnet interval is less than or equal to ending point of new interval.
        //then we're in overlapping situaltion. so take minimum value in starting of new interval.
        //and maximum value in ending of new interval so that we can cover all elements in this range.
        
        
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    
    ans.push_back({newInterval[0], newInterval[1]});
    
    //push remaining elements as it is.
    while(i < n){
        ans.push_back({intervals[i][0], intervals[i][1]});
        i++;
    }
    
    return ans;
}