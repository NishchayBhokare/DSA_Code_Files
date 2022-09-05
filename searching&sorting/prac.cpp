#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

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
        for(double j = ans; (j * j) < num; j = j + factor){ //now initialising j with ans and after adding j with factor, checking j's square is less than num or not.
            ans = j; //if less than num then update ans.
        }
    }
    return ans;
}

int main(){  
    int num = 8;
   int tempAns = binarySearch(num); //Function will return square root without any precision.i.e sqrt(8) will be 2
   cout<<morePrecision(num,tempAns,2); //to get ans in precision then call this function with 3 parameters, num, tempans and no. of precision.

}