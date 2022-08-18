//Example for reverse bits of an unsigned integer number.

#include<bits/stdc++.h>
using namespace std;


//Solution for problem on gfg. no leading zero's are considering in this example at gfg platform.
 unsigned int reverseBits(unsigned int n)
    {
        unsigned int ans=0; //creating ans variable.
        while(n != 0){  //TC - O(number of bits in the binary representation of N) SC is constant.
            // ans = (ans << 1) | (n & 1); // This is shortcut for below 2 lines.
            int bit= n & 1; //taking one by one right most bit from n unsigned integer.
            ans= ans << 1  | bit; //first doing left shift for 1 time then doing or with bit so that if bit is 1 then added bit in ans will be 1, otherwise 0.
            n=n >> 1; //shifting n to its right.
            // bit 000000....01
            //                |
            // ans 000000...100 //(did left shift for one time) suppose ans was 2  (000..10) before left shift 
            //                =
            // ans 000000...101
                              
        }
        return ans; //and yaa that's it returning ans.
    }



//Solution for problem on leetcode.leading zero's are considering in this example at leetcode platform.
//Approach 1:- looping from 31 to 0 and storing it's power in ans.
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0; 
       for(int i=31; i>=0; i--){ //looping from 31 to 0 i.e 32 times.
           int bit=n & 1;
           if(bit==1) ans=pow(2,i) + ans; //if bit is 1 then taking power of that bit index. (notice that i starts from 31. so it will get automatically reverse.)
           n=n>>1; 
       }
        return ans; // returning ans.
    }
    

//Approach 2:- By doing left shift 31-i times.
     uint32_t reverseBits(uint32_t n) {
     uint32_t ans=0,i=0;
         while(n!=0){
             int bit=(n & 1); //taking one by one right most bit from n unsigned integer.
             int revBit=bit << (31-i); //doing 31 - i so that we can reverse it and can start from front.
             ans=ans | revBit; //and now doing or so that if 1 is present in revBit then we will simply get that 1.
             n=n>>1;
             i++;
         }
        //  revBit 01000000000...0
        //          |
        //  ans    10000000000...0
        //          =
        //  ans=   11000000000...0
         return ans;
    }
