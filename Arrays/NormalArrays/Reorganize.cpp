// Example for Reorganise the array.
// link-
    // https://practice.geeksforgeeks.org/problems/reorganize-the-array4810/1#

int * Rearrange(int *arr,int n){ //time complexity is O(n)
int i=0;
while(i<n){  //we are looping till the i is less than size of array.
    if(arr[i]!=-1 && arr[i]!=i){ //checking two conditions:- 1) checking whether arr[i] contain -1 or not, if contain then i++ otherwise enter in loop. 2) checking whether arr[i] is at right positon or not for eg. arr[0] is 4 and i is also 4 then arr[0] == i satisfied so it will not enter in the loop i.e i++.
        swap(arr[i],arr[arr[i]]); //we are swapping between current element and the element at the index of current element. for eg. arr[0]=2 and arr[2]=5 then here swapping will happen betn 2 and 5. 
    }
    else{ //if arr[i]== -1 then just move on.
        i++;
    }
  }
    return arr;
}
