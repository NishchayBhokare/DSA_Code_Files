#include<iostream>
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

void wavy(int arr[][3], int row, int col){
    int i=0,j=0;
    while (j<col)
    {
        
        if(i==0){
            for(i; i<row; i++){
                
                cout<<arr[i][j]<<" ";
            }
            j++; i=(row-1);
        }
        else{
            for(i;i>=0; i--){
                cout<<arr[i][j]<<" ";
            }
            j++; i=0;
        }

    }
    
}
void findRowWiseSum(int matrix[][4],int row,int col){
    for(int i=0; i<row; i++){
        int rowWiseSum = 0;
        for(int j=0; j<col; j++){
            rowWiseSum+=matrix[i][j];
        }
        cout<<rowWiseSum<<endl;
    }
}

void findColumnWiseSum(int matrix[][4],int row,int col){
    for(int i=0; i<col; i++){
        int columnWiseSum = 0;
        for(int j=0; j<row; j++){
            // cout<<matrix[j][i];
            columnWiseSum+=matrix[j][i];
        }cout<<endl;
        cout<<columnWiseSum<<endl;
    }
}

int main(){
    int matrix[3][4]={{3,9,2,1},{5,8,7,6},{6,4,8,2}};
    // findRowWiseSum(matrix,3,4);
    findColumnWiseSum(matrix,3,4);
    // int row=3,col=3;
    // int a[3][3]={{3,9,2},{5,8,7},{6,4,8}};
    // traverse(a,row,col);
    // wavy(a,row,col);
}