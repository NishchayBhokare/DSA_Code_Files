#include<iostream>
using namespace std;

//Approach 1: using recursion (first approach coming into my mind).
int findSum(int arr[],int sum,int size){
//Base case
if(size == 0) return sum;

//Processing 
sum += arr[0];

return findSum(arr+1,sum,size-1);
}

//Approach 2: using recursion by love babbar
int findsum2(int arr[],int size){
    if(size == 0) return 0;
    if(size == 1) return arr[0]; //if size is 1 then return that element


    int sum = arr[0] + findsum2(arr+1, size-1); //this is nothing but sum for 1,3,5 is sum = 1 + (3+(5));
    return sum;
}

int main(){

int sum = 0;
int arr[ ]={10,5,60,5};
cout<<"Sum of array is "<<findSum(arr,sum,4)<<endl;
cout<<"Sum of array is "<<findsum2(arr,4);

}