
 //It is from leetcode.
 //Approach 1: TC,SC - O(N) : first store key value pair of element and it's frequency in map.
 bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ump;
        unordered_set<int>st;

        for(int i = 0; i<arr.size(); i++){
            ump[arr[i]]++; //incremnet frequency count as per element in map.
        }

        for(auto &i:ump){ 
            // if(st.find(i.second) != st.end()) return false;
            if(st.count(i.second)) return false; //if i.second that means current count is already present in set..
            // then it will return count more than zero. 
            //that means no unique occurences.

            st.insert(i.second);  //else push current frequnecies.
        }
        return true; //if we reach till here..that means...frequencies are unique.


        //Approach 2: TC,SC - O(N)-> using same map and set..but apporach is little different
        //if elements freqencies are unique..then we will get size of map and set is equal..
        //but if frequencies are not unique..that means..set will remove duplicate frequency..
        //so size of set..won't be equal to map.
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(int i=0; i<arr.size(); i++) {
            // count the frequency
            mp[arr[i]]++;
        }
        // Insert the frequency into the set
        for (auto pair : mp) {
            s.insert(pair.second); // insert the frequency (second) of the element
        }
        if(s.size()==mp.size()) return true; //checking size is similar or not.
        else return false;


        //Approach 3: TC - O(nlogn),SC - O(N)
        //first sort array..then keep two pointers and check..current elemnet frequencies.
        //then push that frequency in ans vector..and move on to the next element.
        //at last check ans vector after sorting...whether unique frequencies are there are not..by comparing
        //ith frequency with i+1th frequency.
        vector<int>ans;
        int size=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<size)
        {
            int count=1;
            for(int j=i+1;j<size;j++)
            {
                if(arr[i]==arr[j])
                {
                count++;
                }
                else
                {
                    break;
                }
            }
            ans.push_back(count);
            i=i+count; 
        }

        size=ans.size();
        sort(ans.begin(),ans.end()); //sort frequncies..so that..we can compare.
        for(int i=0;i<size-1;i++)
        {
            if(ans[i]==ans[i+1])
            {
                return false;
            }
        }
        return true;
        

        // solutino 4 - tc : O(nlogn), sc: O(1)
        // as max element will be 1000 so..we are creating array of size 2001
        //because..we have negative elements also..so negative elments frequency will be
        //stored from 0 to 999 and 0th element frequency will be stored on 1000th index..
        //and positive nuber will be stored from 1001 to 2001 index.
        vector<int> countVec(2001,0);
        for(auto i:arr){
           countVec[i+1000]++; //doing elemnet plus 1000..so if elemnent is -3 then -3+1000...so we will increment count of 997th index.
            //incrementing count for element...and taking index as element.
        }
        sort(countVec.begin(),countVec.end());//then sort vector.
        for(int i = 0; i<countVec.size()-1; i++){
            //now check...if ith elemnet frequency should not be zero and
            //i th element should be equal to i+1th element..if its true..then 
            //unique occurences are not there..
            if(countVec[i] != 0 && (countVec[i] == countVec[i+1])) return false;
        }
        return true; //else unique elements are present.
    }