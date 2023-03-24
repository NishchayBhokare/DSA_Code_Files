#include<iostream>
using namespace std;

void counting(int n){
    //base case
    // if(n == 1) return 1;

    // n = n + counting(n-1); //so, if n is 3 then 3 + (3-1) and so on. if n=2 then 2 + (2 -1 ) so if n=1 then it will return 1 so at n=2, updated n will be 2+1=3 ans so on.
    // return n;
    if(n == 0) return;
    cout<<n<<" ";
    return counting(n-1); //This return is optional cause as usual stack memory will destroy when we reach till the end of the function.
}

void counting2(int n){
    if(n == 0) return;
    cout<<n<<" ";
    counting2(n-1); //now decrementing n by 1 for next recursive call
}
int main(){
    int n=8;
    counting2(n);
    return 0;
}