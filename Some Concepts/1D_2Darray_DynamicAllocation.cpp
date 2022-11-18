
#include<iostream>
using namespace std;

int main()
{

    //         //Creation of one dimensional array, dynamically
    // int n=5;
    // int *arr1 = new int[n]; //Important step

    // for(int i=0; i<n; i++) cin>>arr1[i]; //Taking input.

    // for(int i=0; i<n; i++) cout<<arr1[i]<<" ";//printing array

    // delete [] arr1; //Deleting array.
    // cout<<endl<<"Printing after deleting an array"<<endl;

    // for(int i=0; i<n; i++) cout<<arr1[i]<<" ";

    // Creation of two dimensional array, dynamically
    int n = 3, m = 4;         // n specifies no. of rows and m specifies no. of coloumns.
    int **arr = new int *[n]; // creating n size rows, which currently contain pointers.
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m]; // adding columns. for every number of rows.
    }

    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; // taking input
        }
    }

    // printing output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting two dimensional array.
    // We have to delete in this way.
    for (int i = 0; i < n; i++)
    { // first deleting arrays whose associated with number of rows.
        delete[] arr[i];
    }
    
    delete[] arr; // deleting array of pointers.

    cout<<endl<<"After deleting "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
         cout<<endl;
    }
    return 0;
}
