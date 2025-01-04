//Leetcode.
//Coco eating banana. (Binary search on answer)


//Approach 1: TC-O(Nlog(max Element)) SC-O(1)
bool isPossible(int &k, int &h, int &n, vector<int>&piles){
    int currHr=0; //curernt hr.

    for(int i=0; i<n; i++){
        currHr += ceil((double)piles[i]/(double)k); //we can do like this too. taking total hours required to eat ith banana.
        //by directly using ceil.

        //or this.
        // currHr += piles[i]/k;
        // if(piles[i]%k != 0){
        //     currHr += 1;
        // }

        if(currHr > h) return false; //if current hours exceeds. then return false; not possible.

    }

    return true; //if reached till here then return true.
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();


    int maxRange=0;
    for(auto i:piles)
        maxRange = max(maxRange,i);

    int low = 1, high= maxRange, ans=-1; //calculate range. range will be from 1 to max element from array.
    
    while(low <= high){
        int k = low+(high-low)/2;

        if(isPossible(k,h,n,piles)){ //if for current k it is possible then loop for lower value of k.
            ans=k;
            high=k-1; //go to left part.
        }
        else{
            low=k+1; //if not possible then to increase value of k(mid) go to right part.
        }

    }
    
    return ans; //return answer.
}


//Approach 2: Linear way. TC-O(N*(maxelement)) SC-O(1)
int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();

    int maxVal=INT_MIN;
    for(auto i:piles)
        maxVal = max(maxVal,i);

    for(int k=1; k<=maxVal; k++){

        if(isPossible(k,h,n,piles)){ //this function is written on top. one time.
            return k;
        }
    }

    return -1;
}