#include <iostream>
using namespace std;
//Example to check whether given array is sorted or not.
//GFG.

// Approach 1 using Recursion TC - O(N) SC-O(N)
bool arraySortedOrNot(int arr[], int n) {
    if (n == 1)
        return true; // when size of array becomes 1 that means array is sorted.

    if (arr[0] > arr[1])
        return false; // condition when first element is greater than second element so if true that means array is not sorted.
    else
    {
        return arraySortedOrNot(arr + 1, n - 1); // sending address of next element so that we can access elements from that index. also decrement size by 1.
    }
 }



//Approach 2- Using loops TC-O(N) SC-O(N);
bool arraySortedOrNot(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++) //starting from index 1, cause if array is of size 1 then definitely array will be sorted so start from index 1 instead 0.
    {
        if (arr[i] < arr[i - 1]) //checking if current i, less than previous one, that means array is not sorted.
            return false; //return false
    }
    return true; //if we reach till here, then array is sorted so return true.
}