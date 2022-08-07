// Example for finding duplicate elements and return it.
// link-
// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/#

int remove_duplicate(int a[], int n)
{ // Time complexity is O(n)
    int p = 0, q = 1;
    while (q < n)
    { // while q<n we will loop
        if (a[p] != a[q])
        {                    // if not same then,
            a[p + 1] = a[q]; // push element of q index in p+1 index so that duplicate element get overwrite.
            q++;
            p++; // then move on.
        }
        else
        { // if same then move on q++ till we not get different element & after getting different element we will perform above task that is, we will overwrite new element with duplicate element.
            q++;
        }
    }
    return p + 1; // we are returning p+1 index as a size of array cause indexing starts from 0 for p. so if p is on index 3 then total size will be 4.
}

// Instead of while we can use for loop also,
    // for (q = 1; q < n; q++)
    // {
    //     if (a[p] != a[q])
    //     {
    //         a[p + 1] = a[q];
    //         p++;
    //     }
    // }