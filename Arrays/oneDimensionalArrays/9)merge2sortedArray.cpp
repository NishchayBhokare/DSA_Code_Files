// Merge two sorted arrays.
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


//Approach 1- Optimize approach TC-O(n) Sc- O(1).
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


//Approach 1- Sorting technique TC-O(nlogn) Sc- O(1).
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (auto i : nums2) //just adding all elements of nums2 in nums1
    {
        nums1[m++] = i;
    }
    sort(nums1.begin(), nums1.end()); //and sorting nums1 so that we will get sorted order.
}