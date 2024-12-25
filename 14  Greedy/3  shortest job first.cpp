//GFG.
//Shortest job first.

//Logic is we have to give summation of all waiting for processs.
//so for eg. n is 5 and these are the process [4,3,7,1,2]. after sorting [1,2,3,4,7]
//so total weighting time will be 20. so 20/5 equals to 4.
//how 20? for first processs waiting time will be 0 and when we add execuation time to it. then that weighting time+execuation time will be waiting time for next process.
//  a[0]  a[1]  a[2]  a[3] 
//0  -> 1  -> 3  -> 6  -> 10 //these are the waiting time for every process.
//p1 -> p2 -> p3 -> p4 -> p5
long long solve(vector<int>& bt) {
    
    int n=bt.size();
    sort(bt.begin(), bt.end()); //sort the array so that we can take minimum execution time process first.
    
    long long wt=0, totalWt=0;
    
    for(int i=1; i<n; i++){ //starting from 1 because for first prcess..waiting time will be 0.
        
        wt += bt[i-1]; //get waiting time for current process by adding execution time of last process.
        totalWt += wt; //also calculate total weighting time. as we have to return answer.
    }
    
    
    return (totalWt/n);
}
