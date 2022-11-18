#include<iostream>
using namespace std;

int main(){

int row;
cout<<"Enter total number arrays in jagged array i.e rows."<<endl;
cin>>row;

int **jagged = new int*[row]; //creating jagged which is pointer of pointer, which points to array which contains addresses to access each of its sub array.
int *sizeArray = new int[row]; //creating size array which stores records of size of every subarray.

cout<<"Enter size of each sub array "<<endl;
for(int i=0; i<row; i++){
    cin>>sizeArray[i]; //storing size of every sub array in sizeArray.
}

//creating sub-array dynamically, corresponding to every address in jagged array.
for(int i=0; i<row; i++){
    jagged[i] = new int[sizeArray[i]]; //creating array(row) corresponding to pointers array.
}


cout<<"Enter elements of each sub array "<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<sizeArray[i]; j++){
        // int *ptr = jagged[i];
        // cin>>ptr[j]; //This is background implementation.
        cin>>jagged[i][j];
    }
}

cout<<"Printing elements of each row in jagged array "<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<sizeArray[i]; j++){
        // int *ptr = jagged[i];
        // cout<<ptr[j]<<" ";
        cout<<jagged[i][j]<<" ";
    }
    cout<<endl;
}


//Deletion.

for(int i=0; i<row; i++){
    delete [] jagged[i]; //first deleting subarray which associated with pointers jagged array.
}
delete [] jagged; //lastly deleting jagged array.
}