// Example for segregate (sort) 0's and 1's.
//GFG
#include <iostream>
using namespace std;


//Approach 1:- Efficient approach using two pointer strategy. TC- O(n) Sc-O(1).
void segregate0and1(int arr[], int n)
{
    // code here
    int left = 0, right = n - 1; // initialise left to 0 and right to n-1.
    while (left < right)
    { // looping till left less than right.
        if (arr[left] == 0)
            left++; // if arr[left] is 0 then simply increment left.

        else if (arr[right] == 1)
            right--; // similarly arr[right] is 1 then no need to do anything simply increment right.

        else
        {                                // if you reach to this else statement that means arr[left] is 1 and arr[right] is 0, so we need to swap left with right inorder to get 0 at left side and 1 at right side.
            swap(arr[left], arr[right]); // swapping left with right.
            left++;
            right--; // incrementing left and decrementing right.
        }
    }
}



//Approach 2:- Using counting 0's and 1's. TC- O(n) Sc-O(1).
void segregate0and1(int arr[], int n)
{
    int cnt0 = 0; //count for 0's.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) //if arr[i] equal to 0, then incrementing cnt0.
            cnt0++;
    }

    for (int i = 0; i < n; i++)
    {
        if (cnt0 > 0) //adding 0's to arr[i] till, cnt0 > 0.
        {
            arr[i] = 0;
            cnt0--;
        }
        else
            arr[i] = 1; //for remaining space we will add 1's.
    }
}


//Approach 3: More optimised 
void segregate0and1(int arr[], int n) {
        for(int i=0,j=0; j<n; j++){
            if(arr[j] == 0){  //if jth element is 0, then swap with ith element because our ith element either will be 0 or 1. 0 swap with 0 becomes 0,0 and if 1 swap with 0 then 0,1 which is required. 
                swap(arr[i++],arr[j]); //once swap update i and j will automatic update in every iteration
            }

            //if jth element not equals to 0 then only increment j not i. 
        }
    }