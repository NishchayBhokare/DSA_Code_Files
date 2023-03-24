//Example for finding Intersection(common and distinct elements) Of Two Sorted Arrays.
//on GFG

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


//Approach 1: by sorting technique. TC-O(nlogn) SC-O(1).
 int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int count =0,i=0,j=0;
        sort(a,a+n);
        sort(b,b+m);
        while(i < n and j < m){
            
        if(i>0 && a[i]==a[i-1]){ //applying this condition because we want common elements but it should be distinct so to avoid from duplicate common elements, applying this condition.
                i++; //and incrementing count.
                continue; 
        }
            if(a[i] < b[j]) i++;
            else if(a[i] > b[j]) j++;
            else if(a[i]==b[j]){
                count++; i++; j++;
            }
        }
        return count;
    }