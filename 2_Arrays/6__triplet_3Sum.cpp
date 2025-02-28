// Example for returning list of triplets whose sum equals to s.
// on coding ninjas and gfg

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

// Approach 1: Most Efficient approach, using two pointer approach TC- O(n2).
vector<vector<int>> findTriplets(vector<int> arr, int n, int s)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // first sort given array.
    for (int i = 0; i < (n - 2); i++)
    { // looping till less than n-2, cause at least there should be 2 elements to the right of i.

        if (i == 0 || (arr[i] != arr[i - 1]))
        { // to handle case of same value of i. if same then don't enter in if block, just simply increment i.

            int low = i + 1, high = (n - 1), sum = (s - arr[i]); // low positiong to i+1, high is n-1 and sum = s-arr[i]. i.e arr[i] + arr[low] + arr[high] =s, so arr[low]+arr[high]=  s - arr[i]

            while (low < high)
            { // looping till low < high cause if low is greter than or equal to high then we may get again same triplet.

                if ((arr[low] + arr[high]) < sum)
                    low++; // if low + high is less than sum then increment low so that we will get higher value

                else if ((arr[low] + arr[high]) > sum)
                    high--; // if low + high is greter than sum then decrement high so that we will get lower value

                else
                {                           // condition when (arr[low] + arr[high]) == sum
                    vector<int> temp;       // creating temp. vector.
                    temp.push_back(arr[i]); // puhsing ith, lowth, highth value in temp.
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    ans.push_back(temp); // pushing temp in ans vector, which is vector of vector.
                   
                    // or ans.push_back({arr[i],arr[low],arr[high]});
                    
                    while (low < high && arr[low] == arr[low + 1])
                        low++; // incrementing low, till low is equal to low+1. (to avoid duplicate triplet)
                    while (low < high && arr[high] == arr[high - 1])
                        high--; // decrementing high, till high is equal to high-1.(to avoid duplicate triplet)

                    low++;
                    high--; // and incrementing low, so that low will stand on next element which will not equal to low -1. similarly for high decrementing.
                }
            }
        }

        //         while(i<(n-1) && arr[i]==arr[i+1]) i++; // to handle case for arr[i] is equal to its next element to get override on same triplet. to handle this case we can write seperate while loop like this or you can write if statement like this "if(i==0 || (arr[i] != arr[i-1]))"  after for loop of i. so that if it is equal to its previous element, then won't enter in if block and increment i. here i==0, which is for first case when i == 0 and do'nt have any triplet in ans.
    }
    return ans;
}

// Approach 2:  Using three for loops. TC- O(n3.logn) SC-O()
vector<vector<int>> findTriplets(vector<int> arr, int n, int sum)
{
    vector<vector<int>> ans = {};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (n - 2); i++)
    {
        for (int j = (i + 1); j < (n - 1); j++)
        {
            for (int k = (j + 1); k < n; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == sum)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    if (ans.size() == 0 || !(binary_search(ans.begin(), ans.end(), temp)))
                        ans.push_back(temp);
                }
            }
        }
    }

    return ans;
}

// Triplet sum from GFG. - In gfg problem no need to return ans vector with triplets, just return true if triplet is present or return false.
//TC- O(n2) SC-O(1)
bool hasTripletSum(vector<int> &arr, int target) {

    int n=arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++){
        
        int newT = target - arr[i]; //considering ith element is first value of pair. now check remaining two value which equals to newT.
        
        int j=i+1, k=n-1;
        
        while(j<k){
            int pairSum = arr[j]+arr[k];
            if(pairSum < newT)
                j++;
            
            else if(pairSum > newT)
                k--;
            
            else
                return true;
        }
    }
    
    return false;
}