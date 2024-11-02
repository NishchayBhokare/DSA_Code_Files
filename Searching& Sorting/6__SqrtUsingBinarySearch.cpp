//Example for Calculate square root of given number using binary search.
//GFG
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

//Approach 1 - Most Efficient Approach, using binary search.TC-O(logn) SC-O(1).
  long long int floorSqrt(long long int num) 
    {
        long long int low =0; //initializing low to 0 and high to num.
        long long int high = num,ans=0;
        while(low <= high){ //looping itll low less than or equal to high.
            long long int mid = low + (high - low)/2; //calculating mid.
            long long int square = (mid * mid); //calculating square.
            if(square == num) return mid; //if square is equal to num that means we got perfect square root so return mid.
            if(square < num) { //square is less than num, then this current mid can be our answer, so store mid in ans and update low to mid + 1.
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1; //if square is greater than num, then just update high to mid-1 cause, current mid won't be our ans.
        }

        return ans; //if we reach to this statement that means we did'nt get any perfect square root, so return ans, which will be nearest square root for num. 
        //for eg. if num =8 then we will reach to this statement and our answer will be 2, it is nearest square root for num.
        //if num is 9 then we won't reacht to this statement, withing while loop we will return our mid, which will be our perfect square root i.e 3.
    }



//Approach 2 - looping from 1 to num.TC-O(sqrt(num)) SC-O(1).
      long long int floorSqrt(long long int num) 
    {
        if(num == 1) return num; //if num is 1 then its square root is also 1.
        long long int ans =0;
        for(long long int i=1; i<=num;i++){ //looping from to 1 to given number
            
           if((i * i) <= num)  ans = i; //if squre of i is less than or equal to num then update ans.
           else if((i * i) > num) return ans; //and when square of i greater than i, then simply return ans. ( cause no need to run for further iteration.)
           
        }
    }

//Approach 3 - Using built in sqrt function(Implementation is same as first approach). TC-O(logn) SC-O(1).
 long long int floorSqrt(long long int num) 
    {
       return sqrt(num); //calculating using built in function and return ans.
       //cout<<setprecision(3)<<sqrt(8)<<endl; //shortcut to get ans with help of sqrt function and set precision function. TC-O(logn).

    }    




// Below implementation for getting square root in given precision.
int binarySearch(int num){
        long long int low =0;
        long long int high = num,ans=0;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int square = (mid * mid);
            if(square == num) return mid;
            if(square < num) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }    
        return ans;
}

double morePrecision(int num,int tempAns,int precision){
    double factor=1,ans=tempAns; //creating factor and ans variable of double type.
    for(int i=1; i<=precision; i++){ //looping precision times, cause if precision is 3 then we want 3 numbers after decimal point.
        factor = factor/10; //dividing factor by 10 so for first iteration factor will be 0.1 then 0.01, 0.001 etc. this is what we want to add in ans.
        for(double newAns = ans; (newAns * newAns) < num; newAns = newAns + factor){ //now initialising j with ans and after adding j with factor, checking j's square is less than num or not.
            ans = newAns; //if less than num then update ans.
        }
    }
    return ans;
}

int main(){  
    int num = 8;
   int tempAns = binarySearch(num); //Function will return square root without any precision.i.e sqrt(8) will be 2
   cout<<morePrecision(num,tempAns,2); //to get ans in precision then call this function with 3 parameters, num, tempans and no. of precision.

//cout<<setprecision(3)<<sqrt(8)<<endl; //shortcut to get ans with help of sqrt function. TC-O(logn).
}