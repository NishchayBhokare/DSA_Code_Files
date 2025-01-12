//coding ninja 

//Tc-O(N) SC-O(N)
//similar approach like 8th example.
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	long long sum = 0;
	deque<int>maxi;
	deque<int>mini;

	for(int i = 0; i<k; i++){  //processing first k elements.
		while(!maxi.empty() && nums[i] >= nums[maxi.back()])
			maxi.pop_back();
		
		while(!mini.empty() && nums[i] <= nums[mini.back()])
			mini.pop_back();
		
		maxi.push_back(i);
		mini.push_back(i);
	}

	sum += nums[maxi.front()] + nums[mini.front()]; //adding sum.
	for(int i = k; i<n; i++){

		//removal
		if(i - maxi.front() >= k) maxi.pop_front(); //if q.front is out of range of new window..then pop it.
		
		if(i - mini.front() >= k) mini.pop_front();

		//addition.
		while(!maxi.empty() && nums[i] >= nums[maxi.back()]) //till current element greater than maxi.back() element...then start popping.
			maxi.pop_back();
		
		while(!mini.empty() && nums[i] <= nums[mini.back()]) //simialrly opposite of above.
			mini.pop_back();
		
		maxi.push_back(i); //now after processing...pushes eleemnt index in maxi qeueu and mini queue.
		mini.push_back(i);

		sum+= nums[maxi.front()] + nums[mini.front()]; //add sum.
	}

	return sum; //return sum...final sum of all subarrays.
}


//Approach 2: We can write all these in single loop too.
long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
	deque<long long>mini;
	deque<long long>maxi;

	long long sum=0;

	for(int i=0; i<n; i++){

		if(!mini.empty() && i-mini.front() >= k) mini.pop_front();
		if(!maxi.empty() && i-maxi.front() >= k) maxi.pop_front();

		while(!mini.empty() && arr[mini.back()]>=arr[i])
			mini.pop_back();

		while(!maxi.empty() && arr[maxi.back()] <= arr[i])
			maxi.pop_back();

		mini.push_back(i);
		maxi.push_back(i);

		if(i>=k-1) sum+=arr[mini.front()] + arr[maxi.front()];
	}

	return sum;
}