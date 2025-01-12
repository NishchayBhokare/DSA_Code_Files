//Find median in a stream.
//Coding ninja, GFG.

//Approach: My approach.
priority_queue<double>maxi;
priority_queue<double,vector<double>, greater<double>>mini;

void insertHeap(int &x)
{
	
	if(maxi.size()==mini.size()){
		if(!mini.empty() && x >= mini.top()){
			mini.push(x);
		}
		else
			maxi.push(x);
	}
	else if(mini.size() > maxi.size()){
		if(x >= mini.top()){
			maxi.push(mini.top());
			mini.pop();
			mini.push(x);
		}
		else
			maxi.push(x);
	}
	else{
		
		if(x <= maxi.top()){
			mini.push(maxi.top());
			maxi.pop();
			maxi.push(x);
		}
			else{
			mini.push(x);
		}
		
	}
}


//Function to return Median.
double getMedian()
{
	
	if(maxi.size() > mini.size()){
		return maxi.top();
	}
	else if(mini.size()>maxi.size())
		return mini.top();
	
	else return ((maxi.top()+mini.top())/2.0);
}

//Approach 1: Optimised Approach gfg. Tc-O(Nlogn) SC-O(N)
class Solution
{
    public:
    //Function to insert heap.
    double median = 0;
    int element;
    priority_queue<int> maxHeap;
	priority_queue< int,vector<int>, greater<int> > minHeap;
	
    void insertHeap(int &x)
    {
        element = x;
		getMedian();
    }
    

    //Function to return Median.
	double getMedian(){

		switch( signum(maxHeap.size(),minHeap.size()) ){
			case 0: //even case
					if(element > median){
						minHeap.push(element);
						median = minHeap.top();
					}
					else{
						maxHeap.push(element);
						median = maxHeap.top();
					}
					break;

			case 1: //odd case -> size of max Heap greater than min heap.
					if(element > median){
						minHeap.push(element);
						median = (maxHeap.top() + minHeap.top())/2;
					}
					else{
						minHeap.push(maxHeap.top());
						maxHeap.pop();

						maxHeap.push(element);
						median = (maxHeap.top()+minHeap.top())/2;
					}
					break;

			case -1: //odd case ->size of min heap greter than max heap.
					if(element > median){
						maxHeap.push(minHeap.top());
						minHeap.pop();

						minHeap.push(element);
						median = (maxHeap.top()+minHeap.top())/2;
					}
					else{
						maxHeap.push(element);
						median = (maxHeap.top()+minHeap.top())/2;
					}	
					break;
		}
		return median;
	}

	int signum(int sizeOfMaxHeap, int sizeOfMinHeap)
	{
		if(sizeOfMaxHeap == sizeOfMinHeap) return 0;
		
		if(sizeOfMaxHeap > sizeOfMinHeap) return 1;
		else return -1;
	}
};




//Approach 2: Using sorting. TC-O(N2) SC-O(1)
vector<int> temp;
void insertHeap(int &X)
{
	temp.push_back(X);
	sort(temp.begin(),temp.end());
	getMedian();
}

//Function to return Median.
double getMedian()
{
	int start = 0, end = temp.size()-1;
	int middle = (start+end)/2;

	if(temp.size() & 1){
		//odd case
		return temp[middle];
	}
	
	else{
		//even case
		double midSum = temp[middle] + temp[middle+1];
		return (midSum/2);
	}
}


//From Coding ninja
//Approach 1: Optimised Approach TC-O(nlogn) SC-O(n)
//Using min and max heap
int signum(int sizeOfMaxHeap, int sizeOfMinHeap)
{
	if(sizeOfMaxHeap == sizeOfMinHeap) return 0; //if size of both priority queue is equal then return 0
	
	if(sizeOfMaxHeap > sizeOfMinHeap) return 1; //if size of max heap greater than min heap return 1.
	else return -1; //else if min heap size greater than max heap size then return -1.
}

void getMedian(int element, int &median,
priority_queue<int,vector<int>, greater<int> > &minHeap,
priority_queue<int> &maxHeap){

	switch( signum(maxHeap.size(),minHeap.size()) ){
		case 0: //even case -> when both priority queue equals
				if(element > median){ //if element greater than median then push into min heap. and median will be top of min heap
					minHeap.push(element);
					median = minHeap.top();
				}
				else{ 
					maxHeap.push(element);
					median = maxHeap.top();
				}
				break;

		case 1: //odd case -> size of max Heap greater than min heap.
				if(element > median){ //suppose size of maxheap is n and min heap is n-1. so push into min heap. and size will be n and n so take average of min and max top element divide by 2
					minHeap.push(element);
					median = (maxHeap.top() + minHeap.top())/2;
				}
				else{
					minHeap.push(maxHeap.top()); //at most 1 size difference will be acceptable so before pushing into max heap, push maxheap top to min heap.
					maxHeap.pop(); //pop out max heap

					maxHeap.push(element); //then push element into max heap
					median = (maxHeap.top()+minHeap.top())/2;
				}
				break;

		case -1: //odd case ->size of min heap greter than max heap.
		//similarly for case of min heap when min heap size is n and max heap size is n-1.
				if(element > median){
					maxHeap.push(minHeap.top());
					minHeap.pop();

					minHeap.push(element);
					median = (maxHeap.top()+minHeap.top())/2;
				}
				else{
					maxHeap.push(element);
					median = (maxHeap.top()+minHeap.top())/2;
				}	
				break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
//left of median will be max heap and right of median will be min heap.
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue< int,vector<int>, greater<int> > minHeap;
	
	int median = 0; //initializing median to 0
	for(int i=0; i<n; i++){ //looping over given array
		int element = arr[i]; //getting current index element
		getMedian(element,median,minHeap,maxHeap); //getting median for currnet element.
		ans.push_back(median); //puhsing median to ans vector
	}

	return ans;
}


//Approach 2: Using sorting. TC-O(N2) SC-O(1)
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> ans;
	for(int i=0; i<n; i++){
		
		sort(arr.begin(),arr.begin()+i+1); //first sort current stream in array. 
		int start = 0, end = i; //point start to 0 and end to current index
		int middle = (start+end)/2; //get middle index

		if((i+1) & 1){ //if size of current stream of array is odd
			//odd case
			ans.push_back(arr[middle]); //then simply push middle element into the answer vector.
		}
		else{ //if size is even
			//even case
			int midSum = arr[middle] + arr[middle+1];
			ans.push_back(midSum/2); //then take two middle element sum divide by 2 and push into the answer vector.
		}

	}

	return ans; //return ans
}


//Approach 3: Using extra space for temp vector. TC-O(n2) SC-O(N)
//Instead sorting in given vector.
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	vector<int> temp;
	for(int i=0; i<n; i++){
		temp.push_back(arr[i]);
		sort(temp.begin(),temp.end());

		int start = 0, end = temp.size()-1;
		int middle = (start+end)/2;
		if(temp.size() & 1){
			//odd case
			ans.push_back(temp[middle]);
		}
		else{
			//even case
			int midSum = temp[middle] + temp[middle+1];
			ans.push_back(midSum/2);
		}
	}
	return ans;
}