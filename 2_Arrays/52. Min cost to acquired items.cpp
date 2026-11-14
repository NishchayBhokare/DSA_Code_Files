//Leetcode problem.
//Approach 1: Simple approach with only conditions. TC-O(N) SC-O(1)
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long totalCost = 0;

        if(cost1+cost2 <= costBoth){
            totalCost += 1LL*need1*cost1 + 1LL*need2*cost2;
        }
        else{
            
            int minNeed = min(need1, need2);
            totalCost = 1LL*minNeed * costBoth;

            need1 -=minNeed;
            need2 -=minNeed;

            if(need1>0) totalCost += 1LL*need1*min(cost1,costBoth);

            else if(need2>0) totalCost += 1LL*need2*min(cost2,costBoth);
            
        }

        return totalCost;
    }
};