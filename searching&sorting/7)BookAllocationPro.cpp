// Book Allocation problem using binary search.

#include <bits/stdc++.h>
using namespace std;

//Approach 1 - Most Efficient Approach, using binary search.TC-O(Nlogn) SC-O(1).
//We have to return minimum value out of all Maximum partition value. 
bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int student = 1; //intially assigning 1 to student.
    int pageSum = 0; //pageSum is basically total sum of pages we are going to allocate for a student.
    for (int i = 0; i < n; i++) //looping from 0 to n-1.
    {

        if (pageSum + arr[i] <= mid) //if pageSum + current i is less than or equal to mid that means we can allocate more pages in pagesum for a student.
        {
            pageSum += arr[i];
        }
        else
        { //else increment student, so that we can allocate pages for next student.
            student++;
            if (student > m || arr[i] > mid) //if at any point, student becomes greater than m(given no. of student) return false, student becomes greater than m when, mid will be small and we unable to allocate all books to student i.e (we still remain some books in array to allocate). and also if current ith element greater than mid, that means our mid is small so return false. and search for larg mid.
                return false;
            pageSum = arr[i]; //if above condition is false, then add ith element in pagesum for next student.
        }
    }
    return true; //if we reach till this condition that means, we allocate books with the help of given mid, so return true.
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int sum = 0, ans = -1; //creating sum and ans two varibles.
    for (auto i : arr) sum += i; //first calculating total sum of pages present in array,
    int low = 0;
    int high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, mid)) //calling is possible function, if it returns true, that means current mid can be our answer, so store mid to ans and update high to mid - 1 so that we can search for more minmium value of mid.
        {
            ans = mid;
            high = mid - 1;
        }
        else //if is possible function returns false that means we have to update low to mid+ 1 to get higher value of mid so that we can allocate book for every student.
            low = mid + 1;
    }
    return ans;
}



//Approach 2 - Using Linear search.TC-O(N*Sum) SC-O(1).
//Checking for every value from 1 to total sum of pages.
bool isPossible(vector<int> arr, int n, int m,int mid ){
    int student = 1;
    int pageSum = 0;
    for(int i=0; i<n; i++){
        
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            student++;
            pageSum = arr[i];
            if(student > m || arr[i] > mid ) return false;
        }
  
    }
  return true;  
}

int allocateBooks(vector<int> arr, int n, int m) {
    int sum = 0, ans=-1;
    for(auto i: arr) sum += i;

 for (int i = 1; i < sum + 1; i++) { //just few change instead of binary search we're using linear approach from 1 to sum.
        if (isPossible(arr, n, m, i)) {
            return i;
        }
    }
    return ans;
}