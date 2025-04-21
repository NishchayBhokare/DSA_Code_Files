//GFG.
//Majority element.

//return element who occurs more than n/2 times.
//Approach 1: Most optimised Approach. Moore’s Voting Algorithm TC-O(N) SC-O(1).
//In short logic is..if any number is majority element. then it will not get cancel out with other element.
//because it will present in array more than n/2 times. so at least one time thier frequency will remain.

//but if..we're getting frequency greater than 1 for any number. Still, we need to croos check at the end..whther that
//number is present more than n/2 times or not.
int majorityElement(vector<int>& nums) {
    int n=nums.size();

    int elem=-1;
    int cnt=0; //using two variables.

    for(int i=0; i<n; i++){

        if(cnt==0){ //if cnt is zero. then assign new element to elem.
            elem = nums[i];
            cnt=1; //and initialise cnt to 1.
        }
        
        else if(nums[i] == elem) //if current elemnt is equal to elem.
            cnt++; //then increment their frequency.
        else 
            cnt--; //else decrement their frequency.
    }

    int freq=0;
    for(auto i:nums){ //cross checking their frequency.
        if(i == elem)
            freq++;
    }

    if(freq > n/2) //if here also greater than n/2 then return elem.
        return elem;
     
    return -1; //else -1.
}

//Approach 2: Using Map. TC-O(N) SC-O(N)
int majorityElement(vector<int>& nums) {
    
    int n=nums.size();
    int freq = n/2;

    unordered_map<int,int>ump;
    for(int i=0; i<n; i++){

        ump[nums[i]]++;

        if(ump[nums[i]] > freq)
            return nums[i];
    }

    return -1;
}