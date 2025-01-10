//Leetcode & GFG..

//Approach 1: TC-O(N+N i.e 2N), SC-O(k) by sliding window approach with one variable. 
vector<int> maxSlidingWindow(vector<int>& arr, int k) {

   vector<int>ans; 
   deque<int>nextMax; //using deque so that..we need to pop element from front also and back also.
    
   int n=arr.size();
   for(int i=0; i<n; i++){

        if(!nextMax.empty() && nextMax.front() <= (i-k)) //if max element goes out of bound. then pop that front max.
            nextMax.pop_front();

        while(!nextMax.empty() && arr[i] >= arr[nextMax.back()]) //if current element is greater than nextmax's back element then pop back that back element.
            nextMax.pop_back();
        
        nextMax.push_back(i); //push current element in deque

        if(i>=k-1) //adding this condition to esacpe pushing elements for less that first k size window.
            ans.push_back(arr[nextMax.front()]);
   }

   return ans;
}


//Approach 2:TC-O(N+N i.e 2N), SC-O(k).  Using left and right pointer.
vector<int> maxSlidingWindow(vector<int>& arr, int k) {

    vector<int>ans; 
    deque<int>nextMax;

    //process first k elements.
    for(int i=0; i<k; i++){

        while(!nextMax.empty() && arr[i] >= arr[nextMax.back()])
            nextMax.pop_back();
        
        nextMax.push_back(i);
    }

    ans.push_back(arr[nextMax.front()]); //once first k processed. push nextMax's front element
    //in answer.
    
    int left=1, right=k, n=arr.size();
    while(right < n){

        if(nextMax.front() < left) //if max element is out of k size window. then pop it.
            nextMax.pop_front();

        while(!nextMax.empty() && arr[right] >= arr[nextMax.back()]) //popback till current element is greater than nextmax's back.
            nextMax.pop_back();
        
        nextMax.push_back(right); //then push this current right index into the nextmax.

        ans.push_back(arr[nextMax.front()]); //store asnwer for current window. in ans.

        left++; right++; //move to next window.
    }

    return ans;
}


//Approach 3: Brute force approach. TC-O((n-k) * k) i.e O(N*K)
vector<int> maxSlidingWindow(vector<int>& arr, int k) {

    vector<int>ans; 
    int n=arr.size();
    for(int i=0; i<=(n-k); i++){ //loop till last window.
        int maxi=INT_MIN;

        for(int j=i; j<(i+k); j++) //check. i to i+k size window. and store maximum
            maxi = max(maxi, arr[j]);
        
        ans.push_back(maxi); //push that maximum.
    }

    return ans; //return answer.
}