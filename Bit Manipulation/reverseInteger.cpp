// Example for reverse integer.
//  link:- (leetcode)
//  https://leetcode.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int ans = 0;
    while (x != 0)
    {                       // looping till x not get zero, at one time x will be zero by dividing it 10.
        int digit = x % 10; // taking digit from integer x, by modulus with 10.
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        { // handling special case when value goes outside the signed 32 bit integer range. that time we will return 0.
            return 0;
        }
        ans = (ans * 10) + digit; // to get binary representation in same flow.
        x = x / 10;               // by dividing it to 10, we will reduce number.
    }
    return ans;
}
