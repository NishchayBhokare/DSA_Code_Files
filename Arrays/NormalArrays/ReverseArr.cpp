// Example for reverse string
// link-
    // https://practice.geeksforgeeks.org/problems/reverse-a-string/1#

#include <iostream>
using namespace std;
int main()
{
    string str = "geeks";
    string s = "";
    for (int i = str.size(); i >= 0; i--) //Accessing an array from last element to first element and stroing it to newly created array 
    //time complexity is O(n)
    {
        s += str[i];
    }
    for (int i = 0; i< s.size(); i++) //printing newly created array
    {
        cout << s[i] << " ";
    }
}

// we can reverse string in this manner also //time complexity is O(logn)
//  reverse(s1.begin(),s1.end()); //we are providing begin iterator and end iterator.
//  return s1;


//We can reverse using swap function
// int j=size-1; //time complexity is O(logn)
// for(int i=0;i<size/2;i++){ // we are looping up to the size/2 - 1. cause middle element are always right at their current position.
//     swap(s1[i],s1[j]); 
//     j--;
// }
// return s1;