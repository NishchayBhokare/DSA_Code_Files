//Leetcode problem.

//Approach 1: Optimised Approach. TC-O(KlogK + NLogK) SC-O(k)

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Stores all currently available servers.
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishing_time, server_id}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        vector<int> freq(k, 0);

        int maxFreq = 0;

        for (int i = 0; i < arrival.size(); i++) {

            // Release all servers whose requests have completed.
            while (!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                available.insert(server);
                busy.pop();
            }

            // Preferred server for current request.
            int preferred = i % k;

            // Find the next available server.
            auto it = available.lower_bound(preferred);

            // Wrap around if no suitable server exists.
            if (it == available.end()) it = available.begin();

            // All servers are busy.
            if (it == available.end()) continue;
            
            int server = *it;

            // Assign request and mark server busy.
            available.erase(it);

            busy.push({arrival[i] + load[i],server});

            // Update request count.
            freq[server]++;

            maxFreq = max(maxFreq, freq[server]);
        }

        // Collect all busiest servers.
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (freq[i] == maxFreq) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};



//Approach 2: Naive Approach TC-O(N*K) SC-O(K)
TC - O(N*K) SC-O(K)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        unordered_map<int, pair<int,int>>serverList;

        int maxFreq=0;
        for(int i=0; i<arrival.size(); i++){

            int ind = i%k;
            int startPos = ind;

            while(serverList[ind%k].first > arrival[i] and (startPos+k)!=ind){ //instead of heap and set
                //exploring all serverlist, and take first available server.
                ind++;
            }
            
            if(ind == startPos+k) continue;

            serverList[ind%k].first = arrival[i] + load[i];
            serverList[ind%k].second++;

            maxFreq = max(maxFreq, serverList[ind%k].second);
        }

        vector<int>ans;
        for(int i=0; i<k; i++){

            if(serverList[i].second == maxFreq){
                ans.push_back(i);
            }
        }
        return ans;
    }
};