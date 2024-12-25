//GFG.

//simple approach sort the array and find min and max.
vector<int> candyStore(int candies[], int N, int K)
{
    
    sort(candies, candies+N);
    
    int minCost = 0, i=0, j=N-1;
    
    while(i<=j){
        
        minCost += candies[i];
        i++;
        
        j=j-K;
        
    }
    
    int maxCost = 0;
    i=N-1, j=0;
    while(i>=j){
        
        maxCost += candies[i];
        i--;
        
        j=j+K;
        
    }
    return {minCost, maxCost};
}