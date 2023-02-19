#include<iostream>
using namespace std;

// void insert(int* arr, int rowIndex, int colIndex,int val){
//  arr[rowIndex][colIndex]=val;
// }

void  traversing(int arr[][3]){
    // cout<<arr[0][0];
    // return arr;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

}

int main(){
    int arr[2][3]={{3,4,5},{6,1,0}};
    // insert(arr,0,0,4);
    // cout<<arr[0][0];
    // cout<<arr[0][1];
    // cout<<arr[0][2];
    // cout<<arr[1][0];
    // cout<<arr[1][1];
    // cout<<arr[1][2];
    traversing(arr);
    }