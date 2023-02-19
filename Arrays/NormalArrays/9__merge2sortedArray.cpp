// Merge two sorted arrays.
//leetcode
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//Approach 1- Optimize approach TC-O(m+n) Sc- O(1).
// Two pointer can used here by keeping pointers from back and keep decrementing our pointers and keep adding the larger elements in back.
// NOTE: Since arr1 can accomadate all the elemnts but m is given without zeroes counting so take care of that i.e take k=m+n-1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1, j=n-1, k=m+n-1;
       while( i >= 0 and j >=0){ //looping till both i and j indexes are greater than 0
           if(nums1[i] <= nums2[j]){ // if(ith element smaller than jth element in nums1 of k i.e add from back.)
                 nums1[k] = nums2[j]; //adding jth element to kth position in array1.
               k--; j--; //Decrementing both kth and jth indexes.
           }
           else{
               nums1[k] = nums1[i]; //similarly, if ith element is grater than jth element then, add ith element at kth position.
               k--; i--;
           }
       }
       while(j >= 0) nums1[k--] = nums2[j--]; //if there elements are still present in jth array i.e nums2 array then add those element in nums1 array by decrementing k on every iteration.
    }

//Approach 2- Approach TC-O(m+n) Sc- O(m+n).
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0; //here i pointing to nums1 array and j pointing to nums2 array or vector.
    vector<int> temp; //creating temporary vector, where we will store elements of nums1 vector and nums2.
    while (i < m && j < n) //looping till both i and j less than n.
    {
        if (nums1[i] <= nums2[j]) //if nums1[i] element less than or equal to nums2[j] th element then add nums1[i]th element in the temp vector.
        {
            temp.push_back(nums1[i]);
            i++; //increment i. 
        }
        else
        {
            temp.push_back(nums2[j]); //else push nums2[j]th element in temp vector.
            j++; //and increment j.
        }
    }

    // looping for i<m i.e if element in nums1 is still present, so copy those elements as it is in temp vector.
    while (i < m)
        temp.push_back(nums1[i++]);

    // looping for j<n i.e if element in nums2 is still present, so copy those elements as it is in temp vector.
    while (j < n)
        temp.push_back(nums2[j++]);


    // for(int i=0; i<temp.size(); i++){
    //     nums1[i] = temp[i];
    // }
    nums1 = temp; // assigning temp to nums1. or you use above for loop to copy all elements of temp to nums1.
}


//Approach 3- Sorting technique TC-O(nlogn) Sc- O(1).
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (auto i : nums2) //just adding all elements of nums2 in nums1
    {
        nums1[m++] = i;
    }
    sort(nums1.begin(), nums1.end()); //and sorting nums1 so that we will get sorted order.
}