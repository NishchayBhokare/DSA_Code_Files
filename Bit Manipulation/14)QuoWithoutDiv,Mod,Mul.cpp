// Example for Find quotient after division, without using multiplication, division and mod operator
//Gfg
#include<bits/stdc++.h>
    //Logice - suppose if a=16,b=3, 3*5=3*(2^2 + 2^0)=3*(4+1)=3*(5)=15
  // Apporach 1: Using left shifting so that iteration gets reduced. TC- O(1) SC- O(1)
     long long divide(long long dividend, long long divisor) 
    {
        int sign=1; //Initially assuming sign is +ve.
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign=-1; //if any of the condition gets  true sign will be -1.

        long long quotient=0,a=abs(dividend),b=abs(divisor); //taking absolute value cause may be dividend or divisor is in negative.so abs will remove negative sign.
        for(int i=31; i>=0; i--){ //looping from 31 to 0. cause we want max. value of 2 raise to i. so that we can reduce iteration. 
            if((b<<i) <= a){ // if (2 pow i) * b <= a . i.e by shifting b to ith times, and if resultant value is less than a that means we can substract it from dividend. 
             a = a - (b<<i); //shifting divisor ith times so that we can substract dividend from it. //dividend -= divisor * pow(2,i);
             quotient = quotient | (1<<i); // shifting ith time 1, which will work as quotient.  taking or with quotinet cause we have to also add previous quotient. quotient+=pow(2,i);
            // above statement we can write like this. quotient+= (1<<i);
            //for eg. a=15, b=3. if i=2 then we can say at 2 pow(i) i.e at i=2 least 4 times we can substract b from a on first iteration when condition ((b<<i) <= a) gets satisfied.
            }
        }
        if(sign == -1) return -quotient;
        return quotient;
    }
    
    // Apporach 2: Substracting divisor from dividend and incrementing count. TC- O(a/b) SC- O(1)
    long long divide(long long dividend, long long divisor) 
    {
        int sign=1; //Initially assuming sign is +ve.
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign=-1; //if any of the condition gets true sign will be -1.
        long long count=0; //intially count is 0.
        long long a=abs(dividend), b=abs(divisor); //taking absolute value cause may be dividend or divisor is in negative.so abs will remove negative sign.
        while(a >= b){ //looping till a >=b i.e dividend (a) is greater than or equal to divisor(b).
            count++; //incrementing count. This quotient is basically refers to how many times we can substract b from a i.e divisor from dividend. so that's why incrementing quotient varibale for every iteration.
            a = a - b; //subtracting divisor from dividend. and storing again it into dividend.
        }
        if(sign == -1) return -count; //if sign is negative then return -ve count.
      return count; //else +ve.
    }