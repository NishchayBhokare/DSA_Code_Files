//Leetcode Hard problem.
//TC-O(m*target*n2). n square because first for n state of color and for every position,we're traversing
//for n color. so, n2 in total.
//SC-O(m*target*n)
class Solution {
public:

    int solve(int ind, int target, int pColor, vector<int>&houses, vector<vector<int>>&cost, int &m, int &n,vector<vector<vector<int>>>&dp){
        
        if(ind<0){
            if(target == 0) return 0;
            return 1e8;
        }

        if(dp[ind][pColor][target] != -1)
            return dp[ind][pColor][target];

        int minCost = 1e8, currCost=1e8;
        if(houses[ind] != 0){

            if(houses[ind] == pColor){ //if houses are already colored
                 currCost = solve(ind-1,target,pColor,houses,cost,m,n,dp);
            }
            else{
               if(target > 0) currCost = solve(ind-1,target-1,houses[ind],houses,cost,m,n,dp);
            }

            minCost = min(minCost,currCost);
        }
        else{ //houses are yet to colored.

            for(int color=1; color<=n; color++){

                if(color == pColor){
                    currCost = cost[ind][color-1] + solve(ind-1,target,pColor,houses,cost,m,n,dp);
                }
                else{
                    if(target > 0 )currCost = cost[ind][color-1] + solve(ind-1,target-1,color,houses,cost,m,n,dp);
                }

                minCost = min(minCost,currCost);
            }
        }

        return  dp[ind][pColor][target]=minCost;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        

        int ind=m-1,pColor=0;

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n+1,vector<int>(target+1,-1)));

        int ans = solve(ind,target,pColor,houses,cost,m,n,dp);
        if(ans==1e8) return -1;

        return ans;
    }
};