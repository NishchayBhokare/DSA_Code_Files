//GFG.
// Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term

 int sumOfSeries(int n) {
    
    if(n==1)
        return n;
    
    return pow(n,3) + sumOfSeries(n-1);
}