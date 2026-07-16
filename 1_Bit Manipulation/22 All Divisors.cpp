//GFG.
//Print all divisors of number.

#include<bits/stdc++.h>
using namespace std;

//Approach 1: TC-O(sqrt(N)) SC-O(N)
//Logic is if suppose number n is 20 and one divisor is 20%5 == 0 so here 5 is divisor. but if you observe
//here quotient will be 4. i.e 5*4 = 20. so second divisor can be 4. i.e 4*5=20.
//that's why instead of looping till n. we will loop till sqrt of n.
void print_divisors(int n) {
        
    vector<int>ans(n+1,0); //but we want divisor in sorted order. so we need to store it in very well order.
    //create array of size n+1. why n+1 to store nth number as divisor of n.
    
    // for(int i=1; i<=sqrt(n); i++)
    // or do like this too.
    for(int i=1; i*i<=n; i++){
        
        if(n%i == 0){
            //first divisor
            ans[i]=i; //store ith divisor on ith index.
            
            //second divisor is
            if(n/i != i)
                ans[n/i]=(n/i); //store second divisor on their index.
        }
        
    }
    
    for(auto i:ans){
        if(i != 0)
            cout<<i<<" ";
    }
}

//Approach 2. TC-O(logn) SC - O(N)
 // Function to get all divisors
    vector<int> getDivisors(int N) {
        // Create a vector to store divisors
        vector<int> res;

        // Loop from 1 to square root of N
        for (int i = 1; i * i <= N; i++) {
            // Check if i divides N
            if (N % i == 0) {
                // Add i to the result
                res.push_back(i);

                // If N / i is different from i, add N / i too
                if (i != N / i) {
                    res.push_back(N / i);
                }
            }
        }

        // Return the list of divisors
        return res;
    }

//Approach 3: TC-O(N) SC-O(1)
void print_divisors(int n) {
    
    for(int i=1; i<=n; i++){
        
        if(n%i == 0)
            cout<<i<<" ";
    }
}