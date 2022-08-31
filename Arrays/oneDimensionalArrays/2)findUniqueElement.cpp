//Example for finding unique element from an array.
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

//Approach 1: Efficient approach, By taking xor of all elements. TC- O(n) SC-O(1).
//if we take xor of all elements then we will get the element which will be unique element. 
int findUnique(int *arr, int size)
{
  int ans = 0;
    for(int i=1; i<size; i++){
        ans = ans ^ arr[i]; //take xor and store it in ans.
    }
    return ans;
}



//Approach 2: using extra space and counting strategies TC- O(n) SC-O(max(arr[i])).
int findUnique(int *arr, int size)
{
    int maxi=INT_MIN; //initialzing maxi to intMin.
    for(int i=0; i<size; i++) if(arr[i] > maxi) maxi = arr[i];  //looping over array to get max element of given arrya.
    int v[maxi+1]={0}; //creating temporary array of size maxi+1, cause indexing starts from 0.
    for(int i=0; i<size; i++) v[arr[i]]++;  //incrementing count of particular element in temporary vector v.
    for(int i=0; i<=maxi; i++)  if(v[i]==1) return i;  //checking if v[i] is equal to 1, that means ith index which refers to element in array arr. is unique element. 
}
