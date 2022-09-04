//Example for returning non repeating elements.

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


 //Approach 1: Most Efficient approach using bit manipulation TC- O(N), SC is constant.
 //step 1- take xor of all elements and finally we will get xor value, which will be combination of distinct elements cause xor of similar elements are always 0.
 //step 2- Get pos. of rightmost set bit  i.e either 001 or 010 or 100 and so on.
 //step 3- while looping over given nums array, take & between rightmost and nums[i]. resultant value will either 0 or any positive number. like 1, 2 and so on.
    //and we are creating  two groups, one is those elements whose value get 0 and another which don't have value equal to 0. and finally doing xor in their groups so that we will get distinct elements.
//step 4- push those x and y  and return ans.


     vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        int XOR=nums[0];
        for(int i=1; i<nums.size(); i++){
            XOR=XOR ^ nums[i]; //at the end of loop we will get XOR of all elements.The value of XOR at the end of loop is the XOR of those two distinct elements. in this example XOR is 7 i.e 3 ^ 4.
            //XOR of similar elements are always 0. like 2 ^ 2 =0 i.e 0010 ^ 0010 = 0000.
        }
        
        int rightMost= XOR & ~(XOR-1); //Throgh this statement we will get rightmost set bit element position. i.e in this case we will get 001 cause XOR is 111
        //so XOR-1 is 110 then ~XOR is 001. finally 111 & 001 is "001". in 001, 1 is showing pos. of right most set bit in 11"1". 
        //if XOR was 10 i.e 1010 then XOR-1 is 1001 , ~XOR is 0110 and finally 1010 & 0110 is 0010. in 0010, 1 is present at tenth place which is showing pos. of right most set bit in 10"1"0.
        
        int x=0, y=0;
        for(int i=0; i<nums.size(); i++){ //in this for loop we're creating two groups. 
            if(rightMost & nums[i]) x = x ^ nums[i]; //first group is, nums'i & rightMost is not equal to 0. i.e it might be 1 or any positive number.
        
            else y = y ^ nums[i]; // second group is nums'i & rightMost is not 1 i.e 0.
        } //At the end of for loop, out of two distinct elements, one will be in x and another in y.
        //so, by doing x ^ nums[i] and y ^ nums[i], we will get those two distinct elements. cause simialr elements of xor is always 0. so other elements will get 0 and only remain distinct element in x and y. 
        
        ans.push_back(x);
        ans.push_back(y); //pushing x and y which is distinct elements.
        sort(ans.begin(), ans.end()); //doing sorting but it always take constant time cause we have only two elements to sort.
        return ans; //returning ans vector.
    }

//iterative way to get right most set bit pos. 
// int j=0;
//  while(XOR){
//             if(XOR & 1) {
//                 comp = pow(2,j); 
//                 break;
//             }
//             j++;
//             XOR>>=1;
//         }



    //Approach 2: By sorting given array. and checking current with next element.
    //TC- O(Nlogn) SC is constant.
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size();i++){
            if(i+1 == nums.size()){ //To handle case when i+1 will go beyound index of array element. i.e it will equal to size.
              ans.push_back(nums[i]); //at this time we will return ith index element and will exit from loop with the help of break statement.
              break;
            } 
            if(nums[i]!=nums[i+1]) ans.push_back(nums[i]);
            else i++;
        }
        // cout<<nums[6]<<" ";
        return ans;
    }


    //Approach 3: by incrementing count i.e 0 to 1 and 1 to 2. and using extra space. 
    //TC- O(N) SC- O(maxElem).
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector <int> ans;
        int maxElem=0;
        for(auto k: nums) maxElem=max(maxElem,k);
        
        vector <int> v(maxElem+1);
        
        for(auto i: nums) v[i]++;
        
        for(int j=0; j<v.size(); j++) if(v[j] == 1) ans.push_back(j); 
        
        return ans;
    }