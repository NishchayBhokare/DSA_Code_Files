// Example for checking range elements are present in array or not.
// link-
// https://practice.geeksforgeeks.org/problems/elements-in-the-range2834/1

// Approach 1- most efficient approach. inplace modification. TC-O(n) SC-O(1)

// 0 1 2 3
// 2 3 4 5  -to find index of 5. we will minus it from first elem. i.e 5-2=3.

bool check_elements(int arr[], int n, int A, int B)
{
    if (B - A >= n)
        return false; // if no. of elements in range is greater than size of array return false

    for (int i = 0; i < n; i++)
    { // looping from 0 to n.
        if (abs(arr[i]) >= A and abs(arr[i]) <= B)
        {                                // checking ith element is in range or not. check with absolute value cause we may be mark it as -ve.
            int index = abs(arr[i]) - A; // to get index of 5 as we explain above, we minus it from first element of range.
            if (arr[index] > 0)
            {                       // checking wheter we alredy mark element of that index as minus or not. if not then mark it otherwise skip.
                arr[index] *= (-1); // multiplying with minus
            }
        }
    }

    for (int i = 0; i <= (B - A); i++)
    { // looping till size of range. i.e 5-2=3 so 0 to 3 is 4 elements
        if (arr[i] > 0)
            return false; // if any of the elements between given range turns into positive then we will return false cause we mark it as -ve.
    }

    return true; // if everything okay then we will return true.
}

//  Approach 2:- using sorting algo. TC-O(nlogn) SC-O(1)

	// bool check_elements(int arr[], int n, int A, int B)
	// {
	// 	// Your code goes here
	// 	sort(arr, arr+n); //first we are sorting
	// 	int i=0;
	// 	while(arr[i]!=A and i<n){ //looping till, we will not reach to A element
	// 	    i++;
	// 	}

	// 	if(i == n) return false; //if element A is not found in array then i index will be equal to n so we will return false.

	// 	while(arr[i]!=B and i<n){ //looping till, we not reach to B
	// 	    if(arr[i] == arr[i+1]) {i++; continue;} //if duplicate elements are present then we will simply skip itertion and move to next iteration
	// 	    if(arr[i]+1 != arr[i+1]) return false; //now prev [pos] + 1 and [pos+1] is not same then false cause we add 1 in prev position, so thats why it should be same. for eg. if arr[i] is 3 then arr[i]+1 is 4 and if arr[i+1] is not 4 then return false.
	// 	    i++;
	// 	}

	// 	if(i == n) return false; //if element B is not found in array then i index will be equal to n so we will return false.

	// 	return true; //otherwise return true.
	// }
