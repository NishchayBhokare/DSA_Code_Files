//Code studio.

//Approach 1: Most optimised Approach. TC-O(NLogn) SC-O(1).
//binary search on answer.
bool isPossible(long double diff, vector<int> &stations, int &k){

    int n=stations.size(), gasStationCnt = 0;

    for(int i=1; i<n; i++){

        //we can do like this too. if divison is 2.14 then it will convert into 3 and if its' 2 then it reaming 2.
        //so as we know for exact division we need to do -1. so as we have taken ceil then no need to check if condition.
        //becasue 2.14 will convert into 3 and by substracting it by 1. it will convert to 2. 
        int gasStation = ceil((stations[i] - stations[i-1])/diff) - 1; 

        //or we can do like this too.
        // int gasStation = (stations[i] - stations[i-1])/diff; //by dividing diff with difference
            //between two stations. then we will get number of stationscnt to maintain
            //differences among i-1 to i which equals to diff. for eg. 0.5 

        // if((stations[i] - stations[i-1]) == (diff * gasStation)){ 
        //     gasStation--;
        // }
        
        gasStationCnt +=gasStation;
        
        if(gasStationCnt > k) //if gas station count exceeds. return false;
            return false;
    }

    return true;
}

double minimiseMaxDistance(vector<int> &stations, int k){

    int n=stations.size();
    
    double long maxDiff = 0;

    for(int i=1; i<n; i++){
        maxDiff = max(maxDiff, (long double)stations[i]-stations[i-1]);
    }

    long double low=0, high=maxDiff;

    long double diff = 1e-6; //it represens how many decimal numbers. 10^ -6 = 0.000001

    while(high - low > diff){ //looping till differnece between high and low is greater than 10^-6 decimal places.

        long double mid = (low+high)/(2.0); //take mid diff.

        if(isPossible(mid, stations, k)){ //check whether this diff possible or not. that means. by using this diff. can we place
        //k gas stations by maintaing mid diff or not.

            high = mid; //if possbile then loop to get min difference.
        }
        else{
            low = mid; //if not possible then check for higher diff. so make low to mid.
        }
    }
    return high; //final answer will be high.
}


// Approach 2: Using Max Heap. TC-O(Nlogn) SC-O(N-1).
//we are using max heap because we should keep gas statino between maximum distance.
//so to get max distance we're storing it into the max heap
double minimiseMaxDistance(vector<int> &stations, int k){

        int n=stations.size();
        
        vector<int>sectionLen(n-1,0); //creation of section lenght array. this array index represent number of places between i and i+1.
        priority_queue<pair<long double,int>>pq; 
        
        //push differnece between adjacent all stations in pq.
        for(int i=0; i<n-1; i++)
            pq.push({stations[i+1] - stations[i], i}); //push difference of gas station and its index. starting from 0.
            //then furhter this index will be used as section ind.
        
        
        for(int i=1; i<=k; i++){
            
            auto pr = pq.top(); //get top element.
            pq.pop();
            
            int sectionInd = pr.second; //store index which acts as section index.
            
            sectionLen[sectionInd]++; //increment sectionlen for this section index as we're going to add one more
            //gas station on this section ind. so increment by 1.
            
            long double diff = stations[sectionInd+1] - stations[sectionInd]; //now take actual differnce between i+1 and i gas station.
            
            long double updatedDiff = (long double)diff/(long double)(sectionLen[sectionInd]+1);
            //why plus 1 in division.

            //suppose stations[i] = 1 and stations[i+1] = 2. then diff will be 2-1=1.
            //now as we are going to add on gas station between them. 
            // then  diff divide by updated gastStationCnt+1 will be my new difference.
            //+1 is necessary if we not do this. then diff will remain as it is, plus 1 indicates in how many places we're dividing this diff.
            //so 1 will be divided into 2. 1 to 1.5 and 1.5 to 2. so two places.
            
            pq.push({updatedDiff, sectionInd}); //now at the end again push updateddiff with section ind.
        }

        
        return (double)pq.top().first; //at the end top element will be my answer.
}


//Approach 3: Brute force apporoach but still feels difficult than heap. TC-O(K*N + N)
     // sort(stations.begin(), stations.end());
        
        int n=stations.size();
        vector<int>sectionLen(n-1,0);
        
        for(int gasStation=1; gasStation<=k; gasStation++){
            
            int placeInd = -1;
            double maxSectionDiff=-1;
            
            for(int i=0; i<n-1; i++){ //in above solution we have eliminate this step by using max heap.
            //but here we're iteratively checking which stations have maximum difference.
                
                double diff = stations[i+1] - stations[i];
                
                double currSectionDiff = diff/(double)(sectionLen[i]+1);
                
                if(currSectionDiff > maxSectionDiff){
                    maxSectionDiff = currSectionDiff;
                    placeInd = i;
                }
            }
            
            sectionLen[placeInd]++; //place station maximum diffenrece.
        }
        
        
        double maxDiff = -1;
        for(int i=0; i<n-1; i++){ //at the end check. which stations has max diff and return that.
            
            double diff = stations[i+1] - stations[i];
                
            double currSectionDiff = diff/(double)(sectionLen[i]+1);
            
            maxDiff = max(maxDiff, currSectionDiff);
        }
        
        return maxDiff;