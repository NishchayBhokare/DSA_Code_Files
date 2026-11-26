//GFG.

//Approach 1: Optimised approach TC-O(N) SC-O(N)
class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        
        int n = s.size();
        vector<int>prefix(n);
        
        int cnt=0;
        for(int i=0; i<n; i++){
            
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt++;
            }
            
            prefix[i]=cnt;
        }

        vector<int>ans;

        for(int i=0; i<queries.size(); i++){
            int l=queries[i][0], r=queries[i][1];
            
     
            int rangeTotal = prefix[r] - (l==0? 0 : prefix[l-1]);
            
            ans.push_back(rangeTotal);
        }
        
        return ans;
    }
};


//Appraoch 2: Two array appraoch. 
class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        
        int n = s.size();
        vector<int>left(n), right(n);
        
        int cnt1 = 0, cnt2=0;
        for(int i=0; i<n; i++){
            
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt1++;
            }
            
            if(s[n-i-1]=='a' or s[n-i-1]=='e' or s[n-i-1]=='i' or s[n-i-1]=='o' or s[n-i-1]=='u'){
                cnt2++;
            }
            
            left[i]=cnt1;
            right[n-i-1]=cnt2;
        }
        
        int totalVowels = cnt1;
        vector<int>ans;
        
        for(int i=0; i<queries.size(); i++){
            int l=queries[i][0], r=queries[i][1];
            
            int leftRemove = 0, rightRemove = 0;
            
            if(l!=0) leftRemove = left[l-1];
            if(r!=n-1) rightRemove = right[r+1];

            
            int rangeTotal = totalVowels - leftRemove - rightRemove;
            
            ans.push_back(rangeTotal);
        }
        
        return ans;
    }
};


//Appraoch 3: Naive approach. TC-O(Q*(r-l+1)) SC-O(1)
class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            
            int cnt = 0;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                
                if(s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u'){
                    cnt++;
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};