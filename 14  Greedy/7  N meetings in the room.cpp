//GFG.

//Approach 1: using greedy TC-O(NLogn) SC-O(N+N).
//sort the array according to the end time. so that..minimum end time will be one top.

bool cmp(pair<int,int>&a, pair<int,int>&b){ //sorting by end time.
    return a.second < b.second;
}

class Solution {
  public:
  
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<pair<int,int>>mapping;
        int n=start.size();
        for(int i=0; i<n; i++){
            
            mapping.push_back({start[i], end[i]});
        }
        
        sort(mapping.begin(), mapping.end(), cmp);
        
        int cnt=1, lastFinishTime = mapping[0].second; //while starting start with 1 index. because any how..
        //size of n will be 1. so start with 1 index and count will be 1 and lastfinishttime will be the end time of first meeting.
        
        for(int i=1; i<n; i++){
            
            int startTime = mapping[i].first;
            int endTime = mapping[i].second;
            
            if(startTime > lastFinishTime){ //if new meeeting start time greater than last meeting's finish time.
                cnt++; //then increment count.
                lastFinishTime = endTime; //update lastfinsih time.
            }
        }
        
        return cnt; //return final count.
    }
};