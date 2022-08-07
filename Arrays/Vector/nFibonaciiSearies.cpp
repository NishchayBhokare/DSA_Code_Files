// Example for Print first n Fibonacci Numbers.
// link-
// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFibb(int n) // TC- O(n) SC- O(n).
{
    // sample fibonacci series is 0 1 1 2 5 7 12 19 31
    // i.e addition of previous two numbers.
    vector<long long> v;
    if (n == 1)
        v.push_back(1); // if given n is 1 then just simply return 1.
    else
    {                                       // otherwise enter in else part.
        long long a = 1, b = 1, nextNumber; // first initialize a and b with 1. in this example we are not considering 0.
        v.push_back(a);                     // push first element in vector.
        v.push_back(b);                     // push second element in vector.
        for (int i = 3; i <= n; i++)
        {                            // loop from 3 to n i.e for n=4 loop will execute 2 times.
            nextNumber = a + b;      // adding previous two numbers a and b.
            v.push_back(nextNumber); // pushing sum of both number in vector.
            a = b;                   // now updating a to b.
            b = nextNumber;          // and b to nextNumber i.e updating to sum of a & b
        }
    }
    return v; // and finally returning the vector.
}