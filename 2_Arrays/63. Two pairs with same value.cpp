
//Approach 1: Optimised approach TC-O(N2) SC-O(N2)
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {

      // Store the first pair of indices for each sum.
      // Since pairs are generated in lexicographical order,
      // this will always be the smallest pair for that sum.
      unordered_map<int, pair<int,int>> mp;

      vector<int> ans = {-1, -1, -1, -1};

      // Generate all possible pairs (i, j) where i < j.
      for(int i = 0; i < arr.size(); i++) {
          for(int j = i + 1; j < arr.size(); j++) {

                int sum = arr[i] + arr[j];

                // If this sum is encountered for the first time,
                // store the current pair of indices.
                if(mp.find(sum) == mp.end()) {
                    mp[sum] = {i, j};
                }

                else {
                    // Retrieve the previously stored pair.
                    auto pr = mp[sum];

                    int a = pr.first, b = pr.second;
                    int c = i, d = j;

                    // Ensure all four indices are distinct.
                    if(a != c and a != d and b != c and b != d) {

                        vector<int> temp = {a, b, c, d};

                        // Update the answer if this quadruple
                        // is lexicographically smaller.
                        if(ans[0] == -1 or temp < ans) {
                            ans = temp;
                        }
                    }
                }
          }
      }

      return ans;
    }
};



//Appraoch 2: Naive approach TC-O(N4logN) SC-O(N4)
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {

       unordered_map<int,vector<pair<int,int>> > mp;

       for(int i=0; i<arr.size(); i++){
           for(int j=i+1; j<arr.size(); j++){
                int sum = arr[i]+arr[j];
                mp[sum].push_back({i,j});
            }
       }


       vector<vector<int>>ans;
        for(auto pr:mp){

            vector<pair<int,int>>temp = pr.second;
            if(temp.size()<=1) continue;

            for(int i=0; i<temp.size()-1; i++){

                for(int j=i+1; j<temp.size(); j++){

                   int a = temp[i].first;
                   int b = temp[i].second;

                   int c = temp[j].first;
                   int d = temp[j].second;

                   if(a!=c and a!=d and b!=c and b!=d ){
                       ans.push_back({a,b,c,d});
                   }
               }
           }
       }

       if(ans.size()==0) return {-1,-1,-1,-1};

       sort(ans.begin(), ans.end());

       return ans[0];
    }
};
