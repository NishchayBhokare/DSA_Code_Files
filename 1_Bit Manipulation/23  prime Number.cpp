//GFG.

//Approach 1: Most optimised Approach. TC-O(sqrt(n)) SC-O(1)
// We can optimise the algorithm by only iterating up to the square root of n when checking for factors. 
// This is because if n has a factor greater than its square root, it must also have a factor smaller than its square root.
bool isPrime(int n) {
    
    for(int i=2; i<=sqrt(n); i++){
        
        if(n%i == 0) return false;
    }
    return true;
}


//Approach 2: Looping till n. TC-O(N) SC-O(1)
bool isPrime(int n) {
    
    for(int i=2; i<n; i++){
        
        if(n%i == 0) return false;
    }
    return true;
}
    
    