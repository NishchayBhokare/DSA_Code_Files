//Leetcode problem.

//Optimised solution.


//TC-O(2^9*K + 9) SC-O(Rcomb*K + K(Auxilary space))
class Solution {
public:

    void findCombination(int cNum,int n, int k, vector<int>&temp, vector<vector<int>>&ans){

        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }

        for(int num=cNum; num<=9; num++){ //starting from cNum instead of again checking from 1.
            //to avoid duplicate list.

            if(n-num>=0){
                temp.push_back(num);
                findCombination(num+1,n-num,k-1,temp,ans); //pass currNum+1. also decrement n and k.
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        int num=1;
        findCombination(num,n,k,temp,ans);

        return ans;
    }
};  

//Approach 2: Not optimised but somehow i solved problem. SC is much higher.//not good solution.
class Solution {
public:

    void findCombination(int n, int k, vector<int>&temp, vector<vector<int>>&ans, vector<int>&used){

        if(k==0){
            if(n==0){
                vector<int>curr = temp;

                sort(curr.begin(),curr.end());
                ans.push_back(curr);
            }
            return;
        }

        for(int num=1; num<=9; num++){

            if(n-num>=0 and used[num]==0){
                temp.push_back(num);
                used[num]=1;

                findCombination(n-num,k-1,temp,ans,used);

                used[num]=0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        vector<int>usedArr(10,0);
    
        findCombination(n,k,temp,ans,usedArr);

        set<vector<int>>st;
        for(auto arr:ans){
            st.insert(arr);
        }

        ans.clear();

        for(auto arr:st){
            ans.push_back(arr);
        }
        return ans;
    }
};
