//GFG.
//Fractional Knapsack.

//TC-O(valWt)log(valWt) SC-O(valWt).
//Approach: merge both the arrays and sort array as per per weight value.
//then just loop over the array. and do process.
bool static cmp(pair<int,int>&a, pair<int,int>&b){

    double x = (a.first/(double)a.second);
    double y = (b.first/(double)b.second);
    return x>y; //sort according per one weight maximum value.
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    
    vector<pair<int,int>>valWt;
    int n=val.size();
    
    for(int i=0; i<n; i++){
        
        valWt.push_back({val[i], wt[i]});
    }
    
    sort(valWt.begin(), valWt.end(), cmp); 
    
    
    double ans = 0;
    
    //first is value and second is weight.
    for(int i=0; i<n; i++){
        
        if(capacity >= valWt[i].second){ //if capacity is greater than required weight then take whole value.
            
            capacity -= valWt[i].second;
            ans += valWt[i].first;
        }
        else{ //else take fraction of it.
            
            ans += (valWt[i].first / (double)valWt[i].second) * capacity;
            break;
        }
    }
    
    return ans;
}