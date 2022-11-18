#include <iostream>
using namespace std;

// Approach 1 using Recursion
bool isSorted(int arr[], int size)
{
    // Base case
    if (size == 0 || size == 1)
        return true; // when size of array becomes 0 or 1 that means array is sorted.

    if (arr[0] > arr[1])
        return false; // condition when first element is greater than second element so if true that means array is not sorted.
    else
    {
        return isSorted(arr + 1, size - 1); // sending address of next element so that we can access elements from that index. also decrement size by 1.
    }
}

//Approach 2- Using loops
bool isSorted2(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++) //starting from index 1, cause if array is of size 1 then definitely array will be sorted so start from index 1 instead 0.
    {
        if (arr[i] < arr[i - 1]) //checking if current i, less than previous one, that means array is not sorted.
            return false; //return false
    }
    return true; //if we reach till here, then array is sorted so return true.
}

int main()
{

    int arr[] = {11, 3, 6, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (isSorted(arr, size))
        cout << "Given array is sorted"<<endl;
    else
        cout << "Given array is not sorted"<<endl;

         if (isSorted2(arr, size))
        cout << "Given array is sorted";
    else
        cout << "Given array is not sorted";
}