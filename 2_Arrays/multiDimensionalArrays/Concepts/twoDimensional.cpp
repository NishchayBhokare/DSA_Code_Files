#include <iostream>
using namespace std;

void traverse(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void input(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}
int findElement(int arr[][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
                return 1;
        }
    }
    return 0;
}

// for row wise sum iterate over row and inside column.
void rowWiseSum(int arr[][3], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
}

// for column wise sum iterate over column and then inside row.
void colWiseSum(int arr[][3], int row, int col)
{
    int sum = 0;
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
}

void LargestRow(int arr[][3], int row, int col)
{
    int sum = 0, maxSum = 0, ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxSum)
        {
            ans = i;
            maxSum = sum;
        }
        sum = 0;
    }
    cout<<"Largest Row is "<<ans+1<<endl;
}
int main()
{
    // int row = 3, col = 3;
    // // int arr[2][3]={1,2,3,4,5,6};
    // int arr[3][3] = {{1, 2, 33}, {4, 5, 6}, {7, 4, 21}};
    // // input(arr,row,col);
    // // traverse(arr, row, col);
    // // findElement(arr,row,col,14)?  cout<<"Found" : cout<<"Not Found"; cout<<endl;
    // // rowWiseSum(arr,row,col);
    // // colWiseSum(arr,row,col);
    // LargestRow(arr, row, col);

    //One dimensional array-> static allocation
    int a1[5];

    //One dimensional array -> dynamic allocation.
    int *a2 = new int[5];

    //Releasing memory
    delete []a2;

    
    //Two dimensional array -> static allocation
    int b[3][4];


    //Two dimensional array -> dynamic allocation.
    int **arr = new int*[3]; //first creating array of pointers.

    for(int i = 0; i<3; i++){
        arr[i] = new int[4]; //now for every pointer create array.
    }

    //taking input.
    // for(int i = 0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    //Printing
    // for(int i = 0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }

    // Releasing memory
     for(int i = 0; i<3; i++){
        for(int j=0; j<4; j++){
            delete [] arr[i];
        }
    }

    delete []arr;
    return 0;
}