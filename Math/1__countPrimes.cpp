//Example to calculate total no. of prime numbers.
//on leetcode, GFG
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//Approach 1: Most Efficient Algo - Sieve of Eratoshthenes with sqrt function. TC- O(n*log(logn)) SC-O(n).
 int countPrimes(int n) {
        int count=0;
       vector<bool>prime(n,true);
       for(int i=2; i<sqrt(n); i++){ //becuase of sqrt function we escape from unnecessary checking. if n=10 then we will loop from 2 to 3. so no need to loop from 2 to 10.
           if(prime[i] == true){
               for(int j=2; (i*j) < n; j++){
                prime[i*j] = false;
                }
           }
       }
       for(int i=2; i<n; i++) if(prime[i]){ //now looping from 2 to less than n and incrementing count if that i index is true i.e it is prime number.
           count++;
       }
       return count;
    }

//Approach 2: Efficient Algo - Sieve of Eratoshthenes without sqrt function. TC- O(n*log(logn)) SC-O(n).
//Analogy:- Initially, Assuming all numbers are prime.
// then, if current no. is prime then increment count and also mark non prime to those numbers which came in table of current number.
 int countPrimes(int n) {   
       
        vector<bool> prime(n+1, true); //assuming all numbers as prime.
        prime[0] = prime[1] = false; //marking 0 and 1 as non prime.
        int count = 0;
        for(int i=2; i<n; i++){ //looping from 2 to less than n.
            
            if(prime[i]){ //if ith number marked as prime then increment count.
                count++;
                
                for(int j = (i * 2); j<n; j = j + i){ // now, mark as non prime to those elements which come in table of i.
                    prime[j] = false; //marking as non prime i.e false.
                }
                
            }
            
        }
      return count;   //finally return count.
    }


//Approach 3: Using brute force solution. TC- O(n2) SC-O(1).
    bool isPrime(int n){ //cehcking whether given no. is prime or not.
        for(int i=2; i<n; i++){
            if((n % i) == 0) return false;
        }
        return true;
    }
    
    int countPrimes(int n) {   
        int count = 0;
        for(int i=2; i<n; i++){ //looping from 2 to less than n.
           if(isPrime(i)) count++; //if current no. is prime then increment count.
        }
      return count;  
    }



//Gfg version 
//Approach 1: Most optimized.
 int countPrimes(int L, int R) {
        vector<bool> prime(R+1,true);
        int count=0;
        prime[0]=prime[1]=false;
        for(int i=2; i<=sqrt(R); i++){ //looping till sqrt of R.
            if(prime[i] == true){
                for(int j=i*2; j<=R; j=j+i){
                    prime[j]=false;
                }
            }
        }

        for(L; L<=R; L++) if(prime[L]) count++; //incrementing count if index from L to R marked as true i.e prime number.
      return count;
    }


//Approach 2: brute force solution.
  bool isPrime(int l){
       for(int i=2; i<l; i++){
           if(l % i == 0) return false;
       }
       return true;
   }
    int countPrimes(int l, int r) {
        // code here
        int count=0;
        if(l <= 1) l=2;
        for(l; l<=r; l++){
            if(isPrime(l)){
                count++;
            }
        }
        return count;
    }