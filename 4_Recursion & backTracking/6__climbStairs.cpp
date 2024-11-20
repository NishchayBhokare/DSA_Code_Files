//count number of steps to reach nth position - climb stairs by either 1 or 2 steps.

//Approach :- Using recursion.
//This problem gives TLE-time limit exceeded problem but it is fine.
 int climbStairs(int n) {
     
        if(n==1) return 1; //if n is 1 then only one way to rech 1 no. of stair
        if(n==0) return 1; //if n is 0 that means stair on which we are standing, so only one way to reach where we are standing.
        
        //Recursive relation by decrementing n values by 1 and by 2. and adding there value and finally returning ans
        int ans = climbStairs(n-1) + climbStairs(n-2); 
        return ans;
    }

//GFG version need DP so solve it once get knowledge about dp.