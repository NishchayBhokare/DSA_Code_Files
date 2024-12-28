// Painters partition problem (Identical as Book Allocation problem).
// On coding ninjas and gfg

#include <bits/stdc++.h>
using namespace std;

//Approach 1 - Most Efficient Approach, using binary search.TC-O(Nlogn) SC-O(1).
//We have to return minimum time required to paint all the boards. 
bool isPossible(vector<int> &boards,int k, int mid){
    int painters = 1;
    int boardLength = 0;
    for(int i = 0; i<boards.size(); i++){
        if(boardLength + boards[i] <= mid){
            boardLength += boards[i];
        }
        else{
            painters++;
            if(painters > k || boards[i] > mid) return false;
            boardLength = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0, ans = -1;
    for(int i = 0; i<boards.size(); i++) sum += boards[i];
    int low = 0, high = sum;
    while( low <= high ){
        int mid = (low + high)/2;  //use low + high for this example otherwise you will get TLE.
        if(isPossible(boards,k,mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}



//Approach 2 - Using Linear search.TC-O(N*Sum) SC-O(1).
//Checking for every value from 1 to total boards to paint.
bool isPossible(vector<int> &boards,int k, int mid){
    int painters = 1;
    int boardLength = 0;
    for(int i = 0; i<boards.size(); i++){
        if(boardLength + boards[i] <= mid){
            boardLength += boards[i];
        }
        else{
            painters++;
            if(painters > k || boards[i] > mid) return false;
            boardLength = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0, ans = -1;
    for(int i = 0; i<boards.size(); i++) sum += boards[i];
   
    
    for(int i = 1; i<=sum; i++){
         if(isPossible(boards,k,i)) return i;
    }
    
    return ans;
}