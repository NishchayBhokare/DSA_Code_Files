//Aggressive cow problem on gfg and coding ninja

//Efficient approach.
//logic is..we have to find maximum distance for which we can set cows from all the combination.
//so answer will be between 0 to max element of array..because we have to set element between array elements i.e stall number so.
//now by taking mid, we're checking whether on this mid or mid greater than distance...we can set 
//cow or not..here greater than mid because we have to find..maximum distance from all the combination to set cows.
bool isPossible(int n, int k, vector<int> &stalls, int mid){
        int cowCount = 1; //now initially cow count will be 1.
        int lastPos = stalls[0];  //first cow..setted at 0th position.
        for(int i = 0; i<n; i++){
            if(stalls[i]-lastPos >= mid){ //now checking can we set cow..on ith position.
            //i.e if ith posiition - last cow position is greater than mid that means we can set cow on this position.
                cowCount++; //so increment cow;
                if(cowCount == k) return true; //if at any point cow count equals to k..that means we're able to set all cows.
                //so return true;
                lastPos = stalls[i]; //else...assign cow and current ith stall.
            }
        }
        return false;// if we reach to this...that means cowcount not equal to k.
        //i.e cowcount is less than k..because mid value is maximum..so look for minimum value..that's why
        //return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end()); //first sort vector
        int maxi = stalls[n-1];  //maximum element is last elemnet
        int low = 0, high = maxi, ans = -1; //high equals to max elemnet
        while(low <= high){
            int mid = low+(high - low)/2; //calculating mid
            if(isPossible(n,k,stalls,mid)){  //checking this mid can be the answer or not.
                ans = mid; //if true..then this mid is possible answer...so store it..and check for maximum possible answer.
                low = mid+1; //so move to right part of the stalls array.
            }
            else{
                high = mid-1; //if false..that means..we're not able to set..k cows..we setted less than k kows..
                //so for that..go to left part..for minimum distance.
            }
        }
        
        return ans;
    }