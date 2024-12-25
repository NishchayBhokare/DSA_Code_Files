//GFG.

//Approach 1: Most optimised approach. using in place checking. TC-O(NLogn) SC-O(1)
int findPlatform(vector<int>& arr, vector<int>& dep) {

        int n=arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end()); //sort both vectors.
        
        int maxCnt = 0, cnt = 0;
        
        int i=0, j=0;//using two pointer approach will solve question.
        while(i<n){
            
            if(arr[i] <= dep[j]){ //if new train came before previous train of departure.
                cnt++; //then increment cnt of platforms
                i++; //and move to arrival time of next train.
            }
            else{ //when current train departure before new train came..then decrement cnt.
                cnt--;
                j++; //then move to departure time of next train.
            }
            
            maxCnt = max(maxCnt, cnt); //take max cnt.
        }
        
        return maxCnt;
    }


//Approach 2: Approach using extra space. TC-O(NLogn) SC-O(2N).
//very amazing approach. if we push all arrival time and departure time with addition of alphabets in additional vector of pair.
//and if we sort it. then we can observe. continueous arrival time of train will be the max answer.
//after sorting we can get like this. 900 'a' -> 910 'd' -> | 950 'a' -> 960 'a' -> 1100 'a' | -> 1200 'd' -> 1300 'd' -> 1400 'd'.
                                                            this is the max range of continues 3 arrivals 
                                                            of train so required maximum 3 platforms.
 int findPlatform(vector<int>& arr, vector<int>& dep) {

    int n=arr.size();
    
    vector<pair<int,char>>trainT;
    
    for(int i=0; i<n; i++){
        trainT.push_back({arr[i], 'a'});
        trainT.push_back({dep[i], 'd'});
    }
    
    int maxCnt = 0, cnt=0;
    
    sort(trainT.begin(), trainT.end());
    
    for(int i=0; i<trainT.size(); i++){
        
        if(trainT[i].second == 'a'){ //if arrival time and then increment cnt.
            cnt++;
        }
        else cnt--;
        
        maxCnt = max(cnt, maxCnt);
    }
    
    
    return maxCnt;
}