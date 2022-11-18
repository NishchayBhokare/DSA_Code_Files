#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//Static Jagged array.
int main()
{
    int row0[] = {1, 2, 3, 4}; //first declaring number of rows and their elemenets.
    int row1[] = {5, 6, 7}; //declaring total two rows.

    int *jagged[] = {row0, row1}; // creating pointer array, which will hold address of row0 and row1.

    int sizeRow[] = {4, 3}; //array to hold the size of each row.
    int jaggedSize = 2; //size of jagged array. i.e total rows present in jagged array.

    for (int i = 0; i < jaggedSize; i++) //looping for every row present in jagged array.
    {  
        for (int j = 0; j < sizeRow[i]; j++) //looping for printing elements of every row present in jagged array.
        {
            cout << jagged[i][j] << " "; //printing jagged array.
        } cout<<endl;
    }
}
