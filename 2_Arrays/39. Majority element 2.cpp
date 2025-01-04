//GFG.

//Approach 1: Most optimised Approach. TC-O(N) SC-O(1)
//As we know at max maximum two possible answer can be found for array. so we will use two variables.
//cnt1, elem1 and cnt2 elem2.
//using two varaibles. we can solve this moores algorithm question 2.
vector<int> findMajority(vector<int>& arr) {
    vector<int>ans;
    
    int n=arr.size(), cnt1=0, cnt2=0, elem1=INT_MAX, elem2=INT_MAX;
    
    for(int i=0; i<n; i++){
        
        if(cnt1 == 0 && arr[i] != elem2){ //if count one is zero and current element is not equal to element 2.
        //becuase if it's already equals to elem2 then no need to consider for element 1.
            
            elem1 = arr[i];
            cnt1 = 1;
        }
        
        else if(cnt2 ==0 && arr[i] != elem1){ //similarly for cnt2.
            
            elem2 = arr[i];
            cnt2 = 1;
        }
        
        else if(elem1 == arr[i]) //if current element is equals to ith element. then increment cnt1.
            cnt1++;
        
        else if(elem2 == arr[i]) //for elem2 increment cnt2.
            cnt2++;
        
        else{ //else decrement both.
            cnt1--;
            cnt2--;
        }
    }
    
    int freq1=0, freq2=0;
    for(auto i:arr){ //also cross check..whether these eleemtns are present n/3 times in array or not.
        
        if(i == elem1)
            freq1++;
        
        else if(i == elem2)
            freq2++;
    }
    
    if(freq1 > n/3) //if yes then only push in ans.
        ans.push_back(elem1);
    
    if(freq2 > n/3)
        ans.push_back(elem2);
        
    sort(ans.begin(), ans.end());
    
    return ans;
}

//Approach 2: Approach using map. TC-O(N) SC-O(N)
vector<int> findMajority(vector<int>& arr) {
    int n=arr.size();
    unordered_map<int,int>ump;
    
    vector<int>ans;
    
    for(auto i:arr){
        ump[i]++;
        
        if(ump[i] > n/3){
            
            if(ans.size() > 0 && i == ans.back()) continue;
            ans.push_back(i);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
    
    