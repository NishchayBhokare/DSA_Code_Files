// Example for return Nth fibonacii number.

#include <bits/stdc++.h>
using namespace std;

long long int nthFibonacci(long long int n){
        // code here
       if(n==1 || n==2) return 1;
       
       long long int a=1, b=1, nthSum=0; // first initialize a and b with 1. in this example we are not considering 0.
       for(long long int i=3; i<=n; i++){ // loop from 3 to n i.e for n=4 loop will execute 2 times.
           nthSum = (a+b) % 1000000007; // adding previous two numbers a and b. (taking modulus is very important otherwise answer will go beyound range.)
           a=b; // now updating a to b.
           b=nthSum; // and b to nextNumber i.e updating to sum of a & b
       }
       return nthSum ; //finally returning ans.
    }

