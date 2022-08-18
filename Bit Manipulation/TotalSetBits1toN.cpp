//Example for counting total set bits from 1 to n.

#include<bits/stdc++.h>
using namespace std;

  //  Approach 1: Not much efficient approach. looping from 1 to n and taking theri set bits.
    int countSetBits(int n) //taking bits of every number from 1 to n. TC: O(n * no. of setbits) and SC is constant.
    //more efficient than nlog(n).
    {
        // Your logic here
        int count=0;
        for(int i=1; i<=n; i++){ //looping till 1 to n.
            int j=i; //storing current position of i to j. so that we can get all set bits of j.
            while(j > 0){ //looping till j not get 0. d
                count++; //incrementing count. cause we will enter in loop, only if j contains set bits.
                j= j & (j-1); //taking and of j & j-1. Explain this analogy in previous problem.
            }
        }
        return count;
    }
    
    
    // Approach 2: Most. Efficient approach, insetead of recursion use while loop. TC: O(logn) SC is constant.
     int countSetBits(int n){
         int TotalBits=0;
         while(n !=0){
             int x = floor(log2(n)); //(This is shortcut instead of writing funciton for nearest 2 pow x)we will get max power of 2. just before n. in this case max power of 2 is 8. cause n=11 and next pow is 16 which is greater than n.
             int bits1to2x_1 = pow(2,x-1) * x; //total set bits from 1 to pow of x-1. i.e for x=3 and n=11 it will be 1 to 7.
             int msb2xton= n - (1 << x) + 1; // ""i.e n - pow(2,x) +1""; //This is total count of most signifcant bits from x to n. i.e in this example, from 8 to 11. total 4 most significant bits.          
             TotalBits += msb2xton + bits1to2x_1; //adding 1 to 2x-1 bits and x to n bits in totalBits.
             n = n - pow(2,x); //updating n to 3 after 1st iteration //after taking most significant bit we reduce those no. of 8 to 11  as 0 to 3. so we will update n=3 after 1 st iteration in this example.
         }
         return TotalBits; //returning total bits.
     }
    
    
   // Approach 3: using recursive function.  TC: logn SC: logn
        int maxPowOf2(int n){
          int x=0; 
          while( pow(2,x) <= n){ //looping till pow of 2 is less than or equal to n. 
              x++; //incrementing x.
          }
          return x-1; //returning x-1 cause we will exit from loop when pow is greater than n so that time value of x is unnecessary incremented by 1. so to reduce this we return x-1.
          //for eg. when n=11 and x becomes 4 so pow is get 16 which is greater, then we will exit from loop and still value of x is 4 but we want 3. so to return that 3, we did x-1.
      }
       
      int countSetBits(int n){
          if(n==0) return 0; //when at the end of recursive call. when restN i.e n is equal to 0. 
           
          int x= maxPowOf2(n); //we will get max power of 2. just before n. in this case max power of 2 is 8. cause n=11 and next pow is 16 which is greater than n.
          int bits1to2x_1 = pow(2,x-1) * x; //total set bits from 1 to pow of x-1. i.e for x=3 and n=11 it will be 1 to 7.
          int msb2xton = n - pow(2,x) + 1; //This is total count of most signifcant bits from x to n. i.e in this example, from 8 to 11. total 4 most significant bits.           
          int restN= n - pow(2,x); //after taking most significant bit we reduce thos no. of 8 to 11  as 0 to 3. cause we collect already most significant bits. So we will again call this function for rest of elements which work as n=3 in this example.
           
          int ans = bits1to2x_1 + msb2xton + countSetBits(restN); //adding sum of bits of 1 to 2x-1  + x to n bits + rest elements bits, by doing recursive call we will get this.
           
          return ans; // finally return ans.
      }