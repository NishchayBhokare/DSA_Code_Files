//Example to calculate total no. of prime numbers.
//on leetcode
#include<iostream>
#include<vector>
using namespace std;

//Approach 1: Most Efficient Algo - Sieve of Eratoshthenes. TC- O(n*log(logn)) SC-O(n).
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

//Approach 2: Using brute force solution. TC- O(n2) SC-O(1).
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