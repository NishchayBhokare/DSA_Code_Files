//EKO-EKO
//Link -> https://www.spoj.com/problems/EKO/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool isPossible(vector<long long>v,long long n, long long m, long long mid){
	long long woodAmt = 0;
	for(int i = 0; i<n; i++){
		if(v[i] > mid){ //logic is basically doing current tree length minus mid..and then
        //adding remaing wood amount in varaible.
			woodAmt += v[i]-mid;
		
		}
	}
	if(woodAmt >= m) return true; //lastly checking if woodamount is greater than or equal to m then return true.
	return false; //if less then return false..and move to lesser mid so that we can cut more tree.
}

int main() {
	long long n,m;
	vector<long long> v;
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		long long val;
		cin>>val;
		v.push_back(val);
	}
	
	sort(v.begin(),v.end());

	long long low = 0, high = v[v.size()-1], ans = -1;
	while(low <= high){
		long long mid = low+(high - low)/2;
		if(isPossible(v,n,m,mid)){
			// cout<<mid<<endl;
			ans = mid;
			low=mid+1;
		}
		else high = mid-1;
	}
	cout<<ans;
	return 0;
}