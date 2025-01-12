 // Example for chocolate distributon problem.
// link-
    // https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/#
 
 #include<bits/stdc++.h>
 using namespace std;

 //Approach 1: We can start simply from m-1 index.
 int findMinDiff(vector<int>& a, int m) {
   sort(a.begin(), a.end());
   
   int minDiff=INT_MAX;
   for(int i=m-1; i<n; i++){
      
      int diff = a[i] - a[i-m+1];
      minDiff = min(minDiff, diff);
   }
   
   return minDiff;
}


//Approach 2: 
 long long findMinDiff(vector<long long> a, long long n, long long m){ //Time complexity is    O(nlogn).
    
    sort(a.begin(),a.end()); //first we need to sort it.
    int min_value=INT_MAX; //we are initializing min with maximum value. so that it will help in comparision.
    int d;
    
    for(int i=0;i+m-1<n;i++){ //we are looping till the mth i.e (i+m-1) element  not get out of bound.
       d=a[i+m-1]-a[i]; //storing difference of maximum value (mth value) and minimum value (ith value).
       if(d<min_value){ //checking difference (d) is minimum than min value. 
           min_value=d; //if minimum then store it into the min. Otherwise skip it.
       }

       // min_value=min(d,min_value); //we can use min default min function to get default value.
    }
    return min_value;  //finally returning the minimum difference.
    }