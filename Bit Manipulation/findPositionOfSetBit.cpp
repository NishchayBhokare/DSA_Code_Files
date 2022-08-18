// Example for find position of set bit.

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Most. Efficient approach using log with base 2. TC: O(logn) SC is constant.
 int findPosition(int n) {
         if(n==0) return -1; //if n is 0, then there will be zero set bits so return -1.
        if((n & (n-1)) != 0) return -1;  //if no. is not in the power of 2, that means it has more than 1 set bits.
        int pos=log2(n); //log2(n) will return pow of 2, which will always nearest or equal to n.
        //In this example, at this point n will be in power of 2, so log2(n) will always return pow of 2 which has value equal to n. i.e if n=16 then log2(n) is 4. so we'll return pos+1 cause we are start counting from 1  not from 0. so final ans will be 5. cause set bit 1 is present at fifth pos. starting from LSB(counting starts from 1).
        //And you can observe element which is in pow. of 2, always have only one set bit.
        return pos+1;
    }


// Approach 2: Using right shifting till n!=0 and incrementing count. TC: O(logn) SC is constant.
int findPosition(int n) {
        // code here
         if(n==0) return -1; //if n is 0, then there will be zero set bits so return -1.
        
        if((n & (n-1)) != 0) return -1; //if no. is not in the power of 2, that means it has more than 1 set bits.
        
        int position=0; //Initializing count to 0.
        while(n!=0){ //looping till n not get 0.
            // n=n>>1; //doing right shift i.e in other word dividing the number by 2.
            n/=2; //any of this 2 statement write one.
            
            position++; //incrementing count.
        }
        return position; 
    }
    
    
// Approach 3: Using left shifting till n!=x and incrementing count. TC: O(logn) SC is constant.
    int findPosition(int n) {
        if(n==0) return -1; //if n is 0, then there will be zero set bits so return -1.
        if((n & (n-1)) != 0) return -1; //if no. is not in the power of 2, that means it has more than 1 set bits.
        int count=1,x=1; //creating variable x=1, which will be updated in loop.
        while(n != x){ //looping till x != n and incrementing count. so when x == n that means we reach to the pos. of 1. i.e x becomes equal to n. so return count or pos.
            x = x<<1; //doing left shift operation.
            count++;
        }
        return count;
    }