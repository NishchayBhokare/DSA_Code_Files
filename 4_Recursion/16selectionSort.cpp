#include <iostream>
using namespace std;

// After every pass we will get (i+1)th smallest element.
// Best TC- O(n2), Worst Tc- O(n2)
// Not stable, Not Adaptive, Not recursive
// Use Case- Useful When list is small,as the TC is O(n2) which makes it inefficient for a large list.
// When memeory space is limited becaise it makes the minimum number of swaps during sorting.
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {                     // looping from 0 to n-1 cause last element will automatically sorted.
        int minIndex = i; // assuming first ith index is minIndex.
        for (int j = i + 1; j < n; j++)
        { // looping from i+1 to less than n, to search for minimum element than minIndex element.
            if (arr[j] < arr[minIndex])
                minIndex = j; // if we found element less than minIndex then just change minIndex to j.
        }
        swap(arr[minIndex], arr[i]); // and after looping out from inner for loop, just swap arr[minIndex] with arr[i]. before incrementing i.
    }
}


//Approach 2: using selection sort.
void selectionSortRecursion(int arr[], int size)
{
    if (size == 0 || size == 1) //if size is 0 or 1 then simply return.
        return;

    int minIndex = 0; //at starting minIndex will be 0.
    for (int i = 1; i < size; i++) //calculating  smallest number.
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap(arr[0], arr[minIndex]); //and finally swapping with 0th index element.

    selectionSortRecursion(arr + 1, size - 1); //now in recursive call, pass arr+1 cause first element is already sorted and decrement size by 1.
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 4, 2, 8, 3};
    int size = sizeof(arr) / sizeof(int);
    // selectionSort(arr,size); //calling selection sort.
    selectionSortRecursion(arr, size);
    print(arr, size); // printing array.
}