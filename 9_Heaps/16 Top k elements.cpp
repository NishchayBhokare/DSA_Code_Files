//Leetcode.

//Appraoch 1: Optimised Approach TC-O(NlogK) SC-O(N)
//TC-O(Nlogk)  SC-O(N)  
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;

        for(auto num:nums) freq[num]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

        for(auto num:freq){
            //insert first k element in priority queue.
            if(pq.size() < k) pq.push({num.second, num.first});
            else{

                //once size is equal to k.
                // num[number,freq]
                if(num.second > pq.top().first){ //pq[freq,number]
                    pq.pop();
                    pq.push({num.second, num.first});
                }
            } 
        } 

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};


//Approach 2: Brute force approach.
//TC-O(NLogN) SC-O(N)
bool cmp(pair<int,int>&a, pair<int,int>&b){
    return a.first > b.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;

        for(auto num:nums) freq[num]++;

        vector<pair<int,int>>vec;
        for(auto numFreq:freq) vec.push_back({numFreq.second, numFreq.first});

        sort(vec.begin(),vec.end(),cmp);

        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};