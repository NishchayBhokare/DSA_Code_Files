// Example for sorting 0's, 1's and 2's.
#include <iostream>
using namespace std;


//Approach 1:- Efficient approach using Dutch national flag algo.(using single pass) TC- O(n) Sc-O(1).
//Dutch national flag algo state that, 
//0 (will be in rane of) -> [0 to l-1]
//1 (will be in rane of) -> [l to m-1]
//2 (will be in rane of) -> [h+1 to n-1]

void sort012(int a[], int n)
{

    int l = 0, m = 0, h = n - 1;
    while (m <= h) //looping till m is less than or equal to h.
    {
        if (a[m] == 0) //if m equal to 0, then swap it with low. and increment mid and low.
        {
            swap(a[l], a[m]);
            l++;
            m++;
        }
        else if (a[m] == 1) //if mid is 1, then just increment mid.
            m++;
        else
        { //last condition when mid is 2, then swap it with high. and decrement high.(we are not inrementing low cause we don't know which element will come from high side.)
            swap(a[m], a[h]);
            h--;
        }
    }
}


// Approach 2:- Using counting 0's ,1's and 2's. (requires 2 iteration over an array.) TC- O(n) Sc-O(1).
void sort012(int a[], int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    { // looping for counting 0's and 1's.
        if (a[i] == 0)
            cnt0++;
        else if (a[i] == 1)
            cnt1++;
    }

    for (int i = 0; i < n; i++)
    { // looping for adding 0's, 1's and 2's.
        if (cnt0 > 0)
        { // if cnt0 > 0 then add 0 in array.
            a[i] = 0;
            cnt0--;
        }
        else if (cnt1 > 0)
        { // if cnt1 > 0 then add 1 in array.
            a[i] = 1;
            cnt1--;
        }
        else
        { // and for remaining space add 2's in an array.
            a[i] = 2;
        }
    }
}