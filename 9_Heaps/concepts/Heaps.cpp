#include <iostream>
#include<queue>
using namespace std;

class heap // example for maxheap in which parent element is greater than it's chld elements.
{
public:
    int arr[100]; // we use array to represent heap.
    int size = 0; // initially size is zero & we not store any element at index 0.

    void insert(int val)
    {
        size += 1;        // increasing size by one when element is add.
        int index = size; // initially index is 1;
        arr[index] = val; // initially insert val in array at end of the array.
        while (index > 1) // looping till index greater than 1 cause to compare elements there should be at least 2 elements in array.
        {
            int parent = index / 2; // parent of any element is their index in array/2.

            if (arr[parent] < arr[index])
            {                                  // checking if parent is small then it's child element then swapping between them.
                swap(arr[parent], arr[index]); // swapping .
                index = parent;                // updating index value so that we can compare it with remaining parent elements
            }
            else
            {
                return; // if parent element is greater then no need to compare. and exit from while loop.
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletionInHeap()
    { // deletion in heap
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step 1: put last element into first index in an array.
        arr[1] = arr[size];

        // step 2: remove last element by decreasing size--
        size--;


        // step 3: take root node to it's correct position.
        int i = 1;       // pointing to root node.
        while (i < size) // looping till i < size so that we can compare our root node with remaining child elements
        {
            int leftIndex = 2 * i;      // left child present at 2*i index position.
            int rightIndex = 2 * i + 1; // right child present at 2*i+1 index pos.

            int largest;
            if(leftIndex <= size and arr[leftIndex] > arr[rightIndex])
                largest = leftIndex;

            else largest = rightIndex; //checking which child is greater either left or right and putting it's index in largest.

            if(largest <= size and arr[i] < arr[largest]){ //and then comparing current element with its child element.
                swap(arr[i], arr[largest]); //if largest index is not out of bound and if it is greater than current element then we will swap.
                i=largest; //changing current index as largest cause we are swapped.
            } 
            else
                return; // if above  condition is false then our root element is at correct position.
        } 
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;      // left child present at 2*i index position.
    int right = 2 * i + 1; // right child present at 2*i+1 index pos.

    if (left <= n and arr[largest] < arr[left])
    {                   // first checking whether leftindex is out of bound or not and then checking largest element < leftchild element or not.
        largest = left; // if largest element is less than left child then we will change index of largest element.
    }
    if (right <= n and arr[largest] < arr[right])
    {                    // first checking whether right index is out of bound or not and then checking largest element < leftchild element or not.
        largest = right; // if largest element is less than right child then we will change index of largest element.
    }

    if (largest != i)
    {                               // now checking whether largest is change or not, if change then we will swap it with 'i'
        swap(arr[largest], arr[i]); // swapping between largest element and ith element.
        heapify(arr, n, largest);   // again calling heapify so that we can check current largest element is present at its correct pos. or not by comparing with its child elements.
    }
}

//or we can do like this also..for heapify 
void heapify(int *arr, int index, int size){
    if(index > size/2) return;

    int leftchild = 2 * index;
    int rightchild = 2 * index + 1;

    int element = arr[index];
    int largest = leftchild;

    if(rightchild <= size &&  arr[rightchild] > arr[largest])
        largest = rightchild;

    if(arr[index] < arr[largest])
    { 
        swap(arr[index], arr[largest]);
        heapify(arr, largest, size);
    }
}


void heapSort(int arr[], int n)
{                 // heap sort algo to sort the array.
    int size = n; // storing size of array cause we are going to decrease n in loop.
    while (n > 1) // till n is greater than 1 we will loop
    {
        swap(arr[1], arr[n]); // swapping between first and last element.
        n--;                  // decresing size by one at every iteration
        heapify(arr, n, 1);   // calling heapify algo. to set root element at it's correct pos.
    }

    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // heap h; // creating object of heap class;
    // h.insert(54);
    // h.insert(53);
    // h.insert(55);
    // h.insert(52);
    // h.insert(50);

    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // cout<<"before deletion"<<endl;
    // h.print();
    // // deletion i.e we're deleting root node.
    // h.deletionInHeap();
    // cout << "after deletion" << endl;
    // h.print();

    // building heap by heapify algorithm.
    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5; //we are not cosidering first element.
    // for (int i = n / 2; i > 0; i--) //looping from n/2 (cause n/2+1 to nth elements are leaf node so not necessary to check their pos.) to 1 i.e from left to right.
    {
        // heapify(arr, n, i); //calling heapify.
        // after all the condition present in heapify function turns into false then index of 'i' get decrease by one.
    }

    // printing the array after building heaps
    //  for(int i=1; i<=n;i++){
    //      cout<<arr[i]<<" ";
    //  }

    // heap sort algorithm
    int arr2[] = {-1, 50, 60, 55, 45, 70};
    int n = 5;
    heapSort(arr2, n);

    //max heap in STL
    priority_queue<int> pq;

    //min heap in STL
    priority_queue<int,vector<int>,greater<int> > minheap;
    //push(), top(), pop(), size(), empty()
    

    return 0;
}