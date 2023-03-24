// Example for return Nth fibonacii number.

#include <bits/stdc++.h>
using namespace std;
//Approach 1: Using while Loop
//series will be  0 1 1 2 3 5 8 13 21 34
long long int nthFibonacci(long long int n){
        // code here
       if(n==1) return 0;
       if(n==2) return 1;
       
       long long int a=0, b=1, nthSum=0; // first initialize a and b with 1. in this example we are not considering 0.
       for(long long int i=3; i<=n; i++){ // loop from 3 to n i.e for n=4 loop will execute 2 times.
           nthSum = (a+b) % 1000000007; // adding previous two numbers a and b. (taking modulus is very important otherwise answer will go beyound range.)
           a=b; // now updating a to b.
           b=nthSum; // and b to nextNumber i.e updating to sum of a & b
       }
       return nthSum ; //finally returning ans.
    }


//Approach 2:Using recursion. Leetcode example
 int fib(int n) {
    //Below are base cases
      if( n == 1) return 0;
      if( n == 2) return 1;
      
      int ans = fib(n-1) + fib(n-2); //taking addition of previous two by calling it.
      return ans;
    }

