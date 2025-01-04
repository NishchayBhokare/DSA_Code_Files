// Book Allocation problem using binary search.
// On coding ninjas and gfg
// Aggressive Cows
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


//Little optimised isPossible function
 int isPossible(int arr[],int N, int students,int mid){
        int pages = 0;
        int st = 1;
        for(int i=0; i<N; i){
            if(pages + arr[i] <= mid){
                pages += arr[i];
                i++; //updating i only when we allocate book
            }
            else{
                st++;
                pages = 0;
                if(st > students) return 0; //if student gets greater than number of given student then current mid can't be possible answer. that is mid should be more
                //second condition is not required because we're incrementing i, only when mid is greater. so no need to check.
            }
        }
        
    return 1; //here we cannot write condition for stud == m or not because if we write condition here.
    //and if we return false if stud not equals to m. then what happens.
    //ther will be scenario like stud 3, pagecnt(mid) is 25 and array is 15,10,18,7. ,
    //if you observe we will allocate 0th and 1st book to s1 because it comes under 25.
    //for s2 18, and s3 7. 
    //but what happens. in code. we're allocating 18+7=25 to s2 which is wrong but if you consider
    //like above then it's right. so in code level. even if student is lesser than m. then also return true.
    
    //suppose we have mid is 50. then with mid 50 answer can be possible. but we have to find out minimum difference between arrangemenet of books.
    //so we need to return true.
    //we will return false only if student gets exceeded.
}

int allocateBooks(vector<int> arr, int n, int m)
{   
    if(m > n) return -1; //if studnet is greater than number of books.    

    int sum = 0, maxi=0, ans = -1; //creating sum and ans two varibles.
    for (auto i : arr){
        maxi = max(mini,i);
        sum += i; //first calculating total sum of pages present in array,
    }

    int low = maxi; //also we can keep our low to maximum pages present in array. for eg. in 10, 20, 30, 40, low can be 40 cause, 
    // answer will be in range between 40 to 100(total sum). why 40 because at least every book should be allocate and for that..we need to take maximum book page.
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

 for (int i = 1; i <= sum; i++) { //just few change instead of binary search we're using linear approach from 1 to sum.
        if (isPossible(arr, n, m, i)) {
            return i;
        }
    }
    return ans;
}


//just normal solved..
bool isPossible(vector<int> &arr, int pageCount, int std){
        int student = 1;
        
        int pages = 0, i = 0; 
        while(i < arr.size()){
            if( (pages + arr[i]) <= pageCount){
                pages += arr[i];
                i++;
            }
            else{
                student++;
                
                if(student > std) 
                    return false;
                
                pages = 0;
            }
        }
        
        if(student <= std) 
            return true;
        
        return false;
    }
  
  
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1; 
        
        
        int totalPages = 0;
        
        for(auto i:arr) totalPages += i;
        
        int low = 0, high = totalPages, ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isPossible(arr, mid, k)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        
        return ans;
        
    }