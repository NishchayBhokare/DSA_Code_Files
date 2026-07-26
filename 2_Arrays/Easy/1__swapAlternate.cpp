//Example for swapping every pair of alternate elements in the array.
//on coding ninjas

#include<iostream>
using namespace std;

//Approach 1: By comparing i and i+1th element. TC- O(n) SC-O(1).
void swapAlternate(int *arr, int size){

    for(int i=0;i<size; i+=2){ //initializing i=0 and j=1.
       if((i+1) < size) swap(arr[i],arr[i+1]); //special if condition for array is of odd length. 
    }

    //or
    for(int i=0; (i+1)<size; i=i+2){ //or write that i+1 condition at entry point.
        swap(arr[i],arr[i+1]);
    }

}



////Approach 2: By usign two pointer approch. TC- O(n) SC-O(1).
void swapAlternate(int *arr, int size)
{
    for(int i=0,j=1;j<size;){ //initializing i=0 and j=1.
        swap(arr[i],arr[j]); //swapping between i and j th element.
        i=j+1; //incrementing i to j+1 th position.
        j=i+1; //incrementing j to i+1 th position.
    }
}